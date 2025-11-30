#include <stdint.h> // Ensure you have this for uint16_t and uint8_t

// This is the full implementation of the outb function
static inline void outb(uint16_t port, uint8_t val)
{
    // 'outb %0, %1' is the assembly instruction
    __asm__ volatile ( "outb %0, %1" : : "a"(val), "Nd"(port) );
}