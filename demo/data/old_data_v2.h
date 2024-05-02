#include <stdint.h>

uint32_t IV[][3] = {
 { 0xb3d8cc01, 0x7cbb89b3, 0x9e0f67e2 },
 { 0xd407301c, 0xfa29af85, 0x25981c17 },
 { 0xc59868b8, 0x701fbf88, 0xe6343262 },
 { 0x281f2552, 0xf8c34fb9, 0xb3ec85aa },
 { 0xb15d6fcd, 0xe5e6cf1f, 0xa99ba145 },
 { 0xf89e1b7e, 0x598cc253, 0x5a5c8659 },
 { 0x3338343f, 0x9b97ebb7, 0x84e75027 },
 { 0x9549e4ba, 0x69a61cad, 0x7856efc1 },
 { 0x474ecccc, 0x3182e03c, 0x80a7be74 },
 { 0x8851ea68, 0xd20ce0be, 0xff1e3a98 },
 { 0xc3c1c307, 0x9cda49a7, 0x5a53b3cc },
 { 0xb401d0f5, 0x0880a621, 0x1fde9d9c },
 { 0x81ceb17d, 0xeee19b81, 0x53ff927c },
 { 0xbb923c93, 0xddca303a, 0xb131238d }, 
 { 0xa103db8a, 0x0825e606, 0xb70427fc }
 };

uint8_t PT[][16] = {
 { 0xc3, 0xb3, 0xc4, 0x1f, 0x11, 0x3a, 0x31, 0xb7, 0x3d, 0x9a, 0x5c, 0xd4, 0x32, 0x10, 0x30, 0x69 },
 { 0xa6, 0xc9, 0xe0, 0xf2, 0x48, 0xf0, 0x7a, 0x30, 0x46, 0xec, 0xe1, 0x21, 0x25, 0x66, 0x69, 0x21 },
 { 0x30, 0x18, 0x73, 0xbe, 0x69, 0xf0, 0x5a, 0x84, 0xf2, 0x24, 0x08, 0xaa, 0x08, 0x62, 0xd1, 0x9a },
 { 0xf8, 0x01, 0xe0, 0x83, 0x96, 0x19, 0xd2, 0xc1, 0x46, 0x5f, 0x02, 0x45, 0x86, 0x93, 0x60, 0xda },
 { 0x82, 0x2a, 0xe0, 0x1a, 0x03, 0x72, 0xb6, 0xaa, 0x46, 0xc2, 0xe5, 0xbf, 0x19, 0xdb, 0x92, 0xf2 },
 { 0xf4, 0xa5, 0x00, 0x3d, 0xb4, 0xa4, 0xeb, 0xbc, 0x2f, 0xdb, 0x8c, 0x67, 0x56, 0x83, 0x03, 0x91 },
 { 0x14, 0xd8, 0x0a, 0xd6, 0x6e, 0x8f, 0x5f, 0x2e, 0x6c, 0x43, 0xc3, 0x10, 0x9e, 0x02, 0x3a, 0x93 },
 { 0xd1, 0x44, 0x8f, 0xa8, 0x52, 0xb8, 0x44, 0x08, 0xe2, 0xda, 0xd8, 0x38, 0x1f, 0x36, 0x3d, 0xe7 },
 { 0xdc, 0x1c, 0x35, 0xbc, 0x78, 0xb9, 0x85, 0xf2, 0xd2, 0xb1, 0xa1, 0x3c, 0xe6, 0x35, 0xdd, 0x69 },
 { 0x2f, 0xec, 0x17, 0xb1, 0xa9, 0x57, 0x0f, 0x66, 0x51, 0xbb, 0xe9, 0xa6, 0x57, 0xd8, 0x2b, 0xce },
 { 0xbe, 0x42, 0x5e, 0x00, 0x8e, 0x9b, 0x0c, 0x08, 0x3b, 0x19, 0xa2, 0xd9, 0x45, 0xc2, 0xed, 0xe9 },
 { 0x47, 0xa8, 0x7a, 0x38, 0x79, 0x44, 0xf7, 0x39, 0xbd, 0x3c, 0xb0, 0x3e, 0x0e, 0x8b, 0xe4, 0x99 },
 { 0x82, 0x42, 0xc6, 0xc0, 0xee, 0xd6, 0xd5, 0xd1, 0xab, 0x69, 0xcd, 0x11, 0xdb, 0xe3, 0x61, 0xd0 },
 { 0x6b, 0x93, 0xd2, 0xd9, 0x2d, 0xe0, 0x5b, 0x53, 0x76, 0x9e, 0xc3, 0x98, 0xab, 0x80, 0x97, 0xdc }, 
 { 0xd1, 0x83, 0x44, 0xc8, 0x6c, 0xaf, 0xfc, 0x42, 0x37, 0xd2, 0xda, 0xae, 0x47, 0x81, 0x7b, 0x13 }
 };
