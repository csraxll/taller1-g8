/*
 * reloj.c
 *
 *  Created on: 30/10/2015
 *      Author: zorito1994
 */
#include "puertos.h"
#include "interfaz.h"
#include "matriz.h"
#include "switches.h"

#define COLUMNA_OFF 0
#define COLUMNA_ON 1

static uint8_t matriz_leds[NUM_FILAS][NUM_COLUMNAS];

static void Registros_ActivarLatch (void) {
	Puertos_EscribirGPIO3 (1);
}

static void Registros_DesactivarLatch (void) {
	Puertos_EscribirGPIO3 (0);
}

static void Registros_DSColumnas (uint8_t indice_columna) {
	if (indice_columna == 0)
		Puertos_EscribirGPIO7 (COLUMNA_ON);
	else
		Puertos_EscribirGPIO7 (COLUMNA_OFF);
}

static void Registros_DSFilas (uint8_t indice_fila, uint8_t indice_columna) {
	Puertos_EscribirGPIO5 (matriz_leds[NUM_FILAS-1-indice_fila][indice_columna]);
}

static void Registros_Columnas (uint8_t indice_columna) {
uint8_t reloj_columnas;
	reloj_columnas = 0;
	Puertos_EscribirGPIO8 (reloj_columnas);
	Registros_DSColumnas (indice_columna);
	reloj_columnas = 1;
	Puertos_EscribirGPIO8 (reloj_columnas);
}

static void Registros_Filas (uint8_t indice_columna, uint8_t indice_fila) {
uint8_t reloj_filas;
	reloj_filas = 0;
	Puertos_EscribirGPIO2 (reloj_filas);
	Registros_DSFilas (indice_fila, indice_columna);
	reloj_filas = 1;
	Puertos_EscribirGPIO2 (reloj_filas);
}

void Registros_EscribirMatriz (uint8_t matriz[NUM_FILAS][NUM_COLUMNAS]) {
uint8_t i, j;
	for (i = 0; i < NUM_FILAS; ++i) {
		for (j = 0; j < NUM_COLUMNAS; ++j)
			matriz_leds[i][j] = matriz[i][j];
	}
}

void Registros_ActivarColumna (void) {
static uint8_t indice_columna = 0;
uint8_t i;
	Registros_DesactivarLatch();
	Registros_Columnas (indice_columna);
	for (i = 0; i < NUM_FILAS; ++i)
		Registros_Filas (indice_columna, i);
	Registros_ActivarLatch();
	indice_columna = (indice_columna + 1) % NUM_COLUMNAS;
}
