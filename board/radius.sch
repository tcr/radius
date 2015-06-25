EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:special
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:stm8
LIBS:serial_interface
LIBS:radius-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L STM8S003F3P IC1
U 1 1 557FA4E7
P 6000 2700
F 0 "IC1" H 4850 3500 50  0000 L CNN
F 1 "STM8S003F3P" H 4850 3400 50  0000 L CNN
F 2 "Housings_SSOP:TSSOP-20_4.4x6.5mm_Pitch0.65mm" H 4850 1900 50  0000 L CIN
F 3 "" H 5950 2300 60  0000 C CNN
	1    6000 2700
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR01
U 1 1 557FA54B
P 4100 3900
F 0 "#PWR01" H 4100 3650 50  0001 C CNN
F 1 "GND" H 4100 3750 50  0000 C CNN
F 2 "" H 4100 3900 60  0000 C CNN
F 3 "" H 4100 3900 60  0000 C CNN
	1    4100 3900
	1    0    0    -1  
$EndComp
$Comp
L C C3
U 1 1 557FA561
P 4100 3650
F 0 "C3" H 4125 3750 50  0000 L CNN
F 1 "C" H 4125 3550 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 4138 3500 30  0001 C CNN
F 3 "" H 4100 3650 60  0000 C CNN
	1    4100 3650
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR02
U 1 1 557FB0DB
P 6000 3900
F 0 "#PWR02" H 6000 3650 50  0001 C CNN
F 1 "GND" H 6000 3750 50  0000 C CNN
F 2 "" H 6000 3900 60  0000 C CNN
F 3 "" H 6000 3900 60  0000 C CNN
	1    6000 3900
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR03
U 1 1 557FB357
P 2700 2400
F 0 "#PWR03" H 2700 2150 50  0001 C CNN
F 1 "GND" H 2700 2250 50  0000 C CNN
F 2 "" H 2700 2400 60  0000 C CNN
F 3 "" H 2700 2400 60  0000 C CNN
	1    2700 2400
	1    0    0    -1  
$EndComp
$Comp
L C C2
U 1 1 557FB37B
P 3050 1900
F 0 "C2" H 3075 2000 50  0000 L CNN
F 1 "C" H 3075 1800 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 3088 1750 30  0001 C CNN
F 3 "" H 3050 1900 60  0000 C CNN
	1    3050 1900
	1    0    0    -1  
$EndComp
$Comp
L Crystal Y1
U 1 1 557FB4E7
P 9350 1350
F 0 "Y1" H 9350 1500 50  0000 C CNN
F 1 "Crystal" H 9350 1200 50  0000 C CNN
F 2 "Crystals:Crystal_SMD_0603_4Pads" H 9350 1350 60  0001 C CNN
F 3 "" H 9350 1350 60  0000 C CNN
	1    9350 1350
	0    1    1    0   
$EndComp
$Comp
L C C4
U 1 1 557FB571
P 9750 1000
F 0 "C4" H 9775 1100 50  0000 L CNN
F 1 "C" H 9775 900 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 9788 850 30  0001 C CNN
F 3 "" H 9750 1000 60  0000 C CNN
	1    9750 1000
	0    1    1    0   
$EndComp
$Comp
L C C5
U 1 1 557FB5A3
P 9750 1650
F 0 "C5" H 9775 1750 50  0000 L CNN
F 1 "C" H 9775 1550 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 9788 1500 30  0001 C CNN
F 3 "" H 9750 1650 60  0000 C CNN
	1    9750 1650
	0    1    1    0   
$EndComp
$Comp
L GND #PWR04
U 1 1 557FB5FD
P 10250 1000
F 0 "#PWR04" H 10250 750 50  0001 C CNN
F 1 "GND" H 10250 850 50  0000 C CNN
F 2 "" H 10250 1000 60  0000 C CNN
F 3 "" H 10250 1000 60  0000 C CNN
	1    10250 1000
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR05
U 1 1 557FB61D
P 10250 1650
F 0 "#PWR05" H 10250 1400 50  0001 C CNN
F 1 "GND" H 10250 1500 50  0000 C CNN
F 2 "" H 10250 1650 60  0000 C CNN
F 3 "" H 10250 1650 60  0000 C CNN
	1    10250 1650
	0    -1   -1   0   
