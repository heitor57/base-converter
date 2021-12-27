#include <math.h>
#include "base_converter.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
const char sim[]="0123456789ABCDEF";
const int allowedbases[]={2,8,10,16};

void read_entry(char n[nsize]){
	setbuf(stdin,NULL);
	fgets(n,nsize,stdin);
	n[strcspn(n,"\n")] = 0;// remove new line
}
void error(const char* str){
	fputs("ERROR: ",stderr);
	fputs(str,stderr);
	exit(EPERM);
}
int parse_entry(char *n,char bc[3],char tc[3]){
	int c=0; // error variable
	int strl=strlen(n);
	for(int i = 0,j=0;i < strl;i++){
		if(n[i] == ' '){
			if(c==0)
				n[i]=0;
			else
				j=0;
			c++;
		}else{
			if(c>0)
			{
				if(c==1){
					bc[j]=n[i];
					j++;
					bc[j]=0;
				}else{
					tc[j]=n[i];
					j++;	
					tc[j]=0;
				}
			}
		}
	}
	return c;
}
void checkbase(int bc,int tc){
	int flag1=0,flag2=0;
	for(int i = 0;i < sizeof allowedbases;i++){
		if(allowedbases[i]==bc){
			flag1=1;
		}
		if(allowedbases[i]==tc){
			flag2=1;
		}
	}
	if(!flag1 || !flag2)
		error("NOT PERMITTED BASE");
}
char* invertstring(char *str){
	char aux;
	for(int i=0,j=strlen(str)-1;i<j;i++,j--){
		aux = str[i];
		str[i]= str[j];
		str[j] = aux;
	}
	return str;
}

char inttochar(int n){
	char c;
	if(n>=0 && n<16){
		if(n<10){
			c = n+'0';
		}else{
			for(int i = 10;i<16;i++)
				if(n==i)
					c = sim[i];
		}
	}
	return c;
}
int dot_pos(char n[]){
	int i;
	for(i = 0;n[i]!=0 && n[i]!='.' ;i++);
	return i;
}

char* convert_int(unsigned long long int n, int t){
	char *str = malloc (sizeof (char) * msize);
	int i;
	for(i = 0 ;n!=0&& i<msize ; i++){
		str[i] = inttochar(n%t);
		n/=t;
	}	
	str[i] = 0;
	return invertstring(str);
}
char* convert_frac(long double n, int t){
	char *str = malloc (sizeof (char) * msize);
	int d,i;
	long double nb;
	for(i=0;n>0;i++){
		nb = n * t;
		d = nb;//only integer part
		str[i]=inttochar(d);
		n = nb-d;
	}
	str[i] = 0;
	return str;
}
unsigned long long int parse_int(char n[],int b){
	unsigned long long int result=0;
	int j;
	for(int i = dot_pos(n)-1, exp=0; i>=0 ;i--,exp++)
		for(j=0;j<b;j++)
			if(n[i]==sim[j]){
				result+=j*powl(b,exp);
				break;
			}

	return result;
}
long double parse_frac(char n[],int b){
	long double result=0;
	int j;
	for(int i = dot_pos(n)+1, exp=-1; n[i]!=0 ;i++,exp--)
		for(j=0;j<b;j++)
			if(n[i]==sim[j]){
				result+=j*powl(b,exp);
				break;
			}
	return result;
}
