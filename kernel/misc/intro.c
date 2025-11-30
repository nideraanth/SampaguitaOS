#include "intro.h"
#include "../vga.h"

// INITIALIZE THE TERMINAL IF NEEDED.
//  demo pseudo-intro 
void ShowPseudoIntro(void)
{
    Term_IO_SetColor(vga_entry_color(VGA_COLOR_WHITE, VGA_COLOR_BLUE));
	
	Term_IO_WriteStr(" FILE  TERM  OPEN  DBGR     SampaguitaOS V0,1              25 / 11 / 2025  [ X ]\n");
	Term_IO_SetColor(vga_entry_color(VGA_COLOR_WHITE, VGA_COLOR_BLACK));
	Term_IO_WriteStr(">  hello im Ronald A.N. Nidera and i created the floratekRev1 kernel and modules\n");
	Term_IO_WriteStr("   which this current OS is based on.                                           \n");
	Term_IO_WriteStr(" == ABOUT ME ==                                                                 \n");
	Term_IO_WriteStr("> i was only around 13 years old when i started this project (current date on   \n");
	Term_IO_WriteStr("  the pseudo-taskbar)                                                           \n");
	Term_IO_WriteStr("> i self-taught myself C and followed the OSDev wiki on where I should start.   \n");
	Term_IO_WriteStr("  I bailed out of the OSDev wiki because the wiki makes a guide mainly for      \n");
	Term_IO_WriteStr("  microkernels or in simple words, an OS that uses kernel-user abstractions,    \n");
	Term_IO_WriteStr("  which is a pain to implement, That's why I created SampaguitaOS to run        \n");
	Term_IO_WriteStr("  entirely in ring 0 (kernel mode). This design choice eliminates those         \n");
	Term_IO_WriteStr("  abstractions,  making the OS simple to tinker with and giving me              \n");
	Term_IO_WriteStr("  (and you, yes you) complete control over everything it does.                  \n");
	Term_IO_SetColor(vga_entry_color(VGA_COLOR_WHITE, VGA_COLOR_BLACK));
}

void TestStr(void)
{
	Term_IO_WriteStr("ABCDEFGHIJKLMNOPQRSTUVWXYZ\n");
	Term_IO_WriteStr("abcdefghijklmnopqrstuvwxyz\n");
	Term_IO_WriteStr("~!@#$%%^&*()-_=+{}[]\\''""/<>,.:;`");
	Term_IO_PutChar('\n');
}

void TestInt(void)
{
		long positive_val = 12345;
    long negative_val = -9876;
    long zero_val     = 0;
    long large_val    = 2147483647;

	// positive decimal
    Term_IO_WriteStr("Pos: ");
    Term_IO_WriteInt(positive_val);
    Term_IO_PutChar('\n');

    // negative decimal
    Term_IO_WriteStr("Neg: ");
    Term_IO_WriteInt(negative_val);
    Term_IO_PutChar('\n');

    // zero
    Term_IO_WriteStr("Zero: ");
    Term_IO_WriteInt(zero_val);
    Term_IO_PutChar('\n');

    // large val
    Term_IO_WriteStr("Max: ");
    Term_IO_WriteInt(large_val);
    Term_IO_PutChar('\n');
}

void TestHex(void)
{
	Term_IO_WriteStr("Kernel Startup Address: ");
    Term_IO_WriteHex(0x100000); // Should print 0x100000
    Term_IO_PutChar('\n');

    Term_IO_WriteStr("VGA Memory Base: ");
    Term_IO_WriteHex(0xB8000); // Should print 0xB8000
    Term_IO_PutChar('\n');

    Term_IO_WriteStr("Error Code: ");
    Term_IO_WriteHex(0xDEADBEEF); // Should print 0xDEADBEEF
    Term_IO_PutChar('\n');
}

void PanicTest(void)
{
    Term_IO_WriteStr("ABCDEFGHIJKLMNOPQRSTUVWXYZ\n");
	Term_IO_WriteStr("abcdefghijklmnopqrstuvwxyz\n");
	Term_IO_WriteStr("~!@#$%%^&*()-_=+{}[]\\''""/<>,.:;`");
	Term_IO_PutChar('\n');

    	long positive_val = 12345;
    long negative_val = -9876;
    long zero_val     = 0;
    long large_val    = 2147483647;

	// positive decimal
    Term_IO_WriteStr("Pos: ");
    Term_IO_WriteInt(positive_val);
    Term_IO_PutChar('\n');

    // negative decimal
    Term_IO_WriteStr("Neg: ");
    Term_IO_WriteInt(negative_val);
    Term_IO_PutChar('\n');

    // zero
    Term_IO_WriteStr("Zero: ");
    Term_IO_WriteInt(zero_val);
    Term_IO_PutChar('\n');

    // large val
    Term_IO_WriteStr("Max: ");
    Term_IO_WriteInt(large_val);
    Term_IO_PutChar('\n');

    	Term_IO_WriteStr("Kernel Startup Address: ");
    Term_IO_WriteHex(0x100000); // Should print 0x100000
    Term_IO_PutChar('\n');

    Term_IO_WriteStr("VGA Memory Base: ");
    Term_IO_WriteHex(0xB8000); // Should print 0xB8000
    Term_IO_PutChar('\n');

    Term_IO_WriteStr("Error Code: ");
    Term_IO_WriteHex(0xDEADBEEF); // Should print 0xDEADBEEF
    Term_IO_PutChar('\n');
}