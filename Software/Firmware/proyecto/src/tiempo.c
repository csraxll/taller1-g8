/*
 * tiempo.c
 *
 *  Created on: 25/12/2015
 *      Author: Facu
 */

#include "tiempo.h"

#define BUS_CLOCK 8000

/*------------------------------------------------------------*
función Tiempo_Delay_ms: retarda la ejecución del programa durante un tiempo determinado
parámetro de entrada: tiempo de retardo en microsegundos (1 milisegundo = 1000 microsegundos). Es un valor entero sin signo de 8 bits (unsigned char)
*------------------------------------------------------------*/
void Tiempo_Delay_ms (unsigned char tiempo) {
unsigned int temp;
	for(;tiempo;tiempo--) for(temp=(BUS_CLOCK/23);temp;temp--);
}


