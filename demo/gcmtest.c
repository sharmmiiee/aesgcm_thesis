#include <stdlib.h>
#include <stdio.h>
#include "aes.h"
#include "gcm.h"

//*** 1. Using normal XOR and shift operations (base code) ***
//#define GF_MUL_ENABLED                 

//*** 2. Using Karatsuba mutiplication and multiplication reduction ***
//#define GF_MUL_KARATSUBA_ENABLED
//#define MUL_REDUCTION

//*** 3. Using Karatsuba multiplication and shift reduction ***
//#define GF_MUL_KARATSUBA_ENABLED
//#define SHIFT_REDUCTION

//*** 4. Karatsuba multiplication with mulclh and mulcl customized instruction (+mul reduction) ***
//#define KARATSUBA_CUSTINSTR_ENABLED
//#define MUL_REDUCTION

//*** 5. Karatsuba multiplication with mulclh and mulcl customized instruction (+shift reduction) ***
//#define KARATSUBA_CUSTINSTR_ENABLED
//#define SHIFT_REDUCTION

//*** 6. Karatsuba multiplication with mulclh and mulcl customized instruction (+mul instruction reduction) ***
//#define KARATSUBA_CUSTINSTR_ENABLED
//#define MUL_INS_REDUCTION

//*** 7. Karatsuba multiplication with mulch, mulcl and immediate instruction (+multiplication reduction) ***
//#define KARATSUBA_CUSTINSTR_ENABLED
//#define MUL_IMM_REDUCTION


int aesgcm(void);

const uint8_t key1[]= {0x5b,0x96,0x04,0xfe,0x14,0xea,0xdb,0xa9,0x31,0xb0,0xcc,0xf3,0x48,0x43,0xda,0xb9};
const uint8_t iv1[] ={0x92,0x1d,0x25,0x07,0xfa,0x80,0x07,0xb7,0xbd,0x06,0x7d,0x34};
const uint8_t  aad1[] ={0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,0xaa,0xbb,0xcc,0xdd,0xee,0xff};
const uint8_t  pt1[]={0x00,0x1d,0x0c,0x23,0x12,0x87,0xc1,0x18,0x27,0x84,0x55,0x4c,0xa3,0xa2,0x19,0x08};
						
int aesgcm(void)
{
	//int encrypt_result, decrypt_result;
	
	
	uint8_t cipher_buf[16], tag_buf[16],plain_buf[16];

	printf("\n\nplaintext: ");
	for (int i = 0; i < 16; ++i)
		printf("%02x ", pt1[i]);
	printf("\n");
	
	printf("\n.....................Encryption...................\n");
	//encrypt_result = aes_gcm_encrypt(key1, sizeof(key1), iv1, sizeof(iv1), pt1, sizeof(pt1),
	//					aad1, sizeof(aad1), cipher_buf, tag_buf);
	aes_gcm_encrypt(key1, sizeof(key1), iv1, sizeof(iv1), pt1, sizeof(pt1), 						aad1, sizeof(aad1), cipher_buf, tag_buf);
	
	printf("Encrypted data: ");
	for (int i = 0; i < 16; ++i) {
		printf("%02x ", cipher_buf[i]); 
	}
	printf("\n");

	printf("Authentication tag: ");
	for (int i = 0; i < 16; ++i) {
		printf("%02x ", tag_buf[i]); 
	}
	printf("\n");

	printf("\n.....................Decryption...................\n");
        //decrypt_result = aes_gcm_decrypt(key1, sizeof(key1), iv1, sizeof(iv1), cipher_buf, sizeof(cipher_buf),
        //                aad1, sizeof(aad1), tag_buf, plain_buf);
        aes_gcm_decrypt(key1, sizeof(key1), iv1, sizeof(iv1), cipher_buf, sizeof(cipher_buf),                         aad1, sizeof(aad1), tag_buf, plain_buf);
    
	printf("plaintext decrypted: ");
	for (int i = 0; i < 16; ++i)
		printf("%02x ", plain_buf[i]);
	printf("\n");
	
	if (memcmp(pt1, plain_buf, sizeof(pt1)) == 0) {
            printf("Decryption successful! \n\n");
        } else {
            printf("FAILED!!! Plaintext does not match the original.\n\n");
        }
	
	
  
    return 0;
}
