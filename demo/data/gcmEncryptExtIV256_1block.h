#include <stdint.h>

uint8_t Key[][32] = { 
{ 0xa5, 0x54, 0x51, 0x6e, 0x92, 0x50, 0x09, 0xdd, 0x85, 0x6f, 0x19, 0x22, 0x13, 0xe5, 0x37, 0x6b, 0xd0, 0x72, 0x07, 0x8a, 0xeb, 0x5d, 0x3a, 0xf9, 0x71, 0xb6, 0x8c, 0xc5, 0x7f, 0x8a, 0xa0, 0xbe },
{ 0x68, 0xde, 0x31, 0x11, 0x89, 0x44, 0xe0, 0x0d, 0x5a, 0x6f, 0xb0, 0x26, 0xa3, 0xeb, 0x24, 0xe1, 0x37, 0xe2, 0xe7, 0xf9, 0x35, 0x05, 0x14, 0x4c, 0x43, 0x1f, 0x34, 0x4e, 0x65, 0x66, 0x2c, 0xa3 },
{ 0x52, 0x77, 0x17, 0x70, 0x7d, 0x00, 0x4e, 0x82, 0x5b, 0xe5, 0xb2, 0x8e, 0xb2, 0xf2, 0xf6, 0x5c, 0x8b, 0xa2, 0xe4, 0x3c, 0x36, 0x5a, 0x4b, 0x05, 0xb5, 0xf0, 0x07, 0x58, 0x49, 0xe8, 0x22, 0x58 },
{ 0x36, 0xf6, 0x10, 0xb6, 0xf0, 0x8b, 0x02, 0x0f, 0x4d, 0x3c, 0xa0, 0xfa, 0xba, 0x58, 0x22, 0x22, 0x01, 0x6a, 0xa4, 0xae, 0x44, 0xc6, 0x19, 0xef, 0xc3, 0xaa, 0x8a, 0x3d, 0x79, 0x4c, 0x46, 0x78 },
{ 0x14, 0x64, 0x4d, 0xe3, 0xb6, 0xef, 0xc1, 0x21, 0x07, 0x79, 0x52, 0xf7, 0x6c, 0x3e, 0x76, 0xce, 0x84, 0x73, 0x06, 0xa3, 0x55, 0xe7, 0x34, 0xe0, 0x86, 0x9b, 0x51, 0x50, 0x6f, 0x6b, 0xd9, 0x79 },
{ 0xeb, 0x3f, 0xe1, 0xc8, 0xbb, 0x57, 0xd7, 0x2f, 0xea, 0x9f, 0x9e, 0x9c, 0xc3, 0xcc, 0x74, 0x6d, 0x41, 0x74, 0x27, 0x16, 0xdd, 0x3c, 0xbf, 0x57, 0x4e, 0xee, 0x95, 0x16, 0x2b, 0xd9, 0x3f, 0x9f },
{ 0x85, 0xee, 0x35, 0x4b, 0x46, 0x75, 0xa9, 0xc5, 0xd1, 0x6e, 0x3d, 0x6f, 0x41, 0x18, 0x04, 0x3b, 0xd9, 0x2f, 0x20, 0x9f, 0x01, 0x6f, 0x49, 0xef, 0xab, 0x7c, 0xe3, 0x02, 0x3b, 0x78, 0x11, 0x2e },
{ 0x6f, 0x79, 0xbf, 0x94, 0xda, 0x7d, 0xde, 0x3c, 0x86, 0x00, 0x99, 0x34, 0xd9, 0x25, 0x8f, 0x1b, 0x3f, 0xc2, 0xf5, 0x38, 0x2a, 0xca, 0x9c, 0x9c, 0xb8, 0xe2, 0x16, 0xee, 0xd2, 0x35, 0xf3, 0x4c },
{ 0x0c, 0x5a, 0xa8, 0xe0, 0xb1, 0x97, 0x91, 0x83, 0xb9, 0x97, 0xf2, 0x93, 0x62, 0xae, 0x83, 0x70, 0x0d, 0x3b, 0xa6, 0x19, 0x0a, 0x21, 0x0f, 0xc9, 0x05, 0x41, 0xb1, 0x7e, 0x45, 0xa4, 0x66, 0x68 },
{ 0xac, 0xe4, 0x9b, 0x23, 0xbe, 0xbd, 0xbb, 0x36, 0xca, 0xe2, 0x48, 0x09, 0xc6, 0x8c, 0xd4, 0x76, 0x3c, 0x00, 0x0c, 0x68, 0x9c, 0x77, 0xd2, 0x30, 0x25, 0x6f, 0x6e, 0x52, 0x06, 0xba, 0x17, 0x8c },
{ 0x69, 0xe0, 0x95, 0xa9, 0xae, 0x4c, 0xd6, 0x97, 0x86, 0x9b, 0x84, 0x5c, 0x4e, 0x84, 0x8b, 0x7f, 0xe1, 0x51, 0x1d, 0x1e, 0xe3, 0x34, 0xff, 0xa6, 0x3e, 0xa4, 0x27, 0xee, 0xe1, 0x8a, 0x6b, 0x54 },
{ 0x9c, 0x8e, 0x8c, 0x06, 0x38, 0xb7, 0x6c, 0x55, 0x2d, 0x1c, 0xe8, 0x00, 0x28, 0xb7, 0x07, 0x28, 0x6b, 0xf2, 0xa8, 0x45, 0x68, 0xd7, 0x02, 0x11, 0x79, 0xbe, 0x55, 0x70, 0x8e, 0x82, 0x0a, 0xdb },
{ 0xd7, 0x4e, 0xb3, 0xcf, 0xdd, 0x9f, 0xd9, 0xfe, 0x17, 0x64, 0x15, 0xe1, 0x97, 0x3a, 0x12, 0xf0, 0x11, 0x0e, 0xf5, 0x55, 0x68, 0x74, 0x6e, 0x99, 0xd0, 0x7d, 0x91, 0xb3, 0x39, 0xce, 0xe7, 0x9f },
{ 0xb5, 0xf8, 0x49, 0xda, 0x88, 0x7e, 0x3c, 0x18, 0x78, 0xb6, 0x77, 0x5a, 0xff, 0x7e, 0x49, 0xf5, 0xf3, 0x1e, 0xd8, 0xcd, 0xf9, 0xf7, 0x9e, 0xad, 0x5b, 0x36, 0x21, 0x9e, 0xea, 0x87, 0xaf, 0x80 },
{ 0xcd, 0x67, 0x0a, 0x8a, 0xc1, 0x09, 0xd0, 0xf0, 0xe4, 0x36, 0xee, 0x42, 0xe4, 0x90, 0xd5, 0x57, 0x6b, 0xb7, 0xc1, 0x32, 0x30, 0xf7, 0x27, 0xb1, 0x50, 0xb4, 0x73, 0xbd, 0xe6, 0x59, 0x82, 0x6d }
};

