#include "mcc_generated_files/mcc.h"
#include "menu.h"
#include "main.h"


extern volatile TASKS tasks;
extern APP_DATA appData;


void saveInteger(int* value)
{
	appData.LEDdutyCycle = *value;
	tasks.controlProcess = 1;
}

void saveBool(bool value)
{
	appData.LEDstate = value;
	tasks.controlProcess = 1;
}

void saveInEEPROM(int* value)
{
	uint8_t buf[EEPROM_PAGE_SIZE];
	buf[0] = (uint8_t)((*value & 0xFF00) >> 8);
	buf[1] = (uint8_t)(*value & 0x00FF);
	
	EEPROM_writePage(0, buf);
}

void MENU_start(unsigned char key, unsigned int render)
{
	static unsigned char indicator = 1;
	unsigned char prevIndicator = indicator;
	const uint8_t nOptions = 4;
	const char* strOptions[4] = {
		"Estado:",
		"% Intensidad:",
		"Guardar valor:",
		"Leer valor:"
	};
	
	switch (key)
	{
	case NULL_KEY:
		break;
		
	case KEY_F1:
		appData.currentMenu = MENU_root;
		GLCD_clear();
		tasks.updateScreen = 1;
		return;
		
	case KEY_UP:
		if (indicator > 1)
		{ /* Sube al apuntador una posición */
			indicator--;
			render |= PAINT_INDICATOR;
		}
		break;
		
	case KEY_DOWN:
		if (indicator < nOptions)
		{ /* Baja al apuntador una posición */
			indicator++;
			render |= PAINT_INDICATOR;
		}
		break;
		
	case KEY_ENT:
		switch (indicator)
		{
		case 1:
		{	 /* Inicia edición del estado lógico del LED */
			EDIT_BOOL_PARAMS ebp;
			ebp.cx = 32;
			ebp.cy = 3;
			ebp.initialValue = appData.LEDstate;
			ebp.text = ENCENDIDO_APAGADO;
			ebp.saveChanges = saveBool;

			appData.currentEdit = EDIT_bool;
			EDIT_bool(NULL_KEY, &ebp);
		}
			break;
		case 2:
		{	 /* Inicia edición de la intensidad del LED */
			EDIT_INT_PARAMS eip;
			eip.cx = 32;
			eip.cy = 4;
			eip.initialValue = appData.LEDdutyCycle;
			eip.vmax = 499;
			eip.vmin = 0;
			eip.saveChanges = saveInteger;

			appData.currentEdit = EDIT_integer;
			EDIT_integer(NULL_KEY, &eip);
		}
			break;
		case 3:
		{
			EDIT_INT_PARAMS eip;
			eip.cx = 32;
			eip.cy = 5;
			eip.initialValue = 0;
			eip.vmax = 32767;
			eip.vmin = 0;
			eip.saveChanges = saveInEEPROM;

			appData.currentEdit = EDIT_integer;
			EDIT_integer(NULL_KEY, &eip);
		}
			break;
		case 4:
		{
			uint8_t buffer[EEPROM_PAGE_SIZE];
			EEPROM_readPage(0, buffer);
			
			int value = ((int)buffer[0] << 8) + (int)buffer[1];
			PRINT_int_rightAlign(value, 32, 6);
		}
			break;
		}
		break;
	
	default:
		break;
	}
	
	
	if (render & PAINT_TIME)
	{
		GLCD_moveCursor(5, 1);
		printf("%02d:%02d:%02d", appData.currentTime.hours,
				appData.currentTime.minutes,
				appData.currentTime.seconds);
	}
	if (render & PAINT_DATE)
	{
		GLCD_moveCursor(21, 1);
		printf("%02d/%02d/%02d", appData.currentTime.date,
				appData.currentTime.month,
				appData.currentTime.year);
	}
	if (render & PAINT_OPTIONS)
	{
		GLCD_moveCursor(2, 3);
		printf("%s", strOptions[0]);
		PRINT_bool_rightAlign(appData.LEDstate, ENCENDIDO_APAGADO, 32, 3);
		
		GLCD_moveCursor(2, 4);
		printf("%s", strOptions[1]);
		PRINT_int_rightAlign(appData.LEDdutyCycle, 32, 4);
		
		GLCD_moveCursor(2, 5);
		printf("%s", strOptions[2]);
		
		GLCD_moveCursor(2, 6);
		printf("%s", strOptions[3]);
	}
	if (render & PAINT_INDICATOR)
	{
		GLCD_moveCursor(1, prevIndicator + 2);
		GLCD_printChar(' ');
		GLCD_moveCursor(1, indicator + 2);
		GLCD_printChar('>');
	}
}