$EndComp
Text GLabel 8350 2600 2    60   Output ~ 0
SCL
Text GLabel 8350 2750 2    60   Output ~ 0
SDA
Text GLabel 8350 2900 2    60   Output ~ 0
SCK
Text GLabel 8350 3200 2    60   Output ~ 0
MOSI
Text GLabel 8350 3350 2    60   Output ~ 0
MISO
Text GLabel 3600 2900 0    60   Output ~ 0
USB_TX
Text GLabel 3600 3050 0    60   Output ~ 0
USB_RX
Text GLabel 7800 3050 2    60   Output ~ 0
G3
Text GLabel 3800 2650 0    60   Output ~ 0
TXD
Text GLabel 3800 2800 0    60   Output ~ 0
RXD
$Comp
L CH340G U1
U 1 1 557FBDB4
P 4200 5550
F 0 "U1" H 4200 6250 60  0000 C CNN
F 1 "CH340G" H 4200 4850 60  0000 C CNN
F 2 "Housings_SSOP:SSOP-16_3.9x4.9mm_Pitch0.635mm" H 4150 6650 60  0001 C CNN
F 3 "" H 4150 6650 60  0000 C CNN
	1    4200 5550
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR06
U 1 1 557FBE42
P 5200 6250
F 0 "#PWR06" H 5200 6000 50  0001 C CNN
F 1 "GND" H 5200 6100 50  0000 C CNN
F 2 "" H 5200 6250 60  0000 C CNN
F 3 "" H 5200 6250 60  0000 C CNN
	1    5200 6250
	1    0    0    -1  
$EndComp
$Comp
L VCC #PWR07
U 1 1 557FBEB7
P 5200 4800
F 0 "#PWR07" H 5200 4650 50  0001 C CNN
F 1 "VCC" H 5200 4950 50  0000 C CNN
F 2 "" H 5200 4800 60  0000 C CNN
F 3 "" H 5200 4800 60  0000 C CNN
	1    5200 4800
	1    0    0    -1  
$EndComp
Text GLabel 5550 5350 2    60   Output ~ 0
USB_TX
Text GLabel 5550 5200 2    60   Output ~ 0
USB_RX
Text GLabel 3150 5350 0    60   Output ~ 0
XI
Text GLabel 3150 5500 0    60   Output ~ 0
XO
Wire Wire Line
	4700 3300 4100 3300
Wire Wire Line
	4100 3300 4100 3500
Wire Wire Line
	4100 3800 4100 3900
Wire Wire Line
	6000 3600 6000 3900
Wire Wire Line
	6000 1600 6000 1900
Wire Wire Line
	2700 2400 2700 2300
Wire Wire Line
	2700 2300 3050 2300
Wire Wire Line
	3050 2300 3050 2050
Wire Wire Line
	3050 1750 3050 1400
Wire Wire Line
	3050 1400 4050 1400
Wire Wire Line
	4050 1400 4050 2200
Wire Wire Line
	4050 2200 4700 2200
Wire Wire Line
	7300 2200 7550 2200
Wire Wire Line
	7550 2200 7550 1700
Wire Wire Line
	9350 1000 9350 1200
Wire Wire Line
	7300 2300 7550 2300
Wire Wire Line
	7550 2300 7550 2350
Wire Wire Line
	9350 1650 9350 1500
Connection ~ 9350 1000
Connection ~ 9350 1650
Wire Wire Line
	9900 1000 10250 1000
Wire Wire Line
	9900 1650 10250 1650
Wire Wire Line
	7300 2600 8350 2600
Wire Wire Line
	8350 2750 7400 2750
Wire Wire Line
	7400 2750 7400 2700
Wire Wire Line
	7400 2700 7300 2700
Wire Wire Line
	8350 2900 7400 2900
Wire Wire Line
	7400 2900 7400 3100
Wire Wire Line
	7400 3100 7300 3100
Wire Wire Line
	8350 3350 7400 3350
Wire Wire Line
	7400 3350 7400 3300
Wire Wire Line
	7400 3300 7300 3300
Wire Wire Line
	7300 3200 8350 3200
Wire Wire Line
	3600 3050 4200 3050
Wire Wire Line
	4200 3050 4200 3000
Wire Wire Line
	4200 3000 4700 3000
Wire Wire Line
	4700 2900 3600 2900
Wire Wire Line
	3800 2800 4250 2800
Wire Wire Line
	4250 2800 4250 2700