uint8_t IV[][128] = { 
{ 0x26, 0xeb, 0x2f, 0x8c, 0x2a, 0x9f, 0xe5, 0xce, 0x6a, 0xf9, 0x3b, 0xe6, 0x3c, 0xf3, 0xe6, 0x70, 0xc5, 0xf0, 0x20, 0x89, 0x33, 0x12, 0x73, 0x27, 0xec, 0x48, 0x69, 0x3e, 0x2e, 0xe3, 0x7e, 0x92, 0xa0, 0xaf, 0x1c, 0x68, 0x81, 0x02, 0xfd, 0x7b, 0x4b, 0xb6, 0x2b, 0xe1, 0xdd, 0xd5, 0xba, 0x0b, 0x8a, 0x6e, 0xd4, 0x71, 0x37, 0x98, 0x7a, 0xf7, 0x68, 0xf0, 0x07, 0x85, 0x7e, 0xdb, 0x2a, 0x74, 0x65, 0xac, 0x0c, 0xa7, 0xa7, 0x29, 0x84, 0x69, 0x66, 0xa4, 0x6d, 0x73, 0x24, 0x45, 0xc4, 0x52, 0x4d, 0x8c, 0xcd, 0x18, 0x23, 0x3e, 0x25, 0xe4, 0xea, 0x70, 0xcf, 0xb3, 0x1b, 0x03, 0xd2, 0xa5, 0x64, 0xf0, 0x94, 0x82, 0x47, 0x05, 0x8e, 0x2a, 0xc3, 0xf9, 0x63, 0xb8, 0x16, 0x31, 0x5f, 0x18, 0x3e, 0xfd, 0x80, 0xc7, 0x11, 0x7e, 0x93, 0xb4, 0xf8, 0x59, 0x2b, 0x49, 0x01, 0xeb, 0x6a, 0xa5 },
{ 0x86, 0x30, 0xc3, 0xe4, 0x0c, 0x11, 0xfe, 0x22, 0x85, 0x59, 0x22, 0x4b, 0x68, 0x25, 0x73, 0x83, 0x0f, 0xe2, 0x41, 0x9c, 0x59, 0x5a, 0xb0, 0x67, 0x51, 0xd9, 0x07, 0xde, 0x3d, 0xdb, 0xdb, 0x62, 0xba, 0x84, 0x24, 0xee, 0x8c, 0x02, 0x9d, 0x2c, 0x0a, 0xdb, 0xaf, 0xee, 0x79, 0x22, 0x3a, 0x80, 0xb8, 0x45, 0xcd, 0x36, 0x15, 0x51, 0x31, 0xce, 0x00, 0x4c, 0x4a, 0x93, 0x78, 0xd0, 0x3e, 0xc4, 0x94, 0x40, 0x5b, 0xd0, 0x53, 0x9c, 0x17, 0x0f, 0x6d, 0x41, 0xfc, 0x09, 0xc3, 0x29, 0x76, 0x07, 0x8f, 0x6a, 0x14, 0x3f, 0x7a, 0xcc, 0xd2, 0xe1, 0xab, 0xd9, 0xfc, 0x53, 0xa2, 0xec, 0x03, 0xc4, 0x69, 0xa7, 0x16, 0x53, 0xc3, 0x2e, 0xa9, 0x5f, 0x44, 0x1d, 0x09, 0xcc, 0x91, 0xe9, 0x04, 0x88, 0xb6, 0xc2, 0xe4, 0xaf, 0x49, 0x56, 0x59, 0xc9, 0x53, 0x13, 0x96, 0x71, 0x04, 0x08, 0xda, 0x0d },
{ 0x90, 0x0c, 0x4c, 0xed, 0xe8, 0x61, 0x4e, 0xfb, 0xc3, 0x47, 0xcc, 0xf4, 0x84, 0xa8, 0x1e, 0x35, 0x5d, 0xda, 0x1b, 0xf1, 0x17, 0x37, 0x75, 0xdc, 0xe5, 0x8e, 0x25, 0x2a, 0x68, 0xd4, 0x08, 0xa5, 0x5e, 0xb7, 0x77, 0xb5, 0x3c, 0xdc, 0xd4, 0x2f, 0x91, 0xe5, 0x97, 0x39, 0x95, 0x26, 0x2e, 0x4e, 0x3e, 0x2c, 0x77, 0x99, 0x70, 0x64, 0x95, 0x6a, 0x5c, 0x86, 0x2f, 0xd5, 0x08, 0x18, 0xc8, 0x3e, 0xc0, 0x29, 0x93, 0x5a, 0x2e, 0xce, 0xd9, 0x60, 0xe6, 0x36, 0x35, 0x93, 0xd0, 0x8f, 0xef, 0xc9, 0x66, 0x1b, 0x59, 0xd5, 0x4a, 0xfc, 0x1c, 0xb9, 0x11, 0xdd, 0x5e, 0x07, 0x1d, 0x0a, 0xab, 0xe5, 0x93, 0xfa, 0x9f, 0x39, 0xe9, 0x30, 0x00, 0x51, 0x28, 0xf3, 0xc1, 0xa1, 0x3a, 0xff, 0xee, 0x5c, 0x2e, 0x05, 0x67, 0x8b, 0x74, 0x5f, 0x28, 0xee, 0x56, 0xd4, 0x0a, 0x5d, 0x89, 0xd6, 0x52, 0x55 },
{ 0x84, 0x2b, 0x95, 0x7c, 0xa5, 0xf5, 0x6f, 0x3b, 0x36, 0x86, 0x26, 0x9f, 0x17, 0xf7, 0xe5, 0xb7, 0x12, 0x59, 0x3b, 0x8f, 0x37, 0xfd, 0x60, 0x79, 0x45, 0x99, 0x58, 0xe3, 0x1e, 0x07, 0x95, 0x5f, 0x1a, 0x18, 0x61, 0x20, 0x4e, 0x4c, 0x9e, 0x5a, 0x6b, 0x70, 0x20, 0x5a, 0x0f, 0x45, 0xa3, 0x32, 0x29, 0xb9, 0x48, 0x52, 0x4f, 0x71, 0x02, 0xdb, 0xaa, 0xf4, 0xe7, 0xa6, 0x69, 0x00, 0x00, 0x61, 0x68, 0xec, 0x0c, 0x99, 0xe7, 0x66, 0xfe, 0x89, 0xda, 0x8a, 0xe7, 0x2d, 0xcd, 0xa8, 0xe0, 0x71, 0xf4, 0xc2, 0xfe, 0x75, 0xce, 0x3c, 0xf9, 0x03, 0xdd, 0x7b, 0x53, 0xdd, 0xf5, 0xef, 0x95, 0xa8, 0x86, 0x63, 0xc3, 0x81, 0xaf, 0xea, 0x00, 0xab, 0xc5, 0xe6, 0xbe, 0x5c, 0x64, 0x77, 0xa9, 0xc5, 0x15, 0x23, 0x12, 0xcf, 0x54, 0xaf, 0x7b, 0x0c, 0x71, 0x8a, 0x59, 0x85, 0xe5, 0xe8, 0xc7, 0xec },
{ 0x84, 0xa4, 0x7e, 0x79, 0x9c, 0x51, 0xd8, 0x05, 0x2b, 0x27, 0x64, 0x43, 0x99, 0xa4, 0xb8, 0x07, 0x48, 0x7d, 0x64, 0xc0, 0x6e, 0xa0, 0x37, 0xb6, 0x2a, 0xf6, 0xa0, 0xb0, 0xd1, 0x21, 0x2f, 0x4a, 0xcf, 0xd1, 0xd0, 0x80, 0x51, 0x8c, 0x1a, 0x9f, 0xec, 0x5b, 0x2c, 0x8b, 0xa4, 0x69, 0x9a, 0xd7, 0xdf, 0x15, 0x57, 0x15, 0xcd, 0x04, 0x9f, 0x50, 0x85, 0xe8, 0x6c, 0x06, 0x01, 0xfa, 0xb7, 0x9e, 0xf1, 0x47, 0x2f, 0xbb, 0x35, 0x06, 0x5e, 0x7d, 0xfe, 0xe9, 0xe4, 0x07, 0x7e, 0x0e, 0x36, 0x5d, 0x18, 0x5f, 0x3c, 0x88, 0x56, 0x4a, 0xbf, 0x1f, 0xd1, 0xc3, 0xd3, 0xbf, 0x1a, 0x20, 0x9a, 0x5e, 0x24, 0xa2, 0xb0, 0x27, 0x89, 0x5e, 0xf1, 0x52, 0x4f, 0xe1, 0x99, 0xc3, 0x1a, 0x4b, 0xf6, 0x90, 0xea, 0x3c, 0xe2, 0x09, 0xcb, 0xb9, 0xff, 0xcb, 0xac, 0x4c, 0x06, 0x46, 0x1e, 0x01, 0x0f, 0xb9 }, 
{ 0x1e, 0xe1, 0xa2, 0xfe, 0x7d, 0xab, 0x97, 0x5f, 0xff, 0xd1, 0x92, 0x30, 0xd8, 0x08, 0x04, 0xb4, 0x56, 0x62, 0x85, 0x5c, 0x0a, 0x5b, 0xbd, 0x28, 0x02, 0xe4, 0x7b, 0x2d, 0x3f, 0xe5, 0x5b, 0x0c, 0x15, 0xe2, 0x38, 0x3e, 0x70, 0x70, 0x40, 0x4c, 0xe4, 0x66, 0x70, 0xc0, 0xa2, 0x84, 0x0a, 0x6e, 0x14, 0x94, 0x5c, 0x5b, 0xd9, 0xac, 0x52, 0x1b, 0xad, 0x8c, 0xa7, 0xef, 0xfd, 0x6d, 0xbe, 0x71, 0xf7, 0x4e, 0xca, 0x08, 0x2a, 0x49, 0x0d, 0x15, 0x08, 0x8d, 0x7b, 0xbf, 0xeb, 0x9c, 0xbb, 0x1e, 0x8e, 0xe8, 0x6d, 0x77, 0xb1, 0xdb, 0x35, 0xb4, 0x3a, 0x25, 0x9a, 0x14, 0xab, 0x6b, 0x77, 0x1a, 0xc5, 0x8c, 0xe3, 0x6b, 0xf9, 0x9d, 0x28, 0x41, 0x7a, 0x04, 0xd2, 0xd3, 0xff, 0x2d, 0x43, 0x80, 0xa6, 0xb2, 0x3c, 0xcd, 0x6e, 0x68, 0xb0, 0xae, 0x58, 0xa6, 0xfa, 0x54, 0xc9, 0x73, 0xb6, 0xa0 },
{ 0x5c, 0x3b, 0x5a, 0x95, 0x14, 0x78, 0x80, 0xf9, 0xd1, 0x43, 0x73, 0xbc, 0x38, 0x86, 0xe9, 0x20, 0x36, 0xa0, 0xab, 0xcb, 0x49, 0xfb, 0x67, 0x68, 0xe2, 0x81, 0x17, 0x61, 0xcf, 0xcd, 0xdb, 0xca, 0xc8, 0x13, 0xbe, 0xa9, 0x5a, 0x5b, 0x76, 0xfa, 0x1c, 0xe5, 0xfc, 0x72, 0x67, 0x08, 0xdd, 0xee, 0xe5, 0xd1, 0xa9, 0x19, 0x6d, 0x31, 0xeb, 0x1f, 0x0c, 0x1d, 0x49, 0x92, 0xba, 0x37, 0xa9, 0xc4, 0x17, 0x9d, 0x22, 0x3c, 0x46, 0x0f, 0xf2, 0xb5, 0x12, 0xa9, 0xd3, 0xcf, 0x35, 0x62, 0xc5, 0x86, 0xd7, 0x93, 0xef, 0xd9, 0x4a, 0x5e, 0x93, 0xd4, 0xb1, 0xe8, 0x6a, 0xe9, 0x6c, 0x3a, 0xa6, 0x71, 0x1a, 0x29, 0x1e, 0xc7, 0x10, 0xdf, 0xbd, 0x7e, 0xc4, 0x6b, 0x2e, 0xd4, 0xf4, 0x08, 0x5d, 0xf5, 0x11, 0xfa, 0xbc, 0xc5, 0xe4, 0x2b, 0xde, 0xd5, 0x21, 0x42, 0x53, 0xd2, 0x35, 0xf1, 0x2d, 0x14 },
{ 0x83, 0xe4, 0x13, 0xc8, 0xe6, 0xf7, 0x6b, 0x32, 0xae, 0xb2, 0x96, 0x0c, 0x11, 0xaa, 0x9e, 0x52, 0x2d, 0x39, 0x94, 0xe1, 0x4c, 0x18, 0x60, 0x9c, 0x63, 0x4c, 0x9c, 0xc1, 0xcf, 0x94, 0xf2, 0xc4, 0x9a, 0x53, 0x47, 0xd3, 0xf4, 0x40, 0x36, 0x7f, 0x08, 0xa3, 0x32, 0x2e, 0xb3, 0x56, 0x06, 0x75, 0xbc, 0x47, 0x15, 0xd0, 0x3a, 0xbb, 0xe0, 0xda, 0x4a, 0x75, 0x20, 0x87, 0x75, 0xe8, 0xbd, 0xc3, 0xff, 0x2d, 0x33, 0xda, 0xa3, 0x01, 0xf5, 0x3d, 0xd7, 0x5a, 0x83, 0xf7, 0x4c, 0x99, 0x82, 0x45, 0xc1, 0x82, 0x6a, 0xd4, 0x16, 0x02, 0xc3, 0xfe, 0xa3, 0x13, 0x09, 0x8d, 0x20, 0xa6, 0x5e, 0x41, 0x7e, 0x7c, 0x6f, 0xf9, 0x54, 0xd9, 0xc9, 0xb2, 0x45, 0x8a, 0x04, 0xab, 0x4d, 0xed, 0xdf, 0x07, 0xdd, 0x22, 0xbc, 0x40, 0x92, 0x11, 0xdb, 0xd1, 0x21, 0xf5, 0xa9, 0x52, 0x15, 0xd4, 0x00, 0x94 },
{ 0x96, 0xa1, 0xf2, 0x55, 0x92, 0x04, 0x78, 0x8f, 0x6b, 0xb0, 0xea, 0x50, 0xbd, 0x59, 0x86, 0x14, 0xa7, 0xce, 0x51, 0x8e, 0xc4, 0xda, 0xb9, 0x51, 0xe9, 0x51, 0x7b, 0xc4, 0x63, 0x57, 0x44, 0x8a, 0x6b, 0x4a, 0xed, 0x20, 0x0e, 0xe2, 0x1a, 0x75, 0x43, 0xfb, 0xff, 0x86, 0x1e, 0xd5, 0x63, 0x21, 0x19, 0x56, 0x75, 0xd9, 0x22, 0x5c, 0xac, 0x72, 0x54, 0x7d, 0x3e, 0x48, 0x80, 0xb9, 0x51, 0x76, 0x72, 0xb8, 0x62, 0x06, 0xe9, 0xac, 0xff, 0xba, 0x53, 0xd6, 0x65, 0x26, 0xe9, 0x19, 0x58, 0x7e, 0x7b, 0x28, 0x4a, 0x61, 0x2a, 0xec, 0x39, 0x15, 0x17, 0xe9, 0x07, 0xf2, 0xbf, 0x6a, 0x62, 0x5a, 0x99, 0x04, 0x66, 0xd6, 0x6c, 0xb1, 0x4c, 0x69, 0x0b, 0xe1, 0x7b, 0x7a, 0x22, 0x08, 0x5a, 0xb0, 0x32, 0xa0, 0x5d, 0xbc, 0x16, 0xa9, 0x94, 0x37, 0x67, 0x0c, 0xfa, 0x2b, 0xb8, 0xa2, 0x83, 0xd6 },
{ 0x34, 0xe8, 0x29, 0x79, 0x6c, 0x7d, 0x18, 0x6b, 0x3c, 0x83, 0xc8, 0x94, 0xb3, 0xf3, 0x6f, 0x3f, 0x07, 0xd6, 0x62, 0x61, 0x67, 0x0f, 0x4c, 0x1f, 0x74, 0xc8, 0x3b, 0x07, 0x4b, 0x2b, 0x7e, 0x5f, 0xab, 0xd8, 0x75, 0x6d, 0x2c, 0x96, 0x76, 0xbb, 0x52, 0xe9, 0xc7, 0xa6, 0x2c, 0x7c, 0x26, 0x37, 0x61, 0x28, 0xd1, 0xff, 0xda, 0x5f, 0x9a, 0xd5, 0xd7, 0xb4, 0x87, 0x24, 0xd4, 0x66, 0x72, 0xea, 0xbf, 0x83, 0xab, 0x9e, 0x6c, 0xd5, 0x96, 0x51, 0x0b, 0xd9, 0xab, 0x3b, 0xe8, 0x10, 0x89, 0xc4, 0x26, 0x2a, 0x9f, 0x8a, 0x88, 0x82, 0x0c, 0x6e, 0x27, 0xa4, 0x95, 0x93, 0xbf, 0x91, 0xb9, 0xdb, 0xc8, 0x84, 0xb4, 0x54, 0x8a, 0xa9, 0xec, 0x4b, 0xed, 0x9e, 0x1d, 0x5b, 0xe5, 0x7d, 0x41, 0x35, 0x53, 0x45, 0x9f, 0x5d, 0x8e, 0x7c, 0xbc, 0xa8, 0x4a, 0xc8, 0x9b, 0xab, 0xb4, 0x5f, 0x50, 0x1c },
{ 0x7a, 0xe6, 0x69, 0xa8, 0xb8, 0x1b, 0xbc, 0xc2, 0xb7, 0x27, 0x24, 0xa1, 0x41, 0x69, 0xf1, 0xe2, 0xe1, 0xc1, 0x14, 0xc0, 0xff, 0x3e, 0xf3, 0x34, 0x34, 0xa8, 0x2d, 0x36, 0x82, 0x72, 0x52, 0x53, 0x98, 0xae, 0x1a, 0x9a, 0xab, 0xb1, 0xc5, 0x0d, 0xde, 0xbf, 0xca, 0x5e, 0x85, 0x3d, 0xde, 0x04, 0xb4, 0x65, 0x18, 0xbc, 0x94, 0xb9, 0x1b, 0x51, 0x36, 0x4c, 0x82, 0x30, 0x10, 0x87, 0xca, 0x30, 0x85, 0x2e, 0xc7, 0xac, 0x52, 0xf5, 0x1e, 0xcd, 0xa1, 0xc2, 0xca, 0x2e, 0x09, 0x9c, 0x04, 0x09, 0x29, 0xf6, 0xd1, 0x23, 0x61, 0x57, 0x01, 0x1d, 0xdf, 0x7e, 0x92, 0x8d, 0xf7, 0xfb, 0x32, 0x9a, 0x01, 0x27, 0x52, 0xeb, 0x66, 0xcd, 0xb7, 0x25, 0xe4, 0x16, 0xe7, 0xa1, 0x01, 0x08, 0xb2, 0xbd, 0x4f, 0x67, 0x6b, 0x5a, 0xb8, 0x5b, 0x8f, 0x33, 0x43, 0x8c, 0x27, 0x3b, 0xdd, 0xb8, 0xcf, 0xfa },
{ 0xf4, 0x14, 0x37, 0x5e, 0xb3, 0xfa, 0xa8, 0x66, 0x34, 0x9e, 0xe5, 0xa6, 0xf1, 0x1d, 0xb1, 0x0b, 0x2d, 0x2b, 0x32, 0x71, 0x99, 0x06, 0xfb, 0x25, 0xf2, 0x2a, 0xc2, 0x05, 0x3e, 0x9f, 0x40, 0x2c, 0x4c, 0xf5, 0x45, 0xae, 0x97, 0x33, 0x36, 0xad, 0xa6, 0x16, 0xd9, 0x9f, 0xd5, 0x7e, 0x7b, 0x2f, 0xbb, 0x6b, 0xb8, 0xf1, 0x67, 0xfd, 0x90, 0x7e, 0xfb, 0xd9, 0x98, 0x35, 0x15, 0xd5, 0x09, 0xcb, 0xb6, 0x96, 0x67, 0x78, 0xbc, 0xcf, 0xde, 0xda, 0xcd, 0x9c, 0xb5, 0x8b, 0x0a, 0x8f, 0xbf, 0x0a, 0x39, 0x00, 0x12, 0x8f, 0x9f, 0x47, 0x31, 0x74, 0x85, 0xe2, 0xc8, 0xe3, 0x0a, 0x65, 0xf6, 0x8e, 0x43, 0xff, 0x8e, 0xd0, 0xb2, 0x0c, 0x83, 0x68, 0x1e, 0x75, 0x02, 0x14, 0xb8, 0xf0, 0x04, 0xf2, 0x52, 0x9f, 0x1f, 0x3f, 0xb0, 0x65, 0x54, 0xa4, 0x7f, 0xfb, 0x85, 0x32, 0xed, 0xec, 0xf9, 0x49 },
{ 0x06, 0xb5, 0xcc, 0x87, 0x1a, 0x93, 0xbf, 0x13, 0x72, 0x68, 0x36, 0x39, 0x2a, 0x7e, 0x13, 0x4f, 0x2b, 0x12, 0x2f, 0x22, 0x38, 0xb0, 0x86, 0xf1, 0x8e, 0xc8, 0x8f, 0x16, 0xd2, 0x1f, 0x19, 0x14, 0x55, 0x1a, 0x63, 0xa1, 0x69, 0xe9, 0x7c, 0x9d, 0xad, 0xab, 0xc9, 0xf4, 0x88, 0xbf, 0x54, 0xa7, 0x88, 0x3e, 0x61, 0x8e, 0x59, 0x47, 0x20, 0x41, 0xdd, 0x74, 0xad, 0x35, 0x6e, 0x7d, 0x92, 0xf8, 0x66, 0x6a, 0xf1, 0xb4, 0xb2, 0xcd, 0xb3, 0x5f, 0xb0, 0xd7, 0x22, 0xac, 0x0b, 0x31, 0xd2, 0xfd, 0x47, 0x50, 0x52, 0x50, 0x7e, 0xaf, 0xb9, 0x8d, 0x5c, 0x21, 0x09, 0xb5, 0xf1, 0x02, 0x54, 0x95, 0x7f, 0xc9, 0xb4, 0xc6, 0xdb, 0xfb, 0x3b, 0xf4, 0x69, 0x27, 0x71, 0xb4, 0xed, 0x30, 0x5d, 0x75, 0x21, 0xf5, 0x84, 0x2d, 0x1a, 0xea, 0xca, 0x0f, 0xfb, 0xab, 0x82, 0x47, 0xfc, 0x3b, 0x76, 0xbd },
{ 0x63, 0xf7, 0x5f, 0xd5, 0x5a, 0x8b, 0xf1, 0x9e, 0xad, 0xfa, 0x23, 0xeb, 0x7a, 0x3e, 0x5c, 0x8f, 0xd1, 0x3d, 0x79, 0xf6, 0xbb, 0x6b, 0xa4, 0x14, 0xd2, 0x02, 0x7f, 0xb0, 0x82, 0x83, 0xf5, 0x10, 0x8c, 0x11, 0xc2, 0xd4, 0x9d, 0xb5, 0x2f, 0x4c, 0x68, 0xc1, 0x11, 0x64, 0xc8, 0xa1, 0x58, 0x5b, 0xf1, 0x15, 0x51, 0x2c, 0xbe, 0x5f, 0x5a, 0xa4, 0x78, 0xc6, 0xc0, 0xe9, 0x18, 0x64, 0xf5, 0x19, 0x88, 0x62, 0xa6, 0x94, 0xf0, 0xc2, 0x47, 0x1a, 0xac, 0xd3, 0x2b, 0xa5, 0x7b, 0xe1, 0xa3, 0x3f, 0x04, 0xa5, 0x6f, 0xdc, 0x60, 0xa3, 0xdc, 0xdd, 0xe7, 0x3c, 0x77, 0x14, 0xc1, 0x0e, 0xb6, 0x7b, 0x74, 0x94, 0x33, 0xb1, 0xb3, 0x02, 0x7b, 0x3c, 0x4b, 0x4f, 0x29, 0xfc, 0x57, 0xc3, 0xea, 0xad, 0x9e, 0xef, 0xd0, 0x33, 0xdc, 0x4d, 0x42, 0xbc, 0x75, 0xb3, 0x6e, 0x74, 0x45, 0xa3, 0x83, 0xdb },
{ 0x71, 0x91, 0x91, 0xdb, 0x1d, 0xc5, 0xae, 0x92, 0xcf, 0x75, 0xcd, 0x8f, 0xf0, 0x2f, 0xf0, 0x36, 0xe7, 0x8d, 0x6b, 0xef, 0x59, 0x71, 0x4e, 0x5d, 0x40, 0xc2, 0x43, 0x01, 0x44, 0x39, 0x52, 0x14, 0x8c, 0x61, 0xab, 0x2e, 0x7e, 0x15, 0xd9, 0x5f, 0x8d, 0x17, 0x92, 0xee, 0x30, 0x7a, 0x27, 0xc0, 0x11, 0x2e, 0xc1, 0xb2, 0x8c, 0x4a, 0x04, 0x16, 0xf7, 0x62, 0x90, 0xb7, 0x7d, 0x89, 0x08, 0x85, 0x42, 0xd1, 0x36, 0x49, 0xd1, 0x7a, 0xf0, 0x9d, 0x6c, 0x53, 0x02, 0x43, 0x88, 0x95, 0x53, 0x4d, 0xed, 0xbb, 0x58, 0x7f, 0x54, 0x3c, 0x0d, 0x76, 0xb1, 0xe3, 0xe0, 0x65, 0xce, 0x6a, 0x26, 0x14, 0x73, 0xd2, 0x7d, 0xab, 0x6a, 0x92, 0x8a, 0xd1, 0xfc, 0x78, 0x63, 0x33, 0xda, 0xc5, 0x12, 0xf3, 0xb5, 0x21, 0x76, 0x0d, 0xd1, 0xf6, 0x79, 0x07, 0x29, 0x2d, 0x86, 0x84, 0x23, 0xa4, 0xf6, 0x4b }
};

