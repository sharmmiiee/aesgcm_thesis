
#include <stdlib.h>
#include <stdio.h>

#include "aes.h"


int main(void) {
    //const uint8_t x[16] ={0x5F, 0xDA, 0x8E, 0x44,0x3E,0x2D,0x09,0xE0,0x84, 0xA9,0x12,0xBD,0x02,0x56,0x82,0x24};
    //const uint8_t H[16]={0xC6, 0xFB, 0xC5, 0x93,0x73,0x21,0xE0,0xB0,0x3F, 0x8A,0xE7,0xED,0xAC,0xD7,0x70,0x30};
    const uint8_t x[16] = {0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff };
    const uint8_t H[16] = {0xeb, 0x45, 0x98, 0x62, 0x28, 0xf4, 0xc2, 0x78, 0x3e, 0xa5, 0x9f, 0x0c, 0x30, 0x21, 0x1f, 0xf9 };
    uint8_t output[16];

    gf_mult(x, H, output);

    printf("Output:");
    for (int i = 0; i < 16; i++) {
        printf(" %02X", output[i]);
    }
    printf("\n");

    return 0;
}



static inline void AES_PUT_BE32( unsigned char *a, unsigned int val)
{
	a[0] = (val >> 24) & 0xff;
	a[1] = (val >> 16) & 0xff;
	a[2] = (val >> 8) & 0xff;
	a[3] = val & 0xff;
}


static inline unsigned int AES_GET_BE32(const unsigned char  *a)
{
	return (a[0] << 24) | (a[1] << 16) | (a[2] << 8) | a[3];
}

// not for gcm
//static inline void AES_PUT_BE64(unsigned char *a, unsigned long long  val)
//{
//	a[0] = val >> 56;
//	a[1] = val >> 48;
//	a[2] = val >> 40;
//	a[3] = val >> 32;
//	a[4] = val >> 24;
//	a[5] = val >> 16;
//	a[6] = val >> 8;
//	a[7] = val & 0xff;
//}

// not for gcm
//typedef struct {
//    int mode;               // cipher direction: encrypt/decrypt
//    aes_context aes_ctx;    // cipher context used
//} gcm_context;
//

// not for gcm
//static void inc32(unsigned char  *block)
//{
//	unsigned int val;
//	val = AES_GET_BE32(block + AES_BLOCK_SIZE - 4);
//	val++;
//	AES_PUT_BE32(block + AES_BLOCK_SIZE - 4, val);
//}


// not for gcm
//static void xor_block(unsigned char  *dst, const unsigned char  *src)
//{
//	
//	unsigned int *d = (	unsigned int *) dst;
//	unsigned int *s = (	unsigned int *) src;
//	*d++ ^= *s++;
//	*d++ ^= *s++;
//	*d++ ^= *s++;
//	*d++ ^= *s++;
//	
//	printf("................................in xor_block.......................................\n");
//}


// not for gcm
//static void shift_right_block(unsigned char  *v)
//{
//	unsigned int val;
//
//	val = AES_GET_BE32(v + 12); //extracts the last 32 bits from the block: 0x0c30211f. 
//	val >>= 1; //Right-shifting the value by one bit, we get: 0x0618098f.
//	if (v[11] & 0x01)     //Handling Carry Propagation for the Last Byte:
//		val |= 0x80000000;
//	AES_PUT_BE32(v + 12, val);
//	val = AES_GET_BE32(v + 8);		
//	val >>= 1;
//	if (v[7] & 0x01)
//		val |= 0x80000000;
//	AES_PUT_BE32(v + 8, val);
//	
//	val = AES_GET_BE32(v + 4);		
//	val >>= 1;
//	if (v[3] & 0x01)
//		val |= 0x80000000;
//	AES_PUT_BE32(v + 4, val);	 
//	val = AES_GET_BE32(v);
//	val >>= 1;	
//	AES_PUT_BE32(v, val);
//	 
//}

void print_hex(const unsigned char *data, size_t len) {
    for (size_t i = 0; i < len; i++) {
        printf("%02x ", data[i]);
    }
    printf("\n");
}

