/*
 * calculadora.h
 *
 *  Created on: 2/1/2016
 *      Author: Facu
 */

#ifndef CALCULADORA_H_
#define CALCULADORA_H_





#endif /* CALCULADORA_H_ */

#include "interfaz.h"

uint8_t Calculadora_Operando1 (uint16_t nuevo_operando);
void Calculadora_Operador (char nuevo_operador);
uint8_t Calculadora_Operando2 (uint16_t nuevo_operando);
uint8_t Calculadora_Calcular (char buffer[BUFFER_LENGTH]);
