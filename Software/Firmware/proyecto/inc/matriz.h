/*
 * matriz.h
 *
 *  Created on: 22/10/2015
 *      Author: zorito1994
 */

#ifndef MATRIZ_H_
#define MATRIZ_H_



#endif /* MATRIZ_H_ */

#define NUM_FILAS 7			/* aquí es donde el programador deberá definir la cantidad de filas del cartel LED */
#define NUM_COLUMNAS 20		/* aquí es donde el programador deberá definir la cantidad de columnas del cartel LED */

#include "os.h"               /* <= operating system header */
#include "Os_Cfg.h"
#include "ciaaPOSIX_stdio.h"  /* <= device handler header */
#include "ciaaPOSIX_string.h" /* <= string header */
#include "ciaak.h"            /* <= ciaa kernel header */
#include "interfaz.h"

void Matriz_Inicializar (void);
void Matriz_EscribirMensaje (const char* buffer, uint8_t long_buffer);
void Matriz_BorrarMensaje (void);
void Matriz_DesplazarMensaje (void);
void Matriz_CambiarSize (void);
void Matriz_CambiarVelocidad_Desplazar (void);
void Matriz_CambiarDetener (void);
