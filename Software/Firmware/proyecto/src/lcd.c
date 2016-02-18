/*
 * lcd.c
 *
 *  Created on: 30/07/2013
 *      Author: pc2
 */

//* Basic Character LCD functions
//* By Fábio Pereira
//* 01/15/08

#include "ciaak.h"            /* <= ciaa kernel header */
#include "lcd.h"
#include "puertos.h"
#include "tiempo.h"

/*------------------------------------------------------------*
constante global LCD_BUFFER_LENGTH: contiene el número máximo de caracteres que podrán almacenarse para mostrar en la pantalla del display LCD
*------------------------------------------------------------*/
#define LCD_BUFFER_LENGTH 40

/*------------------------------------------------------------*
variable global Lcd_Buffer: aquí se almacenan los caracteres que se mostrarán en la pantalla del display LCD
*------------------------------------------------------------*/
static unsigned char Lcd_Indice_Lectura = 0;
static unsigned char Lcd_Indice_Escritura = 0;
static char Lcd_Buffer[LCD_BUFFER_LENGTH];

static unsigned char flecha_adelante = 0;
static unsigned char flecha_atras = 0;

union ubyte
{
	char _byte;
	struct
	{
		unsigned char b0 : 1;
		unsigned char b1 : 1;
		unsigned char b2 : 1;
		unsigned char b3 : 1;
		unsigned char b4 : 1;
		unsigned char b5 : 1;
		unsigned char b6 : 1;
		unsigned char b7 : 1;
	} bit;
};

/*------------------------------------------------------------*
variable global lcd_mode: aquí se almacena información sobre la configuración del display LCD (encendido o apagado de la pantalla y del cursor, titilado del cursor, etc.)
*------------------------------------------------------------*/
static char lcd_mode;	

/*------------------------------------------------------------*
función LCD_send_nibble: envía un nibble (4 bits) al display LCD
parámetro de entrada: datos a ser enviados al display. Aunque es un valor de 8 bits (char), en la función sólo se utilizan los 4 bits menos significativos
*------------------------------------------------------------*/
static void LCD_send_nibble(char data) {
	union ubyte my_union;
	my_union._byte = data;
	Puertos_EscribirLCD1 (my_union.bit.b0);
	Puertos_EscribirLCD2 (my_union.bit.b1);
	Puertos_EscribirLCD3 (my_union.bit.b2);
	Puertos_EscribirLCD4 (my_union.bit.b3);
	Puertos_EscribirLCD_EN (1);
	for (data=20; data; data--);
	Puertos_EscribirLCD_EN (0);
}

/*------------------------------------------------------------*
función LCD_send_byte: escribe un byte (8 bits) en el display LCD
parámetros de entrada: 
	address: indica la naturaleza de la información recibida, tomando el valor 0 si es un código de instrucción y un 1 si son datos. Es un valor de 8 bits (char)
	data: es la instrucción o los datos a ser escritos en el display. Es un valor de 8 bits (char)
*------------------------------------------------------------*/
static void LCD_send_byte(char address, char data) {
  unsigned int temp;
	if(address==0)
		Puertos_EscribirLCD_RS (0);               // config the R/S line
	else
		Puertos_EscribirLCD_RS (1);
	Puertos_EscribirLCD_EN (0);                 // set LCD enable line to 0
	LCD_send_nibble(data >> 4);     // send the higher nibble
	LCD_send_nibble(data & 0x0f);   // send the lower nibble
	for (temp=1000; temp; temp--);
}

static void LCD_flecha_adelante (void) {
char data = 0x7E;
unsigned int temp;
	LCD_pos_xy (15,0);
	Puertos_EscribirLCD_RS (1);
	Puertos_EscribirLCD_EN (0);
	LCD_send_nibble(data >> 4);
	LCD_send_nibble(data & 0x0f);
	for (temp=1000; temp; temp--);
	flecha_adelante = 0;
}

