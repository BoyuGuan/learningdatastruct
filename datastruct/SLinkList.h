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
优点/：在执行插入和删除操作时，只需修改游标，不需要移动表中的元素，从而改进了在顺序表中插入和删除操作需要移
动大量元素的缺点。
缺点：没有解决连续存储分配带来的表长难以确定的问题；静态链表还需要维护一个空闲链；静态链表不能随机存取。*/

void InitSpace_SL(SLinkList& space);//游标初始化

int MallocNode(SLinkList& space);

void FreeNode(SLinkList& space, int k);//回收未使用的空闲节点

void UnitAAndBdifference(SLinkList& space, elt& s); //此种链接一般选取固定开头，如本题中的K，而备用空间一般选取space[0].cur为头指针;


#endif _SLINKLIST_H