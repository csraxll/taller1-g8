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
Sheet 2 2
Title "noname.sch"
Date "12 nov 2015"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L 74HC595 REGF1
U 1 1 5631E1FC
P 4100 1500
F 0 "REGF1" H 4250 2100 70  0000 C CNN
F 1 "74HC595" H 4100 900 70  0000 C CNN
F 2 "Housings_DIP:DIP-16_W7.62mm" H 4100 1500 60  0000 C CNN
F 3 "~" H 4100 1500 60  0000 C CNN
	1    4100 1500
	1    0    0    -1  
$EndComp
$Comp
L 74HC595 REGC1
U 1 1 5631E202
P 3650 4750
F 0 "REGC1" H 3800 5350 70  0000 C CNN
F 1 "74HC595" H 3650 4150 70  0000 C CNN
F 2 "Housings_DIP:DIP-16_W7.62mm" H 3650 4750 60  0000 C CNN
F 3 "~" H 3650 4750 60  0000 C CNN
	1    3650 4750
	0    -1   -1   0   
$EndComp
Text HLabel 1400 2500 0    60   Input ~ 0
GPIO1
Text HLabel 1400 2700 0    60   Input ~ 0
GPIO3
Text HLabel 1400 3000 0    60   Input ~ 0
GPIO5
Text HLabel 1400 3200 0    60   Input ~ 0
GPIO7
Text HLabel 1400 3300 0    60   Input ~ 0
GPIO8
$Comp
L VCC #PWR01
U 1 1 5631E23A
P 2800 5950
F 0 "#PWR01" H 2800 6050 30  0001 C CNN
F 1 "VCC" H 2800 6050 30  0000 C CNN
F 2 "" H 2800 5950 60  0000 C CNN
F 3 "" H 2800 5950 60  0000 C CNN
	1    2800 5950
	0    -1   -1   0   
$EndComp
$Comp
L 74HC595 REGC2
U 1 1 56449088
P 6500 4750
F 0 "REGC2" H 6650 5350 70  0000 C CNN
F 1 "74HC595" H 6500 4150 70  0000 C CNN
F 2 "Housings_DIP:DIP-16_W7.62mm" H 6500 4750 60  0000 C CNN
F 3 "~" H 6500 4750 60  0000 C CNN
	1    6500 4750
	0    -1   -1   0   
$EndComp
$Comp
L 74HC595 REGC3
U 1 1 56449097
P 8850 4800
F 0 "REGC3" H 9000 5400 70  0000 C CNN
F 1 "74HC595" H 8850 4200 70  0000 C CNN
F 2 "Housings_DIP:DIP-16_W7.62mm" H 8850 4800 60  0000 C CNN
F 3 "~" H 8850 4800 60  0000 C CNN
	1    8850 4800
	0    -1   -1   0   
$EndComp
$Comp
L VCC #PWR02
U 1 1 56449A6A
P 5650 5950
F 0 "#PWR02" H 5650 6050 30  0001 C CNN
F 1 "VCC" H 5650 6050 30  0000 C CNN
F 2 "" H 5650 5950 60  0000 C CNN
F 3 "" H 5650 5950 60  0000 C CNN
	1    5650 5950
	0    -1   -1   0   
$EndComp
$Comp
L VCC #PWR03
U 1 1 56449A72
P 8000 6000
F 0 "#PWR03" H 8000 6100 30  0001 C CNN
F 1 "VCC" H 8000 6100 30  0000 C CNN
F 2 "" H 8000 6000 60  0000 C CNN
F 3 "" H 8000 6000 60  0000 C CNN
	1    8000 6000
	0    -1   -1   0   
$EndComp
Wire Wire Line
	3500 5950 2800 5950
Wire Wire Line
	3500 5450 3500 5950
Wire Wire Line
	1400 3300 2350 3300
Wire Wire Line
	3800 5450 4100 5450
Wire Wire Line
	1400 3200 2600 3200
Connection ~ 2150 3000
Wire Wire Line
	4800 1050 5500 1050
Wire Wire Line
	5500 1150 4800 1150
Wire Wire Line
	4800 1250 5500 1250
Wire Wire Line
	5500 1350 4800 1350
Wire Wire Line
	4800 1450 5500 1450
