#pragma once
#include <crtdbg.h>
#include <iostream>
#ifndef _STACK_H
#define _STACK_H

//typedef int Selemtype ;

#define  STACK_INIT_SIZE     80  
#define  STACKINCREMENT    10 
#define  OVERFLOW   -1 


using namespace std;

typedef struct {
	int ord;
	int seat[2];
	int di;
}Selemtype;


typedef struct stack
{
	Selemtype* base;
	Selemtype* top;
	int size;
}SqStack;


int Createstack(stack& S) ;

int GetTop(SqStack S, Selemtype& e);

int push(SqStack& S, Selemtype e);

void assign_e(Selemtype& e, int curstep, int curpos[], int  di);

int pop(stack& S, Selemtype& e); //删除一个栈顶元素并返回这个值

bool StackEmpty(stack S);

//以上为stack的基本函数



void assign_a(int a[], int a1, int b); 

void assign_e(Selemtype& e, int curstep, int curpos[], int  di);

bool equal(int a[], int b[]);

bool pass(stack S, int curpos[], bool maze[10][10]);

void move(int a[], int b);

int MazePath(bool maze[][10], int start[], int end[]);

//以上为迷宫函数






#endif