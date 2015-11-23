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
P 4600 5900
F 0 "C3_OUT1" H 4600 6350 50  0000 C CNN
F 1 "CONN_01X08" V 4700 5900 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x08" H 4600 5900 60  0001 C CNN
F 3 "" H 4600 5900 60  0000 C CNN
	1    4600 5900
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X08 C2_OUT1
U 1 1 5653D3BD
P 5900 5650
F 0 "C2_OUT1" H 5900 6100 50  0000 C CNN
F 1 "CONN_01X08" V 6000 5650 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x08" H 5900 5650 60  0001 C CNN
F 3 "" H 5900 5650 60  0000 C CNN
	1    5900 5650
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X08 C1_OUT1
U 1 1 5653D6A0
P 7200 5450
F 0 "C1_OUT1" H 7200 5900 50  0000 C CNN
F 1 "CONN_01X08" V 7300 5450 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x08" H 7200 5450 60  0001 C CNN
F 3 "" H 7200 5450 60  0000 C CNN
	1    7200 5450
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X08 F1_OUT1
U 1 1 5653D769
P 8400 5300
F 0 "F1_OUT1" H 8400 5750 50  0000 C CNN
F 1 "CONN_01X08" V 8500 5300 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x08" H 8400 5300 60  0001 C CNN
F 3 "" H 8400 5300 60  0000 C CNN
	1    8400 5300
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X03 EXP_C1
U 1 1 5654145E
P 4600 4400
F 0 "EXP_C1" H 4600 4600 50  0000 C CNN
F 1 "CONN_01X03" V 4700 4400 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x03" H 4600 4400 60  0001 C CNN
F 3 "" H 4600 4400 60  0000 C CNN
	1    4600 4400
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X03 EXP_F1
U 1 1 5654159F
P 5900 4300
F 0 "EXP_F1" H 5900 4500 50  0000 C CNN
F 1 "CONN_01X03" V 6000 4300 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x03" H 5900 4300 60  0001 C CNN
F 3 "" H 5900 4300 60  0000 C CNN
	1    5900 4300
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
Entry Wire Line
	3800 4200 3900 4300
Entry Wire Line
	3800 4300 3900 4400
Entry Wire Line
	3800 4400 3900 4500
Entry Wire Line
	4900 4300 5000 4400
Entry Wire Line
	4900 4200 5000 4300
Entry Wire Line
	4900 4100 5000 4200
Wire Wire Line
	3450 3550 6950 3550
Wire Wire Line
	3450 3450 6950 3450
Wire Wire Line
	3450 3650 6950 3650
Wire Bus Line
	3450 4150 3800 4150
Wire Bus Line
	3800 4150 3800 4400
Wire Wire Line
	3900 4500 4400 4500
Wire Wire Line
	3900 4400 4400 4400
Wire Wire Line
	3900 4300 4400 4300
Wire Bus Line
	3450 4050 4900 4050
Wire Bus Line
	4900 4050 4900 4300
Wire Wire Line
	5700 4400 5000 4400
Wire Wire Line
	5000 4300 5700 4300
Wire Wire Line
	5700 4200 5000 4200
Wire Bus Line
	3450 5100 3650 5100
Wire Bus Line
	3650 5100 3650 6150
Wire Bus Line
	3450 5000 4900 5000
Wire Bus Line
	4900 5000 4900 6000
Wire Bus Line
	3450 4900 6200 4900
Wire Bus Line
	6200 4900 6200 5700
Wire Bus Line
	3450 4800 7500 4800
Wire Bus Line
	7500 4800 7500 5550
Entry Wire Line
	3650 6150 3750 6250
Entry Wire Line
	3650 6050 3750 6150
Entry Wire Line
	3650 5950 3750 6050
Entry Wire Line
	3650 5850 3750 5950
Entry Wire Line
	3650 5750 3750 5850
Entry Wire Line
	3650 5650 3750 5750
Entry Wire Line
	3650 5550 3750 5650
Entry Wire Line
	3650 5450 3750 5550
Wire Wire Line
	3750 5550 4400 5550
Wire Wire Line
	4400 5650 3750 5650
Wire Wire Line
	3750 5750 4400 5750
Wire Wire Line
	4400 5850 3750 5850
Wire Wire Line
	3750 5950 4400 5950
Wire Wire Line
	4400 6050 3750 6050
Wire Wire Line
	3750 6150 4400 6150
Wire Wire Line
	4400 6250 3750 6250
Entry Wire Line
	4900 5900 5000 6000
Entry Wire Line
	4900 5800 5000 5900
Entry Wire Line
	4900 5700 5000 5800
Entry Wire Line
	4900 5600 5000 5700
Entry Wire Line
	4900 5500 5000 5600
Entry Wire Line
	4900 5400 5000 5500
Entry Wire Line
	4900 5300 5000 5400
Entry Wire Line
	4900 5200 5000 5300
Wire Wire Line
	5000 6000 5700 6000
Wire Wire Line
	5700 5900 5000 5900
Wire Wire Line
	5000 5800 5700 5800
Wire Wire Line
	5700 5700 5000 5700
Wire Wire Line
	5000 5600 5700 5600
Wire Wire Line
	5700 5500 5000 5500
Wire Wire Line
	5000 5400 5700 5400
Wire Wire Line
	5700 5300 5000 5300
Entry Wire Line
	6200 5700 6300 5800
Entry Wire Line
	6200 5600 6300 5700
