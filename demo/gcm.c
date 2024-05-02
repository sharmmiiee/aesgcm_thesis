
#include <stdlib.h>
#include <stdio.h>

#include "aes.h"
#include "gcm.h"


static inline unsigned int AES_GET_BE32(const unsigned char  *a)
{
	return (a[0] << 24) | (a[1] << 16) | (a[2] << 8) | a[3];
}

static inline void AES_PUT_BE64(unsigned char *a, unsigned long long  val)
{
	a[0] = val >> 56;
	a[1] = val >> 48;
	a[2] = val >> 40;
	a[3] = val >> 32;
	a[4] = val >> 24;
	a[5] = val >> 16;
	a[6] = val >> 8;
	a[7] = val & 0xff;
}


void increment_counter(unsigned char  *block)
{
	unsigned int val;
	val = AES_GET_BE32(block + AES_BLOCK_SIZE - 4);
	val++;
	AES_PUT_BE32(block + AES_BLOCK_SIZE - 4, val);
}


void xor_block(unsigned char *dst, const unsigned char *src) {
	
        for (int i = 0; i < AES_BLOCK_SIZE / sizeof(unsigned int); i++) {
            *((unsigned int *)dst + i) ^= *((unsigned int *)src + i);
        }
}

void shift_right_block(unsigned char  *v)
{
	unsigned int val;

	val = AES_GET_BE32(v + 12); //extracts the last 32 bits from the block: 0x0c30211f. 
	val >>= 1; //Right-shifting the value by one bit, we get: 0x0618098f.
	if (v[11] & 0x01)     //Handling Carry Propagation for the Last Byte:
		val |= 0x80000000;
	AES_PUT_BE32(v + 12, val);
	val = AES_GET_BE32(v + 8);		
	val >>= 1;
	if (v[7] & 0x01)
		val |= 0x80000000;
	AES_PUT_BE32(v + 8, val);
	
	val = AES_GET_BE32(v + 4);		
	val >>= 1;
	if (v[3] & 0x01)
		val |= 0x80000000;
	AES_PUT_BE32(v + 4, val);	 
	val = AES_GET_BE32(v);
	val >>= 1;	
	AES_PUT_BE32(v, val);
	 
}


void print_hex(const unsigned char *data, size_t len) {
        for (size_t i = 0; i < len; i++) {
            printf("%02x ", data[i]);
        }
        printf("\n");
}

uint32_t mulLow(uint32_t rs1, uint32_t rs2)
{
	uint32_t x = 0;
	for (int i = 0; i < 32; i++)
		if ((rs2 >> i) & 1)
			x ^= rs1 << i;
	return x;
}

uint32_t mulHigh(uint32_t rs1, uint32_t rs2)
{
	uint32_t x = 0;
	for (int i = 1; i < 32; i++)
		if ((rs2 >> i) & 1)
			x ^= rs1 >> (32 - i);
	return x;
}



void reverseBits(uint32_t *z) {
        uint32_t temp = *z;
        *z = 0;
        for (int j = 0; j < 32; j++) {
            if (temp & (1U << j)) {
                *z |= (1U << (31 - j)); // Reverse the bit position
            }
        }
}


uint32_t extract_uint32(const unsigned char *x, int offset) {
        uint32_t result = 0;
        result |= ((uint32_t)x[offset + 3] << 24);
        result |= ((uint32_t)x[offset + 2] << 16);
        result |= ((uint32_t)x[offset + 1] << 8);
        result |= ((uint32_t)x[offset]);
        return result;
}

uint32_t reverse_input(uint32_t rs1, uint32_t rs2)
{
	uint32_t x = rs1;
	int ret = rs2 & 31;
	if (ret & 1)
		x = ((x & 0x55555555) << 1) | ((x & 0xAAAAAAAA) >> 1);
	if (ret & 2)
		x = ((x & 0x33333333) << 2) | ((x & 0xCCCCCCCC) >> 2);
	if (ret & 4)
		x = ((x & 0x0F0F0F0F) << 4) | ((x & 0xF0F0F0F0) >> 4);
	if (ret & 8)
		x = ((x & 0x00FF00FF) << 8) | ((x & 0xFF00FF00) >> 8);
	if (ret & 16)
		x = ((x & 0x0000FFFF) << 16) | ((x & 0xFFFF0000) >> 16);
	return x;
}