uint32_t clmul(uint32_t rs1, uint32_t rs2)
{
	uint32_t x = 0;
	for (int i = 0; i < 32; i++)
		if ((rs2 >> i) & 1)
			x ^= rs1 << i;
	return x;
}

uint32_t clmulh(uint32_t rs1, uint32_t rs2)
{
	uint32_t x = 0;
	for (int i = 1; i < 32; i++)
		if ((rs2 >> i) & 1)
			x ^= rs1 >> (32 - i);
	return x;
}
uint32_t rv32b_grev(uint32_t rs1, uint32_t rs2)
{
	uint32_t x = rs1;
	int shamt = rs2 & 31;
	if (shamt & 1)
		x = ((x & 0x55555555) << 1) | ((x & 0xAAAAAAAA) >> 1);
	if (shamt & 2)
		x = ((x & 0x33333333) << 2) | ((x & 0xCCCCCCCC) >> 2);
	if (shamt & 4)
		x = ((x & 0x0F0F0F0F) << 4) | ((x & 0xF0F0F0F0) >> 4);
	if (shamt & 8)
		x = ((x & 0x00FF00FF) << 8) | ((x & 0xFF00FF00) >> 8);
	if (shamt & 16)
		x = ((x & 0x0000FFFF) << 16) | ((x & 0xFFFF0000) >> 16);
	return x;
}

void carryless_mult(int32_t operandA, int32_t operandB, int32_t *mulclh_result, int32_t *mulcl_result) {
    asm volatile (
        "nop \n"
        "mulclh %[mulclh_result], %[operandA], %[operandB]\n"
        "nop \n"
        "mulcl  %[mulcl_result],  %[operandA], %[operandB]\n"
        "nop \n"
        : [mulclh_result] "=r" (*mulclh_result), [mulcl_result] "=r" (*mulcl_result) // output
        : [operandA] "r" (operandA), [operandB] "r" (operandB)                       // input
    );
}