uint8_t PT[][52] = { 
{ 0x94, 0x8a, 0xc5, 0xbf, 0x63, 0x9d, 0x55, 0xb4, 0xd9, 0xe4, 0x6a, 0x88, 0x46, 0xc6, 0x97, 0xe7, 0xd1, 0xb9, 0x45, 0x6b, 0x9c, 0x3f, 0x77, 0xc8, 0x91, 0xd5, 0xac, 0xa3, 0x23, 0xf1, 0x8a, 0xe7, 0x8f, 0xf8, 0x73, 0x6b, 0x81, 0x78, 0xf9, 0x1d, 0x7f, 0xce, 0x40, 0x41, 0x49, 0x5f, 0x61, 0x62, 0x89, 0xdb, 0x79 },
{ 0x98, 0x2d, 0x18, 0x54, 0x7f, 0x9f, 0xda, 0xf9, 0xd3, 0x68, 0x84, 0xdf, 0xa2, 0x07, 0x53, 0x6f, 0xd8, 0x27, 0x5e, 0x9f, 0x69, 0xcd, 0x98, 0xb5, 0xca, 0xd6, 0xae, 0x29, 0xbc, 0xe3, 0xdd, 0x25, 0x89, 0x1b, 0x55, 0x6b, 0x55, 0xcc, 0x25, 0xfb, 0xad, 0x40, 0x99, 0xa3, 0x05, 0xcd, 0xc8, 0x8f, 0xa3, 0x52, 0xfa },
{ 0x06, 0x32, 0x56, 0xfb, 0xc8, 0x79, 0x11, 0xdc, 0xac, 0x7e, 0x34, 0xea, 0x30, 0x1a, 0x2e, 0x32, 0xde, 0xaa, 0x86, 0x40, 0x24, 0x11, 0x4f, 0x9b, 0x59, 0xd0, 0x6b, 0x02, 0x1d, 0xf1, 0x93, 0x8d, 0xe9, 0xb4, 0x29, 0x00, 0x83, 0x43, 0x50, 0xb3, 0x8e, 0xb0, 0x88, 0x9b, 0xf0, 0x30, 0x4e, 0xa4, 0xf8, 0xa7, 0xc5 },
{ 0x78, 0xa7, 0xde, 0xed, 0x4e, 0xb6, 0x13, 0xcf, 0x2b, 0x3e, 0x57, 0x2a, 0x3f, 0xf4, 0x7e, 0x65, 0x51, 0xc7, 0x90, 0x8f, 0xde, 0xd8, 0x55, 0xfb, 0xa6, 0x42, 0x47, 0x49, 0x3a, 0x73, 0x60, 0x50, 0x5f, 0x1a, 0x08, 0xe7, 0xab, 0x85, 0x0d, 0x00, 0xd0, 0x2b, 0x97, 0x0e, 0x3a, 0x2b, 0x5d, 0xa9, 0xbb, 0x6c, 0x33 },
{ 0xed, 0x1a, 0x2a, 0xbb, 0xa7, 0xe7, 0x82, 0xa8, 0xf3, 0x62, 0x5f, 0x5a, 0xbc, 0xf6, 0x13, 0xcb, 0x3d, 0x35, 0x38, 0x37, 0xfb, 0x88, 0xed, 0xc5, 0xb1, 0x17, 0xfc, 0x35, 0xab, 0x55, 0x3e, 0x24, 0x4a, 0x60, 0xdd, 0x2e, 0xd6, 0x7a, 0xa6, 0xb8, 0xa9, 0x9a, 0xde, 0x1b, 0xab, 0x69, 0xcf, 0x04, 0x40, 0x59, 0x57 },
{ 0x0a, 0xce, 0x57, 0x63, 0x40, 0xe5, 0x24, 0x01, 0x98, 0x88, 0xcb, 0x49, 0x00, 0xfd, 0x9b, 0x52, 0xe5, 0x38, 0x2e, 0x4e, 0x36, 0xac, 0x9a, 0x96, 0x9c, 0x5f, 0x6b, 0xdd, 0xdf, 0xac, 0x12, 0xc2, 0xd9, 0x91, 0xea, 0x9e, 0x2e, 0xd5, 0xf6, 0x8d, 0xc4, 0xa5, 0x1d, 0x62, 0xda, 0xb8, 0x3d, 0xf8, 0xf8, 0x38, 0xaf },
{ 0x1b, 0x56, 0xde, 0x10, 0x1a, 0x75, 0xbb, 0x9d, 0x1a, 0x5e, 0x77, 0x59, 0x0b, 0xe3, 0x02, 0x83, 0x7d, 0x39, 0x21, 0x27, 0x8e, 0x48, 0x03, 0x47, 0x94, 0x4b, 0x92, 0x97, 0x5e, 0x81, 0x9e, 0x7a, 0x23, 0x33, 0x39, 0xf3, 0x1e, 0xcf, 0x02, 0xb8, 0x74, 0x84, 0x2f, 0xb5, 0xa1, 0x36, 0xc8, 0x10, 0xa9, 0xa9, 0xca },
{ 0x73, 0x85, 0x16, 0x82, 0x3e, 0x8f, 0x5d, 0x23, 0xf3, 0x18, 0x1b, 0x29, 0x7e, 0xb7, 0x0b, 0xe6, 0x33, 0xe3, 0xb0, 0xcd, 0xd6, 0x11, 0x17, 0x38, 0x4e, 0x47, 0x4e, 0x32, 0x23, 0x65, 0x81, 0x67, 0xad, 0x6a, 0xfd, 0x83, 0xd9, 0x83, 0x9b, 0xc9, 0x25, 0x87, 0x6e, 0x4e, 0x41, 0xa0, 0x01, 0xf6, 0x78, 0xa0, 0x6a }, 
{ 0xf4, 0x60, 0xe2, 0x8c, 0xb6, 0x7f, 0xb2, 0xb0, 0xaa, 0x53, 0x15, 0xc2, 0x5f, 0x81, 0x32, 0xe5, 0xa8, 0x29, 0x8a, 0xe3, 0x07, 0x7e, 0xe0, 0xbd, 0x91, 0x8f, 0xe1, 0xac, 0xd6, 0x31, 0x2a, 0x98, 0xa3, 0x41, 0x2a, 0x31, 0x98, 0xc8, 0x34, 0xbe, 0xb9, 0x32, 0x20, 0x02, 0x81, 0xfe, 0x61, 0x28, 0xa0, 0x8b, 0xe3 }, 
{ 0x9c, 0x85, 0xb9, 0xc4, 0x41, 0x03, 0x4e, 0x26, 0xc5, 0xeb, 0xf0, 0x45, 0x80, 0xcf, 0x61, 0x7e, 0xea, 0x19, 0xa0, 0x01, 0x09, 0x8c, 0x91, 0x0a, 0x7e, 0xac, 0x42, 0x3a, 0xf2, 0xf5, 0xfb, 0x2c, 0xee, 0x03, 0x35, 0xfd, 0xe1, 0xfe, 0x56, 0xbd, 0xfd, 0x31, 0xaf, 0x51, 0x3e, 0x99, 0xe9, 0x2d, 0x5a, 0xd7, 0xcd },
{ 0xb2, 0x72, 0x72, 0x22, 0x24, 0x6b, 0x94, 0x04, 0x48, 0xa2, 0x47, 0x41, 0x98, 0x4a, 0xb6, 0xaf, 0xe5, 0xe9, 0x47, 0x4e, 0x60, 0xcb, 0xb8, 0xce, 0x71, 0x41, 0x10, 0x39, 0x0f, 0x1c, 0x90, 0xb3, 0x3e, 0xd0, 0xec, 0x02, 0x67, 0xb8, 0x6c, 0xc3, 0x05, 0xb9, 0x80, 0x7e, 0x37, 0x0c, 0xa1, 0x46, 0xbd, 0x61, 0xc4 },
{ 0x8a, 0xf3, 0x04, 0xc8, 0xd9, 0xff, 0x79, 0x4d, 0x78, 0x4c, 0xca, 0x9b, 0xaf, 0xec, 0x22, 0x86, 0x8c, 0xf7, 0xcf, 0x5c, 0x03, 0x8b, 0x2a, 0xfa, 0x7c, 0xef, 0xbd, 0x84, 0xbe, 0x5d, 0x98, 0xb5, 0x0d, 0x30, 0x09, 0xba, 0xd9, 0xd6, 0x90, 0x83, 0xab, 0xf4, 0x7b, 0x50, 0x68, 0xd5, 0x94, 0x65, 0xc1, 0x03, 0x89 },
{ 0xd6, 0x54, 0xf5, 0x10, 0x80, 0x6c, 0x9e, 0xce, 0x9c, 0x12, 0xdc, 0x74, 0x9c, 0xb9, 0xa0, 0x84, 0x67, 0xca, 0xc2, 0xca, 0xd1, 0xaf, 0xcf, 0x3b, 0x4a, 0x41, 0xa2, 0xe0, 0x87, 0x3d, 0xea, 0x9b, 0xc0, 0xcf, 0x61, 0xb7, 0xaa, 0xc2, 0xeb, 0xba, 0x93, 0xeb, 0x46, 0xae, 0x6c, 0x5f, 0x11, 0x61, 0x0d, 0x0b, 0x41 },
{ 0xc1, 0xa2, 0x7f, 0x69, 0x33, 0x87, 0xa1, 0xc8, 0xf5, 0xfd, 0x1e, 0xed, 0x0c, 0x5c, 0xf3, 0x11, 0x18, 0x97, 0xdc, 0x87, 0x97, 0xb4, 0xe6, 0x3e, 0x89, 0xbc, 0xea, 0x06, 0xcb, 0x19, 0xb7, 0x34, 0xe3, 0x54, 0xd9, 0xf5, 0x39, 0xf5, 0xaf, 0x70, 0x06, 0x41, 0xf0, 0xf4, 0xac, 0xf9, 0x1a, 0xb5, 0x21, 0x47, 0xf0 },
{ 0xc9, 0x4e, 0xbe, 0xc7, 0xd8, 0xaa, 0x42, 0x1b, 0xfa, 0x9a, 0x02, 0x03, 0x52, 0x0e, 0x02, 0x57, 0x03, 0x38, 0xd1, 0x23, 0x59, 0xc5, 0xb1, 0x6d, 0x51, 0x05, 0x0c, 0xd3, 0xf8, 0x02, 0x35, 0x1b, 0x17, 0xca, 0xd8, 0x5b, 0x52, 0xea, 0x9b, 0x42, 0x14, 0x7f, 0x52, 0x8a, 0x25, 0xe5, 0x2c, 0x17, 0x0c, 0x63, 0x08 }
};

