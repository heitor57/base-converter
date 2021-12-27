#ifndef BASE_CONVERTER_H
#define BASE_CONVERTER_H
#ifdef __linux__ 
	#define EPERM	1 /* OPERATION NOT PERMITTED << UNIX BASED SYSTEMS */
#elif _WIN32
	#define EPERM 13
#else
	#define EPERM	1 /* OPERATION NOT PERMITTED << UNIX BASED SYSTEMS */
#endif
#define nsize 57
#define msize 100
extern const char sim[];
extern const int allowedbases[];
void read_entry(char n[nsize]);
void error(const char* str);
int parse_entry(char *n,char bc[3],char tc[3]);
void checkbase(int bc,int tc);
char* convert_int(unsigned long long int n, int t);
char* convert_frac(long double n, int t);
unsigned long long int parse_int(char n[],int b);
long double parse_frac(char n[],int b);
char* invertstring(char *str);
char inttochar(int n);
int dot_pos(char n[]);
#endif