#ifdef KARATSUBA_CUSTINSTR_ENABLED
/*gf_mul with customized instruction*/
void karatsuba_custinstr( unsigned char  *x, const unsigned char  *y, unsigned char  *z){
	
	// printf("Karatsuba_custinstr ");
	unsigned int start_cc, end_cc;
	unsigned int pcmr = 1; //global enable without saturation 
	unsigned int pcer = 3; //cycles and instr count enable 

	// Enable cycle and instruction count
	asm volatile ("csrw 0x7e0, %0" :: "r" (pcer));

	// Enable global cycle counter
	asm volatile ("csrw 0x7e1, %0" :: "r" (pcmr));
	asm volatile(
	 "    csrr %0, 0x780 \n" 
	  : "=r" (start_cc)
		 
	);
	uint32_t z0, z1, z2, z3, z4, z5, z6, z7;
	uint32_t t0, t1, t2, t3;
	
	// Extract x into four 32-bit integers x0, x1, x2, and x3
        uint32_t x0 = extract_uint32(x, 0);
        uint32_t x1 = extract_uint32(x, 4);
        uint32_t x2 = extract_uint32(x, 8);
        uint32_t x3 = extract_uint32(x, 12);
	
	uint32_t y0 = extract_uint32(y, 0);
        uint32_t y1 = extract_uint32(y, 4);
        uint32_t y2 = extract_uint32(y, 8);
        uint32_t y3 = extract_uint32(y, 12);

  
        x0 = reverse_input(x0, 7);					//  reverse input x 
	x1 = reverse_input(x1, 7);
	x2 = reverse_input(x2, 7);
	x3 = reverse_input(x3, 7);
	
	
	y0 = reverse_input(y0, 7);					//  reverse input y 
	y1 = reverse_input(y1, 7);
	y2 = reverse_input(y2, 7);
	y3 = reverse_input(y3, 7);

	
	asm volatile (
            "nop \n"
            "mulclh %[z7], %[x3], %[y3]\n"
            "nop \n"
            "mulcl  %[z6],  %[x3], %[y3]\n"
            "nop \n"
            "mulclh %[z5], %[x2], %[y2]\n"
            "nop \n"
            "mulcl  %[z4],  %[x2], %[y2]\n"
            "nop \n"
            : [z7] "=r" (z7), [z6] "=r" (z6), [z5] "=r" (z5), [z4] "=r" (z4) // output
            : [x3] "r" (x3), [y3] "r" (y3), [x2] "r" (x2), [y2] "r" (y2)     // input
        );	
		
	t0 = x2 ^ x3;    
	t2 = y2 ^ y3;
	
	
	asm volatile (
            "nop \n"
            "mulclh %[t1_tmp], %[t0], %[t2]\n"   // Perform the multiplication and store the result temporarily
            "nop \n"
            "mulcl  %[t0],  %[t0], %[t2]\n"
            "nop \n"
            : [t1_tmp] "=r" (t1) // Output temporary result to t1_tmp
            : [t0] "r" (t0), [t2] "r" (t2) // Inputs are t0 and t2
	);

	t1 = t1 ^ z5 ^ z7;
	t0 = t0 ^ z4 ^ z6;
	z6 = z6 ^ t1;
	z5 = z5 ^ t0;
	
	
	asm volatile (
            "nop \n"
            "mulclh %[z3], %[x1], %[y1]\n"
            "nop \n"
            "mulcl  %[z2],  %[x1], %[y1]\n"
            "nop \n"
            "mulclh %[z1], %[x0], %[y0]\n"
            "nop \n"
            "mulcl  %[z0],  %[x0], %[y0]\n"
            "nop \n"
            : [z3] "=r" (z3), [z2] "=r" (z2), [z1] "=r" (z1), [z0] "=r" (z0) // output
            : [x1] "r" (x1), [y1] "r" (y1), [x0] "r" (x0), [y0] "r" (y0)     // input
        );	
	
	
	t0 = x0 ^ x1;
	t2 = y0 ^ y1;
	
	asm volatile (
            "nop \n"
            "mulclh %[t1], %[t0], %[t2]\n"
            "nop \n"
            "mulcl  %[t0],  %[t0], %[t2]\n"
            "nop \n"
            : [t1] "=r" (t1) // Output
            : [t0] "r" (t0), [t2] "r" (t2) // Inputs are t0 and t2
	);
	
	t1 = t1 ^ z1 ^ z3;
	t0 = t0 ^ z0 ^ z2;
	z2 = z2 ^ t1;
	z1 = z1 ^ t0;
	
        t3 = y1 ^ y3;							//  split
	t2 = y0 ^ y2;
	t1 = x1 ^ x3;
	t0 = x0 ^ x2;
	
	
        asm volatile (
            "nop \n"
            "mulclh %[x3], %[t1], %[t3]\n"
            "nop \n"
            "mulcl  %[x2],  %[t1], %[t3]\n"
            "nop \n"
            "mulclh %[x1], %[t0], %[t2]\n"
            "nop \n"
            "mulcl  %[x0],  %[t0], %[t2]\n"
            "nop \n"
            : [x3] "=r" (x3), [x2] "=r" (x2), [x1] "=r" (x1), [x0] "=r" (x0) // output
            : [t1] "r" (t1), [t3] "r" (t3), [t0] "r" (t0), [t2] "r" (t2)     // input
        );	

	t0 = t0 ^ t1;
	t2 = t2 ^ t3;
	
	
	asm volatile (
            "nop \n"
            "mulclh %[t1], %[t0], %[t2]\n" 
            "nop \n"
            "mulcl  %[t0],  %[t0], %[t2]\n"
            "nop \n"
            : [t1] "=r" (t1) // Output
            : [t0] "r" (t0), [t2] "r" (t2) // Inputs are t0 and t2
	);
	
	t1 = t1 ^ x1 ^ x3;
	t0 = t0 ^ x0 ^ x2;
	x2 = x2 ^ t1;
	x1 = x1 ^ t0;
	
	
        x3 = x3 ^ z3 ^ z7;						//  finalize
	x2 = x2 ^ z2 ^ z6;
	x1 = x1 ^ z1 ^ z5;
	x0 = x0 ^ z0 ^ z4;
	z5 = z5 ^ x3;
	z4 = z4 ^ x2;
	z3 = z3 ^ x1;
	z2 = z2 ^ x0;
	
	/*mul reduction*/
	
#ifdef MUL_REDUCTION
	//printf("(MUL REDUCTION): ");

	t1 = mulHigh(z7, 0x87);
	t0 = mulLow(z7, 0x87);

	z4 = z4 ^ t1;
	z3 = z3 ^ t0;

	t1 = mulHigh(z6, 0x87);
	t0 = mulLow(z6, 0x87);

	z3 = z3 ^ t1;
	z2 = z2 ^ t0;

	t1 = mulHigh(z5, 0x87);
	t0 = mulLow(z5, 0x87);

	z2 = z2 ^ t1;
	z1 = z1 ^ t0;

	t1 = mulHigh(z4, 0x87);
	t0 = mulLow(z4, 0x87);

	z1 = z1 ^ t1;
	z0 = z0 ^ t0;

#endif


//shift reduction
#ifdef SHIFT_REDUCTION 
	//printf("(SHIFT REDUCTION): ");
        z4 = z4 ^ (z7 >> 31) ^ (z7 >> 30) ^ (z7 >> 25);
	z3 = z3 ^ z7 ^ (z7 << 1) ^ (z7 << 2) ^ (z7 << 7) ^
		(z6 >> 31) ^ (z6 >> 30) ^ (z6 >> 25);
	z2 = z2 ^ z6 ^ (z6 << 1) ^ (z6 << 2) ^ (z6 << 7) ^
		(z5 >> 31) ^ (z5 >> 30) ^ (z5 >> 25);
	z1 = z1 ^ z5 ^ (z5 << 1) ^ (z5 << 2) ^ (z5 << 7) ^
		(z4 >> 31) ^ (z4 >> 30) ^ (z4 >> 25);
	z0 = z0 ^ z4 ^ (z4 << 1) ^ (z4 << 2) ^ (z4 << 7);
	
#endif

	
#ifdef MUL_INS_REDUCTION
	uint32_t imm;

	//printf("(MUL INSTRUCTION REDUCTION): ");
	asm volatile (
		"nop \n"
		"li     %[imm], 0x87\n"
		"mulclh %[t1], %[z7], %[imm]\n"
		"nop \n"
		"mulcl  %[t0], %[z7], %[imm]\n"
		"nop \n"
		: [t1] "=r" (t1), [t0] "=r" (t0), [imm] "=r" (imm)
		: [z7] "r" (z7)
	);	

	z4 = z4 ^ t1;
	z3 = z3 ^ t0;
	
	asm volatile (
		"nop \n"
		"li     %[imm], 0x87\n"
		"mulclh %[t1], %[z6], %[imm]\n"
		"nop \n"
		"mulcl  %[t0], %[z6], %[imm]\n"
		"nop \n"
		: [t1] "=r" (t1), [t0] "=r" (t0), [imm] "=r" (imm)
		: [z6] "r" (z6)
	);	

	z3 = z3 ^ t1;
	z2 = z2 ^ t0;

	asm volatile (
		"nop \n"
		"li     %[imm], 0x87\n"
		"mulclh %[t1], %[z5], %[imm]\n"
		"nop \n"
		"mulcl  %[t0], %[z5], %[imm]\n"
		"nop \n"
		: [t1] "=r" (t1), [t0] "=r" (t0), [imm] "=r" (imm)
		: [z5] "r" (z5)
	);

	z2 = z2 ^ t1;
	z1 = z1 ^ t0;
	

	asm volatile (
		"nop \n"
		"li     %[imm], 0x87\n"
		"mulclh %[t1], %[z4], %[imm]\n"
		"nop \n"
		"mulcl  %[t0], %[z4], %[imm]\n"
		"nop \n"
		: [t1] "=r" (t1), [t0] "=r" (t0), [imm] "=r" (imm)
		: [z4] "r" (z4)
	);

	z1 = z1 ^ t1;
	z0 = z0 ^ t0;
#endif


//#ifdef MUL_REDUCTION
#ifdef MUL_IMM_REDUCTION
	//printf("(MUL IMMEDIATE INSTRUCTION REDUCTION): ");
	
	asm volatile (
	    "nop \n"
	    "mulclhi %[t1], %[z7],0x87\n"
	    "nop \n"
	    "mulcli  %[t0],  %[z7], 0x87\n"
	    "nop \n"
	    : [t1] "=r" (t1), [t0] "=r" (t0) // output
	    : [z7] "r" (z7)
	);	


	z4 = z4 ^ t1;
	z3 = z3 ^ t0;
	
	asm volatile (
	    "nop \n"
	    "mulclhi %[t1], %[z6],0x87\n"
	    "nop \n"
	    "mulcli  %[t0],  %[z6], 0x87\n"
	    "nop \n"
	    : [t1] "=r" (t1), [t0] "=r" (t0) // output
	    : [z6] "r" (z6)
	);	

	z3 = z3 ^ t1;
	z2 = z2 ^ t0;

	
	asm volatile (
	    "nop \n"
	    "mulclhi %[t1], %[z5],0x87\n"
	    "nop \n"
	    "mulcli  %[t0],  %[z5], 0x87\n"
	    "nop \n"
	    : [t1] "=r" (t1), [t0] "=r" (t0) // output
	    : [z5] "r" (z5)
	);	

	z2 = z2 ^ t1;
	z1 = z1 ^ t0;
	
	asm volatile (
	    "nop \n"
	    "mulclhi %[t1], %[z4],0x87\n"
	    "nop \n"
	    "mulcli  %[t0],  %[z4], 0x87\n"
	    "nop \n"
	    : [t1] "=r" (t1), [t0] "=r" (t0) // output
	    : [z4] "r" (z4)
	);	


	z1 = z1 ^ t1;
	z0 = z0 ^ t0;
 #endif
   
	reverseBits(&z0);
	reverseBits(&z1);
	reverseBits(&z2);
	reverseBits(&z3);

        // Store the results into the z array using AES_PUT_BE32
        AES_PUT_BE32(z, z0);
        AES_PUT_BE32(z + 4, z1);
        AES_PUT_BE32(z + 8, z2);
        AES_PUT_BE32(z + 12, z3);
	
	asm volatile (
	     " csrr %0, 0x780 \n"
	     : "=r" (end_cc)
	);
	 

//	printf(" start clock cycle  = %u\n", start_cc);
  //  printf(" end clock cycle  = %u\n", end_cc);
	printf(" total clock cycle = %u\n", end_cc - start_cc);
		       
}
#endif

