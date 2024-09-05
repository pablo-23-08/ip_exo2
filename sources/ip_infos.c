#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void get_ip(char ip[15], char bit_reseau[3]);
void fonct_msr(char ip[15], char br[3], char msr[15], char ip_bin[32], char msr_bin[32]);
void fonct_reseau(char reseau[15], char reseau_bin[32], char ip_bin[32], char msr_bin[32]);
void fonct_broadcast(char broadcast[15], char broadcast_bin[32], char ip_bin[32], char msr_bin[32], char br[3]);
void fonct_nbre_machine(int *nbre_machine, char msr_bin[32]);


void binary(int *nbre, char bin[8]);
void decimal(char bin[8],int *nbre);
void form_bin(char ip[15], char ip_bin[32]);
void form_dec(char ip[15], char ip_bin[32]);

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
	
	return 0;
}

void get_ip(char ip[15], char bit_reseau[3])
{
	char *chaine;
	chaine = getenv("QUERY_STRING");
	sscanf(chaine, "ip=%15[^%%]%%2F%3[^\n]", ip, bit_reseau);
	printf("Content-Type: text/html\n\n");
	printf("<HTML>\n");
	printf("<HEAD><TITLE>ip_infos</TITLE><META CHARSET='utf-8'></HEAD>\n");
	printf("<BODY BGCOLOR='#DDFFFF'>\n");
	printf("IP=%s et bit_reseau=%s <BR>", ip, bit_reseau);
	
}

void fonct_msr(char ip[15], char br[3], char msr[15], char ip_bin[32], char msr_bin[32])
{
	int bit_hote, bit_reseau, i, j;
	sscanf(br, "%d", &bit_reseau);
	form_bin(ip, ip_bin);
	form_bin(ip, msr_bin);
	for(i=0;i<32;i++)
	{
		if(i<bit_reseau)
			msr_bin[i]='1';
		if(i>=bit_reseau)
			msr_bin[i]='0';
	}
	form_dec(msr, msr_bin);
	printf("msr=%s<BR>\n",msr);
}

void fonct_reseau(char reseau[15], char reseau_bin[32], char ip_bin[32], char msr_bin[32])
{
	for(int i=0;i<32;i++)
	{
		if((ip_bin[i]=='1') && (msr_bin[i]=='1'))
		{
			reseau_bin[i]='1';
		}
		else
		{
			reseau_bin[i]='0';
		}
	}
	form_dec(reseau, reseau_bin);
	printf("@reseau=%s<BR>\n",reseau);
}

void fonct_broadcast(char broadcast[15], char broadcast_bin[32], char ip_bin[32], char msr_bin[32], char br[3])
{
	int bit_hote, bit_reseau;
	sscanf(br, "%d", &bit_reseau);
	bit_hote=32-bit_reseau;
	for(int i=0;i<bit_reseau;i++)
	{
		broadcast_bin[i]=ip_bin[i];
	}
	for(int i=bit_reseau;i<32;i++)
	{
		broadcast_bin[i]='1';
	}
	form_dec(broadcast, broadcast_bin);
	printf("@broadcast=%s<BR>\n",broadcast);
}

void fonct_nbre_machine(int *nbre_machine, char msr_bin[32])
{
	int bit_hote=0;
	for(int i=0;i<32;i++)
	{
		if(msr_bin[i]=='0')
			bit_hote++;
	}
	*nbre_machine=pow(2,bit_hote)-2;
	printf("Nombre de machine = %d\n", *nbre_machine);
	printf("<FORM ACTION='acceuil.cgi' METHOD='GET'>\n");
	printf("<INPUT TYPE='SUBMIT' VALUE='voir une autre adresse ip'/>\n");
	printf("</FORM>\n");
	printf("</BODY>\n");
	printf("</HTML>\n");
}

void binary(int *nbre, char bin[8])
{
	int dividende,quotient;
	dividende = *nbre;
	for(int i=7;i>=0;i--)
	{
		quotient = dividende / pow(2,i);
		dividende = dividende - (quotient * pow(2,i));
		if(quotient==0)
		{
			bin[7-i]='0';
		}
		if(quotient==1)
		{
			bin[7-i]='1';
		}
	}
	
}

void form_bin(char ip[15], char ip_bin[32])
{
	int a, b, c, d;
	char a_[8], b_[8], c_[8], d_[8];
	
	sscanf(ip, "%d.%d.%d.%d", &a, &b, &c, &d);
	binary(&a, a_);
	binary(&b, b_);
	binary(&c, c_);
	binary(&d, d_);
	
	for(int i=0;i<32;i++)
	{
		if(i<8)
			ip_bin[i]=a_[i];
		if(i>=8 && i<16)
			ip_bin[i]=b_[i-8];
		if(i>=16 && i<24)
			ip_bin[i]=c_[i-16];
		if(i>=24)
			ip_bin[i]=d_[i-24];
	}
}


void decimal(char bin[8],int *nbre)
{
	for(int i=7;i>=0;i--)
	{
		if(bin[7-i]=='1')
		{
			*nbre=*nbre+pow(2,i);
		}
	}
}

void form_dec(char ip[15], char ip_bin[32])
{
	int a=0, b=0, c=0, d=0;
	char a_[8], b_[8], c_[8], d_[8];
	
	for(int i=0;i<32;i++)
	{
		if(i<8)
			a_[i]=ip_bin[i];
		if(i>=8 && i<16)
			b_[i-8]=ip_bin[i];
		if(i>=16 && i<24)
			c_[i-16]=ip_bin[i];
		if(i>=24)
			d_[i-24]=ip_bin[i];
	}
	
	decimal(a_,&a);
	decimal(b_,&b);
	decimal(c_,&c);
	decimal(d_,&d);
	
	sprintf(ip,"%d.%d.%d.%d", a, b, c, d);
}
