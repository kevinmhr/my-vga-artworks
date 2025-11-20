

/* ====================================
	coded by Mikolaj Feliks aka Majuma
	mail: majuma@wp.pl
	web: http://www.majuma.xt.pl
	all rights reserved
   ==================================== */


#define K_SPACE			0x39
#define K_ESCAPE		0x01
#define K_UPARROW		0x48
#define K_DOWNARROW		0x50
#define K_LEFTARROW		0x4b
#define K_RIGHTARROW	0x4d
#define K_RIGHTCTRL		0x1d
#define K_F9			0x43
#define K_F10			0x44
#define K_COMMA			0x33
#define K_PERIOD		0x34
#define K_TILDE			0x29

typedef unsigned char  byte;
typedef unsigned short word;
typedef unsigned long  dword;


void SetKeyboard(void);
void RestoreKeyboard(void);

void interrupt (*OldKbdInt)(void);
byte KeyTable[256];

//------------------------------------------------------------

void interrupt KbdInt(void) {
	byte c;

	c = inportb(0x60);
	outportb(0x20, 0x20);

	if (c & 0x80)
		KeyTable[c - 0x80] = 0;
	else
		KeyTable[c] = 1;
}

void SetKeyboard(void) {
	int i;

	for (i = 0; i < 256; i++) {
		KeyTable[i] = 0;
	}

	OldKbdInt = getvect(0x09);

	setvect(0x09, KbdInt);
}

void RestoreKeyboard(void) {
	setvect(0x09, OldKbdInt);
}
