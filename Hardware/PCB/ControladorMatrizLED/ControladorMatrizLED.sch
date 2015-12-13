EESchema Schematic File Version 2
LIBS:Poncho_Esqueleto
LIBS:Misc_Poncho_Grande
LIBS:74xx
LIBS:device
LIBS:conn
LIBS:power
LIBS:ControladorMatrizLED-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 3
Title "Poncho Grande - Modelo - Ejemplo - Template"
Date "2015-10-06"
Rev "1.0"
Comp "Proyecto CIAA - COMPUTADORA INDUSTRIAL ABIERTA ARGENTINA"
Comment1 "https://github.com/ciaa/Ponchos/tree/master/modelos/doc"
Comment2 "Autores y Licencia del template (Diego Brengi - UNLaM)"
Comment3 "Autor del poncho (COMPLETAR NOMBRE Y APELLIDO). Ver directorio \"doc\""
Comment4 "CÓDIGO PONCHO:"
$EndDescr
$Comp
L OSHWA #G2
U 1 1 560A0A28
P 10800 6050
F 0 "#G2" H 10770 6450 60  0001 C CNN
F 1 "OSHWA" H 10800 6353 60  0001 C CNN
F 2 "mod:OSHWA" H 10800 6050 60  0001 C CNN
F 3 "" H 10800 6050 60  0000 C CNN
	1    10800 6050
	1    0    0    -1  
$EndComp
$Sheet
S 1400 1200 1350 5600
U 560A0C15
F0 "Conector del Poncho" 50
F1 "conector_poncho.sch" 50
F2 "RESET" I R 2750 1250 60 
F3 "ISP" B R 2750 1350 60 
F4 "ADC3" B R 2750 1750 60 
F5 "ADC2" B R 2750 1650 60 
F6 "ADC1" B R 2750 1550 60 
F7 "DAC" B R 2750 1850 60 
F8 "SDA" B R 2750 2050 60 
F9 "SCL" B R 2750 2150 60 
F10 "RXD" B R 2750 2350 60 
F11 "TXD" B R 2750 2450 60 
F12 "RD" B R 2750 2650 60 
F13 "TD" B R 2750 2750 60 
F14 "COL1" B R 2750 3050 60 
F15 "F0" B R 2750 3250 60 
F16 "F3" B R 2750 3550 60 
F17 "F2" B R 2750 3450 60 
F18 "COL0" B R 2750 2950 60 
F19 "F1" B R 2750 3350 60 
F20 "RXD0" B R 2750 4150 60 
F21 "RCLK" B R 2750 3750 60 
F22 "MOSI" B R 2750 4850 60 
F23 "LCD_EN" I R 2750 5500 60 
F24 "GPIO0" B R 2750 5750 60 
F25 "GPIO2" B R 2750 5950 60 
F26 "GPIO4" B R 2750 6150 60 
F27 "GPIO6" B R 2750 6350 60 
F28 "RXD1" B R 2750 4250 60 
F29 "TXEN" B R 2750 4050 60 
F30 "MDC" B R 2750 4350 60 
F31 "CRS" B R 2750 4450 60 
F32 "MDIO" B R 2750 4550 60 
F33 "TXD0" I R 2750 3850 60 
F34 "TXD1" B R 2750 3950 60 
F35 "MISO" B R 2750 4950 60 
F36 "spiSCK" B R 2750 4750 60 
F37 "LCD4" B R 2750 5400 60 
F38 "RS" B R 2750 5600 60 
F39 "LCD3" B R 2750 5300 60 
F40 "LCD2" B R 2750 5200 60 
F41 "LCD1" B R 2750 5100 60 
F42 "GPIO1" B R 2750 5850 60 
F43 "GPIO3" B R 2750 6050 60 
F44 "GPIO5" B R 2750 6250 60 
F45 "GPIO7" B R 2750 6450 60 
F46 "GPIO8" B R 2750 6550 60 
F47 "COL2" B R 2750 3150 60 
F48 "WAKEUP" B R 2750 1450 60 
$EndSheet
Text Notes 3800 1550 0    60   Italic 12
AD y DA
Text Notes 3800 2000 0    60   Italic 12
I2C
Text Notes 3750 2300 0    60   Italic 12
RS-232
Text Notes 3800 2600 0    60   Italic 12
CAN
Text Notes 3750 2900 0    60   Italic 12
TECLADO
Text Notes 3600 3700 0    60   Italic 12
ETHERNET (RMII)
Text Notes 3850 4700 0    60   Italic 12
SPI
Text Notes 3800 5050 0    60   Italic 12
DSIPLAY
Text Notes 3300 5700 0    60   Italic 12
E/S PROPÓSITOS GENERALES
$Comp
L Logo_Poncho #G1
U 1 1 560CFFC0
P 10150 6000
F 0 "#G1" H 10100 5600 60  0001 C CNN
F 1 "Logo_Poncho" H 10350 5600 60  0001 C CNN
F 2 "" H 10150 6000 60  0000 C CNN
F 3 "" H 10150 6000 60  0000 C CNN
	1    10150 6000
	1    0    0    -1  
