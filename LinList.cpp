#include "LinkList.h"
#include <stdlib.h>
#include <iostream>

int GetElem_L(LinkList L, int i, int& e) {
	LNode* p = L->next; int j = 1;
	while (p && j < i)
	{
		p = p->next; j++;
	}
	if (!p || j > i)
	{
		return ERRO;
	}
	e = p->data;
	return OK;
}

void CreatList(LinkList& L) {
	L = (LinkList)malloc(sizeof(LNode));
	L->next = nullptr;
}


int LinkListInitByArray(LinkList& L, int n, elt a[]) {
	int i = 0;
	if (n < 0) return ERRO;
	LinkList p = L;
	while (i < n)
	{
		LinkList  s = (LinkList)malloc(sizeof(LNode));
		s->data = a[i]; s->next = nullptr; p->next = s; p = s;
		++i;
	}
	return OK;
}


int  LocateLinklist_2_13(LinkList L, elt x) {
	int i = 1;
	LinkList p = L->next;

	while (p->data != x && p->next) {
		i++;
		p = p->next;
	}
	if (!p->next) return ERRO;
	else return i;
}


void  DispLinkList(LinkList L) {
	LinkList p = L->next;

	while (p)
	{
		std::cout << p->data;
		p = p->next;
	}
}


int LinkListDelet(LinkList& L, int i) {
	LinkList p = L; int j = 0;
	while (j < i - 1)
	{
		p = p->next; j++;
	}
	if (!(p->next) || j > i - 1) return ERRO;
	LinkList t = p->next; p->next = t->next;
	free(t);
	return OK;
}


int ListInsert_L(LinkList& L, elt e, int i) {
	LinkList p = L->next; int j = 1;
	while (j < i - 1 && p)
	{
		p = p->next; j++;
	}
	if (!p || j > i - 1)  return ERRO;
	LinkList  s = (LinkList)malloc(sizeof(LNode));
	s->data = e; s->next = p->next;
	p->next = s;
	return OK;
}


void LinkRever_L(LinkList& list) {
	int i = 0;
	LinkList p = list;
	LinkList thead = (LinkList)malloc(sizeof(LNode));
	while (p->next)
	{
		i++;
		p = p->next;
	}
	int n = i;
	int tn = n;
	LinkList q = thead;
	for (i = 0; i < n; i++)
	{
		p = list;
		for (int j = 0; j < tn; j++)
		{
			p = p->next;
		}
		tn--;
		q->next = p;
		q = q->next;
		q->next = nullptr;
	}
	LinkList f = list;
	list = thead;
	free(f);
}


void LinkRever_L2(LinkList& list) {
	LinkList p1 = list->next;
	LinkList p2 = p1->next;
	while (p2->next)
	{
		p1->next = p2->next;//Å£±ÆËã·¨
		p2->next = 0;
		list->next = list->next;
		p2 = p1->next;

	}
	p2->next = list->next;
	list->next = p2;
	p1->next = nullptr;
}


void LinkUnitAndReverse(LinkList& La, LinkList& Lb, LinkList& Lc) {
	LinkList a = La->next, b = Lb->next, c = Lc;
	while (a && b)
	{
		if (a->data > b->data) {
			c->next = b;
			c = b;
			b = b->next;
		}
		else
		{
			c->next = a;
			c = a;
			a = a->next;
		}
	}
	c->next = a ? a : b;
	free(La); free(Lb);

	LinkList p1 = Lc->next;
	LinkList p2 = p1->next;
	while (p2->next)
	{
		p1->next = p2->next;
		p2->next = Lc->next;
		Lc->next = p2;
		p2 = p1->next;
	}
	p2->next = Lc->next;
	Lc->next = p2;
	p1->next = nullptr;
}