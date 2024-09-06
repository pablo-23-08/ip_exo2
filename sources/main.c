#include <stdio.h>
#include <string.h>
#include "ip_infos.h"

void display(char ip[15], char msr[15], char reseau[15], char broadcast[15], int nbre_machine, char bit_reseau[3]);

int main ()
{
	char bit_reseau[3];
	char ip[15];
	char ip_bin[32];
	char msr[15];
	char msr_bin[32];
	char reseau[15];
	char reseau_bin[32];
	char broadcast[15];
	char broadcast_bin[32];
	int nbre_machine;
	get_ip(ip, bit_reseau);
	fonct_msr(ip, bit_reseau, msr, ip_bin, msr_bin);
	fonct_reseau(reseau, reseau_bin, ip_bin, msr_bin);
	fonct_broadcast(broadcast, broadcast_bin, ip_bin, msr_bin, bit_reseau);
	fonct_nbre_machine(&nbre_machine, msr_bin);
	display(ip, msr, reseau, broadcast, nbre_machine, bit_reseau);
	
	return 0;
}

void display(char ip[15], char msr[15], char reseau[15], char broadcast[15], int nbre_machine, char bit_reseau[3])
{
	int a, b, c, d;
	char e;
	sscanf(ip, "%d.%d.%d.%d%c", &a, &b, &c, &d, &e);
	
	printf("Content-Type: text/html\n\n");
	printf("<HTML>\n");
	printf("<HEAD><TITLE>ip_infos</TITLE><META CHARSET=\"utf-8\"></HEAD>\n");
	printf("<BODY BGCOLOR=\"#DDFFFF\">\n");
	if(a<0 || a>255 || b<0 || b>255 || c<0 || c>255 || d<0 || d>255 || e!='\0')
	{
		printf("<H1>L'adresse ip que vous avez entrez est fausse! \n</H1><BR>\n");
        printf("<FORM ACTION=\"acceuil.cgi\" METHOD=\"GET\">\n");
        printf("<INPUT TYPE=\"SUBMIT\" VALUE=\"Recommencez\"/>\n");
	}
	else
	{
		printf("IP=%s et bit_reseau=%s <BR>", ip, bit_reseau);
		printf("msr=%s<BR>\n",msr);
		printf("@reseau=%s<BR>\n",reseau);
		printf("@broadcast=%s<BR>\n",broadcast);
		printf("Nombre de machine = %d\n", nbre_machine);
		printf("<FORM ACTION='acceuil.cgi' METHOD='GET'>\n");
		printf("<INPUT TYPE='SUBMIT' VALUE='voir une autre adresse ip'/>\n");
	}
	printf("</FORM>\n");
	printf("</BODY>\n");
	printf("</HTML>\n");
	
}