void carryless_mult_imm(int32_t operandA, int32_t *mulclhi_result, int32_t *mulcli_result) {
    asm volatile (
        "mulclhi %[mulclhi_result], %[operandA], 0x87\n"
        "nop \n"
        "mulcli  %[mulcli_result],  %[operandA], 0x87\n"
        "nop \n"
        : [mulclhi_result] "=r" (*mulclhi_result), [mulcli_result] "=r" (*mulcli_result) // output
        : [operandA] "r" (operandA)  // input
    );
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




static void gf_mult( unsigned char  *x, const unsigned char  *y, unsigned char  *z){
    printf("x before multiplication:");
    print_hex(x, 16);
    printf("y before multiplication:");
    print_hex(y, 16);
	
    uint32_t z0, z1, z2, z3, z4, z5, z6, z7;
    uint32_t t0, t1, t2, t3;
    uint8_t output[16];	
	
    // Extract x into four 32-bit integers x0, x1, x2, and x3
    uint32_t x0 = extract_uint32(x, 0);
    uint32_t x1 = extract_uint32(x, 4);
    uint32_t x2 = extract_uint32(x, 8);
    uint32_t x3 = extract_uint32(x, 12);
	
    uint32_t y0 = extract_uint32(y, 0);
    uint32_t y1 = extract_uint32(y, 4);
    uint32_t y2 = extract_uint32(y, 8);
    uint32_t y3 = extract_uint32(y, 12);

   
    //  4 x GREV
    x0 = rv32b_grev(x0, 7);					//  reverse input x 
    x1 = rv32b_grev(x1, 7);
    x2 = rv32b_grev(x2, 7);
    x3 = rv32b_grev(x3, 7);
	
	
    y0 = rv32b_grev(y0, 7);					//  reverse input y 
    y1 = rv32b_grev(y1, 7);
    y2 = rv32b_grev(y2, 7);
    y3 = rv32b_grev(y3, 7);

    //z7 = clmulh(x3, y3);				//  high pair
    //z6 = clmul(x3, y3);
    //z5 = clmulh(x2, y2);
    //z4 = clmul(x2, y2);
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
        : [x3] "r" (x3), [y3] "r" (y3), [x2] "r" (x2), [y2] "r" (y2)                      // input
    );	

    t0 = x2 ^ x3;    
    t2 = y2 ^ y3;
	

    //t1 = clmulh(t0, t2);
    //t0 = clmul(t0, t2);
    carryless_mult(t0, t2, &t1, &t0); // operandA, operandB, mulclh_result, mulcl_result
	

    t1 = t1 ^ z5 ^ z7;
    t0 = t0 ^ z4 ^ z6;
    z6 = z6 ^ t1;
    z5 = z5 ^ t0;
	
	
    //z3 = clmulh(x1, y1);				//  low pair
    //z2 = clmul(x1, y1);
    //z1 = clmulh(x0, y0);
    //z0 = clmul(x0, y0);
    carryless_mult(x1, y1, &z3, &z2); // operandA, operandB, mulclh_result, mulcl_result
    carryless_mult(x0, y0, &z1, &z0); // operandA, operandB, mulclh_result, mulcl_result
	
	
    t0 = x0 ^ x1;
    t2 = y0 ^ y1;
    //t1 = clmulh(t0, t2);
    //t0 = clmul(t0, t2);
    carryless_mult(t0, t2, &t1, &t0); // operandA, operandB, mulclh_result, mulcl_result
    t1 = t1 ^ z1 ^ z3;
    t0 = t0 ^ z0 ^ z2;
    z2 = z2 ^ t1;
    z1 = z1 ^ t0;
	
    t3 = y1 ^ y3;							//  split
    t2 = y0 ^ y2;
    t1 = x1 ^ x3;
    t0 = x0 ^ x2;
	
    //x3 = clmulh(t1, t3);				//  middle
    //x2 = clmul(t1, t3);
    //x1 = clmulh(t0, t2);
    //x0 = clmul(t0, t2);
    carryless_mult(t1, t3, &x3, &x2); // operandA, operandB, mulclh_result, mulcl_result
    carryless_mult(t0, t2, &x1, &x0); // operandA, operandB, mulclh_result, mulcl_result

    t0 = t0 ^ t1;
    t2 = t2 ^ t3;
    //t1 = clmulh(t0, t2);
    //t0 = clmul(t0, t2);
    carryless_mult(t0, t2, &t1, &t0); // operandA, operandB, mulclh_result, mulcl_result
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
	
	
	
    //reduction
    //mul reduction
    //t1 = clmulh(z7, 0x87);
    //t0 = clmul(z7, 0x87);
    carryless_mult_imm(z7, &t1, &t0); // operandA, mulclhi_result, mulcli_result
    z4 = z4 ^ t1;
    z3 = z3 ^ t0;
    //t1 = clmulh(z6, 0x87);
    //t0 = clmul(z6, 0x87);
    carryless_mult_imm(z6, &t1, &t0); // operandA, mulclhi_result, mulcli_result
    z3 = z3 ^ t1;
    z2 = z2 ^ t0;
    //t1 = clmulh(z5, 0x87);
    //t0 = clmul(z5, 0x87);
    carryless_mult_imm(z5, &t1, &t0); // operandA, mulclhi_result, mulcli_result
    z2 = z2 ^ t1;
    z1 = z1 ^ t0;
    //t1 = clmulh(z4, 0x87);
    //t0 = clmul(z4, 0x87);
    carryless_mult_imm(z4, &t1, &t0); // operandA, mulclhi_result, mulcli_result
    z1 = z1 ^ t1;
    z0 = z0 ^ t0;
   
   
   //shift reduction
   
 /*z4 = z4 ^ (z7 >> 31) ^ (z7 >> 30) ^ (z7 >> 25);
	z3 = z3 ^ z7 ^ (z7 << 1) ^ (z7 << 2) ^ (z7 << 7) ^
		(z6 >> 31) ^ (z6 >> 30) ^ (z6 >> 25);
	z2 = z2 ^ z6 ^ (z6 << 1) ^ (z6 << 2) ^ (z6 << 7) ^
		(z5 >> 31) ^ (z5 >> 30) ^ (z5 >> 25);
	z1 = z1 ^ z5 ^ (z5 << 1) ^ (z5 << 2) ^ (z5 << 7) ^
		(z4 >> 31) ^ (z4 >> 30) ^ (z4 >> 25);
	z0 = z0 ^ z4 ^ (z4 << 1) ^ (z4 << 2) ^ (z4 << 7);*/
	
/*	printf("............................final result after shift reduction.......\n");
	  printf("z0: %08X\n", z0);
    printf("z1: %08X\n", z1);
	  printf("z2: %08X\n", z2);
    printf("z3: %08X\n", z3);
	printf("z4: %08X\n", z4);*/
	
	reverseBits(&z0);
	reverseBits(&z1);
	reverseBits(&z2);
	reverseBits(&z3);

	 // Store the results into the z array using AES_PUT_BE32
    AES_PUT_BE32(z, z0);
    AES_PUT_BE32(z + 4, z1);
    AES_PUT_BE32(z + 8, z2);
    AES_PUT_BE32(z + 12, z3);
	
	printf("Output:");
    for (int i = 0; i < 16; i++) {
        printf(" %02X", z[i]);
    }
    printf("\n");
	
		
}