//uint32_t PT[][4] = {
// { 0xc3b3c41f, 0x113a31b7, 0x3d9a5cd4, 0x32103069 },
// { 0xa6c9e0f2, 0x48f07a30, 0x46ece121, 0x25666921 },
// { 0x301873be, 0x69f05a84, 0xf22408aa, 0x0862d19a },
// { 0xf801e083, 0x9619d2c1, 0x465f0245, 0x869360da },
// { 0x822ae01a, 0x0372b6aa, 0x46c2e5bf, 0x19db92f2 },
// { 0xf4a5003d, 0xb4a4ebbc, 0x2fdb8c67, 0x56830391 },
// { 0x14d80ad6, 0x6e8f5f2e, 0x6c43c310, 0x9e023a93 },
// { 0xd1448fa8, 0x52b84408, 0xe2dad838, 0x1f363de7 },
// { 0xdc1c35bc, 0x78b985f2, 0xd2b1a13c, 0xe635dd69 },
// { 0x2fec17b1, 0xa9570f66, 0x51bbe9a6, 0x57d82bce },
// { 0xbe425e00, 0x8e9b0c08, 0x3b19a2d9, 0x45c2ede9 },
// { 0x47a87a38, 0x7944f739, 0xbd3cb03e, 0x0e8be499 },
// { 0x8242c6c0, 0xeed6d5d1, 0xab69cd11, 0xdbe361d0 },
// { 0x6b93d2d9, 0x2de05b53, 0x769ec398, 0xab8097dc }, 
// { 0xd18344c8, 0x6caffc42, 0x37d2daae, 0x47817b13 }
// };

uint32_t AAD[][4] = {
 { 0x24825602, 0xbd12a984, 0xe0092d3e, 0x448eda5f },
 { 0x10e72efe, 0x048648d4, 0x0139477a, 0x2016f8ce },
 { 0x67105634, 0xac9fbf84, 0x9970dc41, 0x6de7ad30 },
 { 0xbf12a140, 0xd86727f6, 0x7b860bcf, 0x6f34e55f },
 { 0x72e9cb26, 0x885154d4, 0x629e7bc9, 0x1279bb19 },
 { 0x70910598, 0xe7abd4f0, 0x503ecd9e, 0x21bdafb5 },
 { 0x8b12987e, 0x600ff58d, 0xf54f1f5e, 0x62e59e61 },
 { 0xe98e9d9c, 0x618e46fe, 0xf3266097, 0x6f854ee3 },
 { 0xa1bc98da, 0xcec4b6aa, 0x7fee6dfa, 0x0802f21a },
 { 0xece8d5f6, 0x3aebda80, 0xebde4b75, 0x0637f654 },
 { 0x714fa1d6, 0x904187b3, 0xc5c08a30, 0xdffc86e8 },
 { 0x592e7276, 0xbda06632, 0x7f2b3cd8, 0xcc39f571 },
 { 0x97e07cd6, 0x5065d1ed, 0xc863192d, 0xe98bc62c },
 { 0x0898ea55, 0xc0ca0594, 0x806e2dc7, 0x8be15c27 }, 
 { 0xc2d0d8b7, 0x7a6fd03c, 0xed080e0f, 0x89de8a4b }
 };

uint32_t Tag[][4] = {
 { 0x0032a1dc, 0x85f1c978, 0x6925a2e7, 0x1d8272dd },
 { 0xe2e9c07d, 0x4c3c10a6, 0x137ca433, 0xda42f9a8 },
 { 0x39152e26, 0xbdc4d17e, 0x8c00493f, 0xa0be92f2 },
 { 0xcc2b0b0f, 0x1f8b3db5, 0xdc1b41ce, 0x73f5c221 },
 { 0x2fa042bf, 0xf9a9cd35, 0xe343b520, 0x017841bb },
 { 0x243331b4, 0x8404859c, 0x66af4d7b, 0x2ee44109 },
 { 0x47d7e914, 0x4ff0ed4a, 0xa3300a94, 0x4a007882 },
 { 0xd72da7f5, 0xc6cf0bca, 0x7242c718, 0x35809449 },
 { 0xb9c2b319, 0xadbd743f, 0x5e4ffd44, 0x304a1b5f },
 { 0xeb996677, 0x4c588a31, 0xb71c4d8d, 0xaa495e9e },
 { 0xeaf9bda9, 0xb3322f50, 0x1f7329cb, 0x61c1c428 },
 { 0xc68d8d3c, 0xf8b89e6b, 0x15f623d6, 0x0fef60bd },
 { 0x29e4d7e0, 0x54a6b0a4, 0xe0113357, 0x3fbe632b },
 { 0x3a92f3c9, 0xe3ae6b0c, 0x69dcb886, 0x8d4de27c }, 
 { 0xfb367f47, 0x922d67c8, 0x4bf47aab, 0xb2b98421 }
 };