#ifdef GF_MUL_KARATSUBA_ENABLED
void gf_mul_karatsuba( unsigned char  *x, const unsigned char  *y, unsigned char  *z){

	//printf("gf_mul_karatsuba ");
	unsigned int start_cc, end_cc;
	unsigned int pcmr = 1; //global enable without saturation 
        unsigned int pcer = 3; // cycles and instr count enable 

        // Enable cycle and instruction count
        asm volatile ("csrw 0x7e0, %0" :: "r" (pcer));

        // Enable global cycle counter
        asm volatile ("csrw 0x7e1, %0" :: "r" (pcmr));
	asm volatile(
		 "    csrr %0, 0x780 \n" 
		  : "=r" (start_cc)
		  	 
	);
	
	uint32_t z0, z1, z2, z3, z4, z5, z6, z7;
	uint32_t t0, t1, t2, t3;
	
	// Extract x into four 32-bit integers x0, x1, x2, and x3
        uint32_t x0 = extract_uint32(x, 0);
        uint32_t x1 = extract_uint32(x, 4);
        uint32_t x2 = extract_uint32(x, 8);
        uint32_t x3 = extract_uint32(x, 12);
	
	uint32_t y0 = extract_uint32(y, 0);
        uint32_t y1 = extract_uint32(y, 4);
        uint32_t y2 = extract_uint32(y, 8);
        uint32_t y3 = extract_uint32(y, 12);

        x0 = reverse_input(x0, 7);		//  reverse input x 
	x1 = reverse_input(x1, 7);
	x2 = reverse_input(x2, 7);
	x3 = reverse_input(x3, 7);
	
	
	y0 = reverse_input(y0, 7);	        //  reverse input y 
	y1 = reverse_input(y1, 7);
	y2 = reverse_input(y2, 7);
	y3 = reverse_input(y3, 7);

	z7 = mulHigh(x3, y3);			//  high pair
	z6 = mulLow(x3, y3);
	z5 = mulHigh(x2, y2);
	z4 = mulLow(x2, y2);
		
	t0 = x2 ^ x3;    
	t2 = y2 ^ y3;

	t1 = mulHigh(t0, t2);
	t0 = mulLow(t0, t2);
		
	t1 = t1 ^ z5 ^ z7;
	t0 = t0 ^ z4 ^ z6;
	z6 = z6 ^ t1;
	z5 = z5 ^ t0;
	
        z3 = mulHigh(x1, y1);			//  low pair
	z2 = mulLow(x1, y1);
	z1 = mulHigh(x0, y0);
	z0 = mulLow(x0, y0);
	
	t0 = x0 ^ x1;
	t2 = y0 ^ y1;
	t1 = mulHigh(t0, t2);
	t0 = mulLow(t0, t2);
	t1 = t1 ^ z1 ^ z3;
	t0 = t0 ^ z0 ^ z2;
	z2 = z2 ^ t1;
	z1 = z1 ^ t0;
	
        t3 = y1 ^ y3;			        //  split
	t2 = y0 ^ y2;
	t1 = x1 ^ x3;
	t0 = x0 ^ x2;
	
	x3 = mulHigh(t1, t3);			//  middle
	x2 = mulLow(t1, t3);
	x1 = mulHigh(t0, t2);
	x0 = mulLow(t0, t2);

	t0 = t0 ^ t1;
	t2 = t2 ^ t3;
	t1 = mulHigh(t0, t2);
	t0 = mulLow(t0, t2);
	t1 = t1 ^ x1 ^ x3;
	t0 = t0 ^ x0 ^ x2;
	x2 = x2 ^ t1;
	x1 = x1 ^ t0;
	
	
        x3 = x3 ^ z3 ^ z7;			//  finalize
	x2 = x2 ^ z2 ^ z6;
	x1 = x1 ^ z1 ^ z5;
	x0 = x0 ^ z0 ^ z4;
	z5 = z5 ^ x3;
	z4 = z4 ^ x2;
	z3 = z3 ^ x1;
	z2 = z2 ^ x0;
	
	
	
	//reduction
	//mul reduction
        #ifdef MUL_REDUCTION
	    //printf("(MUL_REDUCTION): ");
	    t1 = mulHigh(z7, 0x87);
	    t0 = mulLow(z7, 0x87);
	    z4 = z4 ^ t1;
	    z3 = z3 ^ t0;
	    t1 = mulHigh(z6, 0x87);
	    t0 = mulLow(z6, 0x87);
	    z3 = z3 ^ t1;
	    z2 = z2 ^ t0;
	    t1 = mulHigh(z5, 0x87);
	    t0 = mulLow(z5, 0x87);
	    z2 = z2 ^ t1;
	    z1 = z1 ^ t0;
	    t1 = mulHigh(z4, 0x87);
	    t0 = mulLow(z4, 0x87);
	    z1 = z1 ^ t1;
	    z0 = z0 ^ t0;	
        #endif
   
   
        //shift reduction
        #ifdef SHIFT_REDUCTION
	    //printf("(SHIFT_REDUCTION): ");
            z4 = z4 ^ (z7 >> 31) ^ (z7 >> 30) ^ (z7 >> 25);
	    z3 = z3 ^ z7 ^ (z7 << 1) ^ (z7 << 2) ^ (z7 << 7) ^
	    	(z6 >> 31) ^ (z6 >> 30) ^ (z6 >> 25);
	    z2 = z2 ^ z6 ^ (z6 << 1) ^ (z6 << 2) ^ (z6 << 7) ^
	    	(z5 >> 31) ^ (z5 >> 30) ^ (z5 >> 25);
	    z1 = z1 ^ z5 ^ (z5 << 1) ^ (z5 << 2) ^ (z5 << 7) ^
	    	(z4 >> 31) ^ (z4 >> 30) ^ (z4 >> 25);
	    z0 = z0 ^ z4 ^ (z4 << 1) ^ (z4 << 2) ^ (z4 << 7);
        #endif		

	reverseBits(&z0);
	reverseBits(&z1);
	reverseBits(&z2);
	reverseBits(&z3);

        // Store the results into the z array using AES_PUT_BE32
        AES_PUT_BE32(z, z0);
        AES_PUT_BE32(z + 4, z1);
        AES_PUT_BE32(z + 8, z2);
        AES_PUT_BE32(z + 12, z3);
	
	asm volatile (
	    " csrr %0, 0x780 \n"
	    : "=r" (end_cc)
	);
	 
	printf(" total clock cycle= %u\n", end_cc - start_cc);
	
			
}

