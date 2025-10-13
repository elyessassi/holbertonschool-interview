#ifndef MUL
#define MUL

#include <stdlib.h>
#include <stdio.h>


int _putchar(char c);
int mystrlen(char *mystring);
void print_string(char *str);
int checkIfNum(char chr);
void exitFunc(void);
void zerosArray(char **array, int len);
char *getMul(char *n1, char *n2, int s1, int s2, char *res, char *s, char *e);
void addTwoDigitNum(char **array, int number);


#endif
