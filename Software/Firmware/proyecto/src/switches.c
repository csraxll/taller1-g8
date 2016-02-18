/*
 * switches.c
 *
 *  Created on: 28/10/2015
 *      Author: zorito1994
 */

#include "ciaaPOSIX_stdio.h"  /* <= device handler header */
#include "ciaaPOSIX_string.h" /* <= string header */
#include "puertos.h"
#include "interfaz.h"
#include "matriz.h"
#include "conversor.h"
#include "calculadora.h"

#define ANTIRREBOTE 35

static int32_t file_in;
static uint8_t inputs = 0;
static uint8_t switch1, switch2, switch3, switch4;

static uint8_t estado = 0;

static uint8_t rebote = 0;
static uint8_t tiempo = 0;

void Switches_MenuPrincipal (void) {
	estado = 0;
}

static void MostrarCartel (void) {
	if (switch1 == 1) {
		Matriz_CambiarSize();
	}
	else if (switch2 == 1) {
		Matriz_CambiarVelocidad_Desplazar();
	}
	else if (switch3 == 1) {
		Matriz_CambiarDetener();
	}
	else if (switch4 == 1) {
		Matriz_BorrarMensaje();
		Switches_MenuPrincipal();
		Interfaz_CargarSubmenu();
		Interfaz_MenuPrincipal();
	}
}

static void f_0 (void) {
	if (switch1 == 1) {
		estado = 1;
		Interfaz_EscribirMensaje();
	}
	else if (switch2 == 1) {
		estado = 2;
		Interfaz_Operando1();
	}
	else if (switch3 == 1) {
		estado = 3;
		Interfaz_CargarSubmenu();
		Interfaz_CodificacionInicial();
	}
}

static void f_1 (void) {
	if (switch1 == 1) {
		Interfaz_CambiarCaracter();
	}
	else if (switch2 == 1) {
		Interfaz_MoverCursor();
	}
	else if (switch3 == 1) {
		Interfaz_CambiarMovimientos();
	}
	else if (switch4 == 1) {
		estado = 4;
		Interfaz_ComprobarMensaje();
	}
}

static void f_2 (void) {
	if (switch1 == 1) {
		Interfaz_CambiarOperando();
	}
	else if (switch2 == 1) {
		Interfaz_MoverCursor();
	}
	else if (switch3 == 1) {
		Interfaz_CambiarMovimientos();
	}
	else if (switch4 == 1) {
		estado = 5;
		Interfaz_ComprobarOperando(1);
	}
}

static void f_3 (void) {
	if (switch1 == 1) {
		estado = 6;
		Conversor_SetCodificacionInicial(1);
		Interfaz_ValorInicial();
	}
	else if (switch2 == 1) {
		estado = 6;
		Conversor_SetCodificacionInicial(2);
		Interfaz_ValorInicial();
	}
	else if (switch3 == 1) {
		estado = 6;
		Conversor_SetCodificacionInicial(3);
		Interfaz_ValorInicial();
	}
	else if (switch4 == 1) {
		Switches_MenuPrincipal();
		Interfaz_CargarSubmenu();
		Interfaz_MenuPrincipal();
	}
}

static void f_4 (void) {
	MostrarCartel();
}

static void f_5 (void) {
	if (switch1 == 1) {
		estado = 7;
		Calculadora_Operador('+');
		Interfaz_Operando2();
	}
	else if (switch2 == 1) {
		estado = 7;
		Calculadora_Operador('-');
		Interfaz_Operando2();
	}
	else if (switch3 == 1) {
		estado = 7;
		Calculadora_Operador('*');
		Interfaz_Operando2();
	}
	else if (switch4 == 1) {
		estado = 7;
		Calculadora_Operador('/');
		Interfaz_Operando2();
	}
}

static void f_6 (void) {
	if (switch1 == 1) {
		Interfaz_CambiarValor();
	}
	else if (switch2 == 1) {
		Interfaz_MoverCursor();
	}
	else if (switch3 == 1) {
		Interfaz_CambiarMovimientos();
	}
	else if (switch4 == 1) {
		estado = 8;
		Interfaz_ComprobarValorInicial();
	}
}

static void f_7 (void) {
	if (switch1 == 1) {
		Interfaz_CambiarOperando();
	}
	else if (switch2 == 1) {
		Interfaz_MoverCursor();
	}
	else if (switch3 == 1) {
		Interfaz_CambiarMovimientos();
	}
	else if (switch4 == 1) {
		estado = 9;
		Interfaz_ComprobarOperando(2);
	}
}

static void f_8 (void) {
	if (switch1 == 1) {
		estado = 10;
		Conversor_SetCodificacionFinal(1);
		Interfaz_Conversion();
	}
	else if (switch2 == 1) {
		estado = 10;
		Conversor_SetCodificacionFinal(2);
		Interfaz_Conversion();
	}
	else if (switch3 == 1) {
		estado = 10;
		Conversor_SetCodificacionFinal(3);
		Interfaz_Conversion();
	}
	else if (switch4 == 1) {
		Switches_MenuPrincipal();
		Interfaz_CargarSubmenu();
		Interfaz_MenuPrincipal();
	}
}

static void f_9 (void) {
	MostrarCartel();
}

static void f_10 (void) {
	MostrarCartel();
}

static void (*f_estados[])(void) = {f_0, f_1, f_2, f_3, f_4, f_5, f_6, f_7, f_8, f_9, f_10};

void Switches_Inicializar (void) {
	file_in = ciaaPOSIX_open ("/dev/dio/in/0", O_RDONLY);
}

void Switches_Polling (void) {
const uint8_t const_estado = estado;
const uint8_t const_rebote = rebote;
const uint8_t const_tiempo = tiempo;
	ciaaPOSIX_read (file_in, &inputs, 1);
	estado = const_estado;
	rebote = const_rebote;
	tiempo = const_tiempo;
	if (rebote == 0) {
		switch1 = inputs & 0x01;
		switch2 = (inputs >> 1) & 0x01;
		switch3 = (inputs >> 2) & 0x01;
		switch4 = (inputs >> 3) & 0x01;
		if ((switch1 == 1)|(switch2 == 1)|(switch3 == 1)|(switch4 == 1)) {
			(*f_estados[estado])();
			rebote = 1;
		}
	}
	else if (++tiempo == ANTIRREBOTE) {
		tiempo = 0;
		rebote = 0;
	}
}

uint8_t Switches_GetEstado (void) {
	return estado;
}

