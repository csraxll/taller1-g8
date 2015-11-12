/*
 * switches.c
 *
 *  Created on: 28/10/2015
 *      Author: zorito1994
 */

#include "ciaaPOSIX_stdio.h"  /* <= device handler header */
#include "ciaaPOSIX_string.h" /* <= string header */
#include "gpio.h"

#define NUM_VELOCIDADES 3

static int32_t file_in;
static uint8_t inputs = 0;
static uint8_t cambiar_mensaje = 0;
static uint8_t desplazar_izquierda = 1;
static uint8_t small_size = 0;
static uint8_t velocidad = 2;

void Switches_InicializarSwitches (void) {
	file_in = ciaaPOSIX_open ("/dev/dio/in/0", O_RDONLY);
}

void Switches_Polling (void) {
	ciaaPOSIX_read (file_in, &inputs, 1);
	if ((inputs & 0x01) == 1) {
		cambiar_mensaje = 1;
	}
	else if ((inputs & 0x02) == 1) {
		desplazar_izquierda ^= 0x01;
	}
	else if ((inputs & 0x04) == 1) {
		small_size ^= 0x01;
	}
	else if ((inputs & 0x08) == 1) {
		velocidad = ((velocidad + 1) % (NUM_VELOCIDADES - 1)) + 1;
	}
}

uint8_t Switches_GetCambiarMensaje (void) {
	return cambiar_mensaje;
}

uint8_t Switches_GetDesplazarIzquierda (void) {
	return desplazar_izquierda;
}

uint8_t Switches_GetSmallSize (void) {
	return small_size;
}

uint8_t Switches_GetVelocidad (void) {
	return velocidad;
}

void Switches_MensajeCambiado (void) {
	cambiar_mensaje = 0;
}