////----------- pure software -----
//static void gf_mult( unsigned char  *x, const unsigned char  *y, unsigned char  *z){
//    printf("x before multiplication:");
//    print_hex(x, 16);
//    printf("y before multiplication:");
//    print_hex(y, 16);
//	
//    uint32_t z0, z1, z2, z3, z4, z5, z6, z7;
//    uint32_t t0, t1, t2, t3;
//    uint8_t output[16];	
//	
//    // Extract x into four 32-bit integers x0, x1, x2, and x3
//    uint32_t x0 = extract_uint32(x, 0);
//    uint32_t x1 = extract_uint32(x, 4);
//    uint32_t x2 = extract_uint32(x, 8);
//    uint32_t x3 = extract_uint32(x, 12);
//	
//    uint32_t y0 = extract_uint32(y, 0);
//    uint32_t y1 = extract_uint32(y, 4);
//    uint32_t y2 = extract_uint32(y, 8);
//    uint32_t y3 = extract_uint32(y, 12);
//
//   
//    //  4 x GREV
//    x0 = rv32b_grev(x0, 7);					//  reverse input x 
//    x1 = rv32b_grev(x1, 7);
//    x2 = rv32b_grev(x2, 7);
//    x3 = rv32b_grev(x3, 7);
//	
//	
//    y0 = rv32b_grev(y0, 7);					//  reverse input y 
//    y1 = rv32b_grev(y1, 7);
//    y2 = rv32b_grev(y2, 7);
//    y3 = rv32b_grev(y3, 7);
//
//    z7 = clmulh(x3, y3);				//  high pair
//    z6 = clmul(x3, y3);
//    z5 = clmulh(x2, y2);
//    z4 = clmul(x2, y2);
//		
//	t0 = x2 ^ x3;    
//	t2 = y2 ^ y3;
//	
//
//	t1 = clmulh(t0, t2);
//	t0 = clmul(t0, t2);
//		
//	t1 = t1 ^ z5 ^ z7;
//	t0 = t0 ^ z4 ^ z6;
//	z6 = z6 ^ t1;
//	z5 = z5 ^ t0;
//	
//	
//    z3 = clmulh(x1, y1);				//  low pair
//	z2 = clmul(x1, y1);
//	z1 = clmulh(x0, y0);
//	z0 = clmul(x0, y0);
//	
//	
//	t0 = x0 ^ x1;
//	t2 = y0 ^ y1;
//	t1 = clmulh(t0, t2);
//	t0 = clmul(t0, t2);
//	t1 = t1 ^ z1 ^ z3;
//	t0 = t0 ^ z0 ^ z2;
//	z2 = z2 ^ t1;
//	z1 = z1 ^ t0;
//	
//    t3 = y1 ^ y3;							//  split
//	t2 = y0 ^ y2;
//	t1 = x1 ^ x3;
//	t0 = x0 ^ x2;
//	
//	x3 = clmulh(t1, t3);				//  middle
//	x2 = clmul(t1, t3);
//	x1 = clmulh(t0, t2);
//	x0 = clmul(t0, t2);
//
//	t0 = t0 ^ t1;
//	t2 = t2 ^ t3;
//	t1 = clmulh(t0, t2);
//	t0 = clmul(t0, t2);
//	t1 = t1 ^ x1 ^ x3;
//	t0 = t0 ^ x0 ^ x2;
//	x2 = x2 ^ t1;
//	x1 = x1 ^ t0;
//	
//	
//    x3 = x3 ^ z3 ^ z7;						//  finalize
//	x2 = x2 ^ z2 ^ z6;
//	x1 = x1 ^ z1 ^ z5;
//	x0 = x0 ^ z0 ^ z4;
//	z5 = z5 ^ x3;
//	z4 = z4 ^ x2;
//	z3 = z3 ^ x1;
//	z2 = z2 ^ x0;
//	
//	
//	
//	//reduction
//	//mul reduction
//	t1 = clmulh(z7, 0x87);
//	t0 = clmul(z7, 0x87);
//	z4 = z4 ^ t1;
//	z3 = z3 ^ t0;
//	t1 = clmulh(z6, 0x87);
//	t0 = clmul(z6, 0x87);
//	z3 = z3 ^ t1;
//	z2 = z2 ^ t0;
//	t1 = clmulh(z5, 0x87);
//	t0 = clmul(z5, 0x87);
//	z2 = z2 ^ t1;
//	z1 = z1 ^ t0;
//	t1 = clmulh(z4, 0x87);
//	t0 = clmul(z4, 0x87);
//	z1 = z1 ^ t1;
//	z0 = z0 ^ t0;
//   
//   
//   //shift reduction
//   
// /*z4 = z4 ^ (z7 >> 31) ^ (z7 >> 30) ^ (z7 >> 25);
//	z3 = z3 ^ z7 ^ (z7 << 1) ^ (z7 << 2) ^ (z7 << 7) ^
//		(z6 >> 31) ^ (z6 >> 30) ^ (z6 >> 25);
//	z2 = z2 ^ z6 ^ (z6 << 1) ^ (z6 << 2) ^ (z6 << 7) ^
//		(z5 >> 31) ^ (z5 >> 30) ^ (z5 >> 25);
//	z1 = z1 ^ z5 ^ (z5 << 1) ^ (z5 << 2) ^ (z5 << 7) ^
//		(z4 >> 31) ^ (z4 >> 30) ^ (z4 >> 25);
//	z0 = z0 ^ z4 ^ (z4 << 1) ^ (z4 << 2) ^ (z4 << 7);*/
//	
///*	printf("............................final result after shift reduction.......\n");
//	  printf("z0: %08X\n", z0);
//    printf("z1: %08X\n", z1);
//	  printf("z2: %08X\n", z2);
//    printf("z3: %08X\n", z3);
//	printf("z4: %08X\n", z4);*/
//	
//	reverseBits(&z0);
//	reverseBits(&z1);
//	reverseBits(&z2);
//	reverseBits(&z3);
//
//	 // Store the results into the z array using AES_PUT_BE32
//    AES_PUT_BE32(z, z0);
//    AES_PUT_BE32(z + 4, z1);
//    AES_PUT_BE32(z + 8, z2);
//    AES_PUT_BE32(z + 12, z3);
//	
//	printf("Output:");
//    for (int i = 0; i < 16; i++) {
//        printf(" %02X", z[i]);
//    }
//    printf("\n");
//	
//		
//}
//
/* Multiplication in GF(2^128) */
/*static void gf_mult(const unsigned char  *x, const unsigned char  *y, unsigned char  *z)
{
	printf("x before multiplication:");
    print_hex(x, 16);
    printf("y before multiplication:");
    print_hex(y, 16);
	
	unsigned char  v[16];
	int i, j;

	memset(z, 0, 16); //Z_0 = 0^128 
	memcpy(v, y, 16); ///V_0 = Y 

	for (i = 0; i < 16; i++) {
		for (j = 0; j < 8; j++) {
			if (x[i] & 1 << (7 - j)) {
				
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
	printf("z after multiplication:\n................");
    print_hex(z, 16);
}*/