Wire Wire Line
	4250 2700 4700 2700
Wire Wire Line
	4700 2600 4200 2600
Wire Wire Line
	4200 2600 4200 2650
Wire Wire Line
	4200 2650 3800 2650
Wire Wire Line
	4700 6100 5200 6100
Wire Wire Line
	5200 6100 5200 6250
Wire Wire Line
	4700 5000 5200 5000
Wire Wire Line
	5200 5000 5200 4800
Wire Wire Line
	2750 5800 3700 5800
Wire Wire Line
	2750 2650 2750 5800
Wire Wire Line
	4700 5200 5550 5200
Wire Wire Line
	4700 5300 5150 5300
Wire Wire Line
	5150 5300 5150 5350
Wire Wire Line
	5150 5350 5550 5350
Wire Wire Line
	3150 5500 3700 5500
Wire Wire Line
	3700 5400 3500 5400
Wire Wire Line
	3500 5400 3500 5350
Wire Wire Line
	3500 5350 3150 5350
Wire Wire Line
	8950 1000 9600 1000
Wire Wire Line
	8950 1650 9600 1650
Wire Wire Line
	7550 1700 7800 1700
Wire Wire Line
	7550 2350 7800 2350
Text GLabel 7800 1700 2    60   Output ~ 0
XO
Text GLabel 7800 2350 2    60   Output ~ 0
XI
Text GLabel 8950 1000 0    60   Input ~ 0
XO
Text GLabel 8950 1650 0    60   Input ~ 0
XI
Text GLabel 3200 4650 0    60   Input ~ 0
D+
Text GLabel 3200 4800 0    60   Input ~ 0
D-
Wire Wire Line
	3200 4650 3550 4650
Wire Wire Line
	3550 4650 3550 5000
Wire Wire Line
	3550 5000 3700 5000
Wire Wire Line
	3700 5100 3450 5100
Wire Wire Line
	3450 5100 3450 4800
Wire Wire Line
	3450 4800 3200 4800
$Comp
L LM2931AZ-3.3/5.0 U2
U 1 1 557FCB91
P 8150 4950
F 0 "U2" H 8150 5200 40  0000 C CNN
F 1 "LM2931AZ-3.3/5.0" H 8150 5150 40  0000 C CNN
F 2 "Power_Integrations:SO-8" H 8150 5050 35  0000 C CIN
F 3 "" H 8150 4950 60  0000 C CNN
	1    8150 4950
	1    0    0    -1  
$EndComp
$Comp
L VCC #PWR08
U 1 1 557FCD3A
P 6000 1600
F 0 "#PWR08" H 6000 1450 50  0001 C CNN
F 1 "VCC" H 6000 1750 50  0000 C CNN
F 2 "" H 6000 1600 60  0000 C CNN
F 3 "" H 6000 1600 60  0000 C CNN
	1    6000 1600
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR09
U 1 1 557FCD60
P 7400 4900
F 0 "#PWR09" H 7400 4750 50  0001 C CNN
F 1 "+5V" H 7400 5040 50  0000 C CNN
F 2 "" H 7400 4900 60  0000 C CNN
F 3 "" H 7400 4900 60  0000 C CNN
	1    7400 4900
	1    0    0    -1  
$EndComp
$Comp
L VCC #PWR010
U 1 1 557FCD86
P 9000 4900
F 0 "#PWR010" H 9000 4750 50  0001 C CNN
F 1 "VCC" H 9000 5050 50  0000 C CNN
F 2 "" H 9000 4900 60  0000 C CNN
F 3 "" H 9000 4900 60  0000 C CNN
	1    9000 4900
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR011
U 1 1 557FCDAC
P 8150 5400
F 0 "#PWR011" H 8150 5150 50  0001 C CNN
F 1 "GND" H 8150 5250 50  0000 C CNN
F 2 "" H 8150 5400 60  0000 C CNN
F 3 "" H 8150 5400 60  0000 C CNN
	1    8150 5400
	1    0    0    -1  
$EndComp
Wire Wire Line
	7400 4900 7750 4900
Wire Wire Line
	8550 4900 9000 4900
Wire Wire Line
	8150 5200 8150 5400
