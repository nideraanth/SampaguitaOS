#include "vga.h"
#include <stdbool.h>

#include "misc/intro.h"

void kernel_main(void) 
{
	Term_IO_Init();
	
	ShowPseudoIntro();
	//PanicTest();
	while(1){__asm__("hlt");}
}
