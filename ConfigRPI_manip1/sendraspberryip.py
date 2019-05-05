  GNU nano 2.7.4                                                                                              File: Envoi_IP_Mail.py

#!usr/bin/env python
# coding: utf-8 -*-

import socket
import fcntl
import struct
import smtplib,os,sys
from email.MIMEMultipart import MIMEMultipart
from email.MIMEText import MIMEText

from_adrs = "custommail@gmail.com"
to_ards = "your_email@onlyyours.you"
login_mail = "custommail@gmail.com"

def mon_ip(ifname):
        s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        return socket.inet_ntoa(fcntl.ioctl(
                s.fileno(),
                0x8915,
                struct.pack( '256s', ifname[:15])
                )[20:24])

osts = ""
try:
        stsl = "interface wlan: " + mon_ip('wlan0')
#       print sts
except:
        stsl = "rien sur wlan0"
#       print sts

osts = stsl + "\n"

try:
        sts2 = "interface eth0: "+ mon_ip('eth0')
#       print sts2
except:
        sts2 = "rien sur eth0"
#       print sts2

osts = osts + sts2

msg = MIMEMultipart()
msg[ 'From' ] = from_adrs
msg['To' ] = to_ards
msg['Subject'] = 'Adresse ip de la raspberry'
msg.attach(MIMEText(osts))
mailserver = smtplib.SMTP('smtp.gmail.com', 587)
mailserver.ehlo()
mailserver.starttls()
mailserver.ehlo()
mailserver.login(from_adrs, "mailpassword")
mailserver.sendmail(from_adrs, to_ards, msg.as_string())
mailserver.quit()