void MENU_root(unsigned char key, unsigned int render)
{
	// Indicator es la flecha que indica la opción activa para la navegación
	// en el menú.
	static unsigned char indicator = 1;
	unsigned char prevIndicator = indicator;
	const int nOptions = 2;
	const char* strOptions[2] = {
		"Cambiar fecha y hora",
		"Regresar"
	};
	
	switch (key)
	{
	case NULL_KEY:
		break;
		
	case KEY_ESC:
		appData.currentMenu = MENU_start;
		tasks.updateScreen = 1;
		GLCD_clear();
		indicator = 1;
		return;
		
	case KEY_UP:
		if (indicator > 1)
		{ /* Sube al apuntador una posición */
			indicator--;
			render |= PAINT_INDICATOR;
		}
		break;
		
	case KEY_DOWN:
		if (indicator < nOptions)
		{ /* Baja al apuntador una posición */
			indicator++;
			render |= PAINT_INDICATOR;
		}
		break;
		
	case KEY_ENT:
		switch (indicator)
		{
		case 1:
			appData.currentMenu = MENU_dateTime;
			break;
		case 2:
			appData.currentMenu = MENU_start;
			break;
		}
		tasks.updateScreen = 1;
		GLCD_clear();
		indicator = 1;
		break;
	
	default:
		break;
	} /* switch (key) */
	
	if (render & PAINT_TITLE)
	{
		GLCD_moveCursor(10, 1);
		printf("MENU PRINCIPAL");
	}
	
	if (render & PAINT_OPTIONS)
	{
		GLCD_moveCursor(2, 2);
		printf("%s", strOptions[0]);
		GLCD_moveCursor(2, 3);
		printf("%s", strOptions[1]);
//		GLCD_moveCursor(2, 4);
//		printf("%s", strOptions[2]);
//		GLCD_moveCursor(2, 5);
//		printf("%s", strOptions[3]);
	}
	
	if (render & PAINT_INDICATOR)
	{
		GLCD_moveCursor(1, prevIndicator + 1);
		GLCD_printChar(' ');
		GLCD_moveCursor(1, indicator + 1);
		GLCD_printChar('>');
	}
}


