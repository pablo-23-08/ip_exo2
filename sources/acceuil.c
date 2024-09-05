#include <stdio.h>

void get_ip();

int main() {
   get_ip();
   return 0;
}

void get_ip()
{
    printf("Content-Type: text/html\n\n");
    printf("<HTML>\n");
    printf("<HEAD><TITLE>acceuil</TITLE><META CHARSET='utf-8'></HEAD>\n");
    printf("<BODY BGCOLOR='#DDFFFF'>\n");
    printf("<LABEL for='ip'>Veuillez entrer une adresse IP de la forme C.I.D.R: </LABEL>\n");
    printf("<FORM ACTION=\"ip_infos.cgi\" METHOD=\"GET\">\n");
    printf("<INPUT TYPE=\"text\" NAME=\"ip\" ID='ip' VALUE=\"\" PLACEHOLDER=\"XXX.XXX.XXX.XXX/SR\"/><BR><BR>\n");
    printf("<INPUT TYPE=\"SUBMIT\" VALUE=\"Identifier\"/>\n");
    printf("</FORM>\n");
    printf("</BODY>\n");
}