uint32_t Key[][4] = {
 { 0xc939cc13, 0x397c1d37, 0xde6ae0e1, 0xcb7c423c },
 { 0x599eb65e, 0x6b2a2a7f, 0xcc40e51c, 0x4f6e3257 },
 { 0x2d265491, 0x712fe6d7, 0x087a5545, 0x852f4f44 },
 { 0x1fd1e536, 0xa1c39c75, 0xfd583bc8, 0xe3372029 },
 { 0x7b0345f6, 0xdcf469ec, 0xf9b17efa, 0x39de5359 },
 { 0x9db91a40, 0x020cdb07, 0xf8876930, 0x9a6ac40b },
 { 0xe2f48398, 0x9b349efb, 0x59ae0a7c, 0xadc74b7a },
 { 0x5c115508, 0x4cc0ede7, 0x6b3bc22e, 0x9f7574ef },
 { 0x23525037, 0x40a4e1b2, 0x2dcc9c00, 0x2f53bd11 },
 { 0xfc1f971b, 0x514a1678, 0x65341b82, 0x8a4295d6 },
 { 0x00ef3c67, 0x62be3fba, 0xb38154d9, 0x02ff43b5 },
 { 0x2d70b956, 0x9943cc49, 0xcdef8495, 0xbdb6f0e6 },
 { 0x775cb7f8, 0xdc73f04f, 0xe4f9d221, 0x26bb7b57 },
 { 0x58ba3cb7, 0xc0a0cf57, 0x75002bf3, 0xb112d051 }, 
 { 0x955b761d, 0xe8e98f37, 0xacb41259, 0xfa308442 }
 };

//uint32_t CT[][4] = {
// { 0x93fe7d9e, 0x9bfd1034, 0x8a5606e5, 0xcafa7354 },
// { 0x1be9359a, 0x543fd7ec, 0x3c4bc6f3, 0xc9395e89 },
// { 0x98b03c77, 0xa67831bc, 0xf16b1dd9, 0x6c324e1c },
// { 0x35371f27, 0x79f4140d, 0xfdb1afe7, 0x9d563ed9 },
// { 0x382e4406, 0x94b0c93b, 0xe8dd438e, 0x37635194 },
// { 0x40d7fc4c, 0xcc814758, 0x1f40655a, 0x07f23ee9 },
// { 0x43c2d683, 0x84d486e9, 0x788950bb, 0xb8cd8fd1 },
// { 0xf78b60ca, 0x12521849, 0x3bea1c50, 0xa2e12ef4 },
// { 0x3f6f4daf, 0x6d07743b, 0x9bd2a069, 0xd3710834 },
// { 0x2d27e5fa, 0x08e218f0, 0x2b2e36df, 0xad87a50e },
// { 0xc961a175, 0x8dcf91e5, 0x39658372, 0xdb18968e },
// { 0xc1b2af4d, 0x273231e7, 0x1e7e066c, 0x206bf567 },
// { 0x580f063a, 0xb1a4801d, 0x279e4ee7, 0x73200abe },
// { 0xd0564006, 0xb1897bf2, 0x1922fef4, 0xf6386fd4 }, 
// { 0x065d228c, 0x1289007a, 0x682aa847, 0xa36b6f30 }
// };