void MENU_dateTime(unsigned char key, unsigned int render)
{
	static unsigned char indicator = 1;
	unsigned char prevIndicator = indicator;
	const int nOptions = 3;
	const char* strOptions[3] = {
		"Hora:",
		"Fecha:",
		"Regresar"
	};
	
	switch (key)
	{
	case NULL_KEY:
		break;
		
	case KEY_ESC:
		appData.currentMenu = MENU_root;
		tasks.updateScreen = 1;
		GLCD_clear();
		indicator = 1;
		return;
		
	case KEY_UP:
		if (indicator > 1)
		{ /* Sube al apuntador una posición */
			indicator--;
			render |= PAINT_INDICATOR;
		}
		break;
		
	case KEY_DOWN:
		if (indicator < nOptions)
		{ /* Baja al apuntador una posición */
			indicator++;
			render |= PAINT_INDICATOR;
		}
		break;
		
	case KEY_ENT:
		switch (indicator)
		{
		case 1:
		{ /* Inicia edición de la hora actual */
			EDIT_TIME_PARAMS eTime;
			eTime.cx = 32;
			eTime.cy = 2;
			eTime.saveChanges = RTC_writeHMS;
			eTime.date_nTime = false;
			eTime.initialValue.hours = appData.currentTime.hours;
			eTime.initialValue.minutes = appData.currentTime.minutes;
			eTime.initialValue.seconds = appData.currentTime.seconds;
			
			appData.currentEdit = EDIT_time;
			EDIT_time(NULL_KEY, &eTime);
		}
			break;
		case 2:
		{ /* Inicia edición de la fecha actual */
			EDIT_TIME_PARAMS eTime;
			eTime.cx = 32;
			eTime.cy = 3;
			eTime.saveChanges = RTC_writeDMY;
			eTime.date_nTime = true;
			eTime.initialValue.date = appData.currentTime.date;
			eTime.initialValue.month = appData.currentTime.month;
			eTime.initialValue.year = appData.currentTime.year;
			
			appData.currentEdit = EDIT_time;
			EDIT_time(NULL_KEY, &eTime);
		}
			break;
		case 3:
			appData.currentMenu = MENU_root;
			tasks.updateScreen = 1;
			GLCD_clear();
			indicator = 1;
			break;
		}
		break;
		
	default:
		break;
	} /* switch (key) */
	
	if (render & PAINT_TITLE)
	{
		GLCD_moveCursor(7, 1);
		printf("CAMBIAR FECHA Y HORA");
	}
	
	if (render & PAINT_OPTIONS)
	{
		GLCD_moveCursor(2, 2);
		printf("%s", strOptions[0]);
		GLCD_moveCursor(25, 2);
		printf("%02d:%02d:%02d", appData.currentTime.hours,
				appData.currentTime.minutes,
				appData.currentTime.seconds);
		GLCD_moveCursor(2, 3);
		printf("%s", strOptions[1]);
		GLCD_moveCursor(25, 3);
		printf("%02d/%02d/%02d", appData.currentTime.date,
				appData.currentTime.month,
				appData.currentTime.year);
		GLCD_moveCursor(2, 4);
		printf("%s", strOptions[2]);
	}
	
	if (render & PAINT_INDICATOR)
	{
		GLCD_moveCursor(1, prevIndicator + 1);
		GLCD_printChar(' ');
		GLCD_moveCursor(1, indicator + 1);
		GLCD_printChar('>');
	}
}


void EDIT_integer(unsigned char key, void* p)
{
	EDIT_INT_PARAMS* eip = (EDIT_INT_PARAMS*)p;
	static int valorTemporal;
	static EDIT_INT_PARAMS ini;
	const int nDigitosMax = 5;		// Valor máximo permitido: 32767
	
	if (eip != NULL)
	{ /* Configuración de una nueva edición */
		valorTemporal = 0;
		
		ini.cx = eip->cx;
		ini.cy = eip->cy;
		ini.saveChanges = eip->saveChanges;
		ini.initialValue = eip->initialValue;
		ini.vmax = eip->vmax;
		ini.vmin = eip->vmin;
		
		// Deja al puntero en la posición de las unidades para inidicar que se
		// está ejecutando una edición de valor.
		GLCD_movePointer(ini.cx, ini.cy);
		GLCD_turnOnPointer();
	} /* Configuración de una nueva edición */
	
	switch (key)
	{
	case NULL_KEY:
		break;
		
	case KEY_ESC:
		appData.currentEdit = NULL;
		GLCD_turnOffPointer();
		valorTemporal = ini.initialValue;
		break;
		
	case KEY_ENT:
		appData.currentEdit = NULL;
		GLCD_turnOffPointer();
		ini.saveChanges(&valorTemporal);
		break;
		
	case KEY_LEFT:	// Borrar el último dígito
		valorTemporal /= 10;
		break;
		
	case KEY_1: case KEY_2: case KEY_3: case KEY_4: case KEY_5:
	case KEY_6: case KEY_7: case KEY_8: case KEY_9: case KEY_0:
	{
		long vProximo = (valorTemporal * 10L) + (long)key;
		
		if ((vProximo <= (long)ini.vmax) && (vProximo >= (long)ini.vmin))
			valorTemporal = (int)vProximo;
	}
		break;
	} /* switch (key) */
	
	// Limpia el espacio para escribir una nueva cifra
	GLCD_moveCursor(ini.cx - nDigitosMax + 1, ini.cy);
	printf("     ");

	PRINT_int_rightAlign(valorTemporal, ini.cx, ini.cy);
}