$EndComp
Text Notes 6950 2850 0    79   Italic 16
Este diseño puede copiarse como un \nTemplate de KICAD. \n1)En el administrador de Proyectos:  \n   Proyecto Nuevo -> Nuevo Proyecto desde Template\n2)Ingresar el nombre del poncho a crear.\n3)Indicar el directorio de este modelo: (Poncho Grande).
Text Notes 7300 950  0    118  ~ 24
http://www.proyecto-ciaa.com.ar/
Text Notes 7000 3650 0    60   ~ 0
Luego de abrir el nuevo proyecto:\n1)Editar datos del rótulo.\n2)Editar los archivos del subdirectorio "doc".\n2.1) Agregarse en el archivo de licencia.\n2.2) Colocar info mínima del Poncho en el LEEME.txt\n2.3) Colocar info mínima en el CAMBIOS.doc
$Sheet
S 5250 1200 1350 5600
U 560A0C1A
F0 "Circuito Principal" 50
F1 "Esquematico_CMLED.sch" 50
F2 "LCD1" B L 5250 5100 60 
F3 "LCD2" B L 5250 5200 60 
F4 "LCD3" B L 5250 5300 60 
F5 "LCD4" B L 5250 5400 60 
F6 "LCD_EN" B L 5250 5500 60 
F7 "RS" B L 5250 5600 60 
F8 "GPIO3" B L 5250 6050 60 
F9 "GPIO5" B L 5250 6250 60 
F10 "GPIO7" B L 5250 6450 60 
F11 "GPIO8" B L 5250 6550 60 
F12 "GPIO1" B L 5250 5850 60 
$EndSheet
Wire Wire Line
	5250 6550 2750 6550
Wire Wire Line
	2750 6450 5250 6450
Wire Wire Line
	2750 6250 5250 6250
Wire Wire Line
	2750 6050 5250 6050
Wire Wire Line
	5250 5850 2750 5850
Wire Wire Line
	5250 5600 2750 5600
Wire Wire Line
	2750 5500 5250 5500
Wire Wire Line
	5250 5400 2750 5400
Wire Wire Line
	2750 5300 5250 5300
Wire Wire Line
	5250 5200 2750 5200
Wire Wire Line
	2750 5100 5250 5100
Wire Wire Line
	2750 1250 3000 1250
Wire Wire Line
	2750 1350 3000 1350
Wire Wire Line
	2750 1450 3000 1450
Wire Wire Line
	2750 1550 3000 1550
Wire Wire Line
	3000 1650 2750 1650
Wire Wire Line
	2750 1750 3000 1750
Wire Wire Line
	3000 1850 2750 1850
Wire Wire Line
	2750 2050 3000 2050
Wire Wire Line
	3000 2150 2750 2150
Wire Wire Line
	2750 2350 3000 2350
Wire Wire Line
	3000 2450 2750 2450
Wire Wire Line
	2750 2650 3000 2650
Wire Wire Line
	3000 2750 2750 2750
Wire Wire Line
	2750 2950 3000 2950
Wire Wire Line
	3000 3050 2750 3050
Wire Wire Line
	3000 3150 2750 3150
Wire Wire Line
	2750 3250 3000 3250
Wire Wire Line
	3000 3350 2750 3350
Wire Wire Line
	2750 3450 3000 3450
Wire Wire Line
	3000 3550 2750 3550
Wire Wire Line
	2750 3750 3000 3750
Wire Wire Line
	3000 3850 2750 3850
Wire Wire Line
	2750 3950 3000 3950
Wire Wire Line
	3000 4050 2750 4050
Wire Wire Line
	2750 4150 3000 4150
Wire Wire Line
	3000 4250 2750 4250
Wire Wire Line
	2750 4350 3000 4350
Wire Wire Line
	3000 4450 2750 4450
Wire Wire Line
	2750 4550 3000 4550
Wire Wire Line
	2750 4750 3000 4750
Wire Wire Line
	3000 4850 2750 4850
Wire Wire Line
	2750 4950 3000 4950
NoConn ~ 3000 1250
NoConn ~ 3000 1350
NoConn ~ 3000 1450
NoConn ~ 3000 1550
NoConn ~ 3000 1650
NoConn ~ 3000 1750
NoConn ~ 3000 1850
NoConn ~ 3000 2050
NoConn ~ 3000 2150
NoConn ~ 3000 2350
NoConn ~ 3000 2450
NoConn ~ 3000 2650
NoConn ~ 3000 2750
NoConn ~ 3000 2950
NoConn ~ 3000 3050
NoConn ~ 3000 3150
NoConn ~ 3000 3250
NoConn ~ 3000 3350
NoConn ~ 3000 3450
NoConn ~ 3000 3550
NoConn ~ 3000 3750
NoConn ~ 3000 3850
NoConn ~ 3000 3950
NoConn ~ 3000 4050
NoConn ~ 3000 4150
NoConn ~ 3000 4250
NoConn ~ 3000 4350
NoConn ~ 3000 4450
NoConn ~ 3000 4550
NoConn ~ 3000 4750
NoConn ~ 3000 4850
NoConn ~ 3000 4950
$EndSCHEMATC
