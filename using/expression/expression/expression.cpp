#include "expression.h"
#include <stdlib.h>

int Createopndstack(opndstack& S) {
	S.base = (double*)malloc(80 * sizeof(double));
	if (!S.base) exit(-1);
	S.top = S.base;
	S.size = 80;
	return 1;
}


double GetTop(opndstack S) {
	return *(S.top-1);
}

int push(opndstack& S, char e) {
	if (S.top - S.base >= S.size) {
		S.base = (double*)realloc(S.base, (10 + S.size) * sizeof(double));
		if (!S.base) exit(-1);
		S.top = S.base + S.size;
		S.size += 10;
	}
	*S.top++ = e-'0';
	return 1;
}

int push(opndstack& S, double e) {
	if (S.top - S.base >= S.size) {
		S.base = (double*)realloc(S.base, (10 + S.size) * sizeof(double));
		if (!S.base) exit(-1);
		S.top = S.base + S.size;
		S.size += 10;
	}
	*S.top++ = e ;
	return 1;
}

int pop(opndstack& S, double& e) {
	if (S.top == S.base) return 0;
	e=*--S.top;
	return e;
}

bool opndstackEmpty(opndstack S) {
	if (S.base == S.top)
	{
		return 1;
	}
	else return 0;
}

int Createoptrstack(optrstack& S)
{
	S.base = (char*)malloc(80 * sizeof(char));
	if (!S.base) exit(-1);
	S.top = S.base;
	S.size = 80;
	return 1;
	return 0;
}

char GetTop(optrstack S)
{
	return *(S.top-1);
}

int push(optrstack& S, char e)
{
	if (S.top - S.base >= S.size) {
		S.base = (char*)realloc(S.base, (10 + S.size) * sizeof(char));
		if (!S.base) exit(-1);
		S.top = S.base + S.size;
		S.size += 10;
	}
	*S.top++ = e;
	return 1;
}

int pop(optrstack& S, char& e)
{
	if (S.top == S.base) return 0;
	e = *--S.top;
	return e;
}

bool opndstackEmpty(optrstack S)
{
	if (S.base == S.top)
	{
		return 1;
	}
	else return 0;
}

char getchar(char a[])
{
	++count;
	return a[count];
}

bool in(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')' || c == '#')return 1;
	else return 0;
}

int precede(char a, char b,int compare[][7])
{
	int i, j;
	switch (a){
	case '+':i = 0; break;
	case '-':i = 1; break;
	case '*':i = 2; break;
	case '/':i = 3; break;
	case '(':i = 4; break;
	case ')':i = 5; break;
	case '#':i = 6; break;
	default:		break;
	}
	switch (b) {
	case '+':j = 0; break;
	case '-':j = 1; break;
	case '*':j = 2; break;
	case '/':j = 3; break;
	case '(':j = 4; break;
	case ')':j = 5; break;
	case '#':j = 6; break;
	default:		break;
	}

	return compare[i][j];
}

double operate(double a, char x, double b)
{
	switch (x) {
	case '+':return a + b; break;
	case '-':return a - b; break;
	case '*':return a * b; break;
	case '/':return a / b; break;
	default: return  -5; break;
	}
}

double EvaluateExpression(char a[])
{
	int com[7][7] = { {1,1,-1,-1,-1,1,1},{1,1,-1,-1,-1,1,1}, {1,1,1,1,-1,1,1}, {1,1,1,1,-1,1,1},\
{-1,-1,-1,-1,-1,0,-2}, {1,1,1,1,-2,1,1}, { -1,-1,-1,-1,-1,-2,0 } };
	opndstack opnd; optrstack optr;	Createopndstack(opnd); Createoptrstack(optr);
	push(optr, '#');	  char c = getchar(a);
	char x; double a1; double a2;
	while (c != '#' || GetTop(optr) != '#')
	{
		if (!in(c)) {
			push(opnd, c); c = getchar(a);
		}
		else
		{
			switch (precede(GetTop(optr), c,com))
			{
			case -1:
				push(optr, c); c = getchar(a); break;
			case 0:
				pop(optr, x); c = getchar(a); break;
			case 1:
				pop(optr, x); pop(opnd, a2); pop(opnd, a1); push(opnd, operate(a1, x, a2)); break;
			}
		}
	}
	return GetTop(opnd);
}