Wire Wire Line
	5500 1550 4800 1550
Wire Wire Line
	4800 1650 5500 1650
Wire Wire Line
	5500 1750 4800 1750
Wire Wire Line
	2750 2500 1400 2500
Wire Wire Line
	3000 2700 1400 2700
Wire Wire Line
	3200 3000 1400 3000
Wire Wire Line
	2600 5450 3200 5450
Wire Wire Line
	3400 5450 3400 5600
Wire Wire Line
	2350 5600 9600 5600
Wire Wire Line
	3700 5450 3700 5750
Wire Wire Line
	2150 5750 10050 5750
Wire Wire Line
	3200 4050 3200 3600
Wire Wire Line
	3300 3600 3300 4050
Wire Wire Line
	3400 4050 3400 3600
Wire Wire Line
	3500 3600 3500 4050
Wire Wire Line
	3600 4050 3600 3600
Wire Wire Line
	3700 3600 3700 4050
Wire Wire Line
	3800 4050 3800 3600
Wire Wire Line
	3900 3600 3900 4050
Wire Wire Line
	6050 3600 6050 4050
Wire Wire Line
	6150 3600 6150 4050
Wire Wire Line
	6250 4050 6250 3600
Wire Wire Line
	6350 3600 6350 4050
Wire Wire Line
	6450 4050 6450 3600
Wire Wire Line
	6550 3600 6550 4050
Wire Wire Line
	6650 4050 6650 3600
Wire Wire Line
	6750 3600 6750 4050
Wire Wire Line
	8400 4100 8400 3600
Wire Wire Line
	8500 3600 8500 4100
Wire Wire Line
	8600 4100 8600 3600
Wire Wire Line
	8700 3600 8700 4100
Wire Wire Line
	8800 4100 8800 3600
Wire Wire Line
	8900 3600 8900 4100
Wire Wire Line
	9000 3600 9000 4100
Wire Wire Line
	9100 4100 9100 3600
Wire Wire Line
	6550 5750 6550 5450
Connection ~ 3700 5750
Wire Wire Line
	8900 5750 8900 5500
Connection ~ 6550 5750
Wire Wire Line
	4100 4050 5550 4050
Wire Wire Line
	5550 4050 5550 5450
Wire Wire Line
	5550 5450 6050 5450
Wire Wire Line
	8000 3750 8000 5500
Wire Wire Line
	8000 5500 8400 5500
Wire Wire Line
	6250 5600 6250 5450
Connection ~ 3400 5600
Connection ~ 6250 5600
Wire Wire Line
	6350 5950 5650 5950
Wire Wire Line
	6350 5450 6350 5950
Wire Wire Line
	8700 6000 8000 6000
Wire Wire Line
	8700 5500 8700 6000
Wire Wire Line
	6650 5450 7000 5450
Wire Wire Line
	9000 5500 9300 5500
Wire Wire Line
	4800 1950 7150 1950
Wire Wire Line
	2750 2500 2750 1050
Wire Wire Line
	2750 1050 3400 1050
Wire Wire Line
	3000 1250 3000 2700
Wire Wire Line
	3000 1250 3400 1250
Connection ~ 3000 2150
Connection ~ 3200 2250
Wire Wire Line
	9300 4100 10050 4100
Wire Wire Line
	10050 4100 10050 4750
Wire Wire Line
	10050 4750 10400 4750
Wire Wire Line
	10400 4850 9600 4850
Wire Wire Line
	9600 4850 9600 5600
Wire Wire Line
	10050 5750 10050 4950
Wire Wire Line
	10050 4950 10400 4950
Connection ~ 8900 5750
Wire Wire Line
	3000 2150 6000 2150
Wire Wire Line
	6000 2150 6000 2050
Wire Wire Line
	6000 2050 7150 2050
Wire Wire Line
	7150 2150 6100 2150
Wire Wire Line
	6100 2150 6100 2250
Wire Wire Line
	6100 2250 3200 2250
Wire Wire Line
	6950 4050 7400 4050
Wire Wire Line
	7700 3750 8000 3750
Wire Wire Line
	7550 3200 5300 3200
Wire Wire Line
	5300 3200 5300 1950
