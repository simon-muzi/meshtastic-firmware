#pragma once
#include <Arduino.h>

#ifdef __cplusplus
extern "C" {
#endif

// Information about a single character
typedef struct {
    uint8_t widthBits; // Glyph width in bits
    uint16_t offset;   // Offset into the bitmap table
} FONT_CHAR_INFO;

// Information about the whole font
typedef struct {
    uint8_t heightBits;             // Character height in pixels (6px)
    uint8_t baseline;               // baseline (height-1) = 5
    uint8_t startChar;              // First supported char = 0x20
    uint8_t endChar;                // Last  supported char = 0xBD
    const FONT_CHAR_INFO *charInfo; // Jump table
    const uint8_t *data;            // Bitmap table
} FONT_INFO;

// Raw PROGMEM font data (jump table + bitmap stream)
extern const uint8_t TomThumb4x6[] PROGMEM;

// Wrapper combining the tables so OLED code can use it
extern const FONT_INFO TomThumb4x6_Info;

#ifdef __cplusplus
}
#endif
