/*
 * interfaz.h
 *
 *  Created on: 22/10/2015
 *      Author: zorito1994
 */

#ifndef INTERFAZ_H_
#define INTERFAZ_H_



#endif /* INTERFAZ_H_ */

#define BUFFER_LENGTH 17

#include "ciaaPOSIX_string.h" /* <= string header */

void Interfaz_CargarSubmenu (void);
void Interfaz_MenuPrincipal (void);
void Interfaz_Inicializar (void);
void Interfaz_EscribirMensaje (void);
void Interfaz_Operando1 (void);
void Interfaz_Operador (void);
void Interfaz_Operando2 (void);
void Interfaz_CodificacionInicial (void);
void Interfaz_ValorInicial (void);
void Interfaz_CodificacionFinal (void);
void Interfaz_ValorFinal (void);
void Interfaz_ComprobarMensaje (void);
void Interfaz_ComprobarOperando (uint8_t num_operando);
void Interfaz_ComprobarValorInicial (void);
void Interfaz_Conversion (void);
void Interfaz_CambiarSubmenu (void);
void Interfaz_Revisar (void);
void Interfaz_PosicionarLCD (void);
void Interfaz_MoverCursor (void);
void Interfaz_CambiarMovimientos (void);
void Interfaz_CambiarCaracter (void);
void Interfaz_CambiarOperando (void);
void Interfaz_CambiarValor (void);
