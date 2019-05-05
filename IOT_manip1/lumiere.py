#=/usr/bir/env python 
# coding: utf-8 -*-

import serial 
import time

portUSB='/dev/ttyACM0'

try:
    ser=serial.Serial(portUSB, baudrate=9600, timeout=1, writeTimeout=1)
    
    while True:
        ligne=ser.readline()
        heure=time.strftime('%y-%m-%d %H:%M:%S')
        print "information prise à {}:{}".format(heure, ligne)
except:
    print "Problème avec le port USB"