#endif

/* Multiplication in GF(2^128) */
#ifdef GF_MUL_ENABLED          // 1. Using normal XOR and shift operations (base code)
void gf_multiply(const unsigned char  *input, const unsigned char  *hashKey, unsigned char  *z)
{
	//printf("gf_multiply: ");
	unsigned int start_cc, end_cc;
	unsigned int pcmr = 1; /* global enable without saturation */
	unsigned int pcer = 3; /* cycles and instr count enable */
	unsigned char  v[16];
	int i, j;

	// Enable cycle and instruction count
	asm volatile ("csrw 0x7e0, %0" :: "r" (pcer));

	// Enable global cycle counter
	asm volatile ("csrw 0x7e1, %0" :: "r" (pcmr));
	asm volatile(
		"    csrr %0, 0x780 \n" 
		: "=r" (start_cc)

	);	
	
	memset(z, 0, 16); 
	memcpy(v, hashKey, 16); 

	for (i = 0; i < 16; i++) {
		for (j = 0; j < 8; j++) {
			if (input[i] & 1 << (7 - j)) {
				
				xor_block(z, v);
			} else {
				
			}
			if (v[15] & 0x01) {
			
				shift_right_block(v);		
				v[0] ^= 0xe1;
			} else {
			
				shift_right_block(v);
			}
		}
	}
	
	asm volatile (
	  "    csrr %0, 0x780 \n"
	   : "=r" (end_cc)
	);
	
	 
	printf(" total clock cycle (MULCLH) = %u\n", end_cc - start_cc);
	
}
#endif

