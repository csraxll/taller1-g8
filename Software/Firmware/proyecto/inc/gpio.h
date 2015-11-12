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

void GPIO_InicializarGPIO (void);

uint16_t GPIO_LeerGPIO (void);

void GPIO_EscribirGPIO0 (unsigned char valor);
void GPIO_EscribirGPIO1 (unsigned char valor);
void GPIO_EscribirGPIO2 (unsigned char valor);
void GPIO_EscribirGPIO3 (unsigned char valor);
void GPIO_EscribirGPIO4 (unsigned char valor);
void GPIO_EscribirGPIO5 (unsigned char valor);
void GPIO_EscribirGPIO6 (unsigned char valor);
void GPIO_EscribirGPIO7 (unsigned char valor);
void GPIO_EscribirGPIO8 (unsigned char valor);
