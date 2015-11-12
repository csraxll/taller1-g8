#include "os.h"               /* <= operating system header */
#include "Os_Cfg.h"
#include "ciaaPOSIX_stdio.h"  /* <= device handler header */
#include "ciaaPOSIX_string.h" /* <= string header */
#include "ciaak.h"            /* <= ciaa kernel header */
#include "proyecto.h"         /* <= header propio del proyecto */
#include "matriz.h"			  /* <= controlador de matriz */
#include "interfaz.h"		  /* <= interfaz entre el programador y la matriz */
#include "switches.h"		  /* <= estado de los switches */

static uint8_t ancho_caracter = 5;
static uint8_t alto_caracter = 8;

static uint8_t matriz_leds[NUM_FILAS][NUM_COLUMNAS];
static int16_t desp_local;

static void f_0 (void) {
int8_t i, j;
	if (alto_caracter == 8) {
		const uint8_t caracter[8][5] = 	{
										{1, 1, 1, 1, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 1, 1, 1, 1}
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < ancho_caracter; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
	else {
		const uint8_t caracter[6][4] = 	{
										{1, 1, 1, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1}
										};
		for (i = 0; i < alto_caracter; ++i) {
				for (j = 0; j < ancho_caracter; ++j) {
					if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
						matriz_leds[i+1][desp_local+j] = caracter[i][j];
					}
				}
		}
	}
}

static void f_1 (void) {
int8_t i, j;
	if (alto_caracter == 8) {
		const uint8_t caracter[8][5] = 	{
										{1, 1, 1, 1, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 1, 1, 1, 1}
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < ancho_caracter; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
	else {
		const uint8_t caracter[6][4] = 	{
										{1, 1, 1, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1}
										};
		for (i = 0; i < alto_caracter; ++i) {
				for (j = 0; j < ancho_caracter; ++j) {
					if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
						matriz_leds[i+1][desp_local+j] = caracter[i][j];
					}
				}
		}
	}
}

static void f_2 (void) {
int8_t i, j;
	if (alto_caracter == 8) {
		const uint8_t caracter[8][5] = 	{
										{1, 1, 1, 1, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 1, 1, 1, 1}
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < ancho_caracter; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
	else {
		const uint8_t caracter[6][4] = 	{
										{1, 1, 1, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1}
										};
		for (i = 0; i < alto_caracter; ++i) {
				for (j = 0; j < ancho_caracter; ++j) {
					if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
						matriz_leds[i+1][desp_local+j] = caracter[i][j];
					}
				}
		}
	}
}

static void f_3 (void) {
int8_t i, j;
	if (alto_caracter == 8) {
		const uint8_t caracter[8][5] = 	{
										{1, 1, 1, 1, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 1, 1, 1, 1}
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < ancho_caracter; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
	else {
		const uint8_t caracter[6][4] = 	{
										{1, 1, 1, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1}
										};
		for (i = 0; i < alto_caracter; ++i) {
				for (j = 0; j < ancho_caracter; ++j) {
					if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
						matriz_leds[i+1][desp_local+j] = caracter[i][j];
					}
				}
		}
	}
}

static void f_4 (void) {
int8_t i, j;
	if (alto_caracter == 8) {
		const uint8_t caracter[8][5] = 	{
										{1, 1, 1, 1, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 1, 1, 1, 1}
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < ancho_caracter; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
	else {
		const uint8_t caracter[6][4] = 	{
										{1, 1, 1, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1}
										};
		for (i = 0; i < alto_caracter; ++i) {
				for (j = 0; j < ancho_caracter; ++j) {
					if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
						matriz_leds[i+1][desp_local+j] = caracter[i][j];
					}
				}
		}
	}
}

static void f_5 (void) {
int8_t i, j;
	if (alto_caracter == 8) {
		const uint8_t caracter[8][5] = 	{
										{1, 1, 1, 1, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 1, 1, 1, 1}
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < ancho_caracter; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
	else {
		const uint8_t caracter[6][4] = 	{
										{1, 1, 1, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1}
										};
		for (i = 0; i < alto_caracter; ++i) {
				for (j = 0; j < ancho_caracter; ++j) {
					if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
						matriz_leds[i+1][desp_local+j] = caracter[i][j];
					}
				}
		}
	}
}

static void f_6 (void) {
int8_t i, j;
	if (alto_caracter == 8) {
		const uint8_t caracter[8][5] = 	{
										{1, 1, 1, 1, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 1, 1, 1, 1}
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < ancho_caracter; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
	else {
		const uint8_t caracter[6][4] = 	{
										{1, 1, 1, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1}
										};
		for (i = 0; i < alto_caracter; ++i) {
				for (j = 0; j < ancho_caracter; ++j) {
					if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
						matriz_leds[i+1][desp_local+j] = caracter[i][j];
					}
				}
		}
	}
}

static void f_7 (void) {
int8_t i, j;
	if (alto_caracter == 8) {
		const uint8_t caracter[8][5] = 	{
										{1, 1, 1, 1, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 1, 1, 1, 1}
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < ancho_caracter; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
	else {
		const uint8_t caracter[6][4] = 	{
										{1, 1, 1, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1}
										};
		for (i = 0; i < alto_caracter; ++i) {
				for (j = 0; j < ancho_caracter; ++j) {
					if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
						matriz_leds[i+1][desp_local+j] = caracter[i][j];
					}
				}
		}
	}
}

static void f_8 (void) {
int8_t i, j;
	if (alto_caracter == 8) {
		const uint8_t caracter[8][5] = 	{
										{1, 1, 1, 1, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 1, 1, 1, 1}
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < ancho_caracter; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
	else {
		const uint8_t caracter[6][4] = 	{
										{1, 1, 1, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1}
										};
		for (i = 0; i < alto_caracter; ++i) {
				for (j = 0; j < ancho_caracter; ++j) {
					if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
						matriz_leds[i+1][desp_local+j] = caracter[i][j];
					}
				}
		}
	}
}

static void f_9 (void) {
int8_t i, j;
	if (alto_caracter == 8) {
		const uint8_t caracter[8][5] = 	{
										{1, 1, 1, 1, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 1, 1, 1, 1}
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < ancho_caracter; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
	else {
		const uint8_t caracter[6][4] = 	{
										{1, 1, 1, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1}
										};
		for (i = 0; i < alto_caracter; ++i) {
				for (j = 0; j < ancho_caracter; ++j) {
					if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
						matriz_leds[i+1][desp_local+j] = caracter[i][j];
					}
				}
		}
	}
}

static void f_A (void) {
int8_t i, j;
	if (alto_caracter == 8) {
		const uint8_t caracter[8][5] = 	{
										{1, 1, 1, 1, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 1, 1, 1, 1}
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < ancho_caracter; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
	else {
		const uint8_t caracter[6][4] = 	{
										{1, 1, 1, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1}
										};
		for (i = 0; i < alto_caracter; ++i) {
				for (j = 0; j < ancho_caracter; ++j) {
					if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
						matriz_leds[i+1][desp_local+j] = caracter[i][j];
					}
				}
		}
	}
}

static void f_B (void) {
int8_t i, j;
	if (alto_caracter == 8) {
		const uint8_t caracter[8][5] = 	{
										{1, 1, 1, 1, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 1, 1, 1, 1}
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < ancho_caracter; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
	else {
		const uint8_t caracter[6][4] = 	{
										{1, 1, 1, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1}
										};
		for (i = 0; i < alto_caracter; ++i) {
				for (j = 0; j < ancho_caracter; ++j) {
					if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
						matriz_leds[i+1][desp_local+j] = caracter[i][j];
					}
				}
		}
	}
}

static void f_C (void) {
int8_t i, j;
	if (alto_caracter == 8) {
		const uint8_t caracter[8][5] = 	{
										{1, 1, 1, 1, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 1, 1, 1, 1}
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < ancho_caracter; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
	else {
		const uint8_t caracter[6][4] = 	{
										{1, 1, 1, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1}
										};
		for (i = 0; i < alto_caracter; ++i) {
				for (j = 0; j < ancho_caracter; ++j) {
					if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
						matriz_leds[i+1][desp_local+j] = caracter[i][j];
					}
				}
		}
	}
}

static void f_D (void) {
int8_t i, j;
	if (alto_caracter == 8) {
		const uint8_t caracter[8][5] = 	{
										{1, 1, 1, 1, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 1, 1, 1, 1}
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < ancho_caracter; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
	else {
		const uint8_t caracter[6][4] = 	{
										{1, 1, 1, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1}
										};
		for (i = 0; i < alto_caracter; ++i) {
				for (j = 0; j < ancho_caracter; ++j) {
					if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
						matriz_leds[i+1][desp_local+j] = caracter[i][j];
					}
				}
		}
	}
}

static void f_E (void) {
int8_t i, j;
	if (alto_caracter == 8) {
		const uint8_t caracter[8][5] = 	{
										{1, 1, 1, 1, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 1, 1, 1, 1}
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < ancho_caracter; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
	else {
		const uint8_t caracter[6][4] = 	{
										{1, 1, 1, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1}
										};
		for (i = 0; i < alto_caracter; ++i) {
				for (j = 0; j < ancho_caracter; ++j) {
					if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
						matriz_leds[i+1][desp_local+j] = caracter[i][j];
					}
				}
		}
	}
}

static void f_F (void) {
int8_t i, j;
	if (alto_caracter == 8) {
		const uint8_t caracter[8][5] = 	{
										{1, 1, 1, 1, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 1, 1, 1, 1}
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < ancho_caracter; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
	else {
		const uint8_t caracter[6][4] = 	{
										{1, 1, 1, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1}
										};
		for (i = 0; i < alto_caracter; ++i) {
				for (j = 0; j < ancho_caracter; ++j) {
					if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
						matriz_leds[i+1][desp_local+j] = caracter[i][j];
					}
				}
		}
	}
}

static void f_G (void) {
int8_t i, j;
	if (alto_caracter == 8) {
		const uint8_t caracter[8][5] = 	{
										{1, 1, 1, 1, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 1, 1, 1, 1}
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < ancho_caracter; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
	else {
		const uint8_t caracter[6][4] = 	{
										{1, 1, 1, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1}
										};
		for (i = 0; i < alto_caracter; ++i) {
				for (j = 0; j < ancho_caracter; ++j) {
					if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
						matriz_leds[i+1][desp_local+j] = caracter[i][j];
					}
				}
		}
	}
}

static void f_H (void) {
int8_t i, j;
	if (alto_caracter == 8) {
		const uint8_t caracter[8][5] = 	{
										{1, 1, 1, 1, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 1, 1, 1, 1}
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < ancho_caracter; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
	else {
		const uint8_t caracter[6][4] = 	{
										{1, 1, 1, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1}
										};
		for (i = 0; i < alto_caracter; ++i) {
				for (j = 0; j < ancho_caracter; ++j) {
					if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
						matriz_leds[i+1][desp_local+j] = caracter[i][j];
					}
				}
		}
	}
}

static void f_I (void) {
int8_t i, j;
	if (alto_caracter == 8) {
		const uint8_t caracter[8][5] = 	{
										{1, 1, 1, 1, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 1, 1, 1, 1}
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < ancho_caracter; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
	else {
		const uint8_t caracter[6][4] = 	{
										{1, 1, 1, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1}
										};
		for (i = 0; i < alto_caracter; ++i) {
				for (j = 0; j < ancho_caracter; ++j) {
					if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
						matriz_leds[i+1][desp_local+j] = caracter[i][j];
					}
				}
		}
	}
}

static void f_J (void) {
int8_t i, j;
	if (alto_caracter == 8) {
		const uint8_t caracter[8][5] = 	{
										{1, 1, 1, 1, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 1, 1, 1, 1}
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < ancho_caracter; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
	else {
		const uint8_t caracter[6][4] = 	{
										{1, 1, 1, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1}
										};
		for (i = 0; i < alto_caracter; ++i) {
				for (j = 0; j < ancho_caracter; ++j) {
					if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
						matriz_leds[i+1][desp_local+j] = caracter[i][j];
					}
				}
		}
	}
}

static void f_K (void) {
int8_t i, j;
	if (alto_caracter == 8) {
		const uint8_t caracter[8][5] = 	{
										{1, 1, 1, 1, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 1, 1, 1, 1}
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < ancho_caracter; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
	else {
		const uint8_t caracter[6][4] = 	{
										{1, 1, 1, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1}
										};
		for (i = 0; i < alto_caracter; ++i) {
				for (j = 0; j < ancho_caracter; ++j) {
					if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
						matriz_leds[i+1][desp_local+j] = caracter[i][j];
					}
				}
		}
	}
}

static void f_L (void) {
int8_t i, j;
	if (alto_caracter == 8) {
		const uint8_t caracter[8][5] = 	{
										{1, 1, 1, 1, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 1, 1, 1, 1}
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < ancho_caracter; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
	else {
		const uint8_t caracter[6][4] = 	{
										{1, 1, 1, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1}
										};
		for (i = 0; i < alto_caracter; ++i) {
				for (j = 0; j < ancho_caracter; ++j) {
					if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
						matriz_leds[i+1][desp_local+j] = caracter[i][j];
					}
				}
		}
	}
}

static void f_M (void) {
int8_t i, j;
	if (alto_caracter == 8) {
		const uint8_t caracter[8][5] = 	{
										{1, 1, 1, 1, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 1, 1, 1, 1}
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < ancho_caracter; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
	else {
		const uint8_t caracter[6][4] = 	{
										{1, 1, 1, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1}
										};
		for (i = 0; i < alto_caracter; ++i) {
				for (j = 0; j < ancho_caracter; ++j) {
					if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
						matriz_leds[i+1][desp_local+j] = caracter[i][j];
					}
				}
		}
	}
}

static void f_N (void) {
int8_t i, j;
	if (alto_caracter == 8) {
		const uint8_t caracter[8][5] = 	{
										{1, 1, 1, 1, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 1, 1, 1, 1}
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < ancho_caracter; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
	else {
		const uint8_t caracter[6][4] = 	{
										{1, 1, 1, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1}
										};
		for (i = 0; i < alto_caracter; ++i) {
				for (j = 0; j < ancho_caracter; ++j) {
					if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
						matriz_leds[i+1][desp_local+j] = caracter[i][j];
					}
				}
		}
	}
}

static void f_O (void) {
int8_t i, j;
	if (alto_caracter == 8) {
		const uint8_t caracter[8][5] = 	{
										{1, 1, 1, 1, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 1, 1, 1, 1}
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < ancho_caracter; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
	else {
		const uint8_t caracter[6][4] = 	{
										{1, 1, 1, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1}
										};
		for (i = 0; i < alto_caracter; ++i) {
				for (j = 0; j < ancho_caracter; ++j) {
					if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
						matriz_leds[i+1][desp_local+j] = caracter[i][j];
					}
				}
		}
	}
}

static void f_P (void) {
int8_t i, j;
	if (alto_caracter == 8) {
		const uint8_t caracter[8][5] = 	{
										{1, 1, 1, 1, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 1, 1, 1, 1}
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < ancho_caracter; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
	else {
		const uint8_t caracter[6][4] = 	{
										{1, 1, 1, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1}
										};
		for (i = 0; i < alto_caracter; ++i) {
				for (j = 0; j < ancho_caracter; ++j) {
					if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
						matriz_leds[i+1][desp_local+j] = caracter[i][j];
					}
				}
		}
	}
}

static void f_Q (void) {
int8_t i, j;
	if (alto_caracter == 8) {
		const uint8_t caracter[8][5] = 	{
										{1, 1, 1, 1, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 1, 1, 1, 1}
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < ancho_caracter; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
	else {
		const uint8_t caracter[6][4] = 	{
										{1, 1, 1, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1}
										};
		for (i = 0; i < alto_caracter; ++i) {
				for (j = 0; j < ancho_caracter; ++j) {
					if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
						matriz_leds[i+1][desp_local+j] = caracter[i][j];
					}
				}
		}
	}
}

static void f_R (void) {
int8_t i, j;
	if (alto_caracter == 8) {
		const uint8_t caracter[8][5] = 	{
										{1, 1, 1, 1, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 1, 1, 1, 1}
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < ancho_caracter; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
	else {
		const uint8_t caracter[6][4] = 	{
										{1, 1, 1, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1}
										};
		for (i = 0; i < alto_caracter; ++i) {
				for (j = 0; j < ancho_caracter; ++j) {
					if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
						matriz_leds[i+1][desp_local+j] = caracter[i][j];
					}
				}
		}
	}
}

static void f_S (void) {
int8_t i, j;
	if (alto_caracter == 8) {
		const uint8_t caracter[8][5] = 	{
										{1, 1, 1, 1, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 1, 1, 1, 1}
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < ancho_caracter; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
	else {
		const uint8_t caracter[6][4] = 	{
										{1, 1, 1, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1}
										};
		for (i = 0; i < alto_caracter; ++i) {
				for (j = 0; j < ancho_caracter; ++j) {
					if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
						matriz_leds[i+1][desp_local+j] = caracter[i][j];
					}
				}
		}
	}
}

static void f_T (void) {
int8_t i, j;
	if (alto_caracter == 8) {
		const uint8_t caracter[8][5] = 	{
										{1, 1, 1, 1, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 1, 1, 1, 1}
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < ancho_caracter; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
	else {
		const uint8_t caracter[6][4] = 	{
										{1, 1, 1, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1}
										};
		for (i = 0; i < alto_caracter; ++i) {
				for (j = 0; j < ancho_caracter; ++j) {
					if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
						matriz_leds[i+1][desp_local+j] = caracter[i][j];
					}
				}
		}
	}
}

static void f_U (void) {
int8_t i, j;
	if (alto_caracter == 8) {
		const uint8_t caracter[8][5] = 	{
										{1, 1, 1, 1, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 1, 1, 1, 1}
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < ancho_caracter; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
	else {
		const uint8_t caracter[6][4] = 	{
										{1, 1, 1, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1}
										};
		for (i = 0; i < alto_caracter; ++i) {
				for (j = 0; j < ancho_caracter; ++j) {
					if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
						matriz_leds[i+1][desp_local+j] = caracter[i][j];
					}
				}
		}
	}
}

static void f_V (void) {
int8_t i, j;
	if (alto_caracter == 8) {
		const uint8_t caracter[8][5] = 	{
										{1, 1, 1, 1, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 1, 1, 1, 1}
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < ancho_caracter; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
	else {
		const uint8_t caracter[6][4] = 	{
										{1, 1, 1, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1}
										};
		for (i = 0; i < alto_caracter; ++i) {
				for (j = 0; j < ancho_caracter; ++j) {
					if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
						matriz_leds[i+1][desp_local+j] = caracter[i][j];
					}
				}
		}
	}
}

static void f_W (void) {
int8_t i, j;
	if (alto_caracter == 8) {
		const uint8_t caracter[8][5] = 	{
										{1, 1, 1, 1, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 1, 1, 1, 1}
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < ancho_caracter; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
	else {
		const uint8_t caracter[6][4] = 	{
										{1, 1, 1, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1}
										};
		for (i = 0; i < alto_caracter; ++i) {
				for (j = 0; j < ancho_caracter; ++j) {
					if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
						matriz_leds[i+1][desp_local+j] = caracter[i][j];
					}
				}
		}
	}
}

static void f_X (void) {
int8_t i, j;
	if (alto_caracter == 8) {
		const uint8_t caracter[8][5] = 	{
										{1, 1, 1, 1, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 1, 1, 1, 1}
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < ancho_caracter; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
	else {
		const uint8_t caracter[6][4] = 	{
										{1, 1, 1, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1}
										};
		for (i = 0; i < alto_caracter; ++i) {
				for (j = 0; j < ancho_caracter; ++j) {
					if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
						matriz_leds[i+1][desp_local+j] = caracter[i][j];
					}
				}
		}
	}
}

static void f_Y (void) {
int8_t i, j;
	if (alto_caracter == 8) {
		const uint8_t caracter[8][5] = 	{
										{1, 1, 1, 1, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 1, 1, 1, 1}
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < ancho_caracter; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
	else {
		const uint8_t caracter[6][4] = 	{
										{1, 1, 1, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1}
										};
		for (i = 0; i < alto_caracter; ++i) {
				for (j = 0; j < ancho_caracter; ++j) {
					if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
						matriz_leds[i+1][desp_local+j] = caracter[i][j];
					}
				}
		}
	}
}

static void f_Z (void) {
int8_t i, j;
	if (alto_caracter == 8) {
		const uint8_t caracter[8][5] = 	{
										{1, 1, 1, 1, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 0, 0, 0, 1},
										{1, 1, 1, 1, 1}
										};
		for (i = 0; i < alto_caracter; ++i) {
			for (j = 0; j < ancho_caracter; ++j) {
				if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
					matriz_leds[i][desp_local+j] = caracter[i][j];
				}
			}
		}
	}
	else {
		const uint8_t caracter[6][4] = 	{
										{1, 1, 1, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1},
										{1, 0, 0, 1}
										};
		for (i = 0; i < alto_caracter; ++i) {
				for (j = 0; j < ancho_caracter; ++j) {
					if ((desp_local >= -j) & (desp_local < NUM_COLUMNAS-j)) {
						matriz_leds[i+1][desp_local+j] = caracter[i][j];
					}
				}
		}
	}
}

static void (*f_caracteres[])(void) = {f_0, f_1, f_2, f_3, f_4, f_5, f_6, f_7, f_8, f_9, f_A, f_B, f_C, f_D, f_E, f_F, f_G, f_H, f_I, f_J, f_K, f_L, f_M, f_N, f_O, f_P, f_Q, f_R, f_S, f_T, f_U, f_V, f_W, f_X, f_Y, f_Z};

static void Reinicializar (void) {
uint8_t i, j;
	for (i = 0; i < NUM_FILAS; ++i) {
		for (j = 0; j < NUM_COLUMNAS; ++j) {
			matriz_leds[i][j] = 0;
		}
	}
}

void Matriz_EscribirMensaje (void) {
static uint8_t num_mensaje = 0;
const char *mensaje = Interfaz_Mensaje(num_mensaje);
const uint8_t long_mensaje = Interfaz_LongitudMensaje(num_mensaje);
const int16_t desp_maximo = long_mensaje*ancho_caracter;
const int16_t desp_minimo = -long_mensaje*ancho_caracter;
const uint8_t cant_mensajes = Interfaz_CantidadMensajes();
static int16_t desp = 32767;
static uint8_t tiempo = 0;
uint8_t cod_ascii;
uint8_t indice_mensaje = 0;
	if (++tiempo == Switches_GetVelocidad()) {
		Reinicializar();
		desp_local = desp;
		if (Switches_GetSmallSize() == 0) {
			ancho_caracter = 5;
			alto_caracter = 8;
		}
		else {
			ancho_caracter = 4;
			alto_caracter = 6;
		}
		if (Switches_GetCambiarMensaje() == 1) {
			num_mensaje = (num_mensaje + 1) % cant_mensajes;
			desp = desp_minimo;
			Switches_MensajeCambiado();
		}
		if ((desp > desp_minimo) & (desp < desp_maximo)) {
			while ((desp_local < NUM_COLUMNAS) & (indice_mensaje < long_mensaje)) {
				cod_ascii = (unsigned char)(mensaje[indice_mensaje]);
				if (cod_ascii < 60)                     // el carácter es un dígito
					(*f_caracteres[cod_ascii-48])();
				else                                    // el carácter es una letra
					(*f_caracteres[cod_ascii-55])();
				desp_local += ancho_caracter;
				++indice_mensaje;
			}
			if (Switches_GetDesplazarIzquierda() == 1) {
				--desp;
			}
			else {
				++desp;
			}
		}
		else {
			if (Switches_GetDesplazarIzquierda() == 1) {
				desp = NUM_COLUMNAS;
			}
			else {
				desp = -1;
			}
			num_mensaje = (num_mensaje + 1) % cant_mensajes;
		}
		tiempo = 0;
	}
}

void Matriz_GetMatriz (uint8_t matriz[NUM_FILAS][NUM_COLUMNAS]) {
	matriz = matriz_leds;
}
