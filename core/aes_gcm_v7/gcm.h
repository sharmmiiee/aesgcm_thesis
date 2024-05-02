#ifndef GCM_HEADER
#define GCM_HEADER
#endif

#include <string.h>
#include <stdint.h>

int aes_gcm_encrypt(const unsigned char  *key, size_t key_len, const unsigned char  *iv, size_t iv_len,
	       const unsigned char  *plain, size_t plain_len,
	       const unsigned char  *aad_data, size_t aad_len, unsigned char  *cipher, unsigned char  *tag);

int aes_gcm_decrypt(const unsigned char  *key, size_t key_len, const unsigned char  *iv, size_t iv_len,
	       const unsigned char  *cipher, size_t cipher_len, const unsigned char  *aad_data, size_t aad_len, 
		   const unsigned char  *tag, unsigned char  *plain);
		   
void decrypt_cipher(void *aes, const unsigned char *counter, const unsigned char *cipher, size_t cipher_len, unsigned char *plain);


void generate_tag(void *aes, const unsigned char *counter, const unsigned char *hash_key,
                         const unsigned char *aad, size_t aad_len,
                         const unsigned char *crypt, size_t crypt_len,
                         unsigned char *tag);

void aes_gcm_ghash(const unsigned char  *H, const unsigned char  *aad, size_t aad_len,
			  const unsigned char  *crypt, size_t crypt_len, unsigned char  *S);
			  
void gcm_set_iv(const unsigned char  *iv, size_t iv_len, const unsigned char  *H, unsigned char  *counter);

void * initialize_hash(const unsigned char  *key, size_t key_len, unsigned char  *H);

void aes_gcm_ctr(void *aes, const unsigned char *counter, const unsigned char *plain, size_t plain_len, unsigned char *cipherout);

void ghash(const unsigned char  *hashKey, const unsigned char  *input ,size_t input_len, unsigned char  *y);
void gf_multiply(const unsigned char  *input, const unsigned char  *hashKey, unsigned char  *z);
void gf_mul_karatsuba( unsigned char  *x, const unsigned char  *y, unsigned char  *z);
void karatsuba_custinstr( unsigned char  *x, const unsigned char  *y, unsigned char  *z);
uint32_t reverse_input(uint32_t rs1, uint32_t rs2);
uint32_t extract_uint32(const unsigned char *x, int offset);
void reverseBits(uint32_t *z);
uint32_t mulHigh(uint32_t rs1, uint32_t rs2);
uint32_t mulLow(uint32_t rs1, uint32_t rs2);
void print_hex(const unsigned char *data, size_t len);
void shift_right_block(unsigned char  *v);
void xor_block(unsigned char *dst, const unsigned char *src);
void increment_counter(unsigned char  *block);

static inline void AES_PUT_BE32( unsigned char *a, unsigned int val)
{
	a[0] = (val >> 24) & 0xff;
	a[1] = (val >> 16) & 0xff;
	a[2] = (val >> 8) & 0xff;
	a[3] = val & 0xff;
}
