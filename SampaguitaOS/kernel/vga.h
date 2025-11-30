#ifndef VGA_H
#define VGA_H

#include <stddef.h>
#include <stdint.h>

enum vga_color {
	VGA_COLOR_BLACK = 0,
	VGA_COLOR_BLUE = 1,
	VGA_COLOR_GREEN = 2,
	VGA_COLOR_CYAN = 3,
	VGA_COLOR_RED = 4,
	VGA_COLOR_MAGENTA = 5,
	VGA_COLOR_BROWN = 6,
	VGA_COLOR_LIGHT_GREY = 7,
	VGA_COLOR_DARK_GREY = 8,
	VGA_COLOR_LIGHT_BLUE = 9,
	VGA_COLOR_LIGHT_GREEN = 10,
	VGA_COLOR_LIGHT_CYAN = 11,
	VGA_COLOR_LIGHT_RED = 12,
	VGA_COLOR_LIGHT_MAGENTA = 13,
	VGA_COLOR_LIGHT_BROWN = 14,
	VGA_COLOR_WHITE = 15,
};  // VGA colors


// Only the DECLARATION (prototype) here:
uint8_t vga_entry_color(enum vga_color fg, enum vga_color bg);

// Only the DECLARATION (prototype) here:
uint16_t vga_entry(unsigned char uc, uint8_t color); 


void Term_IO_Init(void);
void Term_IO_SetColor(uint8_t color);
void Term_IO_PutEntryAt(char c, uint8_t color, size_t x, size_t y);
void Term_IO_PutChar(char c);
void Term_IO_Write(const char* data, size_t size);

void Term_IO_WriteStr(const char* data);
void Term_IO_WriteInt(long value);
void Term_IO_WriteHex(unsigned long value);
#endif