#include <iostream>

#ifndef _SLINKLIST_H
#define _SLINKLIST_H

#define MAXSIZE 1000

using std::cin;

typedef int elt;

typedef struct {
	elt data;
	int cur;
}component, SLinkList[MAXSIZE];

/*
�ŵ�/����ִ�в����ɾ������ʱ��ֻ���޸��α꣬����Ҫ�ƶ����е�Ԫ�أ��Ӷ��Ľ�����˳����в����ɾ��������Ҫ��
������Ԫ�ص�ȱ�㡣
ȱ�㣺û�н�������洢��������ı�����ȷ�������⣻��̬������Ҫά��һ������������̬�����������ȡ��*/

void InitSpace_SL(SLinkList& space);//�α��ʼ��

int MallocNode(SLinkList& space);

void FreeNode(SLinkList& space, int k);//����δʹ�õĿ��нڵ�

void UnitAAndBdifference(SLinkList& space, elt& s); //��������һ��ѡȡ�̶���ͷ���籾���е�K�������ÿռ�һ��ѡȡspace[0].curΪͷָ��;


#endif _SLINKLIST_H