// 
// static void ghash_start(unsigned char  *y)
// {
// 	/* Y_0 = 0^128 */
// 	memset(y, 0, 16);
// }
// 
// 
// 
// static void ghash(const unsigned char  *h, const unsigned char  *x, size_t xlen, unsigned char  *y)
// {
// 	size_t m, i;
// 	const unsigned char  *xpos = x;
// 	unsigned char  tmp[16];
// 
// 	m = xlen / 16;
// 
// 	for (i = 0; i < m; i++) {
// 		/* Y_i = (Y^(i-1) XOR X_i) dot H */
// 		xor_block(y, xpos);
// 		xpos += 16;
// 
// 		/* dot operation:
// 		 * multiplication operation for binary Galois (finite) field of
// 		 * 2^128 elements */
// 		
// 		gf_mult(y, h, tmp);
// 		memcpy(y, tmp, 16);
// 		
// 		print_hex(y, 16);
// 	}
// 
// 	if (x + xlen > xpos) {
// 		/* Add zero padded last block */
// 		size_t last = x + xlen - xpos;
// 		memcpy(tmp, xpos, last);
// 		memset(tmp + last, 0, sizeof(tmp) - last);
// 
// 		/* Y_i = (Y^(i-1) XOR X_i) dot H */
// 		xor_block(y, tmp);
// 
// 		/* dot operation:
// 		 * multiplication operation for binary Galois (finite) field of
// 		 * 2^128 elements */
// 		gf_mult(y, h, tmp);
// 		memcpy(y, tmp, 16);
// 	}
// 
// 	/* Return Y_m */
// }
// 
// 
// static void aes_gctr(void *aes, const unsigned char  *icb, const unsigned char  *x, size_t xlen, unsigned char  *y)
// {
// 	size_t i, n, last;
// 	unsigned char  cb[AES_BLOCK_SIZE], tmp[AES_BLOCK_SIZE];
// 	const unsigned char  *xpos = x;
// 	unsigned char  *ypos = y;
// 
// 	if (xlen == 0)
// 		return;
// 
// 	n = xlen / 16;
// 
// 	memcpy(cb, icb, AES_BLOCK_SIZE);
// 	/* Full blocks */
// 	
// //	memset(ctx, 0, sizeof(gcm_context));//new
// 	
// 	for (i = 0; i < n; i++) {
// 	//	aes_encrypt(aes, cb, ypos);
// 	
// 	    aes_cipher(aes, cb, ypos);
// 		
// 		xor_block(ypos, xpos);
// 		xpos += AES_BLOCK_SIZE;
// 		ypos += AES_BLOCK_SIZE;
// 		inc32(cb);
// 	}
// 
// 	last = x + xlen - xpos;
// 	if (last) {
// 		/* Last, partial block */
// 	//	aes_encrypt(aes, cb, tmp);
// 		aes_cipher(aes, cb, tmp);
// 		
// 		for (i = 0; i < last; i++)
// 			*ypos++ = *xpos++ ^ tmp[i];
// 	}
// }
// 
// 
// static void * aes_gcm_init_hash_subkey(const unsigned char  *key, size_t key_len, unsigned char  *H)
// {
// 	void *aes;
// 
// 	//aes = aes_encrypt_init(key, key_len);
// 	
// 	aes = aes_setkey(key, key_len);
// 	
// 		
// 	if (aes == NULL)
// 		return NULL;
// 
// 	/* Generate hash subkey H = AES_K(0^128) */
// 	memset(H, 0, AES_BLOCK_SIZE);
// 	aes_cipher(aes, H, H);
// 	
// //	aes_hexdump_key(MSG_EXCESSIVE, "Hash subkey H for GHASH", H, AES_BLOCK_SIZE);
// 
// 	//printf("Hash subkey H for GHASH", H);
// 	return aes;
// }
// 
// 
// static void aes_gcm_prepare_j0(const unsigned char  *iv, size_t iv_len, const unsigned char  *H, unsigned char  *J0)
// {
// 	unsigned char len_buf[16];
// 
// 	if (iv_len == 12) {
// 		/* Prepare block J_0 = IV || 0^31 || 1 [len(IV) = 96] */
// 		memcpy(J0, iv, iv_len);
// 		memset(J0 + iv_len, 0, AES_BLOCK_SIZE - iv_len);
// 		J0[AES_BLOCK_SIZE - 1] = 0x01;
// 	} else {
// 		/*
// 		 * s = 128 * ceil(len(IV)/128) - len(IV)
// 		 * J_0 = GHASH_H(IV || 0^(s+64) || [len(IV)]_64)
// 		 */
// 		ghash_start(J0);
// 		ghash(H, iv, iv_len, J0);
// 		AES_PUT_BE64(len_buf, 0);
// 		AES_PUT_BE64(len_buf + 8, iv_len * 8);
// 	//   PUT_UINT32_BE(iv_len * 8, len_buf, 12);
// 	   
// 		ghash(H, len_buf, sizeof(len_buf), J0);
// 	}
// }
// 
// 
// static void aes_gcm_gctr(void *aes, const unsigned char  *J0, const unsigned char  *in, size_t len,
// 			 unsigned char  *out)
// {
// 	unsigned char  J0inc[AES_BLOCK_SIZE];
// 
// 	if (len == 0)
// 		return;
// 
// 	memcpy(J0inc, J0, AES_BLOCK_SIZE);
// 	inc32(J0inc);
// 	aes_gctr(aes, J0inc, in, len, out);
// }
// 
// 
// static void aes_gcm_ghash(const unsigned char  *H, const unsigned char  *aad, size_t aad_len,
// 			  const unsigned char  *crypt, size_t crypt_len, unsigned char  *S)
// {
// 	unsigned char  len_buf[16];
// 
// 	/*
// 	 * u = 128 * ceil[len(C)/128] - len(C)
// 	 * v = 128 * ceil[len(A)/128] - len(A)
// 	 * S = GHASH_H(A || 0^v || C || 0^u || [len(A)]64 || [len(C)]64)
// 	 * (i.e., zero padded to block size A || C and lengths of each in bits)
// 	 */
// 	ghash_start(S);
// 	ghash(H, aad, aad_len, S);
// 	ghash(H, crypt, crypt_len, S);
// 	AES_PUT_BE64(len_buf, aad_len * 8);
// 	AES_PUT_BE64(len_buf + 8, crypt_len * 8);
// 	ghash(H, len_buf, sizeof(len_buf), S);
// 
// 	//aes_hexdump_key(MSG_EXCESSIVE, "S = GHASH_H(...)", S, 16);
// }
// 
// 
// /**
//  * aes_gcm_ae - GCM-AE_K(IV, P, A)
//  */
// int aes_gcm_ae(const unsigned char  *key, size_t key_len, const unsigned char  *iv, size_t iv_len,
// 	       const unsigned char  *plain, size_t plain_len,
// 	       const unsigned char  *aad, size_t aad_len, unsigned char  *crypt, unsigned char  *tag)
// {
// 	unsigned char  H[AES_BLOCK_SIZE];
// 	unsigned char  J0[AES_BLOCK_SIZE];
// 	unsigned char  S[16];
// 	void *aes;
// 
// 	aes = aes_gcm_init_hash_subkey(key, key_len, H);
// 	if (aes == NULL)
// 		return -1;
// 
// 	aes_gcm_prepare_j0(iv, iv_len, H, J0);
// 
// 	/* C = GCTR_K(inc_32(J_0), P) */
// 	aes_gcm_gctr(aes, J0, plain, plain_len, crypt);
// 
// 	aes_gcm_ghash(H, aad, aad_len, crypt, plain_len, S);
// 
// 	/* T = MSB_t(GCTR_K(J_0, S)) */
// 	aes_gctr(aes, J0, S, sizeof(S), tag);
// 
// 	/* Return (C, T) */
// 
// 	//aes_encrypt_deinit(aes);
// 
// 	return 0;
// }