Connection ~ 5300 1950
Entry Wire Line
	3100 3500 3200 3600
Entry Wire Line
	3200 3500 3300 3600
Entry Wire Line
	3300 3500 3400 3600
Entry Wire Line
	3400 3500 3500 3600
Entry Wire Line
	3500 3500 3600 3600
Entry Wire Line
	3600 3500 3700 3600
Entry Wire Line
	3700 3500 3800 3600
Entry Wire Line
	3800 3500 3900 3600
Wire Bus Line
	3100 3500 4000 3500
Text HLabel 4000 3500 2    60   Output ~ 0
C1_OUT
Entry Wire Line
	5950 3500 6050 3600
Entry Wire Line
	6050 3500 6150 3600
Entry Wire Line
	6150 3500 6250 3600
Entry Wire Line
	6250 3500 6350 3600
Entry Wire Line
	6350 3500 6450 3600
Entry Wire Line
	6450 3500 6550 3600
Entry Wire Line
	6550 3500 6650 3600
Entry Wire Line
	6650 3500 6750 3600
Entry Wire Line
	8300 3500 8400 3600
Entry Wire Line
	8400 3500 8500 3600
Entry Wire Line
	8500 3500 8600 3600
Entry Wire Line
	8600 3500 8700 3600
Entry Wire Line
	8700 3500 8800 3600
Entry Wire Line
	8800 3500 8900 3600
Entry Wire Line
	8900 3500 9000 3600
Entry Wire Line
	9000 3500 9100 3600
Wire Bus Line
	5950 3500 6800 3500
Wire Bus Line
	8300 3500 9150 3500
Text HLabel 6800 3500 2    60   Output ~ 0
C2_OUT
Text HLabel 9150 3500 2    60   Output ~ 0
C3_OUT
Entry Wire Line
	5500 1050 5600 1150
Entry Wire Line
	5500 1150 5600 1250
Entry Wire Line
	5500 1250 5600 1350
Entry Wire Line
	5500 1350 5600 1450
Entry Wire Line
	5500 1450 5600 1550
Entry Wire Line
	5500 1550 5600 1650
Entry Wire Line
	5500 1650 5600 1750
Entry Wire Line
	5500 1750 5600 1850
Wire Bus Line
	5600 950  5600 1850
Wire Bus Line
	5600 950  5700 950 
Text HLabel 5700 950  2    60   Output ~ 0
F1_OUT
Entry Wire Line
	7150 1950 7250 2050
Entry Wire Line
	7150 2050 7250 2150
Entry Wire Line
	7150 2150 7250 2250
Wire Bus Line
	7250 2050 7250 2350
Wire Bus Line
	7250 2350 7350 2350
Entry Wire Line
	10400 4750 10500 4850
Entry Wire Line
	10400 4850 10500 4950
Entry Wire Line
	10400 4950 10500 5050
Wire Bus Line
	10500 4850 10500 5150
Wire Bus Line
	10500 5150 10600 5150
Text HLabel 10600 5150 2    60   Output ~ 0
K2_OUT
Text HLabel 7550 3200 2    60   Output ~ 0
JF_OUT
Text HLabel 7400 4050 2    60   Output ~ 0
JC2_OUT
Text HLabel 7700 3750 0    60   Input ~ 0
JC3_OUT
Wire Wire Line
	2150 5750 2150 3000
Wire Wire Line
	2350 3300 2350 5600
Wire Wire Line
	2600 3200 2600 5450
Text HLabel 7800 5550 0    60   Input ~ 0
JCLK_C3
Wire Wire Line
	7800 5550 8600 5550
Wire Wire Line
	8600 5550 8600 5500
