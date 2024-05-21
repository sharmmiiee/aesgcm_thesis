
#include "aes.h"

#include <stdio.h>
#include <stdlib.h>
typedef unsigned char uchar;
typedef unsigned int  uint;

static int aes_tables_inited = 0;

static uint32_t FSb[256];
static uint32_t FT0[256];
static uint32_t FT1[256];
static uint32_t FT2[256];
static uint32_t FT3[256];


static uint32_t RCON[10];   // AES round constants
int sbox[256] =   {
	//0     1    2      3     4    5     6     7      8    9     A      B    C     D     E     F
	0x63, 0x7c, 0x77, 0x7b, 0xf2, 0x6b, 0x6f, 0xc5, 0x30, 0x01, 0x67, 0x2b, 0xfe, 0xd7, 0xab, 0x76, //0
	0xca, 0x82, 0xc9, 0x7d, 0xfa, 0x59, 0x47, 0xf0, 0xad, 0xd4, 0xa2, 0xaf, 0x9c, 0xa4, 0x72, 0xc0, //1
	0xb7, 0xfd, 0x93, 0x26, 0x36, 0x3f, 0xf7, 0xcc, 0x34, 0xa5, 0xe5, 0xf1, 0x71, 0xd8, 0x31, 0x15, //2
	0x04, 0xc7, 0x23, 0xc3, 0x18, 0x96, 0x05, 0x9a, 0x07, 0x12, 0x80, 0xe2, 0xeb, 0x27, 0xb2, 0x75, //3
	0x09, 0x83, 0x2c, 0x1a, 0x1b, 0x6e, 0x5a, 0xa0, 0x52, 0x3b, 0xd6, 0xb3, 0x29, 0xe3, 0x2f, 0x84, //4
	0x53, 0xd1, 0x00, 0xed, 0x20, 0xfc, 0xb1, 0x5b, 0x6a, 0xcb, 0xbe, 0x39, 0x4a, 0x4c, 0x58, 0xcf, //5
	0xd0, 0xef, 0xaa, 0xfb, 0x43, 0x4d, 0x33, 0x85, 0x45, 0xf9, 0x02, 0x7f, 0x50, 0x3c, 0x9f, 0xa8, //6
	0x51, 0xa3, 0x40, 0x8f, 0x92, 0x9d, 0x38, 0xf5, 0xbc, 0xb6, 0xda, 0x21, 0x10, 0xff, 0xf3, 0xd2, //7
	0xcd, 0x0c, 0x13, 0xec, 0x5f, 0x97, 0x44, 0x17, 0xc4, 0xa7, 0x7e, 0x3d, 0x64, 0x5d, 0x19, 0x73, //8
	0x60, 0x81, 0x4f, 0xdc, 0x22, 0x2a, 0x90, 0x88, 0x46, 0xee, 0xb8, 0x14, 0xde, 0x5e, 0x0b, 0xdb, //9
	0xe0, 0x32, 0x3a, 0x0a, 0x49, 0x06, 0x24, 0x5c, 0xc2, 0xd3, 0xac, 0x62, 0x91, 0x95, 0xe4, 0x79, //A
	0xe7, 0xc8, 0x37, 0x6d, 0x8d, 0xd5, 0x4e, 0xa9, 0x6c, 0x56, 0xf4, 0xea, 0x65, 0x7a, 0xae, 0x08, //B
	0xba, 0x78, 0x25, 0x2e, 0x1c, 0xa6, 0xb4, 0xc6, 0xe8, 0xdd, 0x74, 0x1f, 0x4b, 0xbd, 0x8b, 0x8a, //C
	0x70, 0x3e, 0xb5, 0x66, 0x48, 0x03, 0xf6, 0x0e, 0x61, 0x35, 0x57, 0xb9, 0x86, 0xc1, 0x1d, 0x9e, //D
	0xe1, 0xf8, 0x98, 0x11, 0x69, 0xd9, 0x8e, 0x94, 0x9b, 0x1e, 0x87, 0xe9, 0xce, 0x55, 0x28, 0xdf, //E
	0x8c, 0xa1, 0x89, 0x0d, 0xbf, 0xe6, 0x42, 0x68, 0x41, 0x99, 0x2d, 0x0f, 0xb0, 0x54, 0xbb, 0x16 }; //F

#define GET_UINT32_LE(n,b,i) {                  \
    (n) = ( (uint32_t) (b)[(i)    ]       )     \
        | ( (uint32_t) (b)[(i) + 1] <<  8 )     \
        | ( (uint32_t) (b)[(i) + 2] << 16 )     \
        | ( (uint32_t) (b)[(i) + 3] << 24 ); }

#define PUT_UINT32_LE(n,b,i) {                  \
    (b)[(i)    ] = (uchar) ( (n)       );       \
    (b)[(i) + 1] = (uchar) ( (n) >>  8 );       \
    (b)[(i) + 2] = (uchar) ( (n) >> 16 );       \
    (b)[(i) + 3] = (uchar) ( (n) >> 24 ); }

#define ROTL8(x) ( ( x << 8 ) & 0xFFFFFFFF ) | ( x >> 24 )		// circular left shit. shifts x 8 bits to the left then 24 bits to the right. | forms the rotated value
#define XTIME(x) ( ( x << 1 ) ^ ( ( x & 0x80 ) ? 0x1B : 0x00 ) )	// in GF(2^8) t\it multiplies x by 2. shift left and check if MSB is set

