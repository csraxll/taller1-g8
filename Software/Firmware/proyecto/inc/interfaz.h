/*
 * interfaz.h
 *
 *  Created on: 22/10/2015
 *      Author: zorito1994
 */

#ifndef INTERFAZ_H_
#define INTERFAZ_H_



#endif /* INTERFAZ_H_ */

#define NUM_FILAS 8			/* aquí es donde el programador deberá definir la cantidad de filas del cartel LED */
#define NUM_COLUMNAS 24		/* aquí es donde el programador deberá definir la cantidad de columnas del cartel LED */


void Interfaz_Inicializar (void);
uint8_t Interfaz_CantidadMensajes (void);
uint8_t Interfaz_LongitudMensaje (uint8_t indice);
const char * Interfaz_Mensaje (uint8_t indice);