$Comp
L CONN_01X04 P1
U 1 1 557FD28F
P 9450 3850
F 0 "P1" H 9450 4100 50  0000 C CNN
F 1 "CONN_01X04" V 9550 3850 50  0000 C CNN
F 2 "Socket_Strips:Socket_Strip_Straight_1x04" H 9450 3850 60  0001 C CNN
F 3 "" H 9450 3850 60  0000 C CNN
	1    9450 3850
	1    0    0    -1  
$EndComp
Text GLabel 9250 3800 0    60   Output ~ 0
D+
Text GLabel 9250 3900 0    60   Output ~ 0
D-
$Comp
L GND #PWR012
U 1 1 557FD427
P 9200 4200
F 0 "#PWR012" H 9200 3950 50  0001 C CNN
F 1 "GND" H 9200 4050 50  0000 C CNN
F 2 "" H 9200 4200 60  0000 C CNN
F 3 "" H 9200 4200 60  0000 C CNN
	1    9200 4200
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR013
U 1 1 557FD44F
P 9200 3450
F 0 "#PWR013" H 9200 3300 50  0001 C CNN
F 1 "+5V" H 9200 3590 50  0000 C CNN
F 2 "" H 9200 3450 60  0000 C CNN
F 3 "" H 9200 3450 60  0000 C CNN
	1    9200 3450
	1    0    0    -1  
$EndComp
Wire Wire Line
	9250 3700 9250 3450
Wire Wire Line
	9250 3450 9200 3450
Wire Wire Line
	9250 4000 9250 4200
Wire Wire Line
	9250 4200 9200 4200
$Comp
L CONN_01X10 P2
U 1 1 557FD61A
P 1850 4650
F 0 "P2" H 1850 5200 50  0000 C CNN
F 1 "CONN_01X10" V 1950 4650 50  0000 C CNN
F 2 "Socket_Strips:Socket_Strip_Angled_1x10" H 1850 4650 60  0001 C CNN
F 3 "" H 1850 4650 60  0000 C CNN
	1    1850 4650
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR014
U 1 1 557FD669
P 1400 5400
F 0 "#PWR014" H 1400 5150 50  0001 C CNN
F 1 "GND" H 1400 5250 50  0000 C CNN
F 2 "" H 1400 5400 60  0000 C CNN
F 3 "" H 1400 5400 60  0000 C CNN
	1    1400 5400
	1    0    0    -1  
$EndComp
$Comp
L VCC #PWR015
U 1 1 557FD693
P 1350 4000
F 0 "#PWR015" H 1350 3850 50  0001 C CNN
F 1 "VCC" H 1350 4150 50  0000 C CNN
F 2 "" H 1350 4000 60  0000 C CNN
F 3 "" H 1350 4000 60  0000 C CNN
	1    1350 4000
	1    0    0    -1  
$EndComp
Text GLabel 1650 4400 0    60   Input ~ 0
SDA
Text GLabel 1650 4500 0    60   Input ~ 0
SCL
Text GLabel 1650 4600 0    60   Input ~ 0
SCK
Text GLabel 1650 4700 0    60   Input ~ 0
MISO
Text GLabel 1650 4800 0    60   Input ~ 0
MOSI
Text GLabel 1650 4900 0    60   Input ~ 0
TXD
Text GLabel 1650 5000 0    60   Input ~ 0
RXD
Text GLabel 1650 5100 0    60   Input ~ 0
G3
Wire Wire Line
	1650 4300 1350 4300
Wire Wire Line
	1350 4300 1350 4000
Wire Wire Line
	1650 4200 1000 4200
Wire Wire Line
	1000 4200 1000 5400
Wire Wire Line
	1000 5400 1400 5400
Wire Wire Line
	7800 3050 7300 3050
Wire Wire Line
	7300 3050 7300 3000
Wire Wire Line
	2750 2650 3350 2650
Wire Wire Line
	3350 2650 3350 1400
Connection ~ 3350 1400
$Comp
L C C1
U 1 1 558B5C2A
P 8700 5150
F 0 "C1" H 8725 5250 50  0000 L CNN
F 1 "C" H 8725 5050 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 8738 5000 30  0001 C CNN
F 3 "" H 8700 5150 60  0000 C CNN
	1    8700 5150
	1    0    0    -1  
$EndComp
Wire Wire Line
	8700 5000 8700 4900
Connection ~ 8700 4900
Wire Wire Line
	8700 5300 8150 5300
Connection ~ 8150 5300
$EndSCHEMATC