void EDIT_time(unsigned char key, void* p)
{
	EDIT_TIME_PARAMS* etp = (EDIT_TIME_PARAMS*)p;
    static uint8_t temp[3], vmax[3];
	static EDIT_TIME_PARAMS ini;
	static uint8_t iCursor;
	
	if (etp != NULL)
	{ /* Configuración de una nueva edición */
		ini.cx = etp->cx;
		ini.cy = etp->cy;
		ini.saveChanges = etp->saveChanges;
        ini.date_nTime = etp->date_nTime;
        
        if(ini.date_nTime)
        {
			temp[0] = ini.initialValue.date = etp->initialValue.date;
			temp[1] = ini.initialValue.month = etp->initialValue.month;
			temp[2] = ini.initialValue.year = etp->initialValue.year;
			// Valores máximos para fecha, mes y año respectivamente
			vmax[0] = 31;
			vmax[1] = 12;
			vmax[2] = 99;
        }
		else
		{
			temp[0] = ini.initialValue.hours = etp->initialValue.hours;
			temp[1] = ini.initialValue.minutes = etp->initialValue.minutes;
			temp[2] = ini.initialValue.seconds = etp->initialValue.seconds;
			// Valores máximos para horas, minutos y segundos respectivamente
			vmax[0] = 23;
			vmax[1] = 59;
			vmax[2] = 59;
		}
		iCursor = 0;
		GLCD_turnOnPointer();
	} /* Configuración de una nueva edición */
	
	switch(key)
	{
	case NULL_KEY:
		break;
			
	case KEY_ESC:
		appData.currentEdit = NULL;
		GLCD_turnOffPointer();
		if (ini.date_nTime)
		{	/* Restaura la fecha inicial */
			temp[0] = ini.initialValue.date;
			temp[1] = ini.initialValue.month;
			temp[2] = ini.initialValue.year;
		}	/* Restaura la fecha inicial */
		else
		{	/* Restaura la hora inicial */
			temp[0] = ini.initialValue.hours;
			temp[1] = ini.initialValue.minutes;
			temp[2] = ini.initialValue.seconds;
		}	/* Restaura la hora inicial */
		break;
		
	case KEY_ENT:
		appData.currentEdit = NULL;
		GLCD_turnOffPointer();
		if (ini.date_nTime)
		{
			TIME t;
			t.date = temp[0];
			t.month = temp[1];
			t.year = temp[2];
			ini.saveChanges(&t);
		}
		else
		{
			TIME t;
			t.hours = temp[0];
			t.minutes = temp[1];
			t.seconds = temp[2];
			ini.saveChanges(&t);
		}
		break;
		
	case KEY_LEFT:
		(iCursor > 0) ? (iCursor--) : (iCursor = 5);
		break;
		
	case KEY_RIGHT:
		(iCursor < 5) ? (iCursor++) : (iCursor = 0);
		break;
		
	case KEY_0: case KEY_1: case KEY_2: case KEY_3: case KEY_4:
	case KEY_5: case KEY_6: case KEY_7: case KEY_8: case KEY_9:
	{
		uint8_t vProximo;
		uint8_t indice = iCursor / 2;
		uint8_t unidades = temp[indice] % 10;
		uint8_t decenas = temp[indice] / 10;
		
		if ((iCursor % 2) == 0)
		{
			uint8_t decenasMax = vmax[indice] / 10;
			if (key == decenasMax)
				vProximo = (10 * key);
			else
				vProximo = (10 * key) + unidades;
		}
		else
		{
			vProximo = (decenas * 10) + key;
		}
		
		if (vProximo <= vmax[indice])
		{
			temp[indice] = vProximo;
			(iCursor < 5) ? (iCursor++) : (iCursor = 0);
		}
	}
		break;
	} // switch(key)
	
	const uint8_t sizeOfStr = 8;
	char separador;
	(ini.date_nTime == true) ? (separador = '/') : (separador = ':');

	GLCD_moveCursor(ini.cx - sizeOfStr + 1, ini.cy);

	printf("%02d%c%02d%c%02d", temp[0], separador,
							   temp[1], separador,
							   temp[2]);
	
	// Mueve el apuntador en la posición que le corresponde
	uint8_t offset;
	switch(iCursor)
	{
		case 0: offset = 7; break; 
		case 1: offset = 6; break; 
		case 2: offset = 4; break;
		case 3: offset = 3; break;
		case 4: offset = 1; break;
		case 5: offset = 0; break;
	}
	GLCD_movePointer(ini.cx - offset, ini.cy);
}