void ghash(const unsigned char  *hashKey, const unsigned char  *input ,size_t input_len, unsigned char  *y)
{
	
	unsigned char  temp[16];
	size_t len;

	len = input_len / 16;

	for (int i = 0; i < len; i++) {
	
		xor_block(y, input);
		input += 16;

		 /*multiplication operation for binary Galois (finite) field of 2^128 elements */
		#ifdef GF_MUL_ENABLED
			gf_multiply(y, hashKey, temp);
		#endif
		#ifdef GF_MUL_KARATSUBA_ENABLED
			gf_mul_karatsuba(y, hashKey, temp);
		#endif

		#ifdef KARATSUBA_CUSTINSTR_ENABLED
			karatsuba_custinstr(y, hashKey, temp);
		#endif
		
		memcpy(y, temp, 16);
	
	}
}



void aes_gcm_ctr(void *aes, const unsigned char *counter, const unsigned char *plain, size_t plain_len, unsigned char *cipherout)
{
	unsigned char block_count[AES_BLOCK_SIZE];

	if (plain_len == 0)
		return;

	memcpy(block_count, counter, AES_BLOCK_SIZE);

	while (plain_len >= AES_BLOCK_SIZE) {
		
		aes_cipher(aes, block_count, cipherout);
		xor_block(cipherout, plain);
		plain += AES_BLOCK_SIZE;
		cipherout += AES_BLOCK_SIZE;
		increment_counter(block_count);
		plain_len -= AES_BLOCK_SIZE;
	}

}

