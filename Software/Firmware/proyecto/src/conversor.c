/*
 * conversor.c
 *
 *  Created on: 2/1/2016
 *      Author: Facu
 */

// decimal -> 00000XXX
// binario -> XXXXXXXX
// hexadecimal -> 000000XX

#include "ciaaPOSIX_string.h" /* <= string header */


static uint8_t codif_inicial, codif_final;
static char valor_inicial[8], valor_final[8];
static uint16_t valor_dec;

static const char hexadecimales[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
static const uint8_t decimales[16] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

static void Decodificar_Decimal (void) {
static const uint8_t potencias10[3] = {100, 10, 1};
uint8_t i, j;
	valor_dec = 0;
	for (i = 5; i < 8; ++i) {
		for (j = 0; j < 10; ++j) {
			if (valor_inicial[i] == hexadecimales[j]) {
				valor_dec += decimales[j] * potencias10[i-5];
			}
		}
	}
}

void Conversor_SetCodificacionInicial (uint8_t codif) {
	codif_inicial = codif;
}

uint8_t Conversor_GetCodificacionInicial (void) {
	return codif_inicial;
}

void Conversor_ValorInicial (char valor[8]) {
uint8_t i;
	for (i = 0; i < 8; ++i)
		valor_inicial[i] = valor[i];
}

uint8_t Conversor_ComprobarDecimal (void) {
	Decodificar_Decimal();
	return (valor_dec > 255);
}

void Conversor_SetCodificacionFinal (uint8_t codif) {
	codif_final = codif;
}

uint8_t Conversor_GetCodificacionFinal (void) {
	return codif_final;
}

static void Codificar_Decimal (uint8_t valor_d) {
	valor_final[5] = hexadecimales[valor_d / 100];
	valor_final[6] = hexadecimales[(valor_d % 100) / 10];
	valor_final[7] = hexadecimales[valor_d % 10];
}

static uint8_t BinDec (void) {
static const uint8_t potencias2[8] = {128, 64, 32, 16, 8, 4, 2, 1};
uint8_t i;
uint8_t valor_f = 0;
	for (i = 0; i < 8; ++i) {
		if (valor_inicial[i] == '1')
			valor_f += potencias2[i];
	}
	return valor_f;
}

static uint8_t BinDec_Aux (char valor_i[4]) {
static const uint8_t potencias2[4] = {8, 4, 2, 1};
uint8_t i;
uint8_t valor_f = 0;
	for (i = 0; i < 4; ++i) {
		if (valor_i[i] == '1')
			valor_f += potencias2[i];
	}
	return valor_f;
}

static void BinHex (void) {
uint8_t i;
char valor_aux[4];
	for (i = 0; i < 4; ++i) {
		valor_aux[i] = valor_inicial[i];
	}
	valor_final[6] = hexadecimales[BinDec_Aux(valor_aux)];
	for (i = 4; i < 8; ++i) {
		valor_aux[i-4] = valor_inicial[i];
	}
	valor_final[7] = hexadecimales[BinDec_Aux(valor_aux)];
}

static void BinHex_Aux (void) {
uint8_t i;
char valor_aux[4];
char valor_i[8];
	for (i = 0; i < 8; ++i) {
		valor_i[i] = valor_final[i];
	}
	for (i = 0; i < 8; ++i) {
		valor_final[i] = '0';
	}
	for (i = 0; i < 4; ++i) {
		valor_aux[i] = valor_i[i];
	}
	valor_final[6] = hexadecimales[BinDec_Aux(valor_aux)];
	for (i = 4; i < 8; ++i) {
		valor_aux[i-4] = valor_i[i];
	}
	valor_final[7] = hexadecimales[BinDec_Aux(valor_aux)];
}

static void DecBin (void) {
uint8_t resto;
char valor_f[8];
uint8_t i = 0;
uint8_t j;
uint8_t k;
	while (valor_dec >= 2) {
		resto = valor_dec % 2;
		valor_dec = valor_dec / 2;
		valor_f[i] = hexadecimales[resto];
		++i;
	}
	valor_f[i] = hexadecimales[valor_dec];
	k = i;
	for (j = 7-i; j < 8; ++j) {
		valor_final[j] = valor_f[k];
		--k;
	}
}

static void DecBin_Aux (uint8_t valor_d) {
uint8_t resto;
char valor_f[8];
uint8_t i = 0;
uint8_t j;
uint8_t k;
	while (valor_d >= 2) {
		resto = valor_d % 2;
		valor_d = valor_d / 2;
		valor_f[i] = hexadecimales[resto];
		++i;
	}
	valor_f[i] = hexadecimales[valor_d];
	k = i;
	for (j = 7-i; j < 8; ++j) {
		valor_final[j] = valor_f[k];
		--k;
	}
}

static void DecHex (void) {
	DecBin();
	BinHex_Aux();
}

static uint8_t HexDec (void) {
static const uint8_t potencias16[2] = {16, 1};
uint8_t i, j;
uint8_t valor_f = 0;
	for (i = 6; i < 8; ++i) {
		for (j = 0; j < 16; ++j) {
			if (valor_inicial[i] == hexadecimales[j]) {
				valor_f += decimales[j] * potencias16[i-6];
				break;
			}
		}
	}
	return valor_f;
}

static void HexBin (void) {
static uint8_t valor_d;
	valor_d = HexDec();
	DecBin_Aux (valor_d);
}

static void ConservarValor (void) {
uint8_t i;
	for (i = 0; i < 8; ++i)
		valor_final[i] = valor_inicial[i];
}

void Conversor_Convertir (char valor_f[8]) {
uint8_t i;
uint8_t valor_d;
	for (i = 0; i < 8; ++i) {
		valor_final[i] = '0';
	}
	if (codif_inicial == 1) {
		if (codif_final == 1)
			ConservarValor();
		else if (codif_final == 2) {
			valor_d = BinDec();
			Codificar_Decimal (valor_d);
		}
		else
			BinHex();
	}
	else if (codif_inicial == 2) {
		if (codif_final == 1)
			DecBin();
		else if (codif_final == 2)
			ConservarValor();
		else
			DecHex();
	}
	else {
		if (codif_final == 1)
			HexBin();
		else if (codif_final == 2) {
			valor_d = HexDec();
			Codificar_Decimal (valor_d);
		}
		else
			ConservarValor();
	}
	for (i = 0; i < 8; ++i) {
		valor_f[i] = valor_final[i];
	}
}
