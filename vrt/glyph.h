#include <vrt.h>

// TODO: move out of VRT

struct v_fbterm_glyph_t {
	uint8_t code;
	uint8_t bitmap[16];
};

enum {
	CELL_WIDTH = 8,
	CELL_HEIGHT = 16
};

static const struct v_fbterm_glyph_t fb_con_glyphs[] = {
	{32, {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}},
	{33, {0x0, 0x0, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x0, 0x10, 0x10, 0x0, 0x0, 0x0, 0x0}},
	{34, {0x0, 0x24, 0x24, 0x24, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}},
	{35, {0x0, 0x0, 0x24, 0x24, 0x24, 0x7E, 0x24, 0x24, 0x7E, 0x24, 0x24, 0x24, 0x0, 0x0, 0x0, 0x0}},
	{36, {0x0, 0x10, 0x10, 0x7C, 0x92, 0x90, 0x90, 0x7C, 0x12, 0x12, 0x92, 0x7C, 0x10, 0x10, 0x0, 0x0}},
	{37, {0x0, 0x0, 0x64, 0x94, 0x68, 0x8, 0x10, 0x10, 0x20, 0x2C, 0x52, 0x4C, 0x0, 0x0, 0x0, 0x0}},
	{38, {0x0, 0x0, 0x18, 0x24, 0x24, 0x18, 0x30, 0x4A, 0x44, 0x44, 0x44, 0x3A, 0x0, 0x0, 0x0, 0x0}},
	{39, {0x0, 0x10, 0x10, 0x10, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}},
	{40, {0x0, 0x0, 0x8, 0x10, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x10, 0x8, 0x0, 0x0, 0x0, 0x0}},
	{41, {0x0, 0x0, 0x20, 0x10, 0x8, 0x8, 0x8, 0x8, 0x8, 0x8, 0x10, 0x20, 0x0, 0x0, 0x0, 0x0}},
	{42, {0x0, 0x0, 0x0, 0x0, 0x0, 0x24, 0x18, 0x7E, 0x18, 0x24, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}},
	{43, {0x0, 0x0, 0x0, 0x0, 0x0, 0x10, 0x10, 0x7C, 0x10, 0x10, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}},
	{44, {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x10, 0x10, 0x20, 0x0, 0x0, 0x0}},
	{45, {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x7E, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}},
	{46, {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x10, 0x10, 0x0, 0x0, 0x0, 0x0}},
	{47, {0x0, 0x0, 0x4, 0x4, 0x8, 0x8, 0x10, 0x10, 0x20, 0x20, 0x40, 0x40, 0x0, 0x0, 0x0, 0x0}},
	{48, {0x0, 0x0, 0x3C, 0x42, 0x42, 0x46, 0x4A, 0x52, 0x62, 0x42, 0x42, 0x3C, 0x0, 0x0, 0x0, 0x0}},
	{49, {0x0, 0x0, 0x8, 0x18, 0x28, 0x8, 0x8, 0x8, 0x8, 0x8, 0x8, 0x3E, 0x0, 0x0, 0x0, 0x0}},
	{50, {0x0, 0x0, 0x3C, 0x42, 0x42, 0x2, 0x4, 0x8, 0x10, 0x20, 0x40, 0x7E, 0x0, 0x0, 0x0, 0x0}},
	{51, {0x0, 0x0, 0x3C, 0x42, 0x42, 0x2, 0x1C, 0x2, 0x2, 0x42, 0x42, 0x3C, 0x0, 0x0, 0x0, 0x0}},
	{52, {0x0, 0x0, 0x2, 0x6, 0xA, 0x12, 0x22, 0x42, 0x7E, 0x2, 0x2, 0x2, 0x0, 0x0, 0x0, 0x0}},
	{53, {0x0, 0x0, 0x7E, 0x40, 0x40, 0x40, 0x7C, 0x2, 0x2, 0x2, 0x42, 0x3C, 0x0, 0x0, 0x0, 0x0}},
	{54, {0x0, 0x0, 0x1C, 0x20, 0x40, 0x40, 0x7C, 0x42, 0x42, 0x42, 0x42, 0x3C, 0x0, 0x0, 0x0, 0x0}},
	{55, {0x0, 0x0, 0x7E, 0x2, 0x2, 0x4, 0x4, 0x8, 0x8, 0x10, 0x10, 0x10, 0x0, 0x0, 0x0, 0x0}},
	{56, {0x0, 0x0, 0x3C, 0x42, 0x42, 0x42, 0x3C, 0x42, 0x42, 0x42, 0x42, 0x3C, 0x0, 0x0, 0x0, 0x0}},
	{57, {0x0, 0x0, 0x3C, 0x42, 0x42, 0x42, 0x42, 0x3E, 0x2, 0x2, 0x4, 0x38, 0x0, 0x0, 0x0, 0x0}},
	{58, {0x0, 0x0, 0x0, 0x0, 0x0, 0x10, 0x10, 0x0, 0x0, 0x0, 0x10, 0x10, 0x0, 0x0, 0x0, 0x0}},
	{59, {0x0, 0x0, 0x0, 0x0, 0x0, 0x10, 0x10, 0x0, 0x0, 0x0, 0x10, 0x10, 0x20, 0x0, 0x0, 0x0}},
	{60, {0x0, 0x0, 0x0, 0x4, 0x8, 0x10, 0x20, 0x40, 0x20, 0x10, 0x8, 0x4, 0x0, 0x0, 0x0, 0x0}},
	{61, {0x0, 0x0, 0x0, 0x0, 0x0, 0x7E, 0x0, 0x0, 0x7E, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}},
	{62, {0x0, 0x0, 0x0, 0x40, 0x20, 0x10, 0x8, 0x4, 0x8, 0x10, 0x20, 0x40, 0x0, 0x0, 0x0, 0x0}},
	{63, {0x0, 0x0, 0x3C, 0x42, 0x42, 0x42, 0x4, 0x8, 0x8, 0x0, 0x8, 0x8, 0x0, 0x0, 0x0, 0x0}},
	{64, {0x0, 0x0, 0x7C, 0x82, 0x9E, 0xA2, 0xA2, 0xA2, 0xA6, 0x9A, 0x80, 0x7E, 0x0, 0x0, 0x0, 0x0}},
	{65, {0x0, 0x0, 0x3C, 0x42, 0x42, 0x42, 0x42, 0x7E, 0x42, 0x42, 0x42, 0x42, 0x0, 0x0, 0x0, 0x0}},
	{66, {0x0, 0x0, 0x7C, 0x42, 0x42, 0x42, 0x7C, 0x42, 0x42, 0x42, 0x42, 0x7C, 0x0, 0x0, 0x0, 0x0}},
	{67, {0x0, 0x0, 0x3C, 0x42, 0x42, 0x40, 0x40, 0x40, 0x40, 0x42, 0x42, 0x3C, 0x0, 0x0, 0x0, 0x0}},
	{68, {0x0, 0x0, 0x78, 0x44, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x44, 0x78, 0x0, 0x0, 0x0, 0x0}},
	{69, {0x0, 0x0, 0x7E, 0x40, 0x40, 0x40, 0x78, 0x40, 0x40, 0x40, 0x40, 0x7E, 0x0, 0x0, 0x0, 0x0}},
	{70, {0x0, 0x0, 0x7E, 0x40, 0x40, 0x40, 0x78, 0x40, 0x40, 0x40, 0x40, 0x40, 0x0, 0x0, 0x0, 0x0}},
	{71, {0x0, 0x0, 0x3C, 0x42, 0x42, 0x40, 0x40, 0x4E, 0x42, 0x42, 0x42, 0x3C, 0x0, 0x0, 0x0, 0x0}},
	{72, {0x0, 0x0, 0x42, 0x42, 0x42, 0x42, 0x7E, 0x42, 0x42, 0x42, 0x42, 0x42, 0x0, 0x0, 0x0, 0x0}},
	{73, {0x0, 0x0, 0x38, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x38, 0x0, 0x0, 0x0, 0x0}},
	{74, {0x0, 0x0, 0xE, 0x4, 0x4, 0x4, 0x4, 0x4, 0x4, 0x44, 0x44, 0x38, 0x0, 0x0, 0x0, 0x0}},
	{75, {0x0, 0x0, 0x42, 0x44, 0x48, 0x50, 0x60, 0x60, 0x50, 0x48, 0x44, 0x42, 0x0, 0x0, 0x0, 0x0}},
	{76, {0x0, 0x0, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x7E, 0x0, 0x0, 0x0, 0x0}},
	{77, {0x0, 0x0, 0x82, 0xC6, 0xAA, 0x92, 0x92, 0x82, 0x82, 0x82, 0x82, 0x82, 0x0, 0x0, 0x0, 0x0}},
	{78, {0x0, 0x0, 0x42, 0x42, 0x42, 0x62, 0x52, 0x4A, 0x46, 0x42, 0x42, 0x42, 0x0, 0x0, 0x0, 0x0}},
	{79, {0x0, 0x0, 0x3C, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x3C, 0x0, 0x0, 0x0, 0x0}},
	{80, {0x0, 0x0, 0x7C, 0x42, 0x42, 0x42, 0x42, 0x7C, 0x40, 0x40, 0x40, 0x40, 0x0, 0x0, 0x0, 0x0}},
	{81, {0x0, 0x0, 0x3C, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x4A, 0x3C, 0x2, 0x0, 0x0, 0x0}},
	{82, {0x0, 0x0, 0x7C, 0x42, 0x42, 0x42, 0x42, 0x7C, 0x50, 0x48, 0x44, 0x42, 0x0, 0x0, 0x0, 0x0}},
	{83, {0x0, 0x0, 0x3C, 0x42, 0x40, 0x40, 0x3C, 0x2, 0x2, 0x42, 0x42, 0x3C, 0x0, 0x0, 0x0, 0x0}},
	{84, {0x0, 0x0, 0xFE, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x0, 0x0, 0x0, 0x0}},
	{85, {0x0, 0x0, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x3C, 0x0, 0x0, 0x0, 0x0}},
	{86, {0x0, 0x0, 0x42, 0x42, 0x42, 0x42, 0x42, 0x24, 0x24, 0x24, 0x18, 0x18, 0x0, 0x0, 0x0, 0x0}},
	{87, {0x0, 0x0, 0x82, 0x82, 0x82, 0x82, 0x82, 0x92, 0x92, 0xAA, 0xC6, 0x82, 0x0, 0x0, 0x0, 0x0}},
	{88, {0x0, 0x0, 0x42, 0x42, 0x24, 0x24, 0x18, 0x18, 0x24, 0x24, 0x42, 0x42, 0x0, 0x0, 0x0, 0x0}},
	{89, {0x0, 0x0, 0x82, 0x82, 0x44, 0x44, 0x28, 0x10, 0x10, 0x10, 0x10, 0x10, 0x0, 0x0, 0x0, 0x0}},
	{90, {0x0, 0x0, 0x7E, 0x2, 0x2, 0x4, 0x8, 0x10, 0x20, 0x40, 0x40, 0x7E, 0x0, 0x0, 0x0, 0x0}},
	{91, {0x0, 0x0, 0x38, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x38, 0x0, 0x0, 0x0, 0x0}},
	{92, {0x0, 0x0, 0x40, 0x40, 0x20, 0x20, 0x10, 0x10, 0x8, 0x8, 0x4, 0x4, 0x0, 0x0, 0x0, 0x0}},
	{93, {0x0, 0x0, 0x38, 0x8, 0x8, 0x8, 0x8, 0x8, 0x8, 0x8, 0x8, 0x38, 0x0, 0x0, 0x0, 0x0}},
	{94, {0x0, 0x10, 0x28, 0x44, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}},
	{95, {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x7E, 0x0, 0x0}},
	{96, {0x10, 0x8, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}},
	{97, {0x0, 0x0, 0x0, 0x0, 0x0, 0x3C, 0x2, 0x3E, 0x42, 0x42, 0x42, 0x3E, 0x0, 0x0, 0x0, 0x0}},
	{98, {0x0, 0x0, 0x40, 0x40, 0x40, 0x7C, 0x42, 0x42, 0x42, 0x42, 0x42, 0x7C, 0x0, 0x0, 0x0, 0x0}},
	{99, {0x0, 0x0, 0x0, 0x0, 0x0, 0x3C, 0x42, 0x40, 0x40, 0x40, 0x42, 0x3C, 0x0, 0x0, 0x0, 0x0}},
	{100, {0x0, 0x0, 0x2, 0x2, 0x2, 0x3E, 0x42, 0x42, 0x42, 0x42, 0x42, 0x3E, 0x0, 0x0, 0x0, 0x0}},
	{101, {0x0, 0x0, 0x0, 0x0, 0x0, 0x3C, 0x42, 0x42, 0x7E, 0x40, 0x40, 0x3C, 0x0, 0x0, 0x0, 0x0}},
	{102, {0x0, 0x0, 0xE, 0x10, 0x10, 0x7C, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x0, 0x0, 0x0, 0x0}},
	{103, {0x0, 0x0, 0x0, 0x0, 0x0, 0x3E, 0x42, 0x42, 0x42, 0x42, 0x42, 0x3E, 0x2, 0x2, 0x3C, 0x0}},
	{104, {0x0, 0x0, 0x40, 0x40, 0x40, 0x7C, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x0, 0x0, 0x0, 0x0}},
	{105, {0x0, 0x0, 0x10, 0x10, 0x0, 0x30, 0x10, 0x10, 0x10, 0x10, 0x10, 0x38, 0x0, 0x0, 0x0, 0x0}},
	{106, {0x0, 0x0, 0x4, 0x4, 0x0, 0xC, 0x4, 0x4, 0x4, 0x4, 0x4, 0x4, 0x44, 0x44, 0x38, 0x0}},
	{107, {0x0, 0x0, 0x40, 0x40, 0x40, 0x42, 0x44, 0x48, 0x70, 0x48, 0x44, 0x42, 0x0, 0x0, 0x0, 0x0}},
	{108, {0x0, 0x0, 0x30, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x38, 0x0, 0x0, 0x0, 0x0}},
	{109, {0x0, 0x0, 0x0, 0x0, 0x0, 0xFC, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0x0, 0x0, 0x0, 0x0}},
	{110, {0x0, 0x0, 0x0, 0x0, 0x0, 0x7C, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x0, 0x0, 0x0, 0x0}},
	{111, {0x0, 0x0, 0x0, 0x0, 0x0, 0x3C, 0x42, 0x42, 0x42, 0x42, 0x42, 0x3C, 0x0, 0x0, 0x0, 0x0}},
	{112, {0x0, 0x0, 0x0, 0x0, 0x0, 0x7C, 0x42, 0x42, 0x42, 0x42, 0x42, 0x7C, 0x40, 0x40, 0x40, 0x0}},
	{113, {0x0, 0x0, 0x0, 0x0, 0x0, 0x3E, 0x42, 0x42, 0x42, 0x42, 0x42, 0x3E, 0x2, 0x2, 0x2, 0x0}},
	{114, {0x0, 0x0, 0x0, 0x0, 0x0, 0x5E, 0x60, 0x40, 0x40, 0x40, 0x40, 0x40, 0x0, 0x0, 0x0, 0x0}},
	{115, {0x0, 0x0, 0x0, 0x0, 0x0, 0x3E, 0x40, 0x40, 0x3C, 0x2, 0x2, 0x7C, 0x0, 0x0, 0x0, 0x0}},
	{116, {0x0, 0x0, 0x10, 0x10, 0x10, 0x7C, 0x10, 0x10, 0x10, 0x10, 0x10, 0xE, 0x0, 0x0, 0x0, 0x0}},
	{117, {0x0, 0x0, 0x0, 0x0, 0x0, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x3E, 0x0, 0x0, 0x0, 0x0}},
	{118, {0x0, 0x0, 0x0, 0x0, 0x0, 0x42, 0x42, 0x42, 0x24, 0x24, 0x18, 0x18, 0x0, 0x0, 0x0, 0x0}},
	{119, {0x0, 0x0, 0x0, 0x0, 0x0, 0x82, 0x82, 0x92, 0x92, 0x92, 0x92, 0x7C, 0x0, 0x0, 0x0, 0x0}},
	{120, {0x0, 0x0, 0x0, 0x0, 0x0, 0x42, 0x42, 0x24, 0x18, 0x24, 0x42, 0x42, 0x0, 0x0, 0x0, 0x0}},
	{121, {0x0, 0x0, 0x0, 0x0, 0x0, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x3E, 0x2, 0x2, 0x3C, 0x0}},
	{122, {0x0, 0x0, 0x0, 0x0, 0x0, 0x7E, 0x4, 0x8, 0x10, 0x20, 0x40, 0x7E, 0x0, 0x0, 0x0, 0x0}},
	{123, {0x0, 0x0, 0xC, 0x10, 0x10, 0x10, 0x20, 0x10, 0x10, 0x10, 0x10, 0xC, 0x0, 0x0, 0x0, 0x0}},
	{124, {0x0, 0x0, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x0, 0x0, 0x0, 0x0}},
	{125, {0x0, 0x0, 0x30, 0x8, 0x8, 0x8, 0x4, 0x8, 0x8, 0x8, 0x8, 0x30, 0x0, 0x0, 0x0, 0x0}},
	{126, {0x0, 0x62, 0x92, 0x8C, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}},
	{160, {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}},
	{161, {0x0, 0x0, 0x10, 0x10, 0x0, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x0, 0x0, 0x0, 0x0}},
	{162, {0x0, 0x0, 0x0, 0x10, 0x10, 0x7C, 0x92, 0x90, 0x90, 0x90, 0x92, 0x7C, 0x10, 0x10, 0x0, 0x0}},
	{163, {0x0, 0x0, 0x18, 0x24, 0x20, 0x20, 0x78, 0x20, 0x20, 0x20, 0x22, 0x7E, 0x0, 0x0, 0x0, 0x0}},
	{164, {0x0, 0x0, 0x0, 0x0, 0x44, 0x38, 0x44, 0x44, 0x44, 0x38, 0x44, 0x0, 0x0, 0x0, 0x0, 0x0}},
	{165, {0x0, 0x0, 0x82, 0x82, 0x44, 0x28, 0x10, 0x7C, 0x10, 0x7C, 0x10, 0x10, 0x0, 0x0, 0x0, 0x0}},
	{166, {0x0, 0x0, 0x10, 0x10, 0x10, 0x10, 0x0, 0x0, 0x10, 0x10, 0x10, 0x10, 0x0, 0x0, 0x0, 0x0}},
	{167, {0x0, 0x38, 0x44, 0x40, 0x30, 0x48, 0x44, 0x44, 0x24, 0x18, 0x4, 0x44, 0x38, 0x0, 0x0, 0x0}},
	{168, {0x24, 0x24, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}},
	{169, {0x0, 0x0, 0x0, 0x7E, 0x81, 0x99, 0xA5, 0xA1, 0xA5, 0x99, 0x81, 0x7E, 0x0, 0x0, 0x0, 0x0}},
	{170, {0x0, 0x38, 0x4, 0x3C, 0x44, 0x3C, 0x0, 0x7C, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}},
	{171, {0x0, 0x0, 0x0, 0x0, 0x0, 0x12, 0x24, 0x48, 0x90, 0x48, 0x24, 0x12, 0x0, 0x0, 0x0, 0x0}},
	{172, {0x0, 0x0, 0x0, 0x0, 0x0, 0x7E, 0x2, 0x2, 0x2, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}},
	{174, {0x0, 0x0, 0x0, 0x7E, 0x81, 0xB9, 0xA5, 0xB9, 0xA9, 0xA5, 0x81, 0x7E, 0x0, 0x0, 0x0, 0x0}},
	{175, {0x3C, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}},
	{176, {0x0, 0x18, 0x24, 0x24, 0x18, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}},
	{177, {0x0, 0x0, 0x0, 0x0, 0x0, 0x10, 0x10, 0x7C, 0x10, 0x10, 0x0, 0x7C, 0x0, 0x0, 0x0, 0x0}},
	{178, {0x0, 0x18, 0x24, 0x8, 0x10, 0x3C, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}},
	{179, {0x0, 0x38, 0x4, 0x18, 0x4, 0x38, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}},
	{180, {0x8, 0x10, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}},
	{181, {0x0, 0x0, 0x0, 0x0, 0x0, 0x42, 0x42, 0x42, 0x42, 0x42, 0x46, 0x7A, 0x40, 0x40, 0x40, 0x0}},
	{182, {0x0, 0x0, 0x7E, 0x92, 0x92, 0x92, 0x92, 0x72, 0x12, 0x12, 0x12, 0x12, 0x0, 0x0, 0x0, 0x0}},
	{183, {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x10, 0x10, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}},
	{184, {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x10, 0x10, 0x20, 0x0}},
	{185, {0x0, 0x10, 0x30, 0x10, 0x10, 0x10, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}},
	{186, {0x0, 0x38, 0x44, 0x44, 0x44, 0x38, 0x0, 0x7C, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}},
	{187, {0x0, 0x0, 0x0, 0x0, 0x0, 0x90, 0x48, 0x24, 0x12, 0x24, 0x48, 0x90, 0x0, 0x0, 0x0, 0x0}},
	{188, {0x0, 0x20, 0x60, 0x20, 0x22, 0x24, 0x8, 0x10, 0x22, 0x46, 0x8A, 0x1E, 0x2, 0x2, 0x0, 0x0}},
	{189, {0x0, 0x20, 0x60, 0x20, 0x22, 0x24, 0x8, 0x10, 0x20, 0x4C, 0x92, 0x4, 0x8, 0x1E, 0x0, 0x0}},
	{190, {0x0, 0xE0, 0x10, 0x60, 0x12, 0xE4, 0x8, 0x10, 0x22, 0x46, 0x8A, 0x1E, 0x2, 0x2, 0x0, 0x0}},
	{191, {0x0, 0x0, 0x10, 0x10, 0x0, 0x10, 0x10, 0x20, 0x42, 0x42, 0x42, 0x3C, 0x0, 0x0, 0x0, 0x0}},
	{192, {0x10, 0x8, 0x0, 0x3C, 0x42, 0x42, 0x42, 0x7E, 0x42, 0x42, 0x42, 0x42, 0x0, 0x0, 0x0, 0x0}},
	{193, {0x8, 0x10, 0x0, 0x3C, 0x42, 0x42, 0x42, 0x7E, 0x42, 0x42, 0x42, 0x42, 0x0, 0x0, 0x0, 0x0}},
	{194, {0x18, 0x24, 0x0, 0x3C, 0x42, 0x42, 0x42, 0x7E, 0x42, 0x42, 0x42, 0x42, 0x0, 0x0, 0x0, 0x0}},
	{195, {0x32, 0x4C, 0x0, 0x3C, 0x42, 0x42, 0x42, 0x7E, 0x42, 0x42, 0x42, 0x42, 0x0, 0x0, 0x0, 0x0}},
	{196, {0x24, 0x24, 0x0, 0x3C, 0x42, 0x42, 0x42, 0x7E, 0x42, 0x42, 0x42, 0x42, 0x0, 0x0, 0x0, 0x0}},
	{197, {0x18, 0x24, 0x18, 0x3C, 0x42, 0x42, 0x42, 0x7E, 0x42, 0x42, 0x42, 0x42, 0x0, 0x0, 0x0, 0x0}},
	{198, {0x0, 0x0, 0x7E, 0x90, 0x90, 0x90, 0xFC, 0x90, 0x90, 0x90, 0x90, 0x9E, 0x0, 0x0, 0x0, 0x0}},
	{199, {0x0, 0x0, 0x3C, 0x42, 0x42, 0x40, 0x40, 0x40, 0x40, 0x42, 0x42, 0x3C, 0x10, 0x10, 0x20, 0x0}},
	{200, {0x10, 0x8, 0x0, 0x7E, 0x40, 0x40, 0x40, 0x78, 0x40, 0x40, 0x40, 0x7E, 0x0, 0x0, 0x0, 0x0}},
	{201, {0x8, 0x10, 0x0, 0x7E, 0x40, 0x40, 0x40, 0x78, 0x40, 0x40, 0x40, 0x7E, 0x0, 0x0, 0x0, 0x0}},
	{202, {0x18, 0x24, 0x0, 0x7E, 0x40, 0x40, 0x40, 0x78, 0x40, 0x40, 0x40, 0x7E, 0x0, 0x0, 0x0, 0x0}},
	{203, {0x24, 0x24, 0x0, 0x7E, 0x40, 0x40, 0x40, 0x78, 0x40, 0x40, 0x40, 0x7E, 0x0, 0x0, 0x0, 0x0}},
	{204, {0x20, 0x10, 0x0, 0x38, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x38, 0x0, 0x0, 0x0, 0x0}},
	{205, {0x8, 0x10, 0x0, 0x38, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x38, 0x0, 0x0, 0x0, 0x0}},
	{206, {0x18, 0x24, 0x0, 0x38, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x38, 0x0, 0x0, 0x0, 0x0}},
	{207, {0x44, 0x44, 0x0, 0x38, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x38, 0x0, 0x0, 0x0, 0x0}},
	{208, {0x0, 0x0, 0x78, 0x44, 0x42, 0x42, 0xF2, 0x42, 0x42, 0x42, 0x44, 0x78, 0x0, 0x0, 0x0, 0x0}},
	{209, {0x32, 0x4C, 0x0, 0x42, 0x42, 0x62, 0x52, 0x4A, 0x46, 0x42, 0x42, 0x42, 0x0, 0x0, 0x0, 0x0}},
	{210, {0x10, 0x8, 0x0, 0x3C, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x3C, 0x0, 0x0, 0x0, 0x0}},
	{211, {0x8, 0x10, 0x0, 0x3C, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x3C, 0x0, 0x0, 0x0, 0x0}},
	{212, {0x18, 0x24, 0x0, 0x3C, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x3C, 0x0, 0x0, 0x0, 0x0}},
	{213, {0x32, 0x4C, 0x0, 0x3C, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x3C, 0x0, 0x0, 0x0, 0x0}},
	{214, {0x24, 0x24, 0x0, 0x3C, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x3C, 0x0, 0x0, 0x0, 0x0}},
	{215, {0x0, 0x0, 0x0, 0x0, 0x0, 0x42, 0x24, 0x18, 0x18, 0x24, 0x42, 0x0, 0x0, 0x0, 0x0, 0x0}},
	{216, {0x0, 0x0, 0x3C, 0x43, 0x42, 0x46, 0x4A, 0x52, 0x62, 0x42, 0xC2, 0x3C, 0x0, 0x0, 0x0, 0x0}},
	{217, {0x10, 0x8, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x3C, 0x0, 0x0, 0x0, 0x0}},
	{218, {0x8, 0x10, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x3C, 0x0, 0x0, 0x0, 0x0}},
	{219, {0x18, 0x24, 0x0, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x3C, 0x0, 0x0, 0x0, 0x0}},
	{220, {0x24, 0x24, 0x0, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x3C, 0x0, 0x0, 0x0, 0x0}},
	{221, {0x8, 0x10, 0x82, 0x82, 0x44, 0x44, 0x28, 0x10, 0x10, 0x10, 0x10, 0x10, 0x0, 0x0, 0x0, 0x0}},
	{222, {0x0, 0x0, 0x40, 0x40, 0x7C, 0x42, 0x42, 0x42, 0x42, 0x7C, 0x40, 0x40, 0x0, 0x0, 0x0, 0x0}},
	{223, {0x0, 0x0, 0x38, 0x44, 0x44, 0x48, 0x7C, 0x42, 0x42, 0x42, 0x62, 0x5C, 0x0, 0x0, 0x0, 0x0}},
	{224, {0x0, 0x0, 0x10, 0x8, 0x0, 0x3C, 0x2, 0x3E, 0x42, 0x42, 0x42, 0x3E, 0x0, 0x0, 0x0, 0x0}},
	{225, {0x0, 0x0, 0x8, 0x10, 0x0, 0x3C, 0x2, 0x3E, 0x42, 0x42, 0x42, 0x3E, 0x0, 0x0, 0x0, 0x0}},
	{226, {0x0, 0x0, 0x18, 0x24, 0x0, 0x3C, 0x2, 0x3E, 0x42, 0x42, 0x42, 0x3E, 0x0, 0x0, 0x0, 0x0}},
	{227, {0x0, 0x0, 0x32, 0x4C, 0x0, 0x3C, 0x2, 0x3E, 0x42, 0x42, 0x42, 0x3E, 0x0, 0x0, 0x0, 0x0}},
	{228, {0x0, 0x0, 0x24, 0x24, 0x0, 0x3C, 0x2, 0x3E, 0x42, 0x42, 0x42, 0x3E, 0x0, 0x0, 0x0, 0x0}},
	{229, {0x0, 0x0, 0x18, 0x24, 0x18, 0x3C, 0x2, 0x3E, 0x42, 0x42, 0x42, 0x3E, 0x0, 0x0, 0x0, 0x0}},
	{230, {0x0, 0x0, 0x0, 0x0, 0x0, 0x6C, 0x12, 0x72, 0x9E, 0x90, 0x90, 0x6C, 0x0, 0x0, 0x0, 0x0}},
	{231, {0x0, 0x0, 0x0, 0x0, 0x0, 0x3C, 0x42, 0x40, 0x40, 0x40, 0x42, 0x3C, 0x10, 0x10, 0x20, 0x0}},
	{232, {0x0, 0x0, 0x10, 0x8, 0x0, 0x3C, 0x42, 0x42, 0x7E, 0x40, 0x40, 0x3C, 0x0, 0x0, 0x0, 0x0}},
	{233, {0x0, 0x0, 0x8, 0x10, 0x0, 0x3C, 0x42, 0x42, 0x7E, 0x40, 0x40, 0x3C, 0x0, 0x0, 0x0, 0x0}},
	{234, {0x0, 0x0, 0x18, 0x24, 0x0, 0x3C, 0x42, 0x42, 0x7E, 0x40, 0x40, 0x3C, 0x0, 0x0, 0x0, 0x0}},
	{235, {0x0, 0x0, 0x24, 0x24, 0x0, 0x3C, 0x42, 0x42, 0x7E, 0x40, 0x40, 0x3C, 0x0, 0x0, 0x0, 0x0}},
	{236, {0x0, 0x0, 0x20, 0x10, 0x0, 0x30, 0x10, 0x10, 0x10, 0x10, 0x10, 0x38, 0x0, 0x0, 0x0, 0x0}},
	{237, {0x0, 0x0, 0x8, 0x10, 0x0, 0x30, 0x10, 0x10, 0x10, 0x10, 0x10, 0x38, 0x0, 0x0, 0x0, 0x0}},
	{238, {0x0, 0x0, 0x30, 0x48, 0x0, 0x30, 0x10, 0x10, 0x10, 0x10, 0x10, 0x38, 0x0, 0x0, 0x0, 0x0}},
	{239, {0x0, 0x0, 0x48, 0x48, 0x0, 0x30, 0x10, 0x10, 0x10, 0x10, 0x10, 0x38, 0x0, 0x0, 0x0, 0x0}},
	{240, {0x0, 0x0, 0x28, 0x10, 0x28, 0x3C, 0x42, 0x42, 0x42, 0x42, 0x42, 0x3C, 0x0, 0x0, 0x0, 0x0}},
	{241, {0x0, 0x0, 0x32, 0x4C, 0x0, 0x7C, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x0, 0x0, 0x0, 0x0}},
	{242, {0x0, 0x0, 0x10, 0x8, 0x0, 0x3C, 0x42, 0x42, 0x42, 0x42, 0x42, 0x3C, 0x0, 0x0, 0x0, 0x0}},
	{243, {0x0, 0x0, 0x8, 0x10, 0x0, 0x3C, 0x42, 0x42, 0x42, 0x42, 0x42, 0x3C, 0x0, 0x0, 0x0, 0x0}},
	{244, {0x0, 0x0, 0x18, 0x24, 0x0, 0x3C, 0x42, 0x42, 0x42, 0x42, 0x42, 0x3C, 0x0, 0x0, 0x0, 0x0}},
	{245, {0x0, 0x0, 0x32, 0x4C, 0x0, 0x3C, 0x42, 0x42, 0x42, 0x42, 0x42, 0x3C, 0x0, 0x0, 0x0, 0x0}},
	{246, {0x0, 0x0, 0x24, 0x24, 0x0, 0x3C, 0x42, 0x42, 0x42, 0x42, 0x42, 0x3C, 0x0, 0x0, 0x0, 0x0}},
	{247, {0x0, 0x0, 0x0, 0x0, 0x10, 0x10, 0x0, 0x7C, 0x0, 0x10, 0x10, 0x0, 0x0, 0x0, 0x0, 0x0}},
	{248, {0x0, 0x0, 0x0, 0x0, 0x2, 0x3C, 0x46, 0x4A, 0x52, 0x62, 0x42, 0xBC, 0x0, 0x0, 0x0, 0x0}},
	{249, {0x0, 0x0, 0x10, 0x8, 0x0, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x3E, 0x0, 0x0, 0x0, 0x0}},
	{250, {0x0, 0x0, 0x8, 0x10, 0x0, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x3E, 0x0, 0x0, 0x0, 0x0}},
	{251, {0x0, 0x0, 0x18, 0x24, 0x0, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x3E, 0x0, 0x0, 0x0, 0x0}},
	{252, {0x0, 0x0, 0x24, 0x24, 0x0, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x3E, 0x0, 0x0, 0x0, 0x0}},
	{253, {0x0, 0x0, 0x8, 0x10, 0x0, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x3E, 0x2, 0x2, 0x3C, 0x0}},
	{254, {0x0, 0x0, 0x40, 0x40, 0x40, 0x7C, 0x42, 0x42, 0x42, 0x42, 0x42, 0x7C, 0x40, 0x40, 0x40, 0x0}},
	{255, {0x0, 0x0, 0x24, 0x24, 0x0, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x3E, 0x2, 0x2, 0x3C, 0x0}},
};

uint8_t* fbcon_get_glyph(byte idx) {
	if (idx > 190) {
		idx = 0;
	}

	return fb_con_glyphs[idx].bitmap;
}