void * initialize_hash(const unsigned char  *key, size_t key_len, unsigned char  *H)
{
	void *aes;	
	aes = aes_setkey(key, key_len);

	if (aes == NULL)
		return NULL;

	memset(H, 0, AES_BLOCK_SIZE);
	aes_cipher(aes, H, H);
		
	return aes;
}


void gcm_set_iv(const unsigned char  *iv, size_t iv_len, const unsigned char  *H, unsigned char  *counter)
{
	unsigned char len_buf[16];

	if (iv_len == 12) {
		memcpy(counter, iv, iv_len);
		memset(counter + iv_len, 0, AES_BLOCK_SIZE - iv_len);
		counter[AES_BLOCK_SIZE - 1] = 0x01;
	} else {
		
		//ghash_start(J0);
		memset(counter, 0, 16);
		ghash(H, iv, iv_len, counter);
		AES_PUT_BE64(len_buf, 0);
		AES_PUT_BE64(len_buf + 8, iv_len * 8);
		ghash(H, len_buf, sizeof(len_buf), counter);
	}
}


void aes_gcm_ghash(const unsigned char  *H, const unsigned char  *aad, size_t aad_len,
			  const unsigned char  *crypt, size_t crypt_len, unsigned char  *S)
{
	unsigned char  len_buf[16];
	memset(S, 0, 16);
		
	ghash(H, aad, aad_len, S);
	
	ghash(H, crypt, crypt_len, S);
	AES_PUT_BE64(len_buf, aad_len * 8);
	AES_PUT_BE64(len_buf + 8, crypt_len * 8);	
	ghash(H, len_buf, sizeof(len_buf), S);
		
}

