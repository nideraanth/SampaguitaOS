ENTRY(_start)

SECTIONS
{
    . = 1M;           /* safe BIOS load offset */

    .multiboot : { *(.multiboot) }

    .text : { *(.text) }

    .rodata : { *(.rodata) }

    .data : { *(.data) }

    .bss  : { *(COMMON) *(.bss) }
}
