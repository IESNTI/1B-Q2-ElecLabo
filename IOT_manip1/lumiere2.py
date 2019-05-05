#!/usr/bin/env python
# coding: utf-8 -*-

import serial
import time

fichierDeSortie="alarmeDatas.csv"
repDeSortie="/home/pi/Documents/lumiere/"
modeDeFichier="a"
listeColones="Date:Heure;évènement"

portUSB='/dev/ttyACM0'

fichier = open(repDeSortie+fichierDeSortie, 'w')
fichier.write("Date"+";"+"Heure"+";"+"Evenement")
fichier.close()

try:
    ser=serial.Serial(portUSB, baudrate=9600, timeout=1,writeTimeout=1)
    while True:
        ligne=ser.readline()
        date=time.strftime('%y-%m-%Sd')
        heure=time.strftime('%H:%M:%S')
        print "information prise le {} à {}:{}".format(date, heure, ligne)
        fichier = open(repDeSortie+fichierDeSortie, modeDeFichier)
        fichier.write(date+";"+heure+";"+ligne)
        fichier.close()

except:
    print "Probleme avec le port USB"