static void LCD_flecha_atras (void) {
char data = 0x7F;
unsigned int temp;
	LCD_pos_xy (15,0);
	Puertos_EscribirLCD_RS (1);
	Puertos_EscribirLCD_EN (0);
	LCD_send_nibble(data >> 4);
	LCD_send_nibble(data & 0x0f);
	for (temp=1000; temp; temp--);
	flecha_atras = 0;
}

void LCD_escribir_flecha_adelante (void) {
	flecha_adelante = 1;
}

void LCD_escribir_flecha_atras (void) {
	flecha_atras = 1;
}

/*------------------------------------------------------------*
función LCD_pos_xy: ubica al cursor del display en la posición indicada
parámetros de entrada:
	x: columna del display en la que se desea ubicar el cursor. Es un valor de 8 bits (char), con un rango limitado del 0 al 15, pues el display sólo tiene 16 columnas.
	y: línea del display en la que se desea ubicar al cursor. Es un valor de 8 bits (char), con un rango limitado del 0 al 1, pues el display sólo tiene 2 líneas.
*------------------------------------------------------------*/
void LCD_pos_xy(char x, char y) {
  char address;
  if (y) address = LCD_SEC_LINE; else address = 0;
  address += x;
  LCD_send_byte(0,0x80|address);
}

/*------------------------------------------------------------*
función LCD_init: inicializa el display LCD con una interfaz de 4 bits (debe ser invocada antes que cualquier otra función del display)
parámetros de entrada: 
	mode1: contiene información de la configuración del display (número de líneas y tamaño de los caracteres a mostrar en pantalla). Es un valor de 8 bits (char)
	mode2: contiene información de la configuración del display (cursor y estado del display). Es un valor de 8 bits (char)
*------------------------------------------------------------*/
void LCD_init(char mode1, char mode2) {
	char aux;
	// Set the LCD data pins to zero
	Puertos_EscribirLCD1 (0);
	Puertos_EscribirLCD2 (0);
	Puertos_EscribirLCD3 (0);
	Puertos_EscribirLCD4 (0);
	Puertos_EscribirLCD_RS (0);
	Puertos_EscribirLCD_EN (0);      // LCD enable = 0

	Tiempo_Delay_ms(15);
	// LCD 4-bit mode initialization sequence
	// send three times 0x03 and then 0x02 to finish configuring the LCD
	for(aux=0;aux<3;++aux)
	{		
	  LCD_send_nibble(3);
	  Tiempo_Delay_ms(5);
	}
	LCD_send_nibble(2);
	// Now send the LCD configuration data
	LCD_send_byte(0,0x20 | mode1);
	LCD_send_byte(0,0x08 | mode2);
	lcd_mode = 0x08 | mode2;
	
	LCD_send_byte(0,1);
	Tiempo_Delay_ms(5);
	LCD_send_byte(0,6); //entry mode set I/D=1 S=0
	Tiempo_Delay_ms(250);
}

/*------------------------------------------------------------*
función LCD_update: si hay un nuevo caracter para mostrar en el display, lo muestra
*------------------------------------------------------------*/
void LCD_update (void) {
	if (flecha_adelante == 1)
		LCD_flecha_adelante();
	else if (flecha_atras == 1)
		LCD_flecha_atras();
	else if (Lcd_Indice_Lectura < Lcd_Indice_Escritura) {
		switch (Lcd_Buffer[Lcd_Indice_Lectura]) {
			case '\f' :	
				LCD_send_byte(0,1);
			    break;
			case '\r' :
				LCD_pos_xy(0,0);
				break;
			case '>':
				LCD_flecha_adelante();
				break;
			case '<':
				LCD_flecha_atras();
				break;
			case '\n' :
				LCD_pos_xy(0,1);
				break;
			case '{' :
				LCD_cursor_on();
				break;
			case '}' :
				LCD_cursor_off();
				break;
			case '[' :
				LCD_cursor_blink_on();
				break;
			case ']' :
				LCD_cursor_blink_off();
				break;
			default:
				LCD_send_byte(1,Lcd_Buffer[Lcd_Indice_Lectura]);
				break;
		}
		Lcd_Indice_Lectura++;
	}
	else {
		Lcd_Indice_Lectura = 0;
		Lcd_Indice_Escritura = 0;
	}
}

