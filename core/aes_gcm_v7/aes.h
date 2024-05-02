// Author: Sharmine Catherine Reyes
// The author made alterations to this code which was originally sourced from a GitHub
// (https://github.com/mko-x/SharedAES-GCM/tree/master/Sources/gcm_test_vectors)
// The modifications made to ensure the compatibility with the Snitch core

#ifndef AES_HEADER
#define AES_HEADER

/******************************************************************************/
#define AES_DECRYPTION  0       // whether AES decryption is supported
/******************************************************************************/

#include <string.h>
#include <stdint.h>

#define ENCRYPT         1       // specify whether we're encrypting
#define DECRYPT         0       // or decrypting


#endif


//#define AES_PRIV_SIZE (4 * 4 * 15 + 4)
//#define AES_PRIV_NR_POS (4 * 15)
//#define AES_BLOCK_SIZE 16

#define AES_ROUND_KEYS 15
#define AES_BLOCK_SIZE 16

#define AES_PRIV_SIZE (4 * 4 * AES_ROUND_KEYS + 4)
#define AES_PRIV_NR_POS (4 * AES_ROUND_KEYS)
typedef unsigned int uint;

/******************************************************************************
 *  AES_INIT_KEYGEN_TABLES : MUST be called once before any AES use
 ******************************************************************************/

void aes_init_keygen_tables(void);

/******************************************************************************
 *  AES_CONTEXT : cipher context / holds inter-call data
 ******************************************************************************/

typedef struct {
    int mode;           // 1 for Encryption, 0 for Decryption
    int rounds;         // keysize-based rounds count
    uint32_t *rk;       // pointer to current round key
    uint32_t buf[68];   // key expansion buffer
} aes_context;
//aes_context  *nrk;;



///******************************************************************************
// *  AES_SETKEY : called to expand the key for encryption or decryption
// ******************************************************************************/
///*int aes_setkey( aes_context *ctx,       	// pointer to context
//                int mode,               	// 1 or 0 for Encrypt/Decrypt
//                uint keysize,       	// size in bytes (must be 16, 24, 32 for
//		                        	// 128, 192 or 256-bit keys respectively)
//                                        	// returns 0 for success
//                const uint8_t key[keysize]	// AES input key
//);
//
///******************************************************************************
// *  AES_CIPHER : called to encrypt or decrypt ONE 128-bit block of data
// ******************************************************************************/
///*int aes_cipher( aes_context *ctx,       // pointer to context
//                const uint8_t input[16],  // 128-bit block to en/decipher
//                uint8_t output[16] );     // 128-bit output result block
//                                        // returns 0 for success*/
										
										
uint32_t*  aes_setkey(const uint8_t *key, const uint8_t keysize);
int aes_cipher(void  *ctx, const uint8_t input[16], uint8_t output[16]) ;
	
int aes_gcm_ae(const unsigned char *key, size_t key_len,
                                      const unsigned char *iv, size_t iv_len,
                                      const unsigned char *plain, size_t plain_len,
                                      const unsigned char *aad, size_t aad_len,
                                      unsigned char *crypt, unsigned char *tag);
									  
int aes_key_expansion(uint32_t *RK, const uint8_t *key, uint keysize);
void SubBytes(uint8_t state[4][4]);
void ShiftRows(uint8_t state[4][4]);
void MixColumns(uint8_t state[4][4]);
void AddRoundKey(uint8_t state[4][4], uint32_t* RK);

//#endif /* AES_HEADER */

