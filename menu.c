#include "mcc_generated_files/mcc.h"
#include "menu.h"
#include "main.h"


extern volatile TASKS tasks;
extern APP_DATA appData;


void saveInteger(int* value)
{
	appData.LEDdutyCycle = *value;
	PWM1_LoadDutyValue(*value);
}

void MENU_start(unsigned char key, unsigned int render)
{
	switch (key)
	{
	case KEY_F1:
		appData.currentMenu = MENU_root;
		GLCD_clear();
		tasks.updateScreen = 1;
		return;
	case KEY_F2:
	{
		EDIT_INT_PARAMS eip;
		eip.cx = 32;
		eip.cy = 3;
		eip.initialValue = appData.LEDdutyCycle;
		eip.vmax = 499;
		eip.vmin = 0;
		eip.saveChanges = saveInteger;
		
		appData.currentEdit = EDIT_integer;
		EDIT_integer(NULL_KEY, &eip);
	}
		break;
	default:
		break;
	}
	
	if (render & PAINT_TITLE)
	{
		GLCD_moveCursor(2, 3);
		printf("%% Intensidad:");
		char str[4];
		uint8_t bytesWritten = (uint8_t)sprintf(str, "%d", appData.LEDdutyCycle);
		GLCD_moveCursor(TOTAL_COLUMNS - bytesWritten + 1, 3);
		printf("%s", str);
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

	char cadena[6];
	uint8_t bytesEscritos = (uint8_t)sprintf(cadena, "%d", valorTemporal);
	// Escribe la nueva cifra con justificación derecha
	GLCD_moveCursor(ini.cx + 1 - bytesEscritos, ini.cy);
	printf("%d", valorTemporal);
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



