EESchema Schematic File Version 2
LIBS:Misc_Poncho_Grande
LIBS:Poncho_Esqueleto
LIBS:74xx
LIBS:conn
LIBS:power
LIBS:ControladorMatrizLED-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 2
Title "Poncho Mediano - Modelo - Ejemplo - Template"
Date "lun 05 oct 2015"
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
F 2 "Poncho_Esqueleto:Logo_OSHWA" H 10800 6050 60  0001 C CNN
F 3 "" H 10800 6050 60  0000 C CNN
	1    10800 6050
	1    0    0    -1  
$EndComp
$Comp
L Logo_Poncho #G1
U 1 1 560CFFC0
P 10150 6000
F 0 "#G1" H 10100 5600 60  0001 C CNN
F 1 "Logo_Poncho" H 10350 5600 60  0001 C CNN
F 2 "Poncho_Esqueleto:Logo_Poncho" H 10150 6000 60  0001 C CNN
F 3 "" H 10150 6000 60  0001 C CNN
	1    10150 6000
	1    0    0    -1  
$EndComp
Text Notes 750  1900 0    79   Italic 16
Este diseño puede copiarse como un \nTemplate de KICAD. \n1)En el administrador de Proyectos:  \n   Proyecto Nuevo -> Nuevo Proyecto desde Template\n2)Ingresar el nombre del poncho a crear.\n3)Indicar el directorio de este modelo.
Text Notes 800  850  0    118  ~ 24
http://www.proyecto-ciaa.com.ar/
Text Notes 800  3000 0    60   ~ 0
Luego de abrir el nuevo proyecto:\n1)Editar datos del rótulo.\n2)Editar los archivos del subdirectorio "doc".\n2.1) Agregarse en el archivo de licencia.\n2.2) Colocar info mínima del Poncho en el LEEME.txt\n2.3) Colocar info mínima en el CAMBIOS.doc
$Comp
L Conn_PonchoMP_2x_20x2 XA1
U 11 1 5612F0FD
P 1200 4000
F 0 "XA1" H 1050 3450 60  0000 C CNN
F 1 "Conn_PonchoMP_2x_20x2" H 1150 3550 60  0000 C CNN
F 2 "Poncho_Esqueleto:Conn_Poncho_Mediano" H 1050 4350 60  0001 C CNN
F 3 "" H 1050 4350 60  0000 C CNN
	11   1200 4000
	1    0    0    -1  
$EndComp
$Comp
L PCB_HOLE H1
U 1 1 56145856
P 4950 7350
F 0 "H1" H 4900 7500 60  0000 C CNN
F 1 "PCB_HOLE" H 5000 7250 60  0000 C CNN
F 2 "Poncho_Modelos:Led_Hole" H 4800 7400 60  0001 C CNN
F 3 "PCB HOLE" H 4900 7500 60  0001 C CNN
	1    4950 7350
	1    0    0    -1  
$EndComp
$Comp
L PCB_HOLE H2
U 1 1 561458ED
P 5500 7350
F 0 "H2" H 5450 7500 60  0000 C CNN
F 1 "PCB_HOLE" H 5550 7250 60  0000 C CNN
F 2 "Poncho_Modelos:Led_Hole" H 5350 7400 60  0001 C CNN
F 3 "PCB HOLE" H 5450 7500 60  0001 C CNN
	1    5500 7350
	1    0    0    -1  
$EndComp
$Comp
L PCB_HOLE H3
U 1 1 56145920
P 6000 7350
F 0 "H3" H 5950 7500 60  0000 C CNN
F 1 "PCB_HOLE" H 6050 7250 60  0000 C CNN
F 2 "Poncho_Modelos:Led_Hole" H 5850 7400 60  0001 C CNN
F 3 "PCB HOLE" H 5950 7500 60  0001 C CNN
	1    6000 7350
	1    0    0    -1  
