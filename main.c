// heitorwerneck@hotmail.com
// https://github.com/heitor57
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "base_converter.h"

int main(){
	char n[nsize]="";
	int b,t,c=0;
	char bc[3],tc[3];
	while(1){
		read_entry(n);
		// ( ERROR HANDLING
		if(!strcmp(n,"+0 0 0"))
			break;
		else if(n[0]!='-' && n[0]!='+')
			error("MUST PASS SIGNAL");
		else if(strcspn(n,".")==strlen(n))
			error("POINT MISSING/TERMINATOR OF INTEGER PART OF THE NUMBER");
		//	) ERROR HANDLING
		c=parse_entry(n,bc,tc);//GET ARGUMENTS FROM ENTRY
		if(c!=2){						// ERROR HANDLING
			error("NUMBER OF PASSED ARGUMENTS IS WRONG");
		}else if(strlen(n)>50){
			error("NUMBER SIZE HIGHER THAN 50");
		}
		b=parse_int(bc,10);
		t=parse_int(tc,10);
		checkbase(b,t);// CHECK IF BASE IS OK
		char* intvar;
		char* fracvar;
		intvar=convert_int(parse_int(n,b),t);
		fracvar=convert_frac(parse_frac(n,b),t);
		printf("%c%s.%s\n",n[0],intvar,fracvar);
		free(intvar);
		free(fracvar);
	}
	return 0;
}
