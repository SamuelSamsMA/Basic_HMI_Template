#include "mcc_generated_files/mcc.h"
#include "sipo_reg595.h"
#include "matrix_keyboard_5x4.h"



char KEYBOARD_scan(void)
{
	const char keys[5][4] = {
		{KEY_LEFT,	KEY_0,	KEY_RIGHT,	KEY_ENT},
		{KEY_7,		KEY_8,	KEY_9,		KEY_ESC},
		{KEY_4,		KEY_5,	KEY_6,		KEY_DOWN},
		{KEY_1,		KEY_2,	KEY_3,		KEY_UP},
		{KEY_F1,	KEY_F2,	KEY_HASH,	KEY_ASTERISK}};
	
	char row;
	switch(PORTC & 0x87)
	{
	case 0x86:	row = 0;	break;
	case 0x85:	row = 1;	break;
	case 0x83:	row = 2;	break;
	case 0x07:	row = 3;	break;
	default:
		return ERROR_KEY;		// Invalid data
	}

	// Desactiva las interrupciones de flanco negativo para las filas.
	IOCCN = 0;

	// Enciende cada una de las columnas hasta que encuentra aquella
	// que vuelve a dejar todas las filas en estado lógico 1.
	char col, key;
	for (col = 0; col < 5; col++)
	{
		switch (col)
		{
		case 0:
			KEYBOARD_COL1_SetHigh(); break;
		case 1:
			KEYBOARD_COL2_SetHigh(); break;
		case 2:
			KEYBOARD_COL3_SetHigh(); break;
		case 3:
			KEYBOARD_COL4_SetHigh(); break;
		case 4:
			KEYBOARD_COL5_SetHigh(); break;
		}
		
		if ((PORTC | 0x78) == 0xFF)
		{ /* Column found */
			key = keys[col][row];
			break;
		}
	}

	// Regresa todas las columnas a su nivel lógico original
	KEYBOARD_COL1_SetLow();
	KEYBOARD_COL2_SetLow();
	KEYBOARD_COL3_SetLow();
	KEYBOARD_COL4_SetLow();
	KEYBOARD_COL5_SetLow();

	// Activa nuevamente las interrupciones
	IOCCN = 0x87;
	return key;
}