uint8_t AAD[][90] = { 
{ 0x7d, 0x2f, 0x9b, 0x88, 0x0a, 0xfb, 0xad, 0x74, 0x6b, 0xf5, 0x8c, 0x81, 0xe3, 0x1a, 0x8e, 0x8f, 0x88, 0x99, 0x9e, 0xb0, 0xc6, 0xc6, 0x30, 0xec, 0x35, 0xdb, 0x43, 0xf1, 0xe0, 0x95, 0x2f, 0xc7, 0xd9, 0xbc, 0x86, 0x15, 0x48, 0x32, 0xaf, 0xd1, 0x54, 0xbc, 0x49, 0xff, 0xe5, 0xe6, 0x7a, 0x1d, 0x14, 0x4b, 0x89, 0xb7, 0xe7, 0x4a, 0x36, 0xfd, 0xea, 0xc8, 0xe9, 0x5b, 0x8d, 0x9c, 0x3b, 0x22, 0x0e, 0xf7, 0x1f, 0x38, 0x61, 0x1e, 0xdc, 0x32, 0xac, 0x7d, 0x9c, 0x01, 0xa9, 0xbb, 0x3e, 0xc4, 0x8b, 0xc1, 0xaa, 0xf1, 0xdd, 0x79, 0x92, 0x17, 0x59, 0xb6 },
{ 0x17, 0x95, 0xec, 0x3d, 0x3a, 0x3f, 0xaf, 0x82, 0x34, 0xa8, 0x5f, 0x18, 0x69, 0xf8, 0xcb, 0x49, 0xce, 0x13, 0xc4, 0x01, 0xad, 0x64, 0x4a, 0x0a, 0x0a, 0x9c, 0xde, 0x86, 0xcb, 0xf9, 0x89, 0x05, 0x36, 0x8e, 0x03, 0x09, 0x74, 0xcd, 0xf0, 0xc8, 0x7f, 0x2f, 0xc4, 0x6b, 0x20, 0x90, 0x82, 0x5e, 0x25, 0x5f, 0x12, 0x30, 0xbc, 0xae, 0x7f, 0xd5, 0x86, 0xa4, 0x6f, 0x35, 0x0a, 0x63, 0x1a, 0x78, 0xc7, 0xdc, 0x64, 0x56, 0x44, 0x8c, 0xaa, 0x44, 0xd6, 0xcd, 0xca, 0xe1, 0x6d, 0xcf, 0x50, 0xdc, 0xfd, 0x6d, 0x6a, 0x1e, 0x7e, 0xad, 0xc6, 0xc2, 0xb2, 0x3e },
{ 0x0f, 0x14, 0xe3, 0x43, 0x9a, 0xdd, 0xd9, 0x86, 0x2d, 0x38, 0x4a, 0x8c, 0xcc, 0x9e, 0x55, 0x71, 0xbd, 0xbc, 0x68, 0x48, 0x62, 0x2f, 0x3e, 0xc2, 0x5a, 0xfe, 0x20, 0x77, 0xc5, 0x52, 0x8a, 0x00, 0x6d, 0x3f, 0x93, 0x39, 0xff, 0xb3, 0x40, 0x7e, 0x7a, 0x81, 0xe3, 0xb8, 0x39, 0x07, 0x04, 0x4d, 0xa5, 0x1b, 0x00, 0x3d, 0x98, 0xb9, 0x5d, 0x81, 0x4c, 0xd2, 0xde, 0xc2, 0x01, 0xfa, 0x00, 0x54, 0xfb, 0x2c, 0x2e, 0xb4, 0x7c, 0x99, 0xe0, 0x22, 0xd7, 0x3b, 0xde, 0xd3, 0xda, 0xac, 0x23, 0xd7, 0xc1, 0x8f, 0xbb, 0x28, 0x4e, 0x33, 0xfd, 0x0f, 0x40, 0x1f },
{ 0x6f, 0x91, 0xe2, 0x34, 0x94, 0x60, 0x16, 0x96, 0x84, 0x1f, 0xd9, 0xdc, 0x0a, 0x0e, 0x7f, 0xdc, 0xb6, 0xb3, 0x2a, 0xaa, 0xf2, 0xee, 0x7b, 0x84, 0x27, 0x0a, 0x59, 0xaa, 0xa2, 0xbb, 0x13, 0xb5, 0xbd, 0x19, 0x90, 0xa9, 0xfe, 0x3b, 0x05, 0x34, 0x75, 0x1f, 0x10, 0xc2, 0x05, 0x8d, 0xd3, 0xa5, 0x50, 0xfb, 0xab, 0x61, 0xbd, 0xb4, 0x52, 0x5f, 0xe6, 0xbd, 0x45, 0x32, 0x64, 0x19, 0xa4, 0x83, 0x39, 0x39, 0x8f, 0x31, 0x91, 0xe7, 0xdd, 0xb0, 0xd8, 0xf6, 0x5f, 0x4b, 0x00, 0xb4, 0xf5, 0xb6, 0xca, 0x4a, 0xba, 0x9e, 0x99, 0xed, 0xcd, 0x0a, 0xd0, 0x5f },
{ 0x7e, 0x22, 0x37, 0x58, 0xe2, 0x3e, 0x4b, 0xb9, 0x9e, 0xe7, 0x40, 0x60, 0x30, 0xa2, 0xdb, 0x69, 0x8d, 0x5e, 0x32, 0xc6, 0x9d, 0x5f, 0x19, 0x17, 0x0c, 0x05, 0x2b, 0xd5, 0x97, 0xbb, 0xfd, 0x4b, 0xbb, 0xdc, 0xeb, 0xbd, 0xcc, 0x80, 0x1b, 0x1b, 0xca, 0xd8, 0x69, 0xda, 0x19, 0x5a, 0x8c, 0x44, 0x52, 0xbe, 0xde, 0xc0, 0xfc, 0xd9, 0x1f, 0xed, 0xb6, 0xfa, 0x49, 0xc3, 0x8e, 0x18, 0x7e, 0x8b, 0x53, 0x6b, 0x69, 0xda, 0x68, 0x3c, 0xe4, 0xa3, 0x22, 0xb8, 0x1e, 0x70, 0xc9, 0x3e, 0xb6, 0x6c, 0x90, 0x10, 0xca, 0x3b, 0xe5, 0xd5, 0x42, 0x00, 0xd8, 0x7c },
{ 0x28, 0xd4, 0x02, 0xe6, 0xe8, 0xcc, 0xe2, 0x7e, 0x47, 0xa0, 0xeb, 0x03, 0xb5, 0x49, 0x79, 0x15, 0xc3, 0xb7, 0x13, 0x99, 0xfb, 0x95, 0xf4, 0xbc, 0x6d, 0x32, 0x55, 0xca, 0xd7, 0x35, 0x08, 0xee, 0xd4, 0x43, 0xcd, 0x44, 0xe5, 0x9c, 0xac, 0xf9, 0x17, 0x7d, 0xd3, 0xac, 0x1c, 0xdc, 0xa5, 0x23, 0x3b, 0xce, 0x39, 0x62, 0x12, 0x27, 0x95, 0x1d, 0x11, 0xf2, 0xa2, 0x01, 0x29, 0x30, 0x82, 0x2e, 0xe9, 0x29, 0xdc, 0x79, 0x1f, 0x3e, 0xaf, 0x1a, 0x97, 0xe2, 0x19, 0xdb, 0x04, 0xd6, 0xf1, 0x78, 0xb8, 0x04, 0xde, 0x60, 0x22, 0x4a, 0xb1, 0x20, 0xab, 0xdd },
{ 0xd2, 0xeb, 0x4e, 0x76, 0x0e, 0xd4, 0xfb, 0x68, 0x7b, 0x32, 0xc6, 0xbd, 0x07, 0x3b, 0xff, 0xaf, 0x96, 0x31, 0xed, 0x3a, 0xb8, 0x31, 0x01, 0xca, 0xb2, 0x36, 0x35, 0x2d, 0x02, 0x4c, 0xf4, 0x22, 0xb9, 0x17, 0xa7, 0x66, 0x0a, 0x48, 0x4b, 0xe2, 0x36, 0xe4, 0xd3, 0xb3, 0xfa, 0x33, 0x43, 0xd3, 0xf9, 0xe8, 0x7d, 0x86, 0xc5, 0x08, 0x34, 0xa2, 0x13, 0xb7, 0xca, 0x2a, 0x32, 0x12, 0xc2, 0x54, 0x56, 0x4e, 0x1c, 0x59, 0x55, 0x1c, 0x7b, 0xd3, 0xe0, 0x17, 0x10, 0xa7, 0xd8, 0xc8, 0x41, 0x93, 0x20, 0xa6, 0xd3, 0x36, 0x24, 0x89, 0xaa, 0x36, 0x84, 0x24 },
{ 0x02, 0xa5, 0x9b, 0x40, 0x4f, 0x7f, 0xce, 0xab, 0xc0, 0x6e, 0x09, 0x88, 0xbc, 0xbf, 0xbc, 0xa1, 0xd0, 0x8f, 0x75, 0xa8, 0x3f, 0x2c, 0xb9, 0x54, 0x2e, 0xdf, 0x10, 0x67, 0x02, 0xe2, 0xc9, 0x96, 0x4d, 0x7e, 0x37, 0xef, 0x86, 0xfb, 0x36, 0x8a, 0x98, 0x90, 0xa4, 0xf2, 0xae, 0x7f, 0x58, 0xf3, 0x36, 0xcb, 0x2d, 0xf9, 0x90, 0xcd, 0xaa, 0x27, 0x75, 0x95, 0x9c, 0x99, 0xcf, 0x1d, 0x11, 0xa5, 0x9a, 0xbe, 0x34, 0x8c, 0xc5, 0xa4, 0x7f, 0x98, 0xc4, 0x47, 0xe6, 0x50, 0x0b, 0x10, 0x13, 0xb3, 0x84, 0x18, 0x67, 0x7b, 0xd5, 0x82, 0xc5, 0xfb, 0xdc, 0xd8 },
{ 0x9c, 0x41, 0x0a, 0x60, 0x93, 0x1e, 0xf1, 0xcb, 0x5f, 0x6f, 0xa9, 0xc7, 0xda, 0x0a, 0x96, 0xca, 0x53, 0x7d, 0xaa, 0xc1, 0x74, 0xfd, 0x4f, 0x1b, 0xf2, 0x47, 0xde, 0x1e, 0x25, 0xd3, 0xdd, 0x44, 0xa3, 0x7f, 0x54, 0xd5, 0x8c, 0xa4, 0x8d, 0x1e, 0xcd, 0xcf, 0x2e, 0xbf, 0xf8, 0x95, 0x9c, 0x2d, 0xb0, 0xac, 0x82, 0x24, 0x4a, 0xc7, 0x62, 0x43, 0x40, 0x4a, 0xdf, 0x45, 0xbe, 0x72, 0xaf, 0xf4, 0xb1, 0x9b, 0xe0, 0x63, 0xc0, 0x88, 0xe1, 0x81, 0x0f, 0x9e, 0xb4, 0xb8, 0x94, 0xf4, 0x05, 0xc6, 0x16, 0x91, 0xe2, 0x78, 0x92, 0x97, 0xb1, 0x74, 0x30, 0xb8 },
{ 0x41, 0x95, 0x83, 0xe7, 0xbd, 0x2f, 0x69, 0x8d, 0xdb, 0xbd, 0xd4, 0x29, 0xa8, 0x16, 0x54, 0xc3, 0x7b, 0x07, 0xdd, 0x2d, 0x80, 0xf3, 0x4c, 0x9a, 0xc3, 0xd0, 0xf9, 0xef, 0x73, 0x29, 0xf3, 0x9f, 0xb5, 0xc2, 0x1d, 0xb5, 0x7b, 0xdd, 0x49, 0x6f, 0xd6, 0x90, 0x97, 0x73, 0x69, 0x89, 0xfd, 0x0f, 0x1d, 0x3c, 0x80, 0x3e, 0xbb, 0xff, 0x7d, 0x12, 0x8a, 0xc3, 0x18, 0x73, 0x75, 0x4f, 0x88, 0x12, 0x47, 0x89, 0x69, 0x07, 0x57, 0x4b, 0xce, 0xcf, 0xdf, 0x2e, 0xb3, 0xa5, 0xe6, 0x99, 0x60, 0x50, 0xea, 0xfd, 0x68, 0xf0, 0x40, 0x1d, 0x05, 0x43, 0xfd, 0x46 },
{ 0x74, 0xa1, 0x89, 0x90, 0x56, 0xc4, 0xef, 0x9d, 0x84, 0x8c, 0xd7, 0xc8, 0xd8, 0xca, 0x37, 0x7c, 0x68, 0x10, 0x91, 0x2c, 0x62, 0xe4, 0x28, 0xfe, 0x5a, 0xcb, 0x60, 0x90, 0x8a, 0xba, 0xe4, 0x8c, 0x88, 0x7e, 0x74, 0x60, 0x94, 0x3e, 0x9d, 0x67, 0x95, 0xfa, 0x62, 0x03, 0xb9, 0x94, 0xe0, 0x57, 0x99, 0xab, 0x8e, 0xdb, 0x55, 0xc2, 0x9f, 0xcd, 0xcc, 0xc3, 0xc4, 0x1b, 0x3b, 0x74, 0x34, 0x6f, 0x35, 0x4a, 0x21, 0x4d, 0x3a, 0xbf, 0x89, 0x1b, 0x80, 0x58, 0xe5, 0x54, 0x61, 0xd3, 0xf6, 0x8c, 0x3a, 0x28, 0x97, 0xbc, 0x51, 0x42, 0x12, 0xaa, 0xc9, 0x1d },
{ 0x91, 0x3b, 0x19, 0x1b, 0x12, 0x8e, 0x8d, 0x02, 0x1c, 0xa4, 0x6d, 0x29, 0x45, 0x5b, 0x80, 0x82, 0xe7, 0x01, 0x3e, 0xa4, 0x9e, 0x1c, 0x93, 0x1f, 0xe9, 0x4a, 0xdf, 0x3c, 0xfd, 0xe2, 0x67, 0x85, 0xad, 0x9e, 0x98, 0x28, 0xeb, 0x48, 0xbd, 0xda, 0x06, 0x6e, 0xb5, 0x30, 0xc5, 0xaf, 0x62, 0x48, 0x1e, 0xca, 0x44, 0x01, 0xfe, 0x31, 0xeb, 0x32, 0x0f, 0x6c, 0x52, 0x01, 0x1d, 0xb3, 0x8f, 0x98, 0x14, 0x4a, 0x0e, 0xa5, 0xf9, 0xfa, 0x6d, 0x5c, 0x37, 0x3c, 0x76, 0xee, 0xad, 0x28, 0x7e, 0x67, 0xe8, 0x3f, 0x9d, 0xde, 0x0f, 0x2e, 0x27, 0xa6, 0xc4, 0x0e },
{ 0x98, 0x55, 0xa0, 0x5c, 0x20, 0xbe, 0x9b, 0x24, 0x16, 0xfa, 0x00, 0x32, 0xd9, 0x4d, 0xb4, 0x28, 0xc9, 0x49, 0xe6, 0x82, 0x62, 0xf8, 0xa0, 0x84, 0xce, 0x37, 0x62, 0xf8, 0x5c, 0x3e, 0xdb, 0xe6, 0x17, 0x5e, 0xf4, 0x82, 0x79, 0x14, 0x18, 0x22, 0xc1, 0x01, 0x92, 0x9a, 0xec, 0xf3, 0x6e, 0x8a, 0x68, 0xe8, 0xfe, 0xc8, 0x52, 0x49, 0x45, 0xde, 0xbb, 0x54, 0xe0, 0x46, 0xb3, 0xc7, 0x1a, 0x44, 0x63, 0x0e, 0x56, 0x9e, 0xc8, 0x49, 0x69, 0x1c, 0x7f, 0x0f, 0x9a, 0x74, 0xe3, 0x74, 0xd2, 0x77, 0x32, 0xdf, 0x33, 0x57, 0x8c, 0x5b, 0xde, 0x49, 0x29, 0x07 },
{ 0x6d, 0xc7, 0x8b, 0x3a, 0x5e, 0xa4, 0x09, 0x83, 0x8b, 0x53, 0x3e, 0xbd, 0x77, 0xcf, 0x1d, 0x1b, 0x48, 0x08, 0xfe, 0xf1, 0x31, 0x27, 0x5a, 0x0d, 0x4d, 0xcd, 0x94, 0xca, 0x0f, 0x55, 0xb9, 0xdd, 0x86, 0x01, 0x7b, 0xd6, 0x64, 0xe0, 0x36, 0xc2, 0xfa, 0x75, 0x6c, 0x65, 0xa7, 0xa7, 0xd2, 0x46, 0x22, 0x99, 0x00, 0xfa, 0x46, 0x83, 0x49, 0xeb, 0x2d, 0xe1, 0x8b, 0x5b, 0xf1, 0xaf, 0x0f, 0x7d, 0xa5, 0x6e, 0xd0, 0x37, 0x7a, 0x65, 0xf5, 0xe6, 0x50, 0xdd, 0xf0, 0x81, 0xc4, 0xa2, 0x9e, 0xb9, 0x85, 0x45, 0x6b, 0x27, 0x6b, 0x4d, 0x30, 0x3b, 0x78, 0x32 },
{ 0xab, 0xdf, 0x81, 0x7a, 0x7f, 0xf3, 0xf2, 0x8b, 0xd0, 0xb5, 0xef, 0x0c, 0x2e, 0xc0, 0x2c, 0xcd, 0xe1, 0x79, 0x9d, 0x4d, 0xea, 0x80, 0x65, 0x80, 0x94, 0x1f, 0x63, 0xb7, 0x84, 0x0b, 0x2d, 0xee, 0xdd, 0x38, 0x73, 0xad, 0x1c, 0x31, 0x86, 0xee, 0x3c, 0x6b, 0x6f, 0xa9, 0x50, 0x62, 0xfc, 0xb5, 0x6e, 0x33, 0xc6, 0x73, 0x75, 0x32, 0xe7, 0xc3, 0x26, 0xe1, 0x16, 0xf2, 0xda, 0x4c, 0xc9, 0x20, 0xc8, 0xbb, 0x35, 0x4e, 0x8d, 0x2e, 0x27, 0xc1, 0x92, 0x09, 0x62, 0xe1, 0x6a, 0x4c, 0x89, 0x52, 0x1c, 0x4e, 0x16, 0x99, 0xf2, 0x14, 0x5f, 0x74, 0x2d, 0x36 }
};

