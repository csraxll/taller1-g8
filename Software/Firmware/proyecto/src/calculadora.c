/*
 * calculadora.c
 *
 *  Created on: 1/1/2016
 *      Author: Facu
 */

#include "interfaz.h"
#include "ciaaPOSIX_string.h" /* <= string header */

static uint16_t operando1, operando2;
static char operador;
static uint16_t resultado;

static char operacion[BUFFER_LENGTH];
static uint8_t long_operacion;

static const char digitos[10] = {'0','1','2','3','4','5','6','7','8','9'};

static void Calculadora_Codificar3 (uint8_t indice) {
uint8_t decimal1, decimal2;
	operacion[indice] = ' ';
	operacion[indice+1] = '=';
	operacion[indice+2] = ' ';
	if (operador != '/') {
		if (resultado < 10) {
			operacion[indice+3] = digitos[resultado];
			long_operacion = indice + 4;
		}
		else if (resultado < 100) {
			operacion[indice+3] = digitos[resultado / 10];
			operacion[indice+4] = digitos[resultado % 10];
			long_operacion = indice + 5;
		}
		else if (resultado < 1000) {
			operacion[indice+3] = digitos[resultado / 100];
			operacion[indice+4] = digitos[(resultado % 100) / 10];
			operacion[indice+5] = digitos[resultado % 10];
			long_operacion = indice + 6;
		}
		else if (resultado < 10000) {
			operacion[indice+3] = digitos[resultado / 1000];
			operacion[indice+4] = digitos[(resultado % 1000) / 100];
			operacion[indice+5] = digitos[(resultado % 100) / 10];
			operacion[indice+6] = digitos[resultado % 10];
			long_operacion = indice + 7;
		}
		else {
			operacion[indice+3] = digitos[resultado / 10000];
			operacion[indice+4] = digitos[(resultado % 10000) / 1000];
			operacion[indice+5] = digitos[(resultado % 1000) / 100];
			operacion[indice+6] = digitos[(resultado % 100) / 10];
			operacion[indice+7] = digitos[resultado % 10];
			long_operacion = indice + 8;
		}
	}
	else {
		if ( (((operando1 * 1000) / operando2) % 10) >= 5 )
			++resultado;
		if (resultado < 1000) {
			operacion[indice+3] = digitos[resultado / 100];
			long_operacion = indice + 4;
		}
		else if (resultado < 10000) {
			operacion[indice+3] = digitos[resultado / 1000];
			operacion[indice+4] = digitos[(resultado / 100) % 10];
			long_operacion = indice + 5;
		}
		else {
			operacion[indice+3] = digitos[resultado / 10000];
			operacion[indice+4] = digitos[((resultado / 100) % 100) / 10];
			operacion[indice+5] = digitos[(resultado / 100) % 10];
			long_operacion = indice + 6;
		}
		decimal1 = (resultado % 100) / 10;
		decimal2 = resultado % 10;
		if ((decimal1 != 0) | (decimal2 != 0)) {
			operacion[long_operacion] = ',';
			operacion[long_operacion+1] = digitos[decimal1];
			long_operacion += 2;
			if (decimal2 != 0) {
				operacion[long_operacion] = digitos[decimal2];
				++long_operacion;
			}
		}
	}
}

static void Calculadora_Codificar2 (uint8_t indice) {
	operacion[indice] = operador;
	if (operando2 < 10) {
		operacion[indice+1] = digitos[operando2];
		Calculadora_Codificar3 (indice+2);
	}
	else if (operando2 < 100) {
		operacion[indice+1] = digitos[operando2 / 10];
		operacion[indice+2] = digitos[operando2 % 10];
		Calculadora_Codificar3 (indice+3);
	}
	else {
		operacion[indice+1] = digitos[operando2 / 100];
		operacion[indice+2] = digitos[(operando2 % 100) / 10];
		operacion[indice+3] = digitos[operando2 % 10];
		Calculadora_Codificar3 (indice+4);
	}
}

static void Calculadora_Codificar (void) {
	if (operando1 < 10) {
		operacion[0] = digitos[operando1];
		Calculadora_Codificar2 (1);
	}
	else if (operando1 < 100) {
		operacion[0] = digitos[operando1 / 10];
		operacion[1] = digitos[operando1 % 10];
		Calculadora_Codificar2 (2);
	}
	else {
		operacion[0] = digitos[operando1 / 100];
		operacion[1] = digitos[(operando1 % 100) / 10];
		operacion[2] = digitos[operando1 % 10];
		Calculadora_Codificar2 (3);
	}
}

uint8_t Calculadora_Operando1 (uint16_t nuevo_operando) {
	operando1 = nuevo_operando;
	return (operando1 > 255);
}

void Calculadora_Operador (char nuevo_operador) {
	operador = nuevo_operador;
}

uint8_t Calculadora_Operando2 (uint16_t nuevo_operando) {
	operando2 = nuevo_operando;
	return ( (operando2 > 255) | ((operador == '-') & (operando2 > operando1)) | ((operador =='/') & (operando2 == 0)) );
}

uint8_t Calculadora_Calcular (char buffer[BUFFER_LENGTH]) {
uint8_t i;
	for (i = 0; i < BUFFER_LENGTH; ++i)
		operacion[i] = '\0';
	switch (operador) {
		case '+':
			resultado = operando1 + operando2;
			break;
		case '-':
			resultado = operando1 - operando2;
			break;
		case '*':
			resultado = operando1 * operando2;
			break;
		case '/':
			resultado = (operando1 * 100) / operando2;
			break;
		default:
			break;
	}
	Calculadora_Codificar();
	for (i = 0; i < BUFFER_LENGTH; ++i) {
		buffer[i] = operacion[i];
	}
	return long_operacion;
}
