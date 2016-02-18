/*
 * interfaz.c
 *
 *  Created on: 22/10/2015
 *      Author: zorito1994
 */

#include "os.h"               /* <= operating system header */
#include "Os_Cfg.h"
#include "ciaaPOSIX_stdio.h"  /* <= device handler header */
#include "ciaaPOSIX_string.h" /* <= string header */
#include "ciaak.h"            /* <= ciaa kernel header */
#include "lcd.h"
#include "switches.h"
#include "interfaz.h"
#include "conversor.h"
#include "calculadora.h"
#include "matriz.h"

#define NUM_CARACTERES 43
#define NUM_DECIMALES 11
#define NUM_HEXADECIMALES 17
#define NUM_BINARIOS 3

static uint8_t cambiar_posterior = 1;
static uint8_t mover_derecha = 1;

static uint8_t tiempo = 199;
static uint8_t submenu = 1;

const static char caracteres[NUM_CARACTERES] = {' ','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','+','-','*','/','=',',','0','1','2','3','4','5','6','7','8','9'};
const static char decimales[NUM_DECIMALES] = {' ','0','1','2','3','4','5','6','7','8','9'};
const static char hexadecimales[NUM_HEXADECIMALES] = {' ','0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
const static char binarios[NUM_BINARIOS] = {' ','0','1'};

static int8_t i_caracteres = 0;
static int8_t i_decimales = 0;
static int8_t i_hexadecimales = 0;
static int8_t i_binarios = 0;

static char buffer[BUFFER_LENGTH];
static int8_t i_buffer = 0;
static uint8_t long_buffer = 1;

static uint8_t escribir_mensaje = 0;

static void Interfaz_EncenderCursorLCD (void) {
	LCD_write_string_to_buffer ("{[");
}

static void Interfaz_ApagarCursorLCD (void) {
	LCD_write_string_to_buffer ("]}");
}

void Interfaz_CargarSubmenu (void) {
	tiempo = 199;
	submenu = 1;
}

void Interfaz_MenuPrincipal (void) {
	Interfaz_EncenderCursorLCD();
	if (++tiempo == 200) {
		tiempo = 0;
		LCD_clear_buffer();
		if (submenu == 1) {
			LCD_write_string_to_buffer ("\f\rMenu Principal:\n");
			LCD_write_string_to_buffer ("1.Mensaje");
			submenu = 2;
		}
		else {
			LCD_write_string_to_buffer ("\f\r2.Calculadora\n");
			LCD_write_string_to_buffer ("3.Conversor");
			submenu = 1;
		}
	}
}

void Interfaz_Inicializar (void) {
	LCD_init (0x0C, 0x00);
	Interfaz_MenuPrincipal();
	LCD_display_on();
	Interfaz_EncenderCursorLCD();
}

static void Interfaz_ReinicializarMensaje (void) {
	i_buffer = 0;
	long_buffer = 1;
	i_caracteres = 0;
	i_binarios = 0;
	i_decimales = 0;
	i_hexadecimales = 0;
	cambiar_posterior = 1;
	mover_derecha = 1;
}

void Interfaz_EscribirMensaje (void) {
	LCD_clear_buffer();
	Interfaz_ReinicializarMensaje();
	LCD_write_string_to_buffer ("\f\rMensaje:>\n");
	escribir_mensaje = 1;
}

void Interfaz_Operando1 (void) {
	LCD_clear_buffer();
	Interfaz_ReinicializarMensaje();
	LCD_write_string_to_buffer ("\f\rOperando 1:>\n");
	escribir_mensaje = 1;
}

void Interfaz_Operador (void) {
	LCD_clear_buffer();
	LCD_write_string_to_buffer ("\f\rOperador:\n");
	LCD_write_string_to_buffer ("1.+ 2.- 3.* 4./");
}

void Interfaz_Operando2 (void) {
	LCD_clear_buffer();
	Interfaz_ReinicializarMensaje();
	LCD_write_string_to_buffer ("\f\rOperando 2:>\n");
	escribir_mensaje = 1;
}

void Interfaz_CodificacionInicial (void) {
	if (++tiempo == 200) {
		tiempo = 0;
		LCD_clear_buffer();
		if (submenu == 1) {
			LCD_write_string_to_buffer ("\f\rCodif. inicial:\n");
			LCD_write_string_to_buffer ("1.Binaria");
			submenu = 2;
		}
		else {
			LCD_write_string_to_buffer ("\f\r2.Decimal\n");
			LCD_write_string_to_buffer ("3.Hexadecimal");
			submenu = 1;
		}
	}
}

void Interfaz_ValorInicial (void) {
	LCD_clear_buffer();
	Interfaz_ReinicializarMensaje();
	LCD_write_string_to_buffer ("\f\rValor inicial:>\n");
	escribir_mensaje = 1;
}

void Interfaz_CodificacionFinal (void) {
	if (++tiempo == 200) {
		tiempo = 0;
		LCD_clear_buffer();
		if (submenu == 1) {
			LCD_write_string_to_buffer ("\f\rCodif. final:\n");
			LCD_write_string_to_buffer ("1.Binaria");
			submenu = 2;
		}
		else {
			LCD_write_string_to_buffer ("\f\r2.Decimal\n");
			LCD_write_string_to_buffer ("3.Hexadecimal");
			submenu = 1;
		}
	}
}

void Interfaz_ValorFinal (void) {
	LCD_clear_buffer();
	LCD_write_string_to_buffer ("\f\rValor final:\n");
	escribir_mensaje = 1;
}

void Interfaz_ComprobarMensaje (void) {
	if ((buffer[0] == ' ') | (buffer[long_buffer-1] == ' ')) {
		Interfaz_CargarSubmenu();
		Interfaz_MenuPrincipal();
		Switches_MenuPrincipal();
	}
	else {
		Interfaz_ApagarCursorLCD();
		Matriz_EscribirMensaje (buffer, long_buffer);
	}
}

static void Interfaz_MostrarResultadoCalculadora (void) {
	LCD_clear_buffer();
	LCD_write_string_to_buffer ("\f\rResultado:\n");
	LCD_write_string_to_buffer (buffer);
	Interfaz_ApagarCursorLCD();
	Matriz_EscribirMensaje (buffer, long_buffer);
}

void Interfaz_ComprobarOperando (uint8_t num_operando) {
uint16_t operando;
const uint8_t digitos[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
uint8_t es_numero = 1;
uint8_t i;
	for (i = 0; i < long_buffer; ++i) {
		if (buffer[i] == ' ') {
			es_numero = 0;
			break;
		}
	}
	if (es_numero == 0) {
		Interfaz_CargarSubmenu();
		Interfaz_MenuPrincipal();
		Switches_MenuPrincipal();
	}
	else if (long_buffer == 1) {
		for (i = 0; i < 10; ++i) {
			if (buffer[0] == decimales[i+1]) {
				operando = digitos[i];
				if (num_operando == 1) {
					if (Calculadora_Operando1 (operando) == 0)
						Interfaz_Operador();
					else {
						Interfaz_CargarSubmenu();
						Interfaz_MenuPrincipal();
						Switches_MenuPrincipal();
					}
				}
				else {
					if (Calculadora_Operando2 (operando) == 0) {
						long_buffer = Calculadora_Calcular (buffer);
						Interfaz_MostrarResultadoCalculadora();
					}
					else {
						Interfaz_CargarSubmenu();
						Interfaz_MenuPrincipal();
						Switches_MenuPrincipal();
					}
				}
				break;
			}
		}
	}
	else if (long_buffer == 2) {
		for (i = 0; i < 10; ++i) {
			if (buffer[0] == decimales[i+1]) {
				operando = digitos[i] * 10;
				break;
			}
		}
		for (i = 0; i < 10; ++i) {
			if (buffer[1] == decimales[i+1]) {
				operando += digitos[i];
				if (num_operando == 1) {
					if (Calculadora_Operando1 (operando) == 0)
						Interfaz_Operador();
					else {
						Interfaz_CargarSubmenu();
						Interfaz_MenuPrincipal();
						Switches_MenuPrincipal();
					}
				}
				else {
					if (Calculadora_Operando2 (operando) == 0) {
						long_buffer = Calculadora_Calcular (buffer);
						Interfaz_MostrarResultadoCalculadora();
					}
					else {
						Interfaz_CargarSubmenu();
						Interfaz_MenuPrincipal();
						Switches_MenuPrincipal();
					}
				}
				break;
			}
		}
	}
	else if (long_buffer == 3) {
		for (i = 0; i < 10; ++i) {
			if (buffer[0] == decimales[i+1]) {
				operando = digitos[i] * 100;
				break;
			}
		}
		for (i = 0; i < 10; ++i) {
			if (buffer[1] == decimales[i+1]) {
				operando += digitos[i] * 10;
				break;
			}
		}
		for (i = 0; i < 10; ++i) {
			if (buffer[2] == decimales[i+1]) {
				operando += digitos[i];
				if (num_operando == 1) {
					if (Calculadora_Operando1 (operando) == 0)
						Interfaz_Operador();
					else {
						Interfaz_CargarSubmenu();
						Interfaz_MenuPrincipal();
						Switches_MenuPrincipal();
					}
				}
				else {
					if (Calculadora_Operando2 (operando) == 0) {
						long_buffer = Calculadora_Calcular (buffer);
						Interfaz_MostrarResultadoCalculadora();
					}
					else {
						Interfaz_CargarSubmenu();
						Interfaz_MenuPrincipal();
						Switches_MenuPrincipal();
					}
				}
				break;
			}
		}
	}
	else {
		Interfaz_CargarSubmenu();
		Interfaz_MenuPrincipal();
		Switches_MenuPrincipal();
	}
}

void Interfaz_ComprobarValorInicial (void) {
char valor_inicial[8] = {'0','0','0','0','0','0','0','0'};
const char codif_inicial = Conversor_GetCodificacionInicial();
uint8_t es_numero = 1;
uint8_t i;
uint8_t k = 0;
	for (i = 0; i < long_buffer; ++i) {
		if (buffer[i] == ' ') {
			es_numero = 0;
			break;
		}
	}
	if (es_numero == 0) {
		Interfaz_CargarSubmenu();
		Interfaz_MenuPrincipal();
		Switches_MenuPrincipal();
	}
	else if ( ((codif_inicial == 1) & (long_buffer > 8)) | ((codif_inicial == 3) & (long_buffer > 2)) ) {
		Interfaz_CargarSubmenu();
		Interfaz_MenuPrincipal();
		Switches_MenuPrincipal();
	}
	else if (codif_inicial == 2) {
		for (i = 7-(long_buffer-1); i < 8; ++i) {
			valor_inicial[i] = buffer[k];
			++k;
		}
		Conversor_ValorInicial (valor_inicial);
		if (Conversor_ComprobarDecimal() == 0) {
			Interfaz_CargarSubmenu();
			Interfaz_ValorFinal();
		}
		else {
			Interfaz_CargarSubmenu();
			Interfaz_MenuPrincipal();
			Switches_MenuPrincipal();
		}
	}
	else {
		for (i = 7-(long_buffer-1); i < 8; ++i) {
			valor_inicial[i] = buffer[k];
			++k;
		}
		Conversor_ValorInicial (valor_inicial);
		Interfaz_CargarSubmenu();
		Interfaz_ValorFinal();
	}
}

static void Interfaz_MostrarResultadoConversion (void) {
const uint8_t codif_inicial = Conversor_GetCodificacionInicial();
const uint8_t codif_final = Conversor_GetCodificacionFinal();
char resultado[20] = "\f\rResultado (XaX):\n";
	LCD_clear_buffer();
	if (codif_inicial == 1)
		resultado[13] = 'B';
	else if (codif_inicial == 2)
		resultado[13] = 'D';
	else
		resultado[13] = 'H';
	if (codif_final == 1)
		resultado[15] = 'B';
	else if (codif_final == 2)
		resultado[15] = 'D';
	else
		resultado[15] = 'H';
	LCD_write_string_to_buffer (resultado);
	LCD_write_string_to_buffer (buffer);
	Interfaz_ApagarCursorLCD();
	Matriz_EscribirMensaje (buffer, long_buffer);
}

void Interfaz_Conversion (void) {
char valor_final[8] = {'0','0','0','0','0','0','0','0'};
uint8_t i;
	for (i = long_buffer; i < BUFFER_LENGTH; ++i)
		buffer[i] = '\0';
	++long_buffer;
	buffer[long_buffer-1] = ' ';
	++long_buffer;
	buffer[long_buffer-1] = '=';
	++long_buffer;
	buffer[long_buffer-1] = ' ';
	Conversor_Convertir (valor_final);
	i = 0;
	while ((valor_final[i] == '0') & (i < 8))
		++i;
	if (i == 8) {
		++long_buffer;
		buffer[long_buffer-1] = '0';
	}
	else while (i < 8) {
		++long_buffer;
		buffer[long_buffer-1] = valor_final[i];
		++i;
	}
	Interfaz_MostrarResultadoConversion();
}

void Interfaz_CambiarSubmenu (void) {
const uint8_t estado = Switches_GetEstado();
	if (estado == 0) {
		Interfaz_MenuPrincipal();
	}
	else if (estado == 3) {
		Interfaz_CodificacionInicial();
	}
	else if (estado == 8) {
		Interfaz_CodificacionFinal();
	}
}

void Interfaz_Revisar (void) {
const uint8_t estado = Switches_GetEstado();
uint8_t codif_inicial;
	if (estado == 1) {
		if (escribir_mensaje == 0) {
			LCD_write_char_to_buffer (caracteres[i_caracteres]);
			buffer[i_buffer] = caracteres[i_caracteres];
		}
		else if (LCD_end_writing() == 1) {
			escribir_mensaje = 0;
		}
	}
	else if ((estado == 2) | (estado == 7)) {
		if (escribir_mensaje == 0) {
			LCD_write_char_to_buffer (decimales[i_decimales]);
			buffer[i_buffer] = decimales[i_decimales];
		}
		else if (LCD_end_writing() == 1) {
			escribir_mensaje = 0;
		}
	}
	else if (estado == 6) {
		codif_inicial = Conversor_GetCodificacionInicial();
		if (escribir_mensaje == 0) {
			if (codif_inicial == 1) {
				LCD_write_char_to_buffer (binarios[i_binarios]);
				buffer[i_buffer] = binarios[i_binarios];
			}
			else if (codif_inicial == 2) {
				LCD_write_char_to_buffer (decimales[i_decimales]);
				buffer[i_buffer] = decimales[i_decimales];
			}
			else {
				LCD_write_char_to_buffer (hexadecimales[i_hexadecimales]);
				buffer[i_buffer] = hexadecimales[i_hexadecimales];
			}
		}
		else if (LCD_end_writing() == 1) {
			escribir_mensaje = 0;
		}
	}
}

void Interfaz_PosicionarLCD (void) {
const uint8_t estado = Switches_GetEstado();
	if ( ( (estado == 1)|(estado == 2)|(estado == 6)|(estado == 7) ) & (escribir_mensaje == 0) ) {
		LCD_pos_xy (i_buffer,1);
	}
}

void Interfaz_MoverCursor (void) {
const uint8_t estado = Switches_GetEstado();
const uint8_t codif_inicial = Conversor_GetCodificacionInicial();
	i_caracteres = 0;
	i_binarios = 0;
	i_decimales = 0;
	i_hexadecimales = 0;
	if (mover_derecha == 1) {
		if (estado == 1) {
			if (++i_buffer == BUFFER_LENGTH-1) {
				i_buffer = 0;
			}
		}
		else if ((estado == 2) | (estado == 7)) {
			if (++i_buffer == 3) {
				i_buffer = 0;
			}
		}
		else {
			if (codif_inicial == 1) {
				if (++i_buffer == 8) {
					i_buffer = 0;
				}
			}
			else if (codif_inicial == 2) {
				if (++i_buffer == 3) {
					i_buffer = 0;
				}
			}
			else {
				if (++i_buffer == 2) {
					i_buffer = 0;
				}
			}
		}
		if (long_buffer == i_buffer) {
			++long_buffer;
		}
		else if (estado == 1) {
			while (caracteres[i_caracteres] != buffer[i_buffer])
				++i_caracteres;
		}
		else {
			while (hexadecimales[i_hexadecimales] != buffer[i_buffer])
				++i_hexadecimales;
			i_binarios = i_hexadecimales;
			i_decimales = i_hexadecimales;
		}
	}
	else {
		if (--i_buffer < 0)
			i_buffer = long_buffer - 1;
		if (estado == 1) {
			while (caracteres[i_caracteres] != buffer[i_buffer])
				++i_caracteres;
		}
		else {
			while (hexadecimales[i_hexadecimales] != buffer[i_buffer])
				++i_hexadecimales;
			i_binarios = i_hexadecimales;
			i_decimales = i_hexadecimales;
		}
	}
	Interfaz_PosicionarLCD();
}

void Interfaz_CambiarMovimientos (void) {
	if (mover_derecha == 1) {
		mover_derecha = 0;
		cambiar_posterior = 0;
		LCD_escribir_flecha_atras();
	}
	else {
		mover_derecha = 1;
		cambiar_posterior = 1;
		LCD_escribir_flecha_adelante();
	}
}

void Interfaz_CambiarCaracter (void) {
	if (cambiar_posterior == 1) {
		if (++i_caracteres == NUM_CARACTERES) {
			i_caracteres = 0;
		}
	}
	else if (--i_caracteres < 0) {
		i_caracteres = NUM_CARACTERES-1;
	}
}

void Interfaz_CambiarOperando (void) {
	if (cambiar_posterior == 1) {
		if (++i_decimales == NUM_DECIMALES) {
			i_decimales = 0;
		}
	}
	else if (--i_decimales < 0) {
		i_decimales = NUM_DECIMALES-1;
	}
}

static void Interfaz_CambiarValorBinario (void) {
	if (cambiar_posterior == 1) {
		if (++i_binarios == NUM_BINARIOS) {
			i_binarios = 0;
		}
	}
	else if (--i_binarios < 0) {
		i_binarios = NUM_BINARIOS-1;
	}
}

static void Interfaz_CambiarValorDecimal (void) {
	if (cambiar_posterior == 1) {
		if (++i_decimales == NUM_DECIMALES) {
			i_decimales = 0;
		}
	}
	else if (--i_decimales < 0) {
		i_decimales = NUM_DECIMALES-1;
	}
}

static void Interfaz_CambiarValorHexadecimal (void) {
	if (cambiar_posterior == 1) {
		if (++i_hexadecimales == NUM_HEXADECIMALES) {
			i_hexadecimales = 0;
		}
	}
	else if (--i_hexadecimales < 0) {
		i_hexadecimales = NUM_HEXADECIMALES-1;
	}
}

void Interfaz_CambiarValor (void) {
const uint8_t codif_inicial = Conversor_GetCodificacionInicial();
	if (codif_inicial == 1)
		Interfaz_CambiarValorBinario();
	else if (codif_inicial == 2)
		Interfaz_CambiarValorDecimal();
	else
		Interfaz_CambiarValorHexadecimal();
}