$EndComp
$Comp
L PCB_HOLE H4
U 1 1 56145951
P 6500 7350
F 0 "H4" H 6450 7500 60  0000 C CNN
F 1 "PCB_HOLE" H 6550 7250 60  0000 C CNN
F 2 "Poncho_Modelos:Led_Hole" H 6350 7400 60  0001 C CNN
F 3 "PCB HOLE" H 6450 7500 60  0001 C CNN
	1    6500 7350
	1    0    0    -1  
$EndComp
Text Notes 4950 7000 0    60   ~ 0
Agujeros para visualizar los LEDs
NoConn ~ 4950 7350
NoConn ~ 5500 7350
NoConn ~ 6000 7350
NoConn ~ 6500 7350
$Comp
L CONN_01X08 C3_OUT1
U 1 1 5653D2EA
P 10000 4800
F 0 "C3_OUT1" H 10000 5250 50  0000 C CNN
F 1 "CONN_01X08" V 10100 4800 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x08" H 10000 4800 60  0001 C CNN
F 3 "" H 10000 4800 60  0000 C CNN
	1    10000 4800
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X08 C2_OUT1
U 1 1 5653D3BD
P 10000 3750
F 0 "C2_OUT1" H 10000 4200 50  0000 C CNN
F 1 "CONN_01X08" V 10100 3750 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x08" H 10000 3750 60  0001 C CNN
F 3 "" H 10000 3750 60  0000 C CNN
	1    10000 3750
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X08 C1_OUT1
U 1 1 5653D6A0
P 10000 2700
F 0 "C1_OUT1" H 10000 3150 50  0000 C CNN
F 1 "CONN_01X08" V 10100 2700 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x08" H 10000 2700 60  0001 C CNN
F 3 "" H 10000 2700 60  0000 C CNN
	1    10000 2700
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X08 F1_OUT1
U 1 1 5653D769
P 10000 1650
F 0 "F1_OUT1" H 10000 2100 50  0000 C CNN
F 1 "CONN_01X08" V 10100 1650 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x08" H 10000 1650 60  0001 C CNN
F 3 "" H 10000 1650 60  0000 C CNN
	1    10000 1650
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X03 EXP_C1
U 1 1 5654145E
P 7150 4850
F 0 "EXP_C1" H 7150 5050 50  0000 C CNN
F 1 "CONN_01X03" V 7250 4850 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x03" H 7150 4850 60  0001 C CNN
F 3 "" H 7150 4850 60  0000 C CNN
	1    7150 4850
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X03 EXP_F1
U 1 1 5654159F
P 7150 4250
F 0 "EXP_F1" H 7150 4450 50  0000 C CNN
F 1 "CONN_01X03" V 7250 4250 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x03" H 7150 4250 60  0001 C CNN
F 3 "" H 7150 4250 60  0000 C CNN
	1    7150 4250
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X03 J_MODE_SD1
U 1 1 565416A4
P 7150 3550
F 0 "J_MODE_SD1" H 7150 3750 50  0000 C CNN
F 1 "CONN_01X03" V 7250 3550 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x03" H 7150 3550 60  0001 C CNN
F 3 "" H 7150 3550 60  0000 C CNN
	1    7150 3550
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X03 J_MODE_CLK1
U 1 1 56541F19
P 2000 6550
F 0 "J_MODE_CLK1" H 2000 6750 50  0000 C CNN
F 1 "CONN_01X03" V 2100 6550 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x03" H 2000 6550 60  0001 C CNN
F 3 "" H 2000 6550 60  0000 C CNN
	1    2000 6550
	0    1    1    0   
$EndComp
Wire Wire Line
	3450 3550 6950 3550
Wire Wire Line
	3450 3450 6950 3450
Wire Wire Line
	3450 3650 6950 3650
Wire Wire Line
	6450 4950 6950 4950
Wire Wire Line
	6450 4850 6950 4850
Wire Wire Line
	6450 4750 6950 4750
Wire Wire Line
	9200 2350 9800 2350
