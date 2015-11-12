/*
 * matriz.h
 *
 *  Created on: 22/10/2015
 *      Author: zorito1994
 */

#ifndef MATRIZ_H_
#define MATRIZ_H_



#endif /* MATRIZ_H_ */


#include "os.h"               /* <= operating system header */
#include "Os_Cfg.h"
#include "ciaaPOSIX_stdio.h"  /* <= device handler header */
#include "ciaaPOSIX_string.h" /* <= string header */
#include "ciaak.h"            /* <= ciaa kernel header */
#include "interfaz.h"

void Matriz_EscribirMensaje (void);
void Matriz_GetMatriz (uint8_t matriz[NUM_FILAS][NUM_COLUMNAS]);
