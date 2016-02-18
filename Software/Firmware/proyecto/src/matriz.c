#include "os.h"               /* <= operating system header */
#include "Os_Cfg.h"
#include "ciaaPOSIX_stdio.h"  /* <= device handler header */
#include "ciaaPOSIX_string.h" /* <= string header */
#include "ciaak.h"            /* <= ciaa kernel header */
#include "proyecto.h"         /* <= header propio del proyecto */
#include "matriz.h"			  /* <= controlador de matriz */
#include "interfaz.h"		  /* <= interfaz entre el programador y la matriz */
#include "switches.h"		  /* <= estado de los switches */
#include "registros.h"

#define CANT_CARACTERES 50

#define VELOCIDAD_1 15
#define VELOCIDAD_2 10
#define VELOCIDAD_3 7

static uint8_t alto_caracter = 7;
static uint8_t velocidad = VELOCIDAD_2;
static uint8_t detener = 0;

static uint8_t matriz_leds[NUM_FILAS][NUM_COLUMNAS];
static int16_t desp_local;
static int16_t desp_minimo = 0;
static int16_t desp = 32767;

static char mensaje[BUFFER_LENGTH];
static uint8_t long_mensaje;

static uint8_t tiempo = 0;

static const uint8_t anchos_max[CANT_CARACTERES] = {6, 6, 3, 6, 0, 6, 6, 4, 6, 6, 6, 6, 6, 6, 6, 6, 0, 0, 0, 6, 0, 0, 0, 6, 6, 6, 6, 6, 6, 6, 6, 4, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 2};
static const uint8_t anchos_min[CANT_CARACTERES] = {4, 4, 3, 4, 0, 4, 5, 4, 5, 5, 4, 5, 5, 5, 5, 5, 0, 0, 0, 5, 0, 0, 0, 5, 5, 5, 5, 5, 5, 5, 5, 4, 5, 5, 5, 4, 5, 5, 5, 5, 5, 5, 4, 5, 4, 4, 4, 4, 5, 2};

