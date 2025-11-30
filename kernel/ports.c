#include "ports.h"

static inline void outb(uint16_t port, uint8_t val)
{
    // 'outb %0, %1' is the assembly instruction: write the value (%0) to the port (%1)
    // "a"(val) means use the AL register for 'val'
    // "Nd"(port) means use the DX register for 'port'
    __asm__ volatile ( "outb %0, %1" : : "a"(val), "Nd"(port) );
}