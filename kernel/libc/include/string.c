#include <stddef.h> // For size_t

size_t strlen(const char* str) 
{
    size_t len = 0;
    while (str[len])
        len++;
    return len;
}

void* memcpy(void* dest, const void* src, size_t n) {
    char* dp = dest;
    const char* sp = src;
    while (n--) {
        *dp++ = *sp++;
    }
    return dest;
}

// Any other string/memory functions you add later go here too
