/*
 * reloj.c
 *
 *  Created on: 30/10/2015
 *      Author: zorito1994
 */
#include "gpio.h"
#include "interfaz.h"
#include "matriz.h"

#define DS_COLUMNAS 1
#define DS_FILAS 0

static uint8_t indice_fila = 0;
static uint8_t indice_columna = 0;
static uint8_t matriz[NUM_FILAS][NUM_COLUMNAS];
static uint8_t fin_fila = 1;
static uint8_t fin_caracter = 1;

static void Registros_STCPActivar (void) {
	GPIO_EscribirGPIO2 (1);
}

static void Registros_STCPDesactivar (void) {
	GPIO_EscribirGPIO2 (0);
}

static void Registros_DSColumnas (void) {
	if (fin_fila == 0) {
		if (indice_fila == 0) {
			Registros_STCPDesactivar();
		}
		if (indice_columna != NUM_COLUMNAS) {
			GPIO_EscribirGPIO3 (matriz[indice_fila][NUM_COLUMNAS-1-indice_columna]^0x01);
			++indice_columna;
		}
		else {
			fin_fila = 1;
			Registros_STCPActivar();
			if (++indice_fila == NUM_FILAS) {
				fin_caracter = 1;
			}
		}
	}
	else
		GPIO_EscribirGPIO3 (DS_COLUMNAS);
}

static void Registros_DSFilas (void) {
	if (fin_caracter == 1) {
		Matriz_GetMatriz (matriz);
		GPIO_EscribirGPIO0 (1);
		fin_caracter = 0;
		indice_fila = 0;
	}
	else {
		GPIO_EscribirGPIO0 (DS_FILAS);
	}
	if (fin_fila == 1) {
		indice_columna = 0;
		fin_fila = 0;
	}
}

void Registros_SHCP (void) {
uint8_t i;
uint8_t reloj_columnas;
uint8_t reloj_filas;
	reloj_filas = 0;
	GPIO_EscribirGPIO1 (reloj_filas);
	Registros_DSFilas();
	for (i = 0; i < NUM_COLUMNAS; ++i) {
		reloj_columnas = 0;
		GPIO_EscribirGPIO4 (reloj_columnas);
		Registros_DSColumnas();
		reloj_columnas = 1;
		GPIO_EscribirGPIO4 (reloj_columnas);
	}
	reloj_filas = 1;
	GPIO_EscribirGPIO1 (reloj_filas);
	Registros_DSColumnas();
}
