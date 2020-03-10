
#ifndef _LINKLIST_H
#define _LINKLIST_H

#define  OK     1
#define  ERRO	0

typedef int elt ;

typedef struct LNode {
	elt data;
	struct LNode* next;
}LNode, * LinkList;

int GetElem_L(LinkList L, int i, int& e);

void CreatList(LinkList& L);


int LinkListInitByArray(LinkList& L, int n, elt a[]);


int  LocateLinklist_2_13(LinkList L, elt x);


void  DispLinkList(LinkList L);


int LinkListDelet(LinkList& L, int i);

int ListInsert_L(LinkList& L, elt e, int i);

void LinkRever_L(LinkList& list);


void LinkRever_L2(LinkList& list);


void LinkUnitAndReverse(LinkList& La, LinkList& Lb, LinkList& Lc);


#endif