uint8_t CT[][51] = { 
{ 0xc3, 0x66, 0x14, 0x6d, 0xe8, 0xb5, 0x8d, 0x3c, 0xce, 0x00, 0x4c, 0x62, 0xa6, 0x0b, 0x24, 0xbc, 0xa3, 0x81, 0x4d, 0x3d, 0x11, 0xde, 0xd7, 0x6b, 0xb9, 0xf7, 0xd4, 0x7c, 0x41, 0x19, 0x1b, 0x7e, 0x3a, 0x74, 0x44, 0x70, 0x0b, 0xd9, 0x3f, 0xef, 0xdf, 0x54, 0x25, 0x2c, 0xb7, 0xcf, 0x60, 0x41, 0x03, 0x8c, 0xa8 },
{ 0x7e, 0x5d, 0x78, 0x0e, 0xe1, 0x12, 0xb2, 0x44, 0xb1, 0xe9, 0xa4, 0x36, 0x7c, 0xff, 0x3f, 0xd5, 0x2e, 0x14, 0x12, 0x26, 0x37, 0x9b, 0x5f, 0x88, 0xb9, 0xe2, 0x48, 0x46, 0x26, 0x59, 0xd6, 0x1b, 0x25, 0xe6, 0xe0, 0xa8, 0x66, 0x72, 0x1c, 0xa5, 0xd5, 0xb5, 0x01, 0xe4, 0x5f, 0x45, 0x55, 0x0d, 0x93, 0xbe, 0x85 }, 
{ 0x7e, 0x87, 0xca, 0x2e, 0x3a, 0xea, 0xf2, 0x0b, 0xbb, 0xcc, 0x5e, 0x43, 0x18, 0x1b, 0x4f, 0xcd, 0x01, 0x1b, 0x7a, 0x66, 0xac, 0x4f, 0x2c, 0xd8, 0xa7, 0x1f, 0x0f, 0xb0, 0x78, 0x32, 0x34, 0x49, 0xc5, 0xbd, 0x4e, 0x3c, 0xac, 0x84, 0x22, 0x31, 0x8b, 0x06, 0xb4, 0x4c, 0x49, 0xcc, 0xb7, 0x01, 0xd6, 0x98, 0x31 },
{ 0xaa, 0xb4, 0x8f, 0x55, 0x10, 0xad, 0x84, 0x5e, 0xbe, 0x79, 0xe7, 0x68, 0x9d, 0xbf, 0x7f, 0xfb, 0x1d, 0xc3, 0xc6, 0xa8, 0x10, 0xc1, 0xb7, 0x54, 0x57, 0x65, 0x76, 0x67, 0x5e, 0x77, 0xfa, 0x81, 0xea, 0xce, 0x78, 0x82, 0x04, 0x52, 0x20, 0xba, 0xde, 0xd9, 0x0a, 0xc0, 0x98, 0xc6, 0xc6, 0x5f, 0x26, 0x61, 0x3d },
{ 0x80, 0xb8, 0xc3, 0x82, 0x9d, 0x99, 0x1e, 0x5b, 0x13, 0x31, 0xcf, 0x22, 0x9d, 0x74, 0x48, 0x98, 0x8e, 0xd6, 0x27, 0x1e, 0xfc, 0xcf, 0xe8, 0x49, 0x98, 0xac, 0xc6, 0x7e, 0x92, 0x4c, 0x73, 0x36, 0x23, 0x37, 0xda, 0x0d, 0x69, 0x7f, 0x4b, 0x46, 0x13, 0xd0, 0x6a, 0x88, 0xbb, 0x4a, 0xe8, 0xfa, 0x81, 0xc2, 0xcb },
{ 0x50, 0x09, 0x66, 0x32, 0xdf, 0x34, 0xa1, 0xf2, 0xd8, 0x84, 0x83, 0x04, 0xe2, 0x00, 0x60, 0xd9, 0x99, 0xa5, 0xb1, 0xed, 0xa1, 0x93, 0x27, 0x74, 0xe3, 0x0f, 0x36, 0x02, 0x6d, 0xa8, 0xc6, 0xc0, 0xba, 0xca, 0x7f, 0x6e, 0x59, 0xa7, 0xc7, 0x40, 0x18, 0xc5, 0xf5, 0x10, 0x75, 0x00, 0x8b, 0x74, 0x42, 0x4b, 0xd2 },
{ 0x67, 0xde, 0xc6, 0x58, 0xa8, 0x44, 0x68, 0xcb, 0x86, 0x26, 0x80, 0x99, 0xe0, 0x3c, 0xe7, 0x01, 0xe9, 0x93, 0x6c, 0x27, 0xb5, 0x00, 0x59, 0xb5, 0xc9, 0xe8, 0x74, 0x3d, 0xf7, 0xdf, 0x5b, 0x82, 0x83, 0x64, 0xab, 0x70, 0x25, 0xf8, 0x54, 0xcb, 0x9e, 0x3c, 0xfb, 0x27, 0xca, 0x5b, 0x71, 0x75, 0x02, 0xb8, 0x38 },
{ 0x18, 0x3c, 0xc6, 0x3f, 0x53, 0x7b, 0x30, 0x1e, 0x92, 0x8a, 0x1e, 0xfa, 0x21, 0x18, 0x18, 0xa1, 0x28, 0x96, 0x4e, 0x5d, 0x02, 0x5c, 0x7d, 0xde, 0x9c, 0xcd, 0x69, 0xe6, 0xa8, 0xdd, 0xdc, 0x2b, 0x98, 0x24, 0x52, 0x0e, 0x31, 0xd5, 0x2c, 0xde, 0x50, 0x60, 0x62, 0xd2, 0x25, 0x40, 0x75, 0x20, 0xa0, 0x01, 0x55 },
{ 0x3e, 0x12, 0xc2, 0xa1, 0x7c, 0xad, 0x65, 0x07, 0x70, 0x73, 0x38, 0x5c, 0x05, 0x50, 0x54, 0xbc, 0x8f, 0x72, 0xf1, 0xbe, 0xca, 0x59, 0xb0, 0x63, 0x63, 0x84, 0xd0, 0x27, 0xdc, 0x13, 0x50, 0xd3, 0x9a, 0x8f, 0x3c, 0x77, 0xf5, 0xbc, 0x26, 0xeb, 0x91, 0x62, 0x87, 0xdd, 0x74, 0x2b, 0xcd, 0x3a, 0x81, 0x92, 0x99 },
{ 0x91, 0x41, 0xc9, 0x22, 0xcb, 0x59, 0x8a, 0xe9, 0xdd, 0x3a, 0xef, 0xd9, 0x59, 0x3e, 0x27, 0x88, 0x87, 0x0e, 0x9a, 0xc5, 0x46, 0xfb, 0x3f, 0xbf, 0x5b, 0xa0, 0xbd, 0x14, 0x79, 0x21, 0x67, 0x43, 0xcb, 0x60, 0x3c, 0x4c, 0xc2, 0xfa, 0xd0, 0x30, 0x79, 0x6f, 0x9c, 0xdb, 0x5b, 0x32, 0x5e, 0xe4, 0xc3, 0x3d, 0x8a },
{ 0xdd, 0xea, 0xac, 0x80, 0xcb, 0x1d, 0xb0, 0x67, 0xd4, 0x01, 0x43, 0xa3, 0x82, 0xee, 0xdb, 0x21, 0x83, 0x80, 0x91, 0x53, 0xdb, 0x5b, 0x23, 0x52, 0x8c, 0x47, 0x6a, 0xe2, 0x5c, 0x9d, 0xb5, 0xd2, 0x8d, 0x53, 0xdb, 0xab, 0x6f, 0x59, 0xac, 0x5c, 0x01, 0x61, 0x50, 0xf8, 0x38, 0x4f, 0x5b, 0x84, 0x76, 0x71, 0x89 },
{ 0x63, 0xa8, 0xf8, 0xe0, 0x18, 0x3e, 0x5c, 0x30, 0x53, 0x2d, 0xd6, 0xd5, 0x23, 0x5d, 0x64, 0x18, 0x82, 0x82, 0x43, 0xe4, 0xef, 0x9a, 0xab, 0x82, 0xad, 0x53, 0x7e, 0x20, 0xfa, 0x11, 0xfe, 0x18, 0x8d, 0x44, 0x0a, 0x7f, 0xd5, 0xa5, 0x36, 0x69, 0x42, 0x2c, 0x65, 0xfe, 0xd9, 0x8a, 0x00, 0xe4, 0x63, 0x1f, 0x44 },
{ 0xaf, 0x6f, 0x67, 0x76, 0x9f, 0x0f, 0x09, 0x9e, 0x65, 0x90, 0xe9, 0x7d, 0xc6, 0xd6, 0x05, 0xde, 0xa9, 0x86, 0x77, 0x2a, 0x68, 0x96, 0x64, 0x08, 0xe8, 0x1d, 0x49, 0xb1, 0xe8, 0xd2, 0x4f, 0xd8, 0x35, 0xda, 0xed, 0x0d, 0x4b, 0xda, 0x04, 0x8c, 0x47, 0xd5, 0xef, 0x87, 0xf2, 0x27, 0x52, 0xe9, 0x9e, 0x14, 0x46 },
{ 0x83, 0x7a, 0xff, 0x99, 0xc3, 0x2f, 0x66, 0x58, 0x41, 0x23, 0x9e, 0x08, 0x97, 0x13, 0x44, 0x61, 0xfc, 0x3e, 0x8f, 0xaa, 0x8f, 0x99, 0x65, 0xec, 0xa5, 0xda, 0xe6, 0x7b, 0x29, 0x34, 0xe0, 0x81, 0x6f, 0x39, 0xd3, 0x6c, 0x45, 0xef, 0x8a, 0x0b, 0x80, 0x66, 0xae, 0x4f, 0x97, 0x52, 0xe6, 0x5e, 0xf3, 0xa6, 0xd9 },
{ 0x28, 0x6b, 0x59, 0x4c, 0xf9, 0xa9, 0x2b, 0x2d, 0x73, 0x48, 0xf0, 0xc7, 0x56, 0x19, 0xe1, 0x49, 0x16, 0xf2, 0xca, 0xfb, 0x99, 0x0c, 0xc2, 0xd6, 0xaa, 0x07, 0x16, 0x2d, 0x07, 0x03, 0xa9, 0xf7, 0x59, 0x1e, 0x40, 0xea, 0xe4, 0x02, 0xed, 0xfc, 0x64, 0xca, 0xfb, 0xed, 0xfc, 0x7e, 0xc2, 0x14, 0x7a, 0xcd, 0x51 }
};