/*------------------------------------------------------------*
función LCD_clear_buffer: limpia el contenido de la variable utilizada para almacenar los caracteres que se mostrarán en la pantalla del display LCD
*------------------------------------------------------------*/
void LCD_clear_buffer (void) {
	Lcd_Indice_Lectura = 0;
	Lcd_Indice_Escritura = 0;
}

/*------------------------------------------------------------*
función LCD_write_string_to_buffer: almacena una palabra para posteriormente mostrarla en la pantalla del display LCD
parámetro de entrada: es un puntero a la palabra a ser almacenada (const char*)
notas :
	\f limpia la pantalla del display
	\r regresa el cursor al principio de la primera línea
	\n desplaza el cursor al principio de la segunda línea
*------------------------------------------------------------*/
void LCD_write_string_to_buffer (const char* STR_PTR) {
unsigned char i = 0;
	while (STR_PTR[i] != '\0') {
	  LCD_write_char_to_buffer(STR_PTR[i]);
	  i++;
	}
}

/*------------------------------------------------------------*
función LCD_write_char_to_buffer: almacena un caracter para posteriormente mostrarlo en la pantalla del display LCD
parámetro de entrada: es el caracter a ser almacenado. Es un valor de 8 bits (const char)
notas :
	\f limpia la pantalla del display
	\r regresa el cursor al principio de la primera línea
	\n desplaza el cursor al principio de la segunda línea
*------------------------------------------------------------*/
void LCD_write_char_to_buffer (const char Data) {
	if (Lcd_Indice_Escritura < LCD_BUFFER_LENGTH) {
		Lcd_Buffer[Lcd_Indice_Escritura] = Data;
		Lcd_Indice_Escritura++;
	}
}

/*------------------------------------------------------------*
función LCD_display_on: enciende el display LCD
*------------------------------------------------------------*/
void LCD_display_on(void) {
	lcd_mode |= 4;
	LCD_send_byte (0,lcd_mode);
}

/*------------------------------------------------------------*
función LCD_display_off: apaga el display LCD
*------------------------------------------------------------*/
void LCD_display_off(void) {
	lcd_mode &= 0b11111011;
	LCD_send_byte (0,lcd_mode);
}

/*------------------------------------------------------------*
función LCD_cursor_on: muestra el cursor del display
*------------------------------------------------------------*/
void LCD_cursor_on(void) {
	lcd_mode |= 2;
	LCD_send_byte (0,lcd_mode);
}

/*------------------------------------------------------------*
función LCD_cursor_off: esconde el cursor del display
*------------------------------------------------------------*/
void LCD_cursor_off(void) {
	lcd_mode &= 0b11111101;
	LCD_send_byte (0,lcd_mode);
}

/*------------------------------------------------------------*
función LCD_cursor_blink_on: activa el titilado del cursor del display
*------------------------------------------------------------*/
void LCD_cursor_blink_on(void) {
	lcd_mode |= 1;
	LCD_send_byte (0,lcd_mode);
}

/*------------------------------------------------------------*
función LCD_cursor_blink_off: desactiva el titilado del cursor del display
*------------------------------------------------------------*/
void LCD_cursor_blink_off(void) {
	lcd_mode &= 0b11111110;
	LCD_send_byte (0,lcd_mode);
}

/*------------------------------------------------------------*
función LCD_end_writing: retorna 1 si el LCD ha terminado de escribir en su pantalla todo el contenido a mostrar
*------------------------------------------------------------*/
uint8_t LCD_end_writing(void) {
	return ((Lcd_Indice_Lectura == 0) & (Lcd_Indice_Escritura == 0));
}
