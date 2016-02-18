/*
 * conversor.h
 *
 *  Created on: 3/1/2016
 *      Author: Facu
 */

#ifndef CONVERSOR_H_
#define CONVERSOR_H_





#endif /* CONVERSOR_H_ */

void Conversor_SetCodificacionInicial (uint8_t codif);
uint8_t Conversor_GetCodificacionInicial (void);
void Conversor_ValorInicial (char valor[8]);
uint8_t Conversor_ComprobarDecimal (void);
void Conversor_SetCodificacionFinal (uint8_t codif);
uint8_t Conversor_GetCodificacionFinal (void);

void Conversor_Convertir (char valor_f[8]);
