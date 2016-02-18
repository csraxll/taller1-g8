/*
 * puertos.c
 *
 *  Created on: 28/10/2015
 *      Author: zorito1994
 */

#include "puertos.h"

static int32_t file_out;
static uint16_t outputs = 0;

void Puertos_Inicializar (void) {
	file_out = ciaaPOSIX_open("/dev/dio/out/0", O_RDWR);
	ciaaPOSIX_write (file_out, &outputs, 2);
}

uint16_t Puertos_LeerGPIO (void) {
	ciaaPOSIX_read (file_out, &outputs, 2);
	return (outputs >> 6);
}

uint16_t Puertos_LeerLCD (void) {
	ciaaPOSIX_read (file_out, &outputs, 2);
	return (outputs & 0x003F);
}

static void Puertos_Escribir (void) {
	ciaaPOSIX_write (file_out, &outputs, 2);
}

void Puertos_EscribirGPIO0 (unsigned char valor) {
	if (valor == 1)
		outputs |= 0x0040;
	else
		outputs &= 0xFFBF;
	Puertos_Escribir();
}

void Puertos_EscribirGPIO1 (unsigned char valor) {
	if (valor == 1)
		outputs |= 0x0080;
	else
		outputs &= 0xFF7F;
	Puertos_Escribir();
}

void Puertos_EscribirGPIO2 (unsigned char valor) {
	if (valor == 1)
		outputs |= 0x0100;
	else
		outputs &= 0xFEFF;
	Puertos_Escribir();
}

void Puertos_EscribirGPIO3 (unsigned char valor) {
	if (valor == 1)
		outputs |= 0x0200;
	else
		outputs &= 0xFDFF;
	Puertos_Escribir();
}

void Puertos_EscribirGPIO4 (unsigned char valor) {
	if (valor == 1)
		outputs |= 0x0400;
	else
		outputs &= 0xFBFF;
	Puertos_Escribir();
}

void Puertos_EscribirGPIO5 (unsigned char valor) {
	if (valor == 1)
		outputs |= 0x0800;
	else
		outputs &= 0xF7FF;
	Puertos_Escribir();
}

void Puertos_EscribirGPIO6 (unsigned char valor) {
	if (valor == 1)
		outputs |= 0x1000;
	else
		outputs &= 0xEFFF;
	Puertos_Escribir();
}

void Puertos_EscribirGPIO7 (unsigned char valor) {
	if (valor == 1)
		outputs |= 0x2000;
	else
		outputs &= 0xDFFF;
	Puertos_Escribir();
}

void Puertos_EscribirGPIO8 (unsigned char valor) {
	if (valor == 1)
		outputs |= 0x4000;
	else
		outputs &= 0xBFFF;
	Puertos_Escribir();
}

void Puertos_EscribirLCD1 (unsigned char valor) {
	if (valor == 1)
		outputs |= 0x0001;
	else
		outputs &= 0xFFFE;
	Puertos_Escribir();
}

void Puertos_EscribirLCD2 (unsigned char valor) {
	if (valor == 1)
		outputs |= 0x0002;
	else
		outputs &= 0xFFFD;
	Puertos_Escribir();
}

void Puertos_EscribirLCD3 (unsigned char valor) {
	if (valor == 1)
		outputs |= 0x0004;
	else
		outputs &= 0xFFFB;
	Puertos_Escribir();
}

void Puertos_EscribirLCD4 (unsigned char valor) {
	if (valor == 1)
		outputs |= 0x0008;
	else
		outputs &= 0xFFF7;
	Puertos_Escribir();
}

void Puertos_EscribirLCD_RS (unsigned char valor) {
	if (valor == 1)
		outputs |= 0x0010;
	else
		outputs &= 0xFFEF;
	Puertos_Escribir();
}

void Puertos_EscribirLCD_EN (unsigned char valor) {
	if (valor == 1)
		outputs |= 0x0020;
	else
		outputs &= 0xFFDF;
	Puertos_Escribir();
}