void EDIT_bool(unsigned char key, void* p)
{
	EDIT_BOOL_PARAMS* ebp = (EDIT_BOOL_PARAMS*)p;
	
	// Guarda el valor mientras se edita el dato, si se presiona ENTER,
	// este valor se guardará en memoria definitivamente
	static bool valorTemporal;
	// Guarda los datos necesarios para llevar a cabo la edición
	static EDIT_BOOL_PARAMS ini;
	
	if (ebp != NULL)
	{ /* Configuración de una nueva edición */
		ini.cx = ebp->cx;
		ini.cy = ebp->cy;
		ini.saveChanges = ebp->saveChanges;
		ini.initialValue = ebp->initialValue;
		ini.text = ebp->text;
		
		valorTemporal = ini.initialValue;
		
		GLCD_movePointer(ini.cx, ini.cy);
		GLCD_turnOnPointer();
	} /* Configuración de una nueva edición */
	
	switch (key)
	{
	case NULL_KEY:
		break;
		
	case KEY_ESC:
		appData.currentEdit = NULL;
		GLCD_turnOffPointer();
		valorTemporal = ini.initialValue;
		break;
		
	case KEY_ENT:
		appData.currentEdit = NULL;
		GLCD_turnOffPointer();
		ini.saveChanges(valorTemporal);
		break;
		
	case KEY_LEFT: case KEY_RIGHT:
		valorTemporal = !valorTemporal;
		break;
	} /* switch (key) */
	
	PRINT_bool_rightAlign(valorTemporal, ini.text, ini.cx, ini.cy);
}


const char* stringsForBool[4][2] = {
	{"Si",			"No"},
	{"Encendido",	"Apagado"},
	{"On",			"Off"},
	{"Auto",		"Manual"}};


void PRINT_bool_rightAlign(bool logicValue, bool_string text,
		uint8_t cx, uint8_t cy)
{
	char* stringToPrint = NULL;
	uint8_t prevStringLenght, currentStringLenght;
	
	if (logicValue)
	{
		stringToPrint = stringsForBool[text][0];
		currentStringLenght = strlen(stringsForBool[text][0]);
		prevStringLenght = strlen(stringsForBool[text][1]);
	}
	else
	{
		stringToPrint = stringsForBool[text][1];
		currentStringLenght = strlen(stringsForBool[text][1]);
		prevStringLenght = strlen(stringsForBool[text][0]);
	}
	
	// Limpia el texto anterior para escribir uno nuevo
	GLCD_moveCursor(cx - prevStringLenght + 1, cy);
	for (uint8_t i = 0; i < prevStringLenght; i++)
		GLCD_printChar(' ');
	
	// Escribe el texto correspondiente al valor booleano actual
	GLCD_moveCursor(cx - currentStringLenght + 1, cy);
	printf("%s", stringToPrint);
}


void PRINT_int_rightAlign(int value, uint8_t cx, uint8_t cy)
{
	char str[6];
	uint8_t bytesWritten = (uint8_t)sprintf(str, "%d", value);
	GLCD_moveCursor(cx - bytesWritten + 1, cy);
	printf("%s", str);
}
