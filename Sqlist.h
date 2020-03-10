#include <malloc.h>
#include <stdlib.h>
#include <iostream>
#ifndef _SQLIST_H
#define _SQLIST_H

#define  TRUE   1
#define  FALSE  0
#define  OK     1
#define  ERRO	0
#define  INFEASIBLE -1
#define  OVERFLOW	-2
#define  LIST_INIT_SIZE     80  
#define  LISTINCREMENT    10 

//Ë³Ðò±í


typedef int elt;



typedef struct {
	elt* elem;
	int length;
	int listsize;
}SqList;

void CreateSqList(SqList& L) {
	L.elem = (elt*)malloc(LIST_INIT_SIZE * sizeof(elt));
	if (!L.elem) exit(OVERFLOW);
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
}

bool SqListInsert(SqList& L, int i, elt e);

void SqListByArrary(SqList& L, elt a[], int n);

void DestoryList(SqList*& L);

bool ListEmpty(SqList& L);

int Listlength(SqList& L);

void DispSqList(SqList& L);

bool GetElm(SqList* L, int i, elt& e);

int LocateElm(SqList* L, elt e);
bool ListDelete_Single(SqList*& L, int i, elt& e);

void DeleteInCase(SqList& L, elt min, elt max);


void task2_10(SqList& L, int i, int k);

void task2_11(SqList& L, int a);


#endif