Text Label 5000 1050 0    60   ~ 0
F1_QA
Text Label 5000 1150 0    60   ~ 0
F1_QB
Text Label 5000 1250 0    60   ~ 0
F1_QC
Text Label 5000 1350 0    60   ~ 0
F1_QD
Text Label 5000 1450 0    60   ~ 0
F1_QE
Text Label 5000 1550 0    60   ~ 0
F1_QF
Text Label 5000 1650 0    60   ~ 0
F1_QG
Text Label 5000 1750 0    60   ~ 0
F1_QH
Text Label 3200 3950 1    60   ~ 0
C1_QA
Text Label 3300 3950 1    60   ~ 0
C1_QB
Text Label 3400 3950 1    60   ~ 0
C1_QC
Text Label 3500 3950 1    60   ~ 0
C1_QD
Text Label 3600 3950 1    60   ~ 0
C1_QE
Text Label 3700 3950 1    60   ~ 0
C1_QF
Text Label 3800 3950 1    60   ~ 0
C1_QG
Text Label 3900 3950 1    60   ~ 0
C1_QH
Text Label 6050 4000 1    60   ~ 0
C2_QA
Text Label 6150 4000 1    60   ~ 0
C2_QB
Text Label 6250 4000 1    60   ~ 0
C2_QC
Text Label 6350 4000 1    60   ~ 0
C2_QD
Text Label 6450 4000 1    60   ~ 0
C2_QE
Text Label 6550 4000 1    60   ~ 0
C2_QF
Text Label 6650 4000 1    60   ~ 0
C2_QG
Text Label 6750 4000 1    60   ~ 0
C2_QH
Text Label 8400 3950 1    60   ~ 0
C3_QA
Text Label 8500 3950 1    60   ~ 0
C3_QB
Text Label 8600 3950 1    60   ~ 0
C3_QC
Text Label 8700 3950 1    60   ~ 0
C3_QD
Text Label 8800 3950 1    60   ~ 0
C3_QE
Text Label 8900 3950 1    60   ~ 0
C3_QF
Text Label 9000 3950 1    60   ~ 0
C3_QG
Text Label 9100 3950 1    60   ~ 0
C3_QH
Text Label 6700 1950 0    60   ~ 0
F1_SD
Text Label 6700 2050 0    60   ~ 0
F1_CLK
Text Label 6700 2150 0    60   ~ 0
F1_LATCH
Text Label 10100 4750 0    60   ~ 0
C3_SD
Text Label 10100 4850 0    60   ~ 0
C3_CLK
Text Label 10100 4950 0    60   ~ 0
C3_LATCH
$Comp
L GND #PWR04
U 1 1 5653C022
P 4100 5450
F 0 "#PWR04" H 4100 5450 30  0001 C CNN
F 1 "GND" H 4100 5380 30  0001 C CNN
F 2 "" H 4100 5450 60  0000 C CNN
F 3 "" H 4100 5450 60  0000 C CNN
	1    4100 5450
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR05
U 1 1 5653C14E
P 7000 5450
F 0 "#PWR05" H 7000 5450 30  0001 C CNN
F 1 "GND" H 7000 5380 30  0001 C CNN
F 2 "" H 7000 5450 60  0000 C CNN
F 3 "" H 7000 5450 60  0000 C CNN
	1    7000 5450
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR06
U 1 1 5653C1C6
P 9300 5500
F 0 "#PWR06" H 9300 5500 30  0001 C CNN
F 1 "GND" H 9300 5430 30  0001 C CNN
F 2 "" H 9300 5500 60  0000 C CNN
F 3 "" H 9300 5500 60  0000 C CNN
	1    9300 5500
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR07
U 1 1 5653C21E
P 3400 1950
F 0 "#PWR07" H 3400 1950 30  0001 C CNN
F 1 "GND" H 3400 1880 30  0001 C CNN
F 2 "" H 3400 1950 60  0000 C CNN
F 3 "" H 3400 1950 60  0000 C CNN
	1    3400 1950
	1    0    0    -1  
$EndComp
Wire Wire Line
	3200 3000 3200 1550
$Comp
L VCC #PWR08
U 1 1 5631E234
P 2300 850
F 0 "#PWR08" H 2300 950 30  0001 C CNN
F 1 "VCC" H 2300 950 30  0000 C CNN
F 2 "" H 2300 850 60  0000 C CNN
F 3 "" H 2300 850 60  0000 C CNN
	1    2300 850 
	1    0    0    -1  
$EndComp
Wire Wire Line
	3400 1350 2300 1350
Wire Wire Line
	2300 1350 2300 850 
Wire Wire Line
	3400 1650 3400 1950
Wire Wire Line
	3200 1550 3400 1550
Text HLabel 7350 2350 2    60   Output ~ 0
K1_OUT
$EndSCHEMATC
