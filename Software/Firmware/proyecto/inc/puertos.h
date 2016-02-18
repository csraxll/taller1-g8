/*
 * gpio.h
 *
 *  Created on: 28/10/2015
 *      Author: zorito1994
 */

#ifndef PROYECTO_INC_GPIO_H_
#define PROYECTO_INC_GPIO_H_



#endif /* PROYECTO_INC_GPIO_H_ */

#include "os.h"               /* <= operating system header */
#include "Os_Cfg.h"
#include "ciaaPOSIX_stdio.h"  /* <= device handler header */
#include "ciaaPOSIX_string.h" /* <= string header */
#include "ciaak.h"            /* <= ciaa kernel header */

void Puertos_Inicializar (void);

uint16_t Puertos_LeerGPIO (void);
uint16_t Puertos_LeerLCD (void);

void Puertos_EscribirGPIO0 (unsigned char valor);
void Puertos_EscribirGPIO1 (unsigned char valor);
void Puertos_EscribirGPIO2 (unsigned char valor);
void Puertos_EscribirGPIO3 (unsigned char valor);
void Puertos_EscribirGPIO4 (unsigned char valor);
void Puertos_EscribirGPIO5 (unsigned char valor);
void Puertos_EscribirGPIO6 (unsigned char valor);
void Puertos_EscribirGPIO7 (unsigned char valor);
void Puertos_EscribirGPIO8 (unsigned char valor);

void Puertos_EscribirLCD1 (unsigned char valor);
void Puertos_EscribirLCD2 (unsigned char valor);
void Puertos_EscribirLCD3 (unsigned char valor);
void Puertos_EscribirLCD4 (unsigned char valor);
void Puertos_EscribirLCD_RS (unsigned char valor);
void Puertos_EscribirLCD_EN (unsigned char valor);
