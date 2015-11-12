/*
 * interfaz.c
 *
 *  Created on: 22/10/2015
 *      Author: zorito1994
 */

#include "os.h"               /* <= operating system header */
#include "Os_Cfg.h"
#include "ciaaPOSIX_stdio.h"  /* <= device handler header */
#include "ciaaPOSIX_string.h" /* <= string header */
#include "ciaak.h"            /* <= ciaa kernel header */

#define CANTIDAD_MENSAJES 2		/* aquí es donde el programador deberá definir la cantidad de mensajes a mostrar */

const static char *mensajes[CANTIDAD_MENSAJES] = {"ABCDEFGHIJLMNOPQRSTUVWXYZ", "0123456789"};  /* aquí es donde el programador definirá los mensajes a mostrar */
static uint8_t long_mensajes[CANTIDAD_MENSAJES] = {0};

void Interfaz_Inicializar (void) {
uint8_t i;
uint8_t j = 0;
	for (i = 0; i < CANTIDAD_MENSAJES; ++i) {
		while (mensajes[i][j] != '\0') {
			++long_mensajes[i];
			++j;
		}
		j = 0;
	}
}

uint8_t Interfaz_CantidadMensajes (void) {
	return CANTIDAD_MENSAJES;
}

uint8_t Interfaz_LongitudMensaje (uint8_t indice) {
	return long_mensajes[indice];
}

const char * Interfaz_Mensaje (uint8_t indice) {
	return mensajes[indice];
}
