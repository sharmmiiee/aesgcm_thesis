#include <string.h>
#include <stdint.h>

#define AES_ROUND_KEYS 15
#define AES_BLOCK_SIZE 16

#define AES_PRIV_SIZE (4 * 4 * AES_ROUND_KEYS + 4)
#define AES_PRIV_NR_POS (4 * AES_ROUND_KEYS)

typedef unsigned int uint;

void aes_init_keygen_tables(void);

										
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


