#include <stddef.h>
#include <stdint.h>

#include "ports.h"
#include "vga.h"
#include "libc/include/string.h"
// ^^ ADD ONCE KEYBOARD IS READY


uint8_t vga_entry_color(enum vga_color fg, enum vga_color bg) 
{
	return fg | bg << 4;
}

// Remove 'static' and 'inline' for vga_entry as well, as it's now declared in the header
uint16_t vga_entry(unsigned char uc, uint8_t color) 
{
	return (uint16_t) uc | (uint16_t) color << 8;
}

#define VGA_WIDTH   80
#define VGA_HEIGHT  25
#define VGA_MEMORY  0xB8000 

size_t terminal_row;
size_t terminal_column;
uint8_t terminal_color;
uint16_t* terminal_buffer = (uint16_t*)VGA_MEMORY;

void Term_IO_Init(void) 
{
	terminal_row = 0;
	terminal_column = 0;
	terminal_color = vga_entry_color(VGA_COLOR_LIGHT_GREY, VGA_COLOR_BLACK);
	
	terminal_buffer = (uint16_t*)0xB8000;
	for (size_t y = 0; y < VGA_HEIGHT; y++) {
		for (size_t x = 0; x < VGA_WIDTH; x++) {
			terminal_buffer[y*VGA_WIDTH + x] = vga_entry(' ', terminal_color);
		}
	}
}

void Term_IO_SetColor(uint8_t color) 
{
	terminal_color = color;
}

void Term_IO_PutEntryAt(char c, uint8_t color, size_t x, size_t y) 
{
	const size_t index = y * VGA_WIDTH + x;
	terminal_buffer[index] = vga_entry(c, color);
}

void Term_IO_UpdateCursor(void)
{
    // calculate 16-bit linear position
    uint16_t position = terminal_row * VGA_WIDTH + terminal_column;

    //   tell controller OS wants to access the high byte of the cursor position (Register 14)
    outb(0x3D4, 0x0E); 
    //   high 8 bits of the position
    outb(0x3D5, (uint8_t)((position >> 8) & 0xFF));

    //  tell controller OS want to access the low byte of the cursor position (Register 15)
    outb(0x3D4, 0x0F); 
    // send low 8 bits of the position
    outb(0x3D5, (uint8_t)(position & 0xFF));
}

void Term_IO_Scroll()
{
	const size_t RowsToCopy = VGA_HEIGHT - 1;
	const size_t BytesPerRow = VGA_WIDTH * sizeof(uint16_t);
	//  list dimensions as constants

	memcpy(
		terminal_buffer,
		terminal_buffer + VGA_WIDTH,
		RowsToCopy * BytesPerRow
	);  // copy buffer

	const size_t LastRowStartIndex = (VGA_HEIGHT -1) * VGA_WIDTH;
	const uint16_t blank_entry = vga_entry(' ',terminal_color);   //  vga_entry([TEXT],[COLOR]); // clears row.

	// loop through the last row and fill it with blank entries.
    for (size_t x = 0; x < VGA_WIDTH; x++) {
        terminal_buffer[LastRowStartIndex + x] = blank_entry;
    }

    //  update the cursor position to the beginning of the last line
    terminal_row = VGA_HEIGHT - 1;
    terminal_column = 0;
}

void Term_IO_PutChar(char c) 
{
    // Check for a newline character
	if (c == '\n')
	{
		terminal_column = 0;
		if (++terminal_row >= VGA_HEIGHT) {
            // wrap around the top of the screen
            terminal_row = 0; 
        }
		Term_IO_UpdateCursor();
        return; // do not print a newline character
	}

    // if not a newline, print the character at the current position
	Term_IO_PutEntryAt(c, terminal_color, terminal_column, terminal_row);

    // Advance the cursor position
	if (++terminal_column >= VGA_WIDTH) {
		terminal_column = 0;
		if (++terminal_row >= VGA_HEIGHT) {
            // *** CHANGE: Wrap around to the top of the screen (Row 0) ***
			terminal_row = 0;
        }
	}
}


static int Term_IO_IntToStr(unsigned long value, char* buffer, int base)
{
	const char* digits = "0123456789ABCDEF";
	char  *p = buffer;

	if (value == 0)
	{
		*p++ = '0';
		*p = '\0';
		return 1;
	}

	do 
	{
		unsigned long digit_val = value % base;
		*p = digits[digit_val];
		p++;
		value /= base;
	}while (value > 0);

	*p = '\0';
	char *start = buffer;
	char *end = p - 1;

	while (start < end)
	{
		char temp = *start;
		*start = *end;
		*end = temp;

		start++;
		end--;
	}
	return (int)(p - buffer);
}

void Term_IO_Write(const char* data, size_t size) 
{
	for (size_t i = 0; i < size; i++)
		Term_IO_PutChar(data[i]);
}

void Term_IO_WriteHex(unsigned long value)
{
	char buffer[21];

	Term_IO_PutChar('0');
	Term_IO_PutChar('x');

	Term_IO_IntToStr(value, buffer, 16);
	for (size_t i = 0; buffer[i] != '\0'; i++)
	{
		Term_IO_PutChar(buffer[i]);
	}
}
void Term_IO_WriteInt(long value)
{
	char buffer[21];

	if (value < 0 )		// if the value is a negative, add a negative sign
	{
		Term_IO_PutChar('-');
		value = -value;
	}

	Term_IO_IntToStr(value,buffer,10);
	for (size_t i = 0; buffer[i] != '\0'; i++)   // write the integer until it reaches null
	{
		Term_IO_PutChar(buffer[i]);
	}
}
void Term_IO_WriteStr(const char* data) 
{
	Term_IO_Write(data, strlen(data));
}
