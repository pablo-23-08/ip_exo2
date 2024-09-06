#!/bin/bash

#J'ai conçu ce script pour eviter de compiler un à un chaque fichier .c
#Ce script ne peut être executer que par le superutilisateur root

gcc sources/acceuil.c -o sources/acceuil.cgi
cp sources/acceuil.cgi /var/www/html

gcc sources/ip_infos.c sources/main.c -lm -o sources/ip_infos.cgi
cp sources/ip_infos.cgi /var/www/html

systemctl restart apache2

#Copyright PABLO Y IARIVO Hendrinimerina - L1 MIT