uint8_t Tag[][4] = { 
{ 0x50, 0x16, 0xd9, 0x2a },
{ 0xfc, 0xe7, 0x67, 0x0e },
{ 0x73, 0x47, 0x16, 0x6e },
{ 0xb2, 0x1b, 0xcc, 0xec },
{ 0x38, 0xb5, 0x99, 0x16 },
{ 0x7d, 0x9d, 0x24, 0x17 },
{ 0x65, 0xa1, 0xbf, 0xa1 },
{ 0xbb, 0x1d, 0xf6, 0x8d },
{ 0x15, 0x4a, 0x3b, 0x39 },
{ 0x35, 0x6f, 0xdb, 0x25 },
{ 0x09, 0x36, 0xe1, 0xff },
{ 0x33, 0x49, 0x1c, 0xd4 },
{ 0xd4, 0x49, 0xde, 0xc7 },
{ 0x94, 0xb7, 0x3b, 0xcf },
{ 0x22, 0xd3, 0xec, 0x0f } 
};

// ----- End of b_var_concat.h, Start of d_len_concat.h -----

uint16_t Taglen[] = {
 32 ,
 32 ,
 32 ,
 32 ,
 32 ,
 32 ,
 32 ,
 32 ,
 32 ,
 32 ,
 32 ,
 32 ,
 32 ,
 32 , 
 32 
 };

uint16_t IVlen[] = {
 1024 ,
 1024 ,
 1024 ,
 1024 ,
 1024 ,
 1024 ,
 1024 ,
 1024 ,
 1024 ,
 1024 ,
 1024 ,
 1024 ,
 1024 ,
 1024 , 
 1024 
 };

uint16_t PTlen[] = {
 408 ,
 408 ,
 408 ,
 408 ,
 408 ,
 408 ,
 408 ,
 408 ,
 408 ,
 408 ,
 408 ,
 408 ,
 408 ,
 408 , 
 408 
 };

uint16_t Keylen[] = {
 256 ,
 256 ,
 256 ,
 256 ,
 256 ,
 256 ,
 256 ,
 256 ,
 256 ,
 256 ,
 256 ,
 256 ,
 256 ,
 256 , 
 256 
 };

uint16_t AADlen[] = {
 720 ,
 720 ,
 720 ,
 720 ,
 720 ,
 720 ,
 720 ,
 720 ,
 720 ,
 720 ,
 720 ,
 720 ,
 720 ,
 720 , 
 720 
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
  1 , 
  1 
 };
