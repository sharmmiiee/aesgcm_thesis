
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

uint32_t mulLow(uint32_t operand1, uint32_t operand2)
{
	uint32_t output = 0;
	for (int i = 0; i < 32; i++)
		if ((operand2 >> i) & 1)
			output ^= operand1 << i;
	return output;
}

uint32_t mulHigh(uint32_t operand1, uint32_t operand2)
{
	uint32_t output = 0;
	for (int i = 1; i < 32; i++)
		if ((operand2 >> i) & 1)
			output ^= operand1 >> (32 - i);
	return output;
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


uint32_t extract_32bit(const unsigned char *x, int offset) {
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

void reduce(uint32_t *input, uint32_t  *res1, uint32_t  *res2)
{
	uint32_t t0, t1;

	t1 = mulHigh(*input, 0x87);
	t0 = mulLow(*input, 0x87);
	*res1 = *res1 ^ t1;
	*res2 = *res2 ^ t0;
}

void mulReduction(uint32_t *r0, uint32_t *r1, uint32_t *r2, uint32_t *r3, uint32_t *r4, uint32_t *r5, uint32_t *r6, uint32_t *r7) 
 {

	reduce(r7,r4,r3);
	reduce(r6,r3,r2);
	reduce(r5,r2,r1);
	reduce(r4,r1,r0);

}

#ifdef KARATSUBA_CUSTINSTR_ENABLED
/*gf_mul with customized instruction*/
void karatsuba_custinstr( unsigned char  *x, const unsigned char  *y, unsigned char  *z){
	 
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
	nop_func();
	uint32_t z7,z6,z5,z4,z3,z2,z1,z0;
	uint32_t t3,t2,t1,t0;

	// Extract x into four 32-bit integers x0, x1, x2, and x3
	uint32_t x0 = extract_32bit(x, 0);
	uint32_t x1 = extract_32bit(x, 4);
	uint32_t x2 = extract_32bit(x, 8);
	uint32_t x3 = extract_32bit(x, 12);

	uint32_t y0 = extract_32bit(y, 0);
	uint32_t y1 = extract_32bit(y, 4);
	uint32_t y2 = extract_32bit(y, 8);
	uint32_t y3 = extract_32bit(y, 12);


	x0 = reverse_input(x0, 7);					//  reverse input x 
	x1 = reverse_input(x1, 7);
	x2 = reverse_input(x2, 7);
	x3 = reverse_input(x3, 7);


	y0 = reverse_input(y0, 7);					//  reverse input y 
	y1 = reverse_input(y1, 7);
	y2 = reverse_input(y2, 7);
	y3 = reverse_input(y3, 7);

	asm volatile (
		"nop;"
		"mulclh %[z7], %[x3], %[y3];"
		"mulcl  %[z6], %[x3], %[y3];"
		"mulclh %[z5], %[x2], %[y2];"
		"mulcl  %[z4], %[x2], %[y2];"
		"xor    %[t0], %[x2], %[x3];"
		"xor    %[t2], %[y2], %[y3];"
		"nop;"
		"mulclh %[t1], %[t0], %[t2];"
		"mulcl  %[t0], %[t0], %[t2];"
		"xor    %[t1], %[t1], %[z5];"
		"xor    %[t1], %[t1], %[z7];"
		"xor    %[t0], %[t0], %[z4];"
		"xor    %[t0], %[t0], %[z6];"
		"xor    %[z6], %[z6], %[t1];"
		"xor    %[z5], %[z5], %[t0];"
		"nop;"
		"mulclh %[z3], %[x1], %[y1];"
		"mulcl  %[z2], %[x1], %[y1];"
		"mulclh %[z1], %[x0], %[y0];"
		"mulcl  %[z0], %[x0], %[y0];"
		"xor    %[t0], %[x0], %[x1];"
		"xor    %[t2], %[y0], %[y1];"
		"nop;"
		"mulclh %[t1], %[t0], %[t2];"
		"mulcl  %[t0], %[t0], %[t2];"
		"xor    %[t1], %[t1], %[z1];" //t1 = t1 ^ z1 ^ z3;
		"xor    %[t1], %[t1], %[z3];"
		"xor    %[t0], %[t0], %[z0];" //t0 = t0 ^ z0 ^ z2;
		"xor    %[t0], %[t0], %[z2];"
		"xor    %[z2], %[z2], %[t1];" //z2 = z2 ^ t1;
		"xor    %[z1], %[z1], %[t0];" //z1 = z1 ^ t0;
            : [z7] "=r" (z7), [z6] "=r" (z6), [z5] "=r" (z5), [z4] "=r" (z4), 
	      [z3] "=r" (z3), [z2] "=r" (z2), [z1] "=r" (z1), [z0] "=r" (z0),
	      [t0] "=r" (t0), [t1] "=r" (t1), [t2] "=r" (t2), [t3] "=r" (t3)                  // output
            : [x3] "r" (x3),  [x2] "r" (x2),  [x1] "r" (x1),  [x0] "r" (x0),
	      [y3] "r" (y3),  [y2] "r" (y2),  [y1] "r" (y1),  [y0] "r" (y0)      // input

        );		


       asm volatile (
           "xor    %[t3], %[y1], %[y3];"  // t3 = y1 ^ y3 // split
           "xor    %[t2], %[y0], %[y2];"  // t2 = y0 ^ y2
           "xor    %[t1], %[x1], %[x3];"  // t1 = x1 ^ x3
           "xor    %[t0], %[x0], %[x2];"  // t0 = x0 ^ x2
           "nop;"
           "mulclh %[x3], %[t1], %[t3];"
           "mulcl  %[x2], %[t1], %[t3];"
           "mulclh %[x1], %[t0], %[t2];"
           "mulcl  %[x0], %[t0], %[t2];"
           "xor    %[t0], %[t0], %[t1];"  // t0 = t0 ^ t1
           "xor    %[t2], %[t2], %[t3];"  // t2 = t2 ^ t3
           "nop;"
           "mulclh %[t1], %[t0], %[t2];" 
           "mulcl  %[t0], %[t0], %[t2];"
           "xor    %[t1], %[t1], %[x1]; "
           "xor    %[t1], %[t1], %[x3]; "
           "xor    %[t0], %[t0], %[x0]; "
           "xor    %[t0], %[t0], %[x2]; "
           "xor    %[x2], %[x2], %[t1]; "
           "xor    %[x1], %[x1], %[t0]; "
           "xor    %[x3], %[x3], %[z3]; " // finalize
           "xor    %[x3], %[x3], %[z7]; "
           "xor    %[x2], %[x2], %[z2]; "
           "xor    %[x2], %[x2], %[z6]; "
           "xor    %[x1], %[x1], %[z1]; "
           "xor    %[x1], %[x1], %[z5]; "
           "xor    %[x0], %[x0], %[z0]; "
           "xor    %[x0], %[x0], %[z4]; "
           "xor    %[z5], %[z5], %[x3]; "
           "xor    %[z4], %[z4], %[x2]; "
           "xor    %[z3], %[z3], %[x1]; "
           "xor    %[z2], %[z2], %[x0]; "
       
           : [t3] "=r" (t3), [t2] "=r" (t2), [t1] "=r" (t1), [t0] "=r" (t0), [x3] "+r" (x3), [x2] "+r" (x2), [x1] "+r" (x1), [x0] "+r" (x0)
           : [y1] "r" (y1), [y3] "r" (y3), [y0] "r" (y0), [y2] "r" (y2), [z3] "r" (z3), [z7] "r" (z7), [z2] "r" (z2), [z6] "r" (z6), [z1] "r" (z1), [z5] "r" (z5), [z0] "r" (z0), [z4] "r" (z4)
       );

	/*mul reduction*/
	
#ifdef MUL_REDUCTION
	
	//mulReduction(&z0, &z1, &z2, &z3, &z4, &z5, &z6, &z7);	
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
	asm volatile (
		"nop;"
		"li     %[imm], 0x87;"
		"mulclh %[t1], %[z7], %[imm];"
		"nop;"
		"mulcl  %[t0], %[z7], %[imm];"
		"nop;"
		"xor    %[z4], %[z4], %[t1];"
        "xor    %[z3], %[z3], %[t0];"	
		: [t1] "=r" (t1), [t0] "=r" (t0), [imm] "=r" (imm),[z4] "+r" (z4),[z3] "+r" (z3)
		: [z7] "r" (z7)
	);	
	
	  asm volatile (
		"nop \n"
		"li     %[imm], 0x87\n"
		"mulclh %[t1], %[z6], %[imm]\n"
		"nop \n"
		"mulcl  %[t0], %[z6], %[imm]\n"
		"nop \n"
		"xor    %[z3], %[z3], %[t1]; "
	    "xor    %[z2], %[z2], %[t0]; "
		: [t1] "=r" (t1), [t0] "=r" (t0), [imm] "=r" (imm), [z3] "+r" (z3), [z2] "+r" (z2)
		: [z6] "r" (z6)
	);	

	asm volatile (
		"nop \n"
		"li     %[imm], 0x87\n"
		"mulclh %[t1], %[z5], %[imm]\n"
		"nop \n"
		"mulcl  %[t0], %[z5], %[imm]\n"
		"nop \n"
		"xor    %[z2], %[z2], %[t1]; "
	     "xor    %[z1], %[z1], %[t0]; "
		: [t1] "=r" (t1), [t0] "=r" (t0), [imm] "=r" (imm), [z2] "+r" (z2), [z1] "+r" (z1)
		: [z5] "r" (z5)
	);

	asm volatile (
		"nop \n"
		"li     %[imm], 0x87\n"
		"mulclh %[t1], %[z4], %[imm]\n"
		"nop \n"
		"mulcl  %[t0], %[z4], %[imm]\n"
		"nop \n"
		"xor    %[z1], %[z1], %[t1]; "
	     "xor    %[z0], %[z0], %[t0]; "
		: [t1] "=r" (t1), [t0] "=r" (t0), [imm] "=r" (imm), [z1] "+r" (z1), [z0] "+r" (z0)
		: [z4] "r" (z4)
	);
    
#endif

#ifdef MUL_IMM_REDUCTION
        asm volatile (
            "nop;"
            "mulclhi %[t1], %[z7], 0x87;"
            "mulcli  %[t0], %[z7], 0x87;"
            "xor     %[z4], %[z4], %[t1];"
            "xor     %[z3], %[z3], %[t0];"
            "nop;"
            "mulclhi %[t1], %[z6], 0x87;"
            "mulcli  %[t0], %[z6], 0x87;"
            "xor     %[z3], %[z3], %[t1];"
            "xor     %[z2], %[z2], %[t0];"
            "nop;"
            "mulclhi %[t1], %[z5], 0x87;"
            "mulcli  %[t0], %[z5], 0x87;"
            "xor     %[z2], %[z2], %[t1];"
            "xor     %[z1], %[z1], %[t0];"
            "nop \n"
            "mulclhi %[t1], %[z4],0x87\n"
            "nop \n"
            "mulcli  %[t0],  %[z4], 0x87\n"
            "nop \n"
            "xor     %[z1], %[z1], %[t1];"
            "xor     %[z0], %[z0], %[t0];"
            : [t1] "=r" (t1), [t0] "=r" (t0), [z4] "+r" (z4), [z3] "+r" (z3), [z2] "+r" (z2), [z1] "+r" (z1), [z0] "+r" (z0) // output and input
            : [z7] "r" (z7), [z6] "r" (z6), [z5] "r" (z5)
        );

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

	nop_func();
	asm volatile (
	     " csrr %0, 0x780 \n"
	     : "=r" (end_cc)
	);
	 
	printf(" total clock cycle = %u\n", end_cc - start_cc);
		       
}
#endif

void shiftReduction(uint32_t *r0, uint32_t *r1, uint32_t *r2, uint32_t *r3, uint32_t *r4, uint32_t *r5, uint32_t *r6, uint32_t *r7) 
{
        *r4 = *r4 ^ (*r7 >> 31) ^ (*r7 >> 30) ^ (*r7 >> 25);
        *r3 = *r3 ^ *r7 ^ (*r7 << 1) ^ (*r7 << 2) ^ (*r7 << 7) ^
            (*r6 >> 31) ^ (*r6 >> 30) ^ (*r6 >> 25);
        *r2 = *r2 ^ *r6 ^ (*r6 << 1) ^ (*r6 << 2) ^ (*r6 << 7) ^
            (*r5 >> 31) ^ (*r5 >> 30) ^ (*r5 >> 25);
        *r1 = *r1 ^ *r5 ^ (*r5 << 1) ^ (*r5 << 2) ^ (*r5 << 7) ^
            (*r4 >> 31) ^ (*r4 >> 30) ^ (*r4 >> 25);
        *r0 = *r0 ^ *r4 ^ (*r4 << 1) ^ (*r4 << 2) ^ (*r4 << 7);
}



void pair_multiplication_xor(

	uint32_t high1, uint32_t low1, uint32_t high2, uint32_t low2,
	uint32_t *res3, uint32_t *res2,uint32_t *res1, uint32_t *res0) {
	 
	uint32_t temp0, temp1, temp2;

	// Compute high and low parts of multiplication for the pair
	*res3 = mulHigh(high1, high2);				
	*res2 = mulLow(high1, high2);
	*res1 = mulHigh(low1, low2);
	*res0 = mulLow(low1, low2);
		
	temp0 = low1 ^ high1;    
	temp2 = low2 ^ high2;
  
	temp1 = mulHigh(temp0, temp2);
	temp0 = mulLow(temp0, temp2);
		
	temp1 = temp1 ^ *res1 ^ *res3;
	temp0 = temp0 ^ *res0 ^ *res2;
	*res2 = *res2 ^ temp1;
	*res1 = *res1 ^ temp0;
	
}

#ifdef GF_MUL_KARATSUBA_ENABLED
void gf_mul_karatsuba( unsigned char  *x, const unsigned char  *h, unsigned char  *z)
{

	unsigned int start_cc, end_cc;
	unsigned int pcmr = 1; //global enable without saturation 
	unsigned int pcer = 3; // cycles and instr count enable 

	// Enable cycle and instruction count
	asm volatile ("csrw 0x7e0, %0" :: "r" (pcer));

	// Enable global cycle counter
	asm volatile ("csrw 0x7e1, %0" :: "r" (pcmr));
	asm volatile(
	  " csrr %0, 0x780;" 
	  : "=r" (start_cc)
		 
	);

	uint32_t temp0, temp1, temp2, temp3;
	uint32_t r0, r1, r2, r3, r4, r5, r6, r7;

	// Extract x into four 32-bit integers x0, x1, x2, and x3
	uint32_t x0 = extract_32bit(x, 0);
	uint32_t x1 = extract_32bit(x, 4);
	uint32_t x2 = extract_32bit(x, 8);
	uint32_t x3 = extract_32bit(x, 12);

	uint32_t h0 = extract_32bit(h, 0);
	uint32_t h1 = extract_32bit(h, 4);
	uint32_t h2 = extract_32bit(h, 8);
	uint32_t h3 = extract_32bit(h, 12);
	//  reverse input x 
	x0 = reverse_input(x0, 7);					
	x1 = reverse_input(x1, 7);
	x2 = reverse_input(x2, 7);
	x3 = reverse_input(x3, 7);

	//  reverse input h
	h0 = reverse_input(h0, 7);					
	h1 = reverse_input(h1, 7);
	h2 = reverse_input(h2, 7);
	h3 = reverse_input(h3, 7);
	//High pair multiplication

	pair_multiplication_xor(x3, x2, h3, h2, &r7, &r6,&r5,&r4);

	//Low pair multiplication

	pair_multiplication_xor(x1, x0, h1, h0, &r3, &r2,&r1,&r0);

	temp3 = h1 ^ h3;						
	temp2 = h0 ^ h2;
	temp1 = x1 ^ x3;
	temp0 = x0 ^ x2;

	//Middle pair multiplication
	 pair_multiplication_xor(temp1, temp0, temp3, temp2, &x3, &x2, &x1, &x0);
	 //final xor
	x3 = x3 ^ r3 ^ r7;						
	x2 = x2 ^ r2 ^ r6;
	x1 = x1 ^ r1 ^ r5;
	x0 = x0 ^ r0 ^ r4;
	r5 = r5 ^ x3;
	r4 = r4 ^ x2;
	r3 = r3 ^ x1;
	r2 = r2 ^ x0;
	
	
	//reduction
	//mul reduction
	#ifdef MUL_REDUCTION
		mulReduction(&r0, &r1, &r2, &r3, &r4, &r5, &r6, &r7);
	#endif
	   
	   //shift reduction
	 #ifdef SHIFT_REDUCTION
		shiftReduction(&r0, &r1, &r2, &r3, &r4, &r5, &r6, &r7);
	#endif		

	reverseBits(&r0);
	reverseBits(&r1);
	reverseBits(&r2);
	reverseBits(&r3);

        // Store the results into the z array using AES_PUT_BE32
        AES_PUT_BE32(z, r0);
        AES_PUT_BE32(z + 4, r1);
        AES_PUT_BE32(z + 8, r2);
        AES_PUT_BE32(z + 12, r3);
	
	asm volatile (
	   " csrr %0, 0x780;"
	   : "=r" (end_cc)
	);
	printf(" total clock cycle = %u\n", end_cc - start_cc);
	
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
	
	 
	//printf(" start clock cycle (MULCLH) = %u\n", start_cc);
        // printf(" end clock cycle (MULCLH) = %u\n", end_cc);
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

	//return 0;
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
		   const unsigned char  *tag, unsigned char  *plain, unsigned char *validate_tag)
{
	
	void *aes;
	unsigned char  inc_counter[AES_BLOCK_SIZE];
	unsigned char  hash_key[AES_BLOCK_SIZE];
	unsigned char  counter[AES_BLOCK_SIZE];
	//unsigned char  output_tag[16];


	aes = initialize_hash(key, key_len, hash_key);
	if (aes == NULL)
		return -1;
	
	if (cipher_len == 0)
		return 0;
	
	gcm_set_iv(iv, iv_len, hash_key, counter);

	memcpy(inc_counter, counter, AES_BLOCK_SIZE);
	increment_counter(inc_counter);
			
	decrypt_cipher(aes, inc_counter, cipher, cipher_len, plain);
	
	
	generate_tag(aes, counter, hash_key, aad_data, aad_len, cipher, cipher_len, validate_tag);
	print_hex(validate_tag, 16);
	
	return 0;

}



void nop_func(void)
{

	asm volatile (  "nop;"
			"nop;"
			"nop;"
			"nop;"
			"nop;"
			"nop;"
			"nop;"
			"nop;"
			"nop;"
			"nop;"
			"nop;"
			"nop;"
			"nop;"
			"nop;"
			"nop;"
			"nop;"
			"nop;"
			"nop;"
			"nop;"
			"nop;"
			"nop;"
			"nop;"
			"nop;"
			"nop;"
			"nop;"
			"nop;"
			"nop;"
			"nop;"
			"nop;"
			"nop;"
			"nop;"
			"nop;"
			"nop;"
			"nop;"
			"nop;"
			"nop;"
			"nop;"
			"nop;"
			"nop;"
			"nop;"
			"nop;"
			"nop;"
			"nop;"
			"nop;"
			"nop;"
			"nop;"
			"nop;"
			"nop;"
			"nop;"
			"nop;"
			"nop;"
			"nop;"
			"nop;"
			"nop;"
			"nop;"
			"nop;"
			"nop;"
			"nop;"
			"nop;"
			"nop;"
			"nop;"
			"nop;"
			"nop;"
			"nop;"
			"nop;"
			"nop;"
			"nop;"
			"nop;"
			"nop;"
			"nop;"
			"nop;"
			"nop;"
			"nop;"
			"nop;"
			"nop;"
			"nop;"
			"nop;"
			"nop;"
			"nop;"
			"nop;"
			"nop;"
			"nop;"
			"nop;"
			"nop;"
			"nop;"
			"nop;"
			"nop;"
			"nop;"
			"nop;"
			"nop;"
			"nop;"
			"nop;"
			"nop;"
			"nop;"
			"nop;"
			"nop;"
			"nop;"
			"nop;"
			"nop;"
			"nop;"
			"nop;"
		     );
}