void generate_tag(void *aes, const unsigned char *counter, const unsigned char *hash_key,
                         const unsigned char *aad, size_t aad_len,
                         const unsigned char *crypt, size_t crypt_len,
                         unsigned char *tag) {
							 
        unsigned char S[16];
        unsigned char len_buf[16];

        memset(S, 0, sizeof(S));

        ghash(hash_key, aad, aad_len, S);
        ghash(hash_key, crypt, crypt_len, S);

        // Calculate the lengths and update S with GHASH(H, lengths)
        AES_PUT_BE64(len_buf, aad_len * 8);
        AES_PUT_BE64(len_buf + 8, crypt_len * 8);
        ghash(hash_key, len_buf, sizeof(len_buf), S);
            
        aes_gcm_ctr(aes, counter, S, AES_BLOCK_SIZE, tag);
}

int aes_gcm_encrypt(const unsigned char  *key, size_t key_len, const unsigned char  *iv, size_t iv_len,
	       const unsigned char  *plain, size_t plain_len,
	       const unsigned char  *aad_data, size_t aad_len, unsigned char  *cipher, unsigned char  *tag)
{
	void *aes;
	unsigned char  counter[AES_BLOCK_SIZE];
	unsigned char  inc_counter[AES_BLOCK_SIZE];
	unsigned char  hash_key[AES_BLOCK_SIZE];	
	
	aes = initialize_hash(key, key_len, hash_key);
	if (aes == NULL)
		return -1;

	gcm_set_iv(iv, iv_len, hash_key, counter);
	
	if (plain_len == 0)
		return 0;
	
	memcpy(inc_counter, counter, AES_BLOCK_SIZE);
	increment_counter(inc_counter);	
	aes_gcm_ctr(aes, inc_counter, plain, plain_len, cipher);	
	generate_tag(aes, counter, hash_key,aad_data, aad_len,cipher, plain_len,tag);

	return 0;

}

