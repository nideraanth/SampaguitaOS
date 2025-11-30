# SampaguitaOS
SampaguitaOS is a hobby 32-bit operating system kernel, written primarily in C and Assembly, targeting the x86 architecture. The project is focused on learning the fundamentals of bare-metal development, boot protocols (Multiboot 1), kernel architecture, and device driver implementation.

SampaguitaOS is under active development and is intended solely for educational purposes and learning.

QUALITY DISCLAIMER: This operating system is a **WORK IN PROGRESS**, learning project. 

This is meant to demonstrate the capabilities of my OS,
such as text coloring, hexadecimal, integer, and string direct VGA buffer writing, meaning when you do a ```Term_IO_Write**()```; , it writes directly to the screen.

I also added proprietary print functions that write directly to the VGA buffer, examples include:

```Term_IO_WriteStr("");```
```Term_IO_WriteInt(123);```
```Term_IO_WriteHex(0xDEADBEEF);```

**HOW TO RUN THIS OS** (premade ISO, with the pseudo-intro.):
1. Install QEMU, specfically the x86 emulator one (There are a lot of guides on this, don't be lazy, look it up.)
2. Download the repo [here](https://github.com/nideraanth/SampaguitaOS/releases/tag/versionVGA) and put it into a folder called ```SampaguitaOS``` (to be sure) and copy all the repo files into the folder.
3. Use ```qemu-system-i386 -cdrom SampaguitaOS.iso``` in the ```SampaguitaOS``` directory.


How to run and modify this OS (assuming you are using a Linux distribution or Windows Subsystem for Linux (WSL) ):
1. Install QEMU (There are a lot of guides on this, don't be lazy, look it up.)
2. Install a cross compiler. **NOTE:** if you skip this step, the OS woudn't compile at all.
3. Download the repo and put it into a folder called ```SampaguitaOS``` (to be sure) and copy all the repo files into the folder.
4. Make any changes you like.
5. Run the upd.sh in the newly created ```SampaguitaOS``` folder (**NOTE:** DO this every time you update the OS.)
6. Use ```qemu-system-i386 -cdrom SampaguitaOS.iso``` in the ```SampaguitaOS``` directory.



  Copyright (C) [2025] [Ronald A. N. Nidera]
 
  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  any later version.
 
  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
  GNU General Public License for more details.
 
   You should have received a copy of the GNU General Public License
   along with this program. If not, see [http://www.gnu.org/licenses/](http://www.gnu.org/licenses/).
 
Testing Safety: IT IS HIGHLY RECOMENDED THAT YOU ONLY TEST THIS OS WITHIN VIRTUAL MACHINES (like QEMU) OR ON DEDICATED, NON-ESSENTIAL HARDWARE.