uint8_t CT[][16] = {
 { 0x93, 0xfe, 0x7d, 0x9e, 0x9b, 0xfd, 0x10, 0x34, 0x8a, 0x56, 0x06, 0xe5, 0xca, 0xfa, 0x73, 0x54 },
 { 0x1b, 0xe9, 0x35, 0x9a, 0x54, 0x3f, 0xd7, 0xec, 0x3c, 0x4b, 0xc6, 0xf3, 0xc9, 0x39, 0x5e, 0x89 },
 { 0x98, 0xb0, 0x3c, 0x77, 0xa6, 0x78, 0x31, 0xbc, 0xf1, 0x6b, 0x1d, 0xd9, 0x6c, 0x32, 0x4e, 0x1c },
 { 0x35, 0x37, 0x1f, 0x27, 0x79, 0xf4, 0x14, 0x0d, 0xfd, 0xb1, 0xaf, 0xe7, 0x9d, 0x56, 0x3e, 0xd9 },
 { 0x38, 0x2e, 0x44, 0x06, 0x94, 0xb0, 0xc9, 0x3b, 0xe8, 0xdd, 0x43, 0x8e, 0x37, 0x63, 0x51, 0x94 },
 { 0x40, 0xd7, 0xfc, 0x4c, 0xcc, 0x81, 0x47, 0x58, 0x1f, 0x40, 0x65, 0x5a, 0x07, 0xf2, 0x3e, 0xe9 },
 { 0x43, 0xc2, 0xd6, 0x83, 0x84, 0xd4, 0x86, 0xe9, 0x78, 0x89, 0x50, 0xbb, 0xb8, 0xcd, 0x8f, 0xd1 },
 { 0xf7, 0x8b, 0x60, 0xca, 0x12, 0x52, 0x18, 0x49, 0x3b, 0xea, 0x1c, 0x50, 0xa2, 0xe1, 0x2e, 0xf4 },
 { 0x3f, 0x6f, 0x4d, 0xaf, 0x6d, 0x07, 0x74, 0x3b, 0x9b, 0xd2, 0xa0, 0x69, 0xd3, 0x71, 0x08, 0x34 },
 { 0x2d, 0x27, 0xe5, 0xfa, 0x08, 0xe2, 0x18, 0xf0, 0x2b, 0x2e, 0x36, 0xdf, 0xad, 0x87, 0xa5, 0x0e },
 { 0xc9, 0x61, 0xa1, 0x75, 0x8d, 0xcf, 0x91, 0xe5, 0x39, 0x65, 0x83, 0x72, 0xdb, 0x18, 0x96, 0x8e },
 { 0xc1, 0xb2, 0xaf, 0x4d, 0x27, 0x32, 0x31, 0xe7, 0x1e, 0x7e, 0x06, 0x6c, 0x20, 0x6b, 0xf5, 0x67 },
 { 0x58, 0x0f, 0x06, 0x3a, 0xb1, 0xa4, 0x80, 0x1d, 0x27, 0x9e, 0x4e, 0xe7, 0x73, 0x20, 0x0a, 0xbe },
 { 0xd0, 0x56, 0x40, 0x06, 0xb1, 0x89, 0x7b, 0xf2, 0x19, 0x22, 0xfe, 0xf4, 0xf6, 0x38, 0x6f, 0xd4 }, 
 { 0x06, 0x5d, 0x22, 0x8c, 0x12, 0x89, 0x00, 0x7a, 0x68, 0x2a, 0xa8, 0x47, 0xa3, 0x6b, 0x6f, 0x30 }
 };


// ----- End of b_var_concat.h, Start of d_len_concat.h -----

uint16_t AADlen[] = {
  128 ,
  128 ,
  128 ,
  128 ,
  128 ,
  128 ,
  128 ,
  128 ,
  128 ,
  128 ,
  128 ,
  128 ,
  128 , 
  128 
 };

uint16_t PTlen[] = {
  128 ,
  128 ,
  128 ,
  128 ,
  128 ,
  128 ,
  128 ,
  128 ,
  128 ,
  128 ,
  128 ,
  128 ,
  128 , 
  128 
 };

uint16_t Keylen[] = {
  128 ,
  128 ,
  128 ,
  128 ,
  128 ,
  128 ,
  128 ,
  128 ,
  128 ,
  128 ,
  128 ,
  128 ,
  128 , 
  128 
 };

uint16_t Taglen[] = {
  128 ,
  128 ,
  128 ,
  128 ,
  128 ,
  128 ,
  128 ,
  128 ,
  128 ,
  128 ,
  128 ,
  128 ,
  128 , 
  128 
 };

uint16_t IVlen[] = {
  96 ,
  96 ,
  96 ,
  96 ,
  96 ,
  96 ,
  96 ,
  96 ,
  96 ,
  96 ,
  96 ,
  96 ,
  96 , 
  96 
 };

// record type
uint16_t RecordType[] = {
  1 ,
  1 ,
  1 ,
  1 ,
  1 ,
  1 ,
  1 ,
  1 ,
  1 ,
  1 ,
  1 ,
  1 ,
  1 , 
  1 
 };