Entry Wire Line
	6200 5500 6300 5600
Entry Wire Line
	6200 5400 6300 5500
Entry Wire Line
	6200 5300 6300 5400
Entry Wire Line
	6200 5200 6300 5300
Entry Wire Line
	6200 5100 6300 5200
Entry Wire Line
	6200 5000 6300 5100
Entry Wire Line
	7500 5250 7600 5350
Entry Wire Line
	7500 5150 7600 5250
Entry Wire Line
	7500 5050 7600 5150
Entry Wire Line
	7500 4950 7600 5050
Entry Wire Line
	7500 4850 7600 4950
Entry Wire Line
	7500 5350 7600 5450
Entry Wire Line
	7500 5450 7600 5550
Entry Wire Line
	7500 5550 7600 5650
Wire Wire Line
	6300 5100 7000 5100
Wire Wire Line
	7000 5200 6300 5200
Wire Wire Line
	6300 5300 7000 5300
Wire Wire Line
	7000 5400 6300 5400
Wire Wire Line
	6300 5500 7000 5500
Wire Wire Line
	7000 5600 6300 5600
Wire Wire Line
	6300 5700 7000 5700
Wire Wire Line
	7000 5800 6300 5800
Wire Wire Line
	7600 5650 8200 5650
Wire Wire Line
	8200 5550 7600 5550
Wire Wire Line
	7600 5450 8200 5450
Wire Wire Line
	8200 5350 7600 5350
Wire Wire Line
	7600 5250 8200 5250
Wire Wire Line
	8200 5150 7600 5150
Wire Wire Line
	7600 5050 8200 5050
Wire Wire Line
	8200 4950 7600 4950
Wire Wire Line
	2000 6350 2000 5250
Wire Wire Line
	2000 5250 2350 5250
Text Label 7700 4950 0    60   ~ 0
F1_QA
Text Label 7700 5050 0    60   ~ 0
F1_QB
Text Label 7700 5150 0    60   ~ 0
F1_QC
Text Label 7700 5250 0    60   ~ 0
F1_QD
Text Label 7700 5350 0    60   ~ 0
F1_QE
Text Label 7700 5450 0    60   ~ 0
F1_QF
Text Label 7700 5550 0    60   ~ 0
F1_QG
Text Label 7700 5650 0    60   ~ 0
F1_QH
Text Label 6400 5100 0    60   ~ 0
C1_QA
Text Label 6400 5200 0    60   ~ 0
C1_QB
Text Label 6400 5300 0    60   ~ 0
C1_QC
Text Label 6400 5400 0    60   ~ 0
C1_QD
Text Label 6400 5500 0    60   ~ 0
C1_QE
Text Label 6400 5600 0    60   ~ 0
C1_QF
Text Label 6400 5700 0    60   ~ 0
C1_QG
Text Label 6400 5800 0    60   ~ 0
C1_QH
Text Label 5100 5300 0    60   ~ 0
C2_QA
Text Label 5100 5400 0    60   ~ 0
C2_QB
Text Label 5100 5500 0    60   ~ 0
C2_QC
Text Label 5100 5600 0    60   ~ 0
C2_QD
Text Label 5100 5700 0    60   ~ 0
C2_QE
Text Label 5100 5800 0    60   ~ 0
C2_QF
Text Label 5100 5900 0    60   ~ 0
C2_QG
Text Label 5100 6000 0    60   ~ 0
C2_QH
Text Label 3900 5550 0    60   ~ 0
C3_QA
Text Label 3900 5650 0    60   ~ 0
C3_QB
Text Label 3900 5750 0    60   ~ 0
C3_QC
Text Label 3900 5850 0    60   ~ 0
C3_QD
Text Label 3900 5950 0    60   ~ 0
C3_QE
Text Label 3900 6050 0    60   ~ 0
C3_QF
Text Label 3900 6150 0    60   ~ 0
C3_QG
Text Label 3900 6250 0    60   ~ 0
C3_QH
Text Label 5100 4200 0    60   ~ 0
F1_SD
Text Label 5100 4300 0    60   ~ 0
F1_CLK
Text Label 5100 4400 0    60   ~ 0
F1_LATCH
Text Label 4000 4300 0    60   ~ 0
C3_SD
Text Label 4000 4400 0    60   ~ 0
C3_CLK
Text Label 4000 4500 0    60   ~ 0
C3_LATCH
$Sheet
S 2350 3350 1100 2000
U 565380D6
F0 "CMLED" 60
F1 "Esquematico_CMLED.sch" 60
F2 "C1_OUT" O R 3450 4900 60 
F3 "C2_OUT" O R 3450 5000 60 
F4 "C3_OUT" O R 3450 5100 60 
F5 "F1_OUT" O R 3450 4800 60 
F6 "K2_OUT" O R 3450 4150 60 
F7 "JF_OUT" O R 3450 3450 60 
F8 "JC2_OUT" O R 3450 3650 60 
F9 "JC3_OUT" I R 3450 3550 60 
F10 "JCLK_C3" I L 2350 5250 60 
F11 "K1_OUT" O R 3450 4050 60 
F12 "GPIO1" I L 2350 3800 60 
F13 "GPIO3" I L 2350 4000 60 
F14 "GPIO5" I L 2350 4200 60 
F15 "GPIO7" I L 2350 4400 60 
F16 "GPIO8" I L 2350 4500 60 
$EndSheet
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
$EndSCHEMATC
