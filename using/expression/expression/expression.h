#pragma once

static int count = 0;

typedef struct opndstack
{
	double* base;
	double* top;
	int size;
};



int Createopndstack(opndstack& S);

double GetTop(opndstack S);

int push(opndstack& S, double e);


int pop(opndstack& S, double& e); //删除一个栈顶元素并返回这个值

bool opndstackEmpty(opndstack S);

typedef struct optrstack
{
	char* base;
	char* top;
	int size;
};

int Createoptrstack(optrstack& S);

char GetTop(optrstack S);

int push(optrstack& S, char e);

int pop(optrstack& S, char& e); //删除一个栈顶元素并返回这个值

bool opndstackEmpty(optrstack S);

char getchar(char a[]);

bool in(char c);

int precede(char a, char b, int compare[][7]);

double operate(double a, char x,double b);

double EvaluateExpression(char a[]);