Wire Wire Line
	9800 2450 9200 2450
Wire Wire Line
	9200 2550 9800 2550
Wire Wire Line
	9800 2650 9200 2650
Wire Wire Line
	9200 2750 9800 2750
Wire Wire Line
	9800 2850 9200 2850
Wire Wire Line
	9200 2950 9800 2950
Wire Wire Line
	9800 3050 9200 3050
Wire Wire Line
	9200 2000 9800 2000
Wire Wire Line
	9800 1900 9200 1900
Wire Wire Line
	9200 1800 9800 1800
Wire Wire Line
	9800 1700 9200 1700
Wire Wire Line
	9200 1600 9800 1600
Wire Wire Line
	9800 1500 9200 1500
Wire Wire Line
	9200 1400 9800 1400
Wire Wire Line
	9800 1300 9200 1300
Wire Wire Line
	2000 6350 2000 5250
Wire Wire Line
	2000 5250 2350 5250
Wire Wire Line
	1650 3800 2350 3800
Wire Wire Line
	1650 4000 2350 4000
Wire Wire Line
	1650 4200 2350 4200
Wire Wire Line
	1650 4400 2350 4400
Wire Wire Line
	1650 4500 2350 4500
Wire Wire Line
	2100 6350 2100 4000
Connection ~ 2100 4000
Wire Wire Line
	1900 6350 1900 4500
Connection ~ 1900 4500
Text GLabel 9200 4450 0    60   Output ~ 0
C3_QA
$Sheet
S 2350 3350 1100 2000
U 565380D6
F0 "CMLED" 60
F1 "Esquematico_CMLED.sch" 60
F2 "JF_OUT" O R 3450 3450 60 
F3 "JC2_OUT" O R 3450 3650 60 
F4 "JC3_OUT" I R 3450 3550 60 
F5 "JCLK_C3" I L 2350 5250 60 
F6 "GPIO1" I L 2350 3800 60 
F7 "GPIO3" I L 2350 4000 60 
F8 "GPIO5" I L 2350 4200 60 
F9 "GPIO7" I L 2350 4400 60 
F10 "GPIO8" I L 2350 4500 60 
$EndSheet
Text GLabel 9200 4550 0    60   Output ~ 0
C3_QB
Text GLabel 9200 4650 0    60   Output ~ 0
C3_QC
Text GLabel 9200 4750 0    60   Output ~ 0
C3_QD
Text GLabel 9200 4850 0    60   Output ~ 0
C3_QE
Text GLabel 9200 4950 0    60   Output ~ 0
C3_QF
Text GLabel 9200 5050 0    60   Output ~ 0
C3_QG
Text GLabel 9200 5150 0    60   Output ~ 0
C3_QH
Text GLabel 9200 3400 0    60   Output ~ 0
C2_QA
Text GLabel 9200 3500 0    60   Output ~ 0
C2_QB
Text GLabel 9200 3600 0    60   Output ~ 0
C2_QC
Text GLabel 9200 3700 0    60   Output ~ 0
C2_QD
Text GLabel 9200 3800 0    60   Output ~ 0
C2_QE
Text GLabel 9200 3900 0    60   Output ~ 0
C2_QF
Text GLabel 9200 4000 0    60   Output ~ 0
C2_QG
Text GLabel 9200 4100 0    60   Output ~ 0
C2_QH
Text GLabel 9200 2350 0    60   Output ~ 0
C1_QA
Text GLabel 9200 2450 0    60   Output ~ 0
C1_QB
Text GLabel 9200 2550 0    60   Output ~ 0
C1_QC
Text GLabel 9200 2650 0    60   Output ~ 0
C1_QD
Text GLabel 9200 2750 0    60   Output ~ 0
C1_QE
Text GLabel 9200 2850 0    60   Output ~ 0
C1_QF
Text GLabel 9200 2950 0    60   Output ~ 0
C1_QG
Text GLabel 9200 3050 0    60   Output ~ 0
C1_QH
Text GLabel 9200 1300 0    60   Output ~ 0
F1_QA
Text GLabel 9200 1400 0    60   Output ~ 0
F1_QB
Text GLabel 9200 1500 0    60   Output ~ 0
F1_QC
Text GLabel 9200 1600 0    60   Output ~ 0
F1_QD
Text GLabel 9200 1700 0    60   Output ~ 0
F1_QE
Text GLabel 9200 1800 0    60   Output ~ 0
F1_QF
Text GLabel 9200 1900 0    60   Output ~ 0
F1_QG
Text GLabel 9200 2000 0    60   Output ~ 0
F1_QH
Wire Wire Line
	9200 3400 9800 3400