static void f_0 (void) {
int8_t i, j;
	if (alto_caracter == 7) {
		const uint8_t caracter[7][6] = 	{
										{0, 1, 1, 1, 0, 0},
										{1, 0, 0, 0, 1, 0},
										{1, 0, 0, 1, 1, 0},
										{1, 0, 1, 0, 1, 0},
										{1, 1, 0, 0, 1, 0},
										{1, 0, 0, 0, 1, 0},
										{0, 1, 1, 1, 0, 0}
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < 6; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
	else {
		const uint8_t caracter[5][5] = 	{
										{1, 1, 1, 1, 0},
										{1, 0, 0, 1, 0},
										{1, 0, 0, 1, 0},
										{1, 0, 0, 1, 0},
										{1, 1, 1, 1, 0}
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < 5; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i+1][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
}

static void f_1 (void) {
int8_t i, j;
	if (alto_caracter == 7) {
		const uint8_t caracter[7][4] = 	{
										{0, 1, 0, 0},
										{1, 1, 0, 0},
										{0, 1, 0, 0},
										{0, 1, 0, 0},
										{0, 1, 0, 0},
										{0, 1, 0, 0},
										{1, 1, 1, 0}
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < 4; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
	else {
		const uint8_t caracter[5][4] = 	{
										{0, 1, 0, 0},
										{1, 1, 0, 0},
										{0, 1, 0, 0},
										{0, 1, 0, 0},
										{1, 1, 1, 0},
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < 4; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i+1][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
}

static void f_2 (void) {
int8_t i, j;
	if (alto_caracter == 7) {
		const uint8_t caracter[7][6] = 	{
										{0, 1, 1, 1, 0, 0},
										{1, 0, 0, 0, 1, 0},
										{0, 0, 0, 0, 1, 0},
										{0, 0, 0, 1, 0, 0},
										{0, 0, 1, 0, 0, 0},
										{0, 1, 0, 0, 0, 0},
										{1, 1, 1, 1, 1, 0}
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < 6; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
	else {
		const uint8_t caracter[5][5] = 	{
										{0, 1, 1, 0, 0},
										{1, 0, 0, 1, 0},
										{0, 0, 1, 0, 0},
										{0, 1, 0, 0, 0},
										{1, 1, 1, 1, 0}
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < 5; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i+1][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
}

static void f_3 (void) {
int8_t i, j;
	if (alto_caracter == 7) {
		const uint8_t caracter[7][6] = 	{
										{1, 1, 1, 1, 1, 0},
										{0, 0, 0, 1, 0, 0},
										{0, 0, 1, 0, 0, 0},
										{0, 0, 0, 1, 0, 0},
										{0, 0, 0, 0, 1, 0},
										{1, 0, 0, 0, 1, 0},
										{0, 1, 1, 1, 0, 0}
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < 6; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
	else {
		const uint8_t caracter[5][5] = 	{
										{1, 1, 1, 0, 0},
										{0, 0, 0, 1, 0},
										{0, 1, 1, 0, 0},
										{0, 0, 0, 1, 0},
										{1, 1, 1, 0, 0}
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < 5; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i+1][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
}

static void f_4 (void) {
int8_t i, j;
	if (alto_caracter == 7) {
		const uint8_t caracter[7][6] = 	{
										{0, 0, 0, 1, 0, 0},
										{0, 0, 1, 1, 0, 0},
										{0, 1, 0, 1, 0, 0},
										{1, 0, 0, 1, 0, 0},
										{1, 1, 1, 1, 1, 0},
										{0, 0, 0, 1, 0, 0},
										{0, 0, 0, 1, 0, 0}
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < 6; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
	else {
		const uint8_t caracter[5][4] = 	{
										{1, 0, 1, 0},
										{1, 0, 1, 0},
										{1, 1, 1, 0},
										{0, 0, 1, 0},
										{0, 0, 1, 0}
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < 4; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i+1][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
}

static void f_5 (void) {
int8_t i, j;
	if (alto_caracter == 7) {
		const uint8_t caracter[7][6] = 	{
										{1, 1, 1, 1, 1, 0},
										{1, 0, 0, 0, 0, 0},
										{1, 1, 1, 1, 0, 0},
										{0, 0, 0, 0, 1, 0},
										{0, 0, 0, 0, 1, 0},
										{1, 0, 0, 0, 1, 0},
										{0, 1, 1, 1, 0, 0}
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < 6; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
	else {
		const uint8_t caracter[5][5] = 	{
										{1, 1, 1, 1, 0},
										{1, 0, 0, 0, 0},
										{1, 1, 1, 0, 0},
										{0, 0, 0, 1, 0},
										{1, 1, 1, 0, 0}
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < 5; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i+1][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
}

static void f_6 (void) {
int8_t i, j;
	if (alto_caracter == 7) {
		const uint8_t caracter[7][6] = 	{
										{0, 0, 1, 1, 0, 0},
										{0, 1, 0, 0, 0, 0},
										{1, 0, 0, 0, 0, 0},
										{1, 1, 1, 1, 0, 0},
										{1, 0, 0, 0, 1, 0},
										{1, 0, 0, 0, 1, 0},
										{0, 1, 1, 1, 0, 0}
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < 6; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
	else {
		const uint8_t caracter[5][5] = 	{
										{0, 1, 1, 1, 0},
										{1, 0, 0, 0, 0},
										{1, 1, 1, 0, 0},
										{1, 0, 0, 1, 0},
										{0, 1, 1, 0, 0}
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < 5; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i+1][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
}

static void f_7 (void) {
int8_t i, j;
	if (alto_caracter == 7) {
		const uint8_t caracter[7][6] = 	{
										{1, 1, 1, 1, 1, 0},
										{0, 0, 0, 0, 1, 0},
										{0, 0, 0, 1, 0, 0},
										{0, 0, 1, 0, 0, 0},
										{0, 1, 0, 0, 0, 0},
										{0, 1, 0, 0, 0, 0},
										{0, 1, 0, 0, 0, 0}
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < 6; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
	else {
		const uint8_t caracter[5][5] = 	{
										{1, 1, 1, 1, 0},
										{0, 0, 0, 1, 0},
										{0, 0, 1, 0, 0},
										{0, 1, 0, 0, 0},
										{0, 1, 0, 0, 0}
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < 5; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i+1][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
}

static void f_8 (void) {
int8_t i, j;
	if (alto_caracter == 7) {
		const uint8_t caracter[7][6] = 	{
										{0, 1, 1, 1, 0, 0},
										{1, 0, 0, 0, 1, 0},
										{1, 0, 0, 0, 1, 0},
										{0, 1, 1, 1, 0, 0},
										{1, 0, 0, 0, 1, 0},
										{1, 0, 0, 0, 1, 0},
										{0, 1, 1, 1, 0, 0}
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < 6; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
	else {
		const uint8_t caracter[5][5] = 	{
										{0, 1, 1, 0, 0},
										{1, 0, 0, 1, 0},
										{0, 1, 1, 0, 0},
										{1, 0, 0, 1, 0},
										{0, 1, 1, 0, 0}
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < 5; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i+1][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
}

static void f_9 (void) {
int8_t i, j;
	if (alto_caracter == 7) {
		const uint8_t caracter[7][6] = 	{
										{0, 1, 1, 1, 0, 0},
										{1, 0, 0, 0, 1, 0},
										{1, 0, 0, 0, 1, 0},
										{0, 1, 1, 1, 1, 0},
										{0, 0, 0, 0, 1, 0},
										{0, 0, 0, 1, 0, 0},
										{0, 1, 1, 0, 0, 0}
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < 6; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
	else {
		const uint8_t caracter[5][5] = 	{
										{0, 1, 1, 0, 0},
										{1, 0, 0, 1, 0},
										{0, 1, 1, 1, 0},
										{0, 0, 0, 1, 0},
										{0, 1, 1, 0, 0}
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < 5; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i+1][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
}

static void f_A (void) {
int8_t i, j;
	if (alto_caracter == 7) {
		const uint8_t caracter[7][6] = 	{
										{0, 1, 1, 1, 0, 0},
										{1, 0, 0, 0, 1, 0},
										{1, 0, 0, 0, 1, 0},
										{1, 1, 1, 1, 1, 0},
										{1, 0, 0, 0, 1, 0},
										{1, 0, 0, 0, 1, 0},
										{1, 0, 0, 0, 1, 0}
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < 6; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
	else {
		const uint8_t caracter[5][5] = 	{
										{0, 1, 1, 0, 0},
										{1, 0, 0, 1, 0},
										{1, 1, 1, 1, 0},
										{1, 0, 0, 1, 0},
										{1, 0, 0, 1, 0}
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < 4; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i+1][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
}

static void f_B (void) {
int8_t i, j;
	if (alto_caracter == 7) {
		const uint8_t caracter[7][6] = 	{
										{1, 1, 1, 1, 0, 0},
										{1, 0, 0, 0, 1, 0},
										{1, 0, 0, 0, 1, 0},
										{1, 1, 1, 1, 0, 0},
										{1, 0, 0, 0, 1, 0},
										{1, 0, 0, 0, 1, 0},
										{1, 1, 1, 1, 0, 0}
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < 6; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
	else {
		const uint8_t caracter[5][5] = 	{
										{1, 1, 1, 0, 0},
										{1, 0, 0, 1, 0},
										{1, 1, 1, 0, 0},
										{1, 0, 0, 1, 0},
										{1, 1, 1, 0, 0}
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < 5; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i+1][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
}

static void f_C (void) {
int8_t i, j;
	if (alto_caracter == 7) {
		const uint8_t caracter[7][6] = 	{
										{0, 1, 1, 1, 0, 0},
										{1, 0, 0, 0, 1, 0},
										{1, 0, 0, 0, 0, 0},
										{1, 0, 0, 0, 0, 0},
										{1, 0, 0, 0, 0, 0},
										{1, 0, 0, 0, 1, 0},
										{0, 1, 1, 1, 0, 0}
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < 6; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
	else {
		const uint8_t caracter[5][5] = 	{
										{0, 1, 1, 1, 0},
										{1, 0, 0, 0, 0},
										{1, 0, 0, 0, 0},
										{1, 0, 0, 0, 0},
										{0, 1, 1, 1, 0}
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < 5; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i+1][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
}

static void f_D (void) {
int8_t i, j;
	if (alto_caracter == 7) {
		const uint8_t caracter[7][6] = 	{
										{1, 1, 1, 0, 0, 0},
										{1, 0, 0, 1, 0, 0},
										{1, 0, 0, 0, 1, 0},
										{1, 0, 0, 0, 1, 0},
										{1, 0, 0, 0, 1, 0},
										{1, 0, 0, 1, 0, 0},
										{1, 1, 1, 0, 0, 0}
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < 6; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
	else {
		const uint8_t caracter[5][5] = 	{
										{1, 1, 1, 0, 0},
										{1, 0, 0, 1, 0},
										{1, 0, 0, 1, 0},
										{1, 0, 0, 1, 0},
										{1, 1, 1, 0, 0}
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < 5; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i+1][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
}

static void f_E (void) {
int8_t i, j;
	if (alto_caracter == 7) {
		const uint8_t caracter[7][6] = 	{
										{1, 1, 1, 1, 1, 0},
										{1, 0, 0, 0, 0, 0},
										{1, 0, 0, 0, 0, 0},
										{1, 1, 1, 1, 0, 0},
										{1, 0, 0, 0, 0, 0},
										{1, 0, 0, 0, 0, 0},
										{1, 1, 1, 1, 1, 0}
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < 6; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
	else {
		const uint8_t caracter[5][5] = 	{
										{1, 1, 1, 1, 0},
										{1, 0, 0, 0, 0},
										{1, 1, 1, 0, 0},
										{1, 0, 0, 0, 0},
										{1, 1, 1, 1, 0}
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < 5; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i+1][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
}

static void f_F (void) {
int8_t i, j;
	if (alto_caracter == 7) {
		const uint8_t caracter[7][6] = 	{
										{1, 1, 1, 1, 1, 0},
										{1, 0, 0, 0, 0, 0},
										{1, 0, 0, 0, 0, 0},
										{1, 1, 1, 1, 0, 0},
										{1, 0, 0, 0, 0, 0},
										{1, 0, 0, 0, 0, 0},
										{1, 0, 0, 0, 0, 0}
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < 6; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
	else {
		const uint8_t caracter[5][5] = 	{
										{1, 1, 1, 1, 0},
										{1, 0, 0, 0, 0},
										{1, 1, 1, 0, 0},
										{1, 0, 0, 0, 0},
										{1, 0, 0, 0, 0}
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < 5; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i+1][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
}

static void f_G (void) {
int8_t i, j;
	if (alto_caracter == 7) {
		const uint8_t caracter[7][6] = 	{
										{0, 1, 1, 1, 0, 0},
										{1, 0, 0, 0, 1, 0},
										{1, 0, 0, 0, 0, 0},
										{1, 0, 1, 1, 1, 0},
										{1, 0, 0, 0, 1, 0},
										{1, 0, 0, 0, 1, 0},
										{0, 1, 1, 1, 1, 0}
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < 6; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
	else {
		const uint8_t caracter[5][5] = 	{
										{0, 1, 1, 1, 0},
										{1, 0, 0, 0, 0},
										{1, 0, 1, 1, 0},
										{1, 0, 0, 1, 0},
										{0, 1, 1, 1, 0}
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < 5; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i+1][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
}

static void f_H (void) {
int8_t i, j;
	if (alto_caracter == 7) {
		const uint8_t caracter[7][6] = 	{
										{1, 0, 0, 0, 1, 0},
										{1, 0, 0, 0, 1, 0},
										{1, 0, 0, 0, 1, 0},
										{1, 1, 1, 1, 1, 0},
										{1, 0, 0, 0, 1, 0},
										{1, 0, 0, 0, 1, 0},
										{1, 0, 0, 0, 1, 0}
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < 6; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
	else {
		const uint8_t caracter[5][5] = 	{
										{1, 0, 0, 1, 0},
										{1, 0, 0, 1, 0},
										{1, 1, 1, 1, 0},
										{1, 0, 0, 1, 0},
										{1, 0, 0, 1, 0}
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < 5; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i+1][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
}

static void f_I (void) {
int8_t i, j;
	if (alto_caracter == 7) {
		const uint8_t caracter[7][4] = 	{
										{1, 1, 1, 0},
										{0, 1, 0, 0},
										{0, 1, 0, 0},
										{0, 1, 0, 0},
										{0, 1, 0, 0},
										{0, 1, 0, 0},
										{1, 1, 1, 0}
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < 4; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
	else {
		const uint8_t caracter[5][4] = 	{
										{1, 1, 1, 0},
										{0, 1, 0, 0},
										{0, 1, 0, 0},
										{0, 1, 0, 0},
										{1, 1, 1, 0}
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < 4; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i+1][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
}

static void f_J (void) {
int8_t i, j;
	if (alto_caracter == 7) {
		const uint8_t caracter[7][6] = 	{
										{0, 0, 1, 1, 1, 0},
										{0, 0, 0, 1, 0, 0},
										{0, 0, 0, 1, 0, 0},
										{0, 0, 0, 1, 0, 0},
										{0, 0, 0, 1, 0, 0},
										{1, 0, 0, 1, 0, 0},
										{0, 1, 1, 0, 0, 0}
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < 6; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
	else {
		const uint8_t caracter[5][5] = 	{
										{0, 0, 0, 1, 0},
										{0, 0, 0, 1, 0},
										{0, 0, 0, 1, 0},
										{1, 0, 0, 1, 0},
										{0, 1, 1, 0, 0}
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < 5; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i+1][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
}

static void f_K (void) {
int8_t i, j;
	if (alto_caracter == 7) {
		const uint8_t caracter[7][6] = 	{
										{1, 0, 0, 0, 1, 0},
										{1, 0, 0, 1, 0, 0},
										{1, 0, 1, 0, 0, 0},
										{1, 1, 0, 0, 0, 0},
										{1, 0, 1, 0, 0, 0},
										{1, 0, 0, 1, 0, 0},
										{1, 0, 0, 0, 1, 0}
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < 6; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
	else {
		const uint8_t caracter[5][5] = 	{
										{1, 0, 0, 1, 0},
										{1, 0, 1, 0, 0},
										{1, 1, 0, 0, 0},
										{1, 0, 1, 0, 0},
										{1, 0, 0, 1, 0}
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < 5; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i+1][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
}

static void f_L (void) {
int8_t i, j;
	if (alto_caracter == 7) {
		const uint8_t caracter[7][6] = 	{
										{1, 0, 0, 0, 0, 0},
										{1, 0, 0, 0, 0, 0},
										{1, 0, 0, 0, 0, 0},
										{1, 0, 0, 0, 0, 0},
										{1, 0, 0, 0, 0, 0},
										{1, 0, 0, 0, 0, 0},
										{1, 1, 1, 1, 1, 0}
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < 6; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
	else {
		const uint8_t caracter[5][5] = 	{
										{1, 0, 0, 0, 0},
										{1, 0, 0, 0, 0},
										{1, 0, 0, 0, 0},
										{1, 0, 0, 0, 0},
										{1, 1, 1, 1, 0}
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < 5; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i+1][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
}

static void f_M (void) {
int8_t i, j;
	if (alto_caracter == 7) {
		const uint8_t caracter[7][6] = 	{
										{1, 0, 0, 0, 1, 0},
										{1, 1, 0, 1, 1, 0},
										{1, 0, 1, 0, 1, 0},
										{1, 0, 1, 0, 1, 0},
										{1, 0, 0, 0, 1, 0},
										{1, 0, 0, 0, 1, 0},
										{1, 0, 0, 0, 1, 0}
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < 6; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
	else {
		const uint8_t caracter[5][4] = 	{
										{1, 0, 1, 0},
										{1, 1, 1, 0},
										{1, 0, 1, 0},
										{1, 0, 1, 0},
										{1, 0, 1, 0}
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < 4; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i+1][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
}

static void f_N (void) {
int8_t i, j;
	if (alto_caracter == 7) {
		const uint8_t caracter[7][6] = 	{
										{1, 0, 0, 0, 1, 0},
										{1, 0, 0, 0, 1, 0},
										{1, 1, 0, 0, 1, 0},
										{1, 0, 1, 0, 1, 0},
										{1, 0, 0, 1, 1, 0},
										{1, 0, 0, 0, 1, 0},
										{1, 0, 0, 0, 1, 0}
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < 6; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
	else {
		const uint8_t caracter[5][5] = 	{
										{1, 0, 0, 1, 0},
										{1, 0, 0, 1, 0},
										{1, 1, 0, 1, 0},
										{1, 0, 1, 1, 0},
										{1, 0, 0, 1, 0}
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < 5; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i+1][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
}

static void f_O (void) {
int8_t i, j;
	if (alto_caracter == 7) {
		const uint8_t caracter[7][6] = 	{
										{0, 1, 1, 1, 0, 0},
										{1, 0, 0, 0, 1, 0},
										{1, 0, 0, 0, 1, 0},
										{1, 0, 0, 0, 1, 0},
										{1, 0, 0, 0, 1, 0},
										{1, 0, 0, 0, 1, 0},
										{0, 1, 1, 1, 0, 0}
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < 6; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
	else {
		const uint8_t caracter[5][5] = 	{
										{0, 1, 1, 0, 0},
										{1, 0, 0, 1, 0},
										{1, 0, 0, 1, 0},
										{1, 0, 0, 1, 0},
										{0, 1, 1, 0, 0}
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < 5; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i+1][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
}

static void f_P (void) {
int8_t i, j;
	if (alto_caracter == 7) {
		const uint8_t caracter[7][6] = 	{
										{1, 1, 1, 1, 0, 0},
										{1, 0, 0, 0, 1, 0},
										{1, 0, 0, 0, 1, 0},
										{1, 1, 1, 1, 0, 0},
										{1, 0, 0, 0, 0, 0},
										{1, 0, 0, 0, 0, 0},
										{1, 0, 0, 0, 0, 0}
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < 6; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
	else {
		const uint8_t caracter[5][5] = 	{
										{1, 1, 1, 0, 0},
										{1, 0, 0, 1, 0},
										{1, 1, 1, 0, 0},
										{1, 0, 0, 0, 0},
										{1, 0, 0, 0, 0}
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < 5; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i+1][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
}

static void f_Q (void) {
int8_t i, j;
	if (alto_caracter == 7) {
		const uint8_t caracter[7][6] = 	{
										{0, 1, 1, 1, 0, 0},
										{1, 0, 0, 0, 1, 0},
										{1, 0, 0, 0, 1, 0},
										{1, 0, 0, 0, 1, 0},
										{1, 0, 1, 0, 1, 0},
										{1, 0, 0, 1, 0, 0},
										{0, 1, 1, 0, 1, 0}
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < 6; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
	else {
		const uint8_t caracter[5][5] = 	{
										{0, 1, 1, 0, 0},
										{1, 0, 0, 1, 0},
										{1, 0, 0, 1, 0},
										{1, 0, 1, 0, 0},
										{0, 1, 0, 1, 0}
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < 5; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i+1][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
}

static void f_R (void) {
int8_t i, j;
	if (alto_caracter == 7) {
		const uint8_t caracter[7][6] = 	{
										{1, 1, 1, 1, 0, 0},
										{1, 0, 0, 0, 1, 0},
										{1, 0, 0, 0, 1, 0},
										{1, 1, 1, 1, 0, 0},
										{1, 0, 1, 0, 0, 0},
										{1, 0, 0, 1, 0, 0},
										{1, 0, 0, 0, 1, 0}
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < 6; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
	else {
		const uint8_t caracter[5][5] = 	{
										{1, 1, 1, 0, 0},
										{1, 0, 0, 1, 0},
										{1, 1, 1, 0, 0},
										{1, 0, 1, 0, 0},
										{1, 0, 0, 1, 0}
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < 5; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i+1][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
}

static void f_S (void) {
int8_t i, j;
	if (alto_caracter == 7) {
		const uint8_t caracter[7][6] = 	{
										{0, 1, 1, 1, 0, 0},
										{1, 0, 0, 0, 1, 0},
										{1, 0, 0, 0, 0, 0},
										{0, 1, 1, 1, 0, 0},
										{0, 0, 0, 0, 1, 0},
										{1, 0, 0, 0, 1, 0},
										{0, 1, 1, 1, 0, 0}
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < 6; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
	else {
		const uint8_t caracter[5][5] = 	{
										{0, 1, 1, 1, 0},
										{1, 0, 0, 0, 0},
										{0, 1, 1, 0, 0},
										{0, 0, 0, 1, 0},
										{1, 1, 1, 0, 0}
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < 5; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i+1][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
}

static void f_T (void) {
int8_t i, j;
	if (alto_caracter == 7) {
		const uint8_t caracter[7][6] = 	{
										{1, 1, 1, 1, 1, 0},
										{0, 0, 1, 0, 0, 0},
										{0, 0, 1, 0, 0, 0},
										{0, 0, 1, 0, 0, 0},
										{0, 0, 1, 0, 0, 0},
										{0, 0, 1, 0, 0, 0},
										{0, 0, 1, 0, 0, 0}
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < 6; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
	else {
		const uint8_t caracter[5][4] = 	{
										{1, 1, 1, 0},
										{0, 1, 0, 0},
										{0, 1, 0, 0},
										{0, 1, 0, 0},
										{0, 1, 0, 0}
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < 4; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i+1][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
}

static void f_U (void) {
int8_t i, j;
	if (alto_caracter == 7) {
		const uint8_t caracter[7][6] = 	{
										{1, 0, 0, 0, 1, 0},
										{1, 0, 0, 0, 1, 0},
										{1, 0, 0, 0, 1, 0},
										{1, 0, 0, 0, 1, 0},
										{1, 0, 0, 0, 1, 0},
										{1, 0, 0, 0, 1, 0},
										{0, 1, 1, 1, 0, 0}
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < 6; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
	else {
		const uint8_t caracter[5][5] = 	{
										{1, 0, 0, 1, 0},
										{1, 0, 0, 1, 0},
										{1, 0, 0, 1, 0},
										{1, 0, 0, 1, 0},
										{0, 1, 1, 0, 0}
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < 5; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i+1][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
}

static void f_V (void) {
int8_t i, j;
	if (alto_caracter == 7) {
		const uint8_t caracter[7][6] = 	{
										{1, 0, 0, 0, 1, 0},
										{1, 0, 0, 0, 1, 0},
										{1, 0, 0, 0, 1, 0},
										{1, 0, 0, 0, 1, 0},
										{1, 0, 0, 0, 1, 0},
										{0, 1, 0, 1, 0, 0},
										{0, 0, 1, 0, 0, 0}
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < 6; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
	else {
		const uint8_t caracter[5][4] = 	{
										{1, 0, 1, 0},
										{1, 0, 1, 0},
										{1, 0, 1, 0},
										{1, 0, 1, 0},
										{0, 1, 0, 0}
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < 4; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i+1][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
}

static void f_W (void) {
int8_t i, j;
	if (alto_caracter == 7) {
		const uint8_t caracter[7][6] = 	{
										{1, 0, 0, 0, 1, 0},
										{1, 0, 0, 0, 1, 0},
										{1, 0, 0, 0, 1, 0},
										{1, 0, 1, 0, 1, 0},
										{1, 0, 1, 0, 1, 0},
										{1, 0, 1, 0, 1, 0},
										{0, 1, 0, 1, 0, 0}
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < 6; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
	else {
		const uint8_t caracter[5][4] = 	{
										{1, 0, 1, 0},
										{1, 0, 1, 0},
										{1, 0, 1, 0},
										{1, 1, 1, 0},
										{1, 0, 1, 0}
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < 4; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i+1][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
}

static void f_X (void) {
int8_t i, j;
	if (alto_caracter == 7) {
		const uint8_t caracter[7][6] = 	{
										{1, 0, 0, 0, 1, 0},
										{1, 0, 0, 0, 1, 0},
										{0, 1, 0, 1, 0, 0},
										{0, 0, 1, 0, 0, 0},
										{0, 1, 0, 1, 0, 0},
										{1, 0, 0, 0, 1, 0},
										{1, 0, 0, 0, 1, 0}
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < 6; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
	else {
		const uint8_t caracter[5][4] = 	{
										{1, 0, 1, 0},
										{1, 0, 1, 0},
										{0, 1, 0, 0},
										{1, 0, 1, 0},
										{1, 0, 1, 0}
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < 4; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i+1][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
}

static void f_Y (void) {
int8_t i, j;
	if (alto_caracter == 7) {
		const uint8_t caracter[7][6] = 	{
										{1, 0, 0, 0, 1, 0},
										{1, 0, 0, 0, 1, 0},
										{1, 0, 0, 0, 1, 0},
										{0, 1, 0, 1, 0, 0},
										{0, 0, 1, 0, 0, 0},
										{0, 0, 1, 0, 0, 0},
										{0, 0, 1, 0, 0, 0}
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < 6; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
	else {
		const uint8_t caracter[5][4] = 	{
										{1, 0, 1, 0},
										{1, 0, 1, 0},
										{0, 1, 0, 0},
										{0, 1, 0, 0},
										{0, 1, 0, 0}
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < 4; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i+1][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
}

static void f_Z (void) {
int8_t i, j;
	if (alto_caracter == 7) {
		const uint8_t caracter[7][6] = 	{
										{1, 1, 1, 1, 1, 0},
										{0, 0, 0, 0, 1, 0},
										{0, 0, 0, 1, 0, 0},
										{0, 0, 1, 0, 0, 0},
										{0, 1, 0, 0, 0, 0},
										{1, 0, 0, 0, 0, 0},
										{1, 1, 1, 1, 1, 0}
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < 6; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
	else {
		const uint8_t caracter[5][5] = 	{
										{1, 1, 1, 1, 0},
										{0, 0, 0, 1, 0},
										{0, 0, 1, 0, 0},
										{0, 1, 0, 0, 0},
										{1, 1, 1, 1, 0}
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < 5; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i+1][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
}

static void f_Sum (void) {
int8_t i, j;
	if (alto_caracter == 7) {
		const uint8_t caracter[7][6] = 	{
										{0, 0, 0, 0, 0, 0},
										{0, 0, 1, 0, 0, 0},
										{0, 0, 1, 0, 0, 0},
										{1, 1, 1, 1, 1, 0},
										{0, 0, 1, 0, 0, 0},
										{0, 0, 1, 0, 0, 0},
										{0, 0, 0, 0, 0, 0}
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < 6; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
	else {
		const uint8_t caracter[5][4] = 	{
										{0, 0, 0, 0},
										{0, 1, 0, 0},
										{1, 1, 1, 0},
										{0, 1, 0, 0},
										{0, 0, 0, 0}
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < 4; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i+1][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
}

static void f_Res (void) {
int8_t i, j;
	if (alto_caracter == 7) {
		const uint8_t caracter[7][6] = 	{
										{0, 0, 0, 0, 0, 0},
										{0, 0, 0, 0, 0, 0},
										{0, 0, 0, 0, 0, 0},
										{1, 1, 1, 1, 1, 0},
										{0, 0, 0, 0, 0, 0},
										{0, 0, 0, 0, 0, 0},
										{0, 0, 0, 0, 0, 0}
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < 6; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
	else {
		const uint8_t caracter[5][4] = 	{
										{0, 0, 0, 0},
										{0, 0, 0, 0},
										{1, 1, 1, 0},
										{0, 0, 0, 0},
										{0, 0, 0, 0}
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < 4; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i+1][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
}

static void f_Mul (void) {
int8_t i, j;
	if (alto_caracter == 7) {
		const uint8_t caracter[7][6] = 	{
										{0, 0, 0, 0, 0, 0},
										{0, 0, 1, 0, 0, 0},
										{1, 0, 1, 0, 1, 0},
										{0, 1, 1, 1, 0, 0},
										{1, 0, 1, 0, 1, 0},
										{0, 0, 1, 0, 0, 0},
										{0, 0, 0, 0, 0, 0}
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < 6; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
	else {
		const uint8_t caracter[5][4] = 	{
										{0, 0, 0, 0},
										{1, 0, 1, 0},
										{0, 1, 0, 0},
										{1, 0, 1, 0},
										{0, 0, 0, 0}
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < 4; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i+1][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
}

static void f_Div (void) {
int8_t i, j;
	if (alto_caracter == 7) {
		const uint8_t caracter[7][6] = 	{
										{0, 0, 0, 0, 0, 0},
										{0, 0, 0, 0, 1, 0},
										{0, 0, 0, 1, 0, 0},
										{0, 0, 1, 0, 0, 0},
										{0, 1, 0, 0, 0, 0},
										{1, 0, 0, 0, 0, 0},
										{0, 0, 0, 0, 0, 0}
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < 6; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
	else {
		const uint8_t caracter[5][4] = 	{
										{0, 0, 0, 0},
										{0, 0, 1, 0},
										{0, 1, 0, 0},
										{1, 0, 0, 0},
										{0, 0, 0, 0}
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < 4; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i+1][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
}

static void f_Igu (void) {
int8_t i, j;
	if (alto_caracter == 7) {
		const uint8_t caracter[7][6] = 	{
										{0, 0, 0, 0, 0, 0},
										{0, 0, 0, 0, 0, 0},
										{1, 1, 1, 1, 1, 0},
										{0, 0, 0, 0, 0, 0},
										{1, 1, 1, 1, 1, 0},
										{0, 0, 0, 0, 0, 0},
										{0, 0, 0, 0, 0, 0}
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < 6; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
	else {
		const uint8_t caracter[5][5] = 	{
										{0, 0, 0, 0, 0},
										{1, 1, 1, 1, 0},
										{0, 0, 0, 0, 0},
										{1, 1, 1, 1, 0},
										{0, 0, 0, 0, 0}
										};
		for (i = 0; i < alto_caracter; ++i) {
				for (j = 0; j < 5; ++j) {
					if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
						matriz_leds[i+1][desp_local+j] = caracter[i][j];
					}
				}
		}
	}
}

static void f_Esp (void) {
int8_t i, j;
	if (alto_caracter == 7) {
		const uint8_t caracter[7][2] = 	{
										{0, 0},
										{0, 0},
										{0, 0},
										{0, 0},
										{0, 0},
										{0, 0},
										{0, 0}
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < 3; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
	else {
		const uint8_t caracter[5][2] = 	{
										{0, 0},
										{0, 0},
										{0, 0},
										{0, 0},
										{0, 0}
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < 3; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i+1][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
}

static void f_Com (void) {
int8_t i, j;
	if (alto_caracter == 7) {
		const uint8_t caracter[7][3] = 	{
										{0, 0, 0},
										{0, 0, 0},
										{0, 0, 0},
										{0, 0, 0},
										{1, 1, 0},
										{0, 1, 0},
										{1, 0, 0}
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < 3; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
	else {
		const uint8_t caracter[5][3] = 	{
										{0, 0, 0},
										{0, 0, 0},
										{1, 1, 0},
										{0, 1, 0},
										{1, 0, 0}
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < 3; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i+1][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
}

static void f_Nula (void) {

}

static void (*f_caracteres[])(void) = {f_Mul, f_Sum, f_Com, f_Res, f_Nula, f_Div, f_0, f_1, f_2, f_3, f_4, f_5, f_6, f_7, f_8, f_9, f_Nula, f_Nula, f_Nula, f_Igu, f_Nula, f_Nula, f_Nula, f_A, f_B, f_C, f_D, f_E, f_F, f_G, f_H, f_I, f_J, f_K, f_L, f_M, f_N, f_O, f_P, f_Q, f_R, f_S, f_T, f_U, f_V, f_W, f_X, f_Y, f_Z, f_Esp};

static void ReinicializarMatriz (void) {
uint8_t i, j;
	for (i = 0; i < NUM_FILAS; ++i) {
		for (j = 0; j < NUM_COLUMNAS; ++j) {
			matriz_leds[i][j] = 0;
		}
	}
	Registros_EscribirMatriz (matriz_leds);
}

static void ReinicializarValores (void) {
	desp = 32767;
	desp_minimo = 0;
	tiempo = 0;
	alto_caracter = 7;
	velocidad = VELOCIDAD_2;
	detener = 0;
}

static uint8_t DesplazarIzquierda_RangoValido (void) {
	return ((desp > desp_minimo) & (desp < NUM_COLUMNAS));
}

static void Matriz_DespMinimo (void) {
uint8_t cod_ascii;
uint8_t i;
	desp_minimo = 0;
	for (i = 0; i < long_mensaje-1; ++i) {
		cod_ascii = (unsigned char)(mensaje[i]);
		if (alto_caracter == 7) {
			if ((cod_ascii >= 42) & (cod_ascii <= 90)) {
				desp_minimo -= anchos_max[cod_ascii-42];
			}
			else if (cod_ascii == 32) {
				desp_minimo -= anchos_max[49];
			}
		}
		else {
			if ((cod_ascii >= 42) & (cod_ascii <= 90)) {
				desp_minimo -= anchos_min[cod_ascii-42];
			}
			else if (cod_ascii == 32) {
				desp_minimo -= anchos_min[49];
			}
		}
	}
	cod_ascii = (unsigned char)(mensaje[long_mensaje-1]);
	if (alto_caracter == 7) {
		if ((cod_ascii >= 42) & (cod_ascii <= 90)) {
			desp_minimo -= (anchos_max[cod_ascii-42] - 1);
		}
		else if (cod_ascii == 32) {
			desp_minimo -= (anchos_max[49] - 1);
		}
	}
	else {
		if ((cod_ascii >= 42) & (cod_ascii <= 90)) {
			desp_minimo -= (anchos_min[cod_ascii-42] - 1);
		}
		else if (cod_ascii == 32) {
			desp_minimo -= (anchos_min[49] - 1);
		}
	}
}

static void Matriz_AumentarDesp (void) {
uint8_t cod_ascii;
int16_t desp_aux = desp;
uint8_t i_mensaje = 0;
	cod_ascii = (unsigned char)(mensaje[i_mensaje]);
	if ((cod_ascii >= 42) & (cod_ascii <= 90)) {
		desp_aux += anchos_max[cod_ascii-42];
	}
	else if (cod_ascii == 32) {
		desp_aux += anchos_max[49];
	}
	while (desp_aux < 0) {
		if ((cod_ascii >= 42) & (cod_ascii <= 90)) {
			if (anchos_max[cod_ascii-42] == 6) {
				if (anchos_min[cod_ascii-42] == 4) {
					desp += 2;
				}
				else {
					desp += 1;
				}
			}
		}
		++i_mensaje;
		cod_ascii = (unsigned char)(mensaje[i_mensaje]);
		if ((cod_ascii >= 42) & (cod_ascii <= 90)) {
			desp_aux += anchos_max[cod_ascii-42];
		}
		else if (cod_ascii == 32) {
			desp_aux += anchos_max[49];
		}
	}
	if (desp < 0) {
		if ((cod_ascii >= 42) & (cod_ascii <= 90)) {
			if (anchos_max[cod_ascii-42] == 6) {
				if (anchos_min[cod_ascii-42] == 4) {
					desp += 2;
				}
				else {
					desp += 1;
				}
			}
		}
	}
}

static void Matriz_DisminuirDesp (void) {
uint8_t cod_ascii;
int16_t desp_aux = desp;
uint8_t i_mensaje = 0;
	cod_ascii = (unsigned char)(mensaje[i_mensaje]);
	if ((cod_ascii >= 42) & (cod_ascii <= 90)) {
		desp_aux += anchos_min[cod_ascii-42];
	}
	else if (cod_ascii == 32) {
		desp_aux += anchos_min[49];
	}
	while (desp_aux < 0) {
		if ((cod_ascii >= 42) & (cod_ascii <= 90)) {
			if (anchos_max[cod_ascii-42] == 6) {
				if (anchos_min[cod_ascii-42] == 4) {
					desp -= 2;
				}
				else {
					desp -= 1;
				}
			}
		}
		++i_mensaje;
		cod_ascii = (unsigned char)(mensaje[i_mensaje]);
		if ((cod_ascii >= 42) & (cod_ascii <= 90)) {
			desp_aux += anchos_min[cod_ascii-42];
		}
		else if (cod_ascii == 32) {
			desp_aux += anchos_min[49];
		}
	}
	if (desp < 0) {
		if ((cod_ascii >= 42) & (cod_ascii <= 90)) {
			if (anchos_max[cod_ascii-42] == 6) {
				if (anchos_min[cod_ascii-42] == 4) {
					desp -= 2;
				}
				else {
					desp -= 1;
				}
			}
		}
	}
}

static void Matriz_EscribirCaracter (const char caracter, uint8_t i_buffer) {
	mensaje[i_buffer] = caracter;
}

void Matriz_Inicializar (void) {
uint8_t i;
	ReinicializarMatriz();
	for (i = 0; i < NUM_COLUMNAS; ++i)
		Registros_ActivarColumna();
	ReinicializarValores();
}

void Matriz_EscribirMensaje (const char* buffer, uint8_t long_buffer) {
uint8_t i = 0;
	for (i = 0; i < long_buffer; ++i)
		Matriz_EscribirCaracter (buffer[i], i);
	long_mensaje = long_buffer;
	Matriz_DespMinimo();
}

void Matriz_BorrarMensaje (void) {
	ReinicializarMatriz();
	ReinicializarValores();
}

void Matriz_DesplazarMensaje (void) {
const uint8_t estado = Switches_GetEstado();
uint8_t indice_mensaje = 0;
uint8_t rango_valido = DesplazarIzquierda_RangoValido();
uint8_t cod_ascii;
	if ( ((estado == 4) | (estado == 9) | (estado == 10)) ) {
		if (rango_valido == 0) {
			desp = NUM_COLUMNAS-1;
			rango_valido = DesplazarIzquierda_RangoValido();
		}
		if (++tiempo == velocidad) {
			ReinicializarMatriz();
			if (rango_valido == 1) {
				desp_local = desp;
				while ((desp_local < NUM_COLUMNAS) & (indice_mensaje < long_mensaje)) {
					cod_ascii = (unsigned char)(mensaje[indice_mensaje]);
					if ((cod_ascii >= 42) & (cod_ascii <= 90)) {
						(*f_caracteres[cod_ascii-42])();
					}
					else if (cod_ascii == 32) {
						(*f_caracteres[49])();
					}
					if (alto_caracter == 7) {
						if ((cod_ascii >= 42) & (cod_ascii <= 90)) {
							desp_local += anchos_max[cod_ascii-42];
						}
						else if (cod_ascii == 32) {
							desp_local += anchos_max[49];
						}
					}
					else {
						if ((cod_ascii >= 42) & (cod_ascii <= 90)) {
							desp_local += anchos_min[cod_ascii-42];
						}
						else if (cod_ascii == 32) {
							desp_local += anchos_min[49];
						}
					}
					++indice_mensaje;
				}
				if (detener == 0) {
					--desp;
				}
			}
			Registros_EscribirMatriz (matriz_leds);
			tiempo = 0;
		}
	}
}

void Matriz_CambiarSize (void) {
	if (alto_caracter == 7) {
		alto_caracter = 5;
		Matriz_AumentarDesp();
	}
	else {
		alto_caracter = 7;
		Matriz_DisminuirDesp();
	}
	Matriz_DespMinimo();
}

void Matriz_CambiarVelocidad_Desplazar (void) {
	if (detener == 0) {
		if (velocidad == VELOCIDAD_1)
			velocidad = VELOCIDAD_2;
		else if (velocidad == VELOCIDAD_2)
			velocidad = VELOCIDAD_3;
		else
			velocidad = VELOCIDAD_1;
	}
	else if (++desp == NUM_COLUMNAS) {
		desp = desp_minimo + 1;
	}
	tiempo = 0;
}

void Matriz_CambiarDetener (void) {
	if (detener == 0) {
		detener = 1;
		++desp;
	}
	else {
		detener = 0;
		--desp;
	}
	tiempo = 0;
}
