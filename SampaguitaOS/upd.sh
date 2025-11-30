#!/bin/bash

CC=i686-elf-gcc
CFLAGS="-std=gnu99 -ffreestanding -O2 -Wall -Wextra -I."
LDFLAGS="-T linker.ld -ffreestanding -O2 -nostdlib -lgcc"

BUILD_DIR=build
ISO_DIR=isodir
TARGET=SampaguitaOS.bin
ISO_IMAGE=SampaguitaOS.iso

OBJS="$BUILD_DIR/boot.o $BUILD_DIR/floratek.o $BUILD_DIR/vga.o $BUILD_DIR/intro.o $BUILD_DIR/libc_string.o"

clean_project() {
    echo "Cleaning..."
    rm -rf $BUILD_DIR $ISO_DIR $ISO_IMAGE
    echo "Done."
}

if [ "$1" == "clean" ]; then
    clean_project
    exit 0
fi

mkdir -p $BUILD_DIR

echo "Compiling C files..."
$CC $CFLAGS -c kernel/floratek.c -o $BUILD_DIR/floratek.o
$CC $CFLAGS -c kernel/vga.c -o $BUILD_DIR/vga.o
$CC $CFLAGS -c kernel/misc/intro.c -o $BUILD_DIR/intro.o
$CC $CFLAGS -c kernel/libc/include/string.c -o $BUILD_DIR/libc_string.o

echo "Assembling boot.s..."
$CC $CFLAGS -c boot/boot.s -o $BUILD_DIR/boot.o

# Ensure ISO staging
mkdir -p $ISO_DIR/boot/grub

echo "Linking kernel..."
$CC $LDFLAGS -o $ISO_DIR/boot/$TARGET $OBJS
cp $ISO_DIR/boot/$TARGET $BUILD_DIR
echo "Copying GRUB config..."
cp grub.cfg $ISO_DIR/boot/grub/grub.cfg

echo "Building ISO with GRUB..."
grub-mkrescue -o $ISO_IMAGE $ISO_DIR

echo "Cleaning ISO staging directory..."
rm -rf $ISO_DIR
echo "Build complete."