void decrypt_cipher(void *aes, const unsigned char *counter, const unsigned char *cipher, size_t cipher_len, unsigned char *plain)
{
	unsigned char block_count[AES_BLOCK_SIZE],temp[AES_BLOCK_SIZE];

	if (cipher_len == 0)
		return;

	memcpy(block_count, counter, AES_BLOCK_SIZE);


	if (cipher_len > 0) {
		aes_cipher(aes, block_count, temp);
		
		for (size_t i = 0; i < 16; i++) {
			*plain++ = *cipher++ ^ temp[i];
		}
	}
}

int aes_gcm_decrypt(const unsigned char  *key, size_t key_len, const unsigned char  *iv, size_t iv_len,
	       const unsigned char  *cipher, size_t cipher_len, const unsigned char  *aad_data, size_t aad_len, 
		   const unsigned char  *tag, unsigned char  *plain)
{
	
	void *aes;
	unsigned char  inc_counter[AES_BLOCK_SIZE];
	unsigned char  hash_key[AES_BLOCK_SIZE];
	unsigned char  counter[AES_BLOCK_SIZE];
	unsigned char  T[16];


	aes = initialize_hash(key, key_len, hash_key);
	if (aes == NULL)
		return -1;
	
	if (cipher_len == 0)
		return 0;
	
	gcm_set_iv(iv, iv_len, hash_key, counter);

	memcpy(inc_counter, counter, AES_BLOCK_SIZE);
	increment_counter(inc_counter);
			
	decrypt_cipher(aes, inc_counter, cipher, cipher_len, plain);
	
	generate_tag(aes, counter, hash_key, aad_data, aad_len, plain, cipher_len, T);
	

	return 0;

}