void aes_init_keygen_tables(void) {

    int i, x, y, z;
    
    if (aes_tables_inited) // If true, AES tables are initialized
        return;

    // Fill the 'pow' and 'log' tables over GF(2^8) - power and logarithm -------------------------------
    for (i = 0, x = 1; i < 256; i++) {
        //pow[i] = x;
        //log[x] = i;
        x = (x ^ XTIME(x)) & 0xFF;
    }

    // Compute the round constants -----------------------------------------------------------------------
    for (i = 0, x = 1; i < 10; i++) {
        RCON[i] = (uint32_t)x;
        x = XTIME(x) & 0xFF;
    }

    // Use the predefined S-box -------------------------------------------------------------------------
    for (i = 0; i < 256; i++) {
        FSb[i] = sbox[i]; // Use the predefined sbox values
    }

    // Generate the forward and reverse key expansion tables ---------------------------------------------
    for (i = 0; i < 256; i++) {
        x = FSb[i];
        y = XTIME(x) & 0xFF;
        z = (y ^ x) & 0xFF;

        FT0[i] = ((uint32_t)y) ^ ((uint32_t)x << 8) ^
                 ((uint32_t)x << 16) ^ ((uint32_t)z << 24);

        FT1[i] = ROTL8(FT0[i]);
        FT2[i] = ROTL8(FT1[i]);
        FT3[i] = ROTL8(FT2[i]);
    }
    aes_tables_inited = 1;  // Flag that the tables have been generated
}


int aes_key_expansion(uint32_t *RK, const uint8_t *key, uint keysize) {//before void
    uint i;

    for (i = 0; i < (keysize >> 2); i++) {
        GET_UINT32_LE(RK[i], key, i << 2);
    }

    for (i = 0; i < 10; i++, RK += 4) {
        RK[4] = RK[0] ^ RCON[i] ^
                ((uint32_t)FSb[(RK[3] >> 8) & 0xFF]) ^
                ((uint32_t)FSb[(RK[3] >> 16) & 0xFF] << 8) ^
                ((uint32_t)FSb[(RK[3] >> 24) & 0xFF] << 16) ^
                ((uint32_t)FSb[(RK[3]) & 0xFF] << 24);

        RK[5] = RK[1] ^ RK[4];
        RK[6] = RK[2] ^ RK[5];
        RK[7] = RK[3] ^ RK[6];
    }
	return 0; //added
}


uint32_t* aes_setkey(const uint8_t *key, const uint8_t keysize) {
	
    static uint32_t rk[AES_PRIV_SIZE / sizeof(uint32_t)];
    int res;
    aes_init_keygen_tables();
    res = aes_key_expansion(rk, key, keysize * 8);

    if (res < 0) {
        return NULL;
    }

    rk[AES_PRIV_NR_POS] = res;
    return rk;
}

// Substitute bytes using S-box
void SubBytes(uint8_t state[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            state[i][j] = FSb[state[i][j]];
        }
    }
}

// Shift rows in the state array
void ShiftRows(uint8_t state[4][4]) {
    // Perform row shifts (1 byte left for row 1, 2 bytes for row 2, 3 bytes for row 3)
    for (int i = 1; i < 4; i++) {
        for (int j = 0; j < i; j++) {
            uint8_t temp = state[i][0];
            for (int k = 0; k < 3; k++) {
                state[i][k] = state[i][k + 1];
            }
            state[i][3] = temp;
        }
    }
}

// Mix columns in the state array
void MixColumns(uint8_t state[4][4]) {
    for (int i = 0; i < 4; i++) {
        uint8_t a[4], b[4], h;
        for (int j = 0; j < 4; j++) {
            a[j] = state[j][i];
            h = (uint8_t)((signed char)state[j][i] >> 7);
            b[j] = state[j][i] << 1;
            b[j] ^= 0x1B & h;
        }
        state[0][i] = b[0] ^ a[1] ^ b[1] ^ a[2] ^ a[3];
        state[1][i] = a[0] ^ b[1] ^ a[2] ^ b[2] ^ a[3];
        state[2][i] = a[0] ^ a[1] ^ b[2] ^ a[3] ^ b[3];
        state[3][i] = a[0] ^ b[0] ^ a[1] ^ a[2] ^ b[3];
    }
}

// Add round key
void AddRoundKey(uint8_t state[4][4], uint32_t* RK) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            state[j][i] ^= (uint8_t)((RK[i] >> (j * 8)) & 0xFF);
        }
    }
}

int aes_cipher(void  *ctx, const uint8_t input[16], uint8_t output[16]) {
		
	uint32_t *RK = ctx;
	uint8_t state[4][4];

	// Copy input into the state
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			state[j][i] = input[i * 4 + j];
		}
	}
	
	// Initial round
	AddRoundKey(state, RK);
	// Main rounds
	for (int round = 1; round <10; round++) {
		SubBytes(state);
		ShiftRows(state);
		MixColumns(state);
		RK += 4; // Move to the next round key
		AddRoundKey(state, RK);
	}
		
	// Final round (without MixColumns)
	SubBytes(state);
	ShiftRows(state);

	RK += 4;
	AddRoundKey(state, RK);

	// Copy the state to output
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			output[i * 4 + j] = state[j][i];
		}
	}

	return 0;
}