Wire Wire Line
	9800 3500 9200 3500
Wire Wire Line
	9200 3600 9800 3600
Wire Wire Line
	9800 3700 9200 3700
Wire Wire Line
	9200 3800 9800 3800
Wire Wire Line
	9800 3900 9200 3900
Wire Wire Line
	9200 4000 9800 4000
Wire Wire Line
	9800 4100 9200 4100
Wire Wire Line
	9200 4450 9800 4450
Wire Wire Line
	9800 4550 9200 4550
Wire Wire Line
	9200 4650 9800 4650
Wire Wire Line
	9800 4750 9200 4750
Wire Wire Line
	9200 4850 9800 4850
Wire Wire Line
	9800 4950 9200 4950
Wire Wire Line
	9200 5050 9800 5050
Wire Wire Line
	9800 5150 9200 5150
Text GLabel 6450 4750 0    60   Output ~ 0
C3_SD
Text GLabel 6450 4850 0    60   Output ~ 0
C3_CLK
Text GLabel 6450 4950 0    60   Output ~ 0
C3_LATCH
Text GLabel 6450 4150 0    60   Output ~ 0
F1_SD
Text GLabel 6450 4250 0    60   Output ~ 0
F1_CLK
Text GLabel 6450 4350 0    60   Output ~ 0
F1_LATCH
Wire Wire Line
	6450 4350 6950 4350
Wire Wire Line
	6450 4250 6950 4250
Wire Wire Line
	6450 4150 6950 4150
NoConn ~ 1650 3700
NoConn ~ 1650 3900
NoConn ~ 1650 4100
NoConn ~ 1650 4300
$Comp
L Conn_PonchoMP_2x_20x2 XA?
U 2 1 5658B4BB
P 4700 5450
F 0 "XA?" H 4700 6000 60  0000 C CNN
F 1 "Conn_PonchoMP_2x_20x2" H 4700 5900 60  0000 C CNN
F 2 "" H 4550 5800 60  0000 C CNN
F 3 "" H 4550 5800 60  0000 C CNN
	2    4700 5450
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 56588A59
P 4250 5350
F 0 "#PWR?" H 4250 5350 30  0001 C CNN
F 1 "GND" H 4250 5280 30  0001 C CNN
F 2 "" H 4250 5350 60  0000 C CNN
F 3 "" H 4250 5350 60  0000 C CNN
	1    4250 5350
	0    1    1    0   
$EndComp
$Comp
L VCC #PWR?
U 1 1 56588C71
P 4250 5250
F 0 "#PWR?" H 4250 5100 50  0001 C CNN
F 1 "VCC" H 4250 5400 50  0000 C CNN
F 2 "" H 4250 5250 60  0000 C CNN
F 3 "" H 4250 5250 60  0000 C CNN
	1    4250 5250
	0    -1   -1   0   
$EndComp
NoConn ~ 4250 5150
NoConn ~ 4250 5450
NoConn ~ 4250 5550
NoConn ~ 4250 5650
NoConn ~ 5150 5750
NoConn ~ 5150 5650
NoConn ~ 5150 5550
NoConn ~ 5150 5450
NoConn ~ 5150 5350
NoConn ~ 5150 5250
NoConn ~ 5150 5150
$EndSCHEMATC
