/* 
 * File:   menu.h
 * Author: Samuel Muñoz Aguilar
 *
 * Created on April 3, 2024
 */

#ifndef MENU_H
#define	MENU_H

#include <xc.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <limits.h>
#include "rtc_ds3231.h"
#include "lcd_192x64_text.h"
#include "matrix_keyboard_5x4.h"


//
// Banderas para actualizar elementos estáticos de la pantalla
//
#define PAINT_TIME				0x0001
#define PAINT_DATE				0x0002
#define PAINT_TITLE				0x0004
#define PAINT_OPTIONS			0x0008
#define PAINT_INDICATOR			0x0010
#define PAINT_VALUES			0x0020
#define PAINT_ALL				0xFFFF
#define NO_PAINT				0x0000
#define PAINT_DATE_TIME			(PAINT_DATE|PAINT_TIME)


//
// Types of text strings to show when editing a boolean value
//
typedef enum {
	SI_NO, ENCENDIDO_APAGADO, ON_OFF, AUTO_MANUAL
} bool_string;


/****************************************************************************
 *							 EDIT_TIME_PARAMS
 * Descripción:
 *		Datos necesarios para iniciar una edición de fecha u hora en el menú
 * Variables:
 *		TIME initialValue:
 *			Valor inicial de la fecha u hora a editar.
 *		uint8_t cx, cy:
 *			Coordenadas en pantalla del extremo derecho del texto a mostrar.
 *		void (*saveChanges)(TIME*):
 *			Puntero a la función que guarde el nuevo valor en memoria.
 *		bool date_nTime:
 *			Tipo de dato a editar -> true: fecha / false: hora.
 ***************************************************************************/
typedef struct {
	TIME initialValue;
    uint8_t cx, cy;
	void (*saveChanges)(TIME*);
	bool date_nTime;
} EDIT_TIME_PARAMS;


/****************************************************************************
 *							 EDIT_INT_PARAMS
 * Descripción:
 *		Datos necesarios para iniciar una edición de número entero en el menú
 * Variables:
 *		int initialValue:
 *			Valor inicial del número a editar.
 *		int cx, cy:
 *			Coordenadas en pantalla del extremo derecho del texto a mostrar.
 *		void (*saveChanges)(int*):
 *			Puntero a la función que guarde el nuevo valor en memoria.
 *		int vmax:
 *			Valor máximo que se podrá ingresar.
 *		int vmin:
 *			Valor mínimo que se podrá ingresar.
 ***************************************************************************/
typedef struct {
	int initialValue;
	uint8_t cx, cy;
	void (*saveChanges)(int*);
	int vmax, vmin;
} EDIT_INT_PARAMS;


/****************************************************************************
 *							 EDIT_BOOL_PARAMS
 * Descripción:
 *		Datos necesarios para iniciar una edición de dato booleano en el menú
 * Variables:
 *		bool initialValue:
 *			Valor lógico inicial.
 *		uint8_t cx, cy:
 *			Coordenadas en pantalla del extremo derecho del texto a mostrar.
 *		void (*saveChanges)(bool):
 *			Puntero a la función que guarde el nuevo valor en memoria.
 *		bool_string text:
 *			Este valor indica a la función las cadenas de texto
 *			predeterminadas que deberá imprimir en pantalla para indicar
 *			el estado lógico de la variable.
 ***************************************************************************/
typedef struct {
	bool initialValue;
	uint8_t cx, cy;
	void (*saveChanges)(bool);
	bool_string text;
} EDIT_BOOL_PARAMS;


//
// Cada una de estas funciones representa un submenú por el cual se
// puede navegar.
//
void MENU_start(unsigned char key, unsigned int render);

void MENU_root(unsigned char key, unsigned int render);

void MENU_dateTime(unsigned char key, unsigned int render);


//
// Funciones dedicadas a la edición de distintos tipos de datos
// desde el teclado
//
void EDIT_integer(unsigned char key, void* p);

void EDIT_time(unsigned char key, void* p);

void EDIT_bool(unsigned char key, void* p);


//
// Funciones especiales para imprimir tipos de datos especiales que
// la función 'printf' no soporta.
//
void PRINT_bool_rightAlign(bool logicValue, bool_string text,
		uint8_t cx, uint8_t cy);

void PRINT_int_rightAlign(int value, uint8_t cx, uint8_t cy);

#endif	/* MENU_H */

