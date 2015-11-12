/*
 * gpio.c
 *
 *  Created on: 28/10/2015
 *      Author: zorito1994
 */

#include "gpio.h"

static int32_t file_out;
static uint16_t outputs = 0;

void GPIO_InicializarGPIO (void) {
	file_out = ciaaPOSIX_open("/dev/dio/out/0", O_RDWR);
	ciaaPOSIX_write (file_out, &outputs, 2);
}

uint16_t GPIO_LeerGPIO (void) {
	ciaaPOSIX_read (file_out, &outputs, 2);
	return (outputs >> 6);
}

static void GPIO_EscribirGPIO (void) {
	ciaaPOSIX_write (file_out, &outputs, 2);
}

void GPIO_EscribirGPIO0 (unsigned char valor) {
	if (valor == 1)
		outputs |= 0x0040;
	else
		outputs &= 0xFFBF;
	GPIO_EscribirGPIO();
}

void GPIO_EscribirGPIO1 (unsigned char valor) {
	if (valor == 1)
		outputs |= 0x0080;
	else
		outputs &= 0xFF7F;
	GPIO_EscribirGPIO();
}

void GPIO_EscribirGPIO2 (unsigned char valor) {
	if (valor == 1)
		outputs |= 0x0100;
	else
		outputs &= 0xFEFF;
	GPIO_EscribirGPIO();
}

void GPIO_EscribirGPIO3 (unsigned char valor) {
	if (valor == 1)
		outputs |= 0x0200;
	else
		outputs &= 0xFDFF;
	GPIO_EscribirGPIO();
}

void GPIO_EscribirGPIO4 (unsigned char valor) {
	if (valor == 1)
		outputs |= 0x0400;
	else
		outputs &= 0xFBFF;
	GPIO_EscribirGPIO();
}

void GPIO_EscribirGPIO5 (unsigned char valor) {
	if (valor == 1)
		outputs |= 0x0800;
	else
		outputs &= 0xF7FF;
	GPIO_EscribirGPIO();
}

void GPIO_EscribirGPIO6 (unsigned char valor) {
	if (valor == 1)
		outputs |= 0x1000;
	else
		outputs &= 0xEFFF;
	GPIO_EscribirGPIO();
}

void GPIO_EscribirGPIO7 (unsigned char valor) {
	if (valor == 1)
		outputs |= 0x2000;
	else
		outputs &= 0xDFFF;
	GPIO_EscribirGPIO();
}

void GPIO_EscribirGPIO8 (unsigned char valor) {
	if (valor == 1)
		outputs |= 0x4000;
	else
		outputs &= 0xBFFF;
	GPIO_EscribirGPIO();
}
