# SampaguitaOS
SampaguitaOS is a hobby 32-bit operating system kernel, written primarily in C and Assembly, targeting the x86 architecture. The project is focused on learning the fundamentals of bare-metal development, boot protocols (Multiboot 1), kernel architecture, and device driver implementation.

SampaguitaOS is under active development and is intended solely for educational purposes and learning.

QUALITY DISCLAIMER: This operating system is a **WORK IN PROGRESS**, learning project. 

This is meant to demonstrate the capabilities of my OS,
such as text coloring, hexadecimal, integer, and string direct VGA buffer writing, meaning when you do a ```Term_IO_Write**()```; , it writes directly to the screen.

I also added proprietary print functions that write directly to the VGA buffer, such as:
```Term_IO_WriteStr("");```
```Term_IO_WriteInt(123);```
```Term_IO_WriteHex(0xDEADBEEF);```

This OS is not guaranteed to be **STABLE**,   
**PERFORMANT**, or possess any certain level of    
**QUALITY**, **RELIABILITY**, or **SECURITY**. 
Features are incomplete, and bugs are expected.

 NO WARRANTY: This software is provided "as-is," without any warranty, express or implied. The author is not responsible for any damage, loss of 
 data, or corruption to hardware or software that may occur from compiling, running, or testing this OS. 
 
Testing Safety: IT IS HIGHLY RECOMENDED THAT YOU ONLY TEST THIS OS WITHIN VIRTUAL MACHINES (like QEMU) OR ON DEDICATED, NON-ESSENTIAL HARDWARE.
