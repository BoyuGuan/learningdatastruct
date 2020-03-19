#include "linkQueue.h"
void InitQueue(LinkQueue& Q)
{
	Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
	if (!Q.front) exit(-1);
	Q.front->next = nullptr;
}

void destoryQueue(LinkQueue& Q)
{
	while (Q.front )
	{
		Q.rear = Q.front->next;
		free(Q.front);
		Q.front = Q.rear;
	}
}

void clearQueue(LinkQueue& Q)
{
	Q.front->data = NULL;
	QueuePtr p = Q.front->next;
	while (p!=Q.rear->next)
	{
		Q.front->next = p->next;
		free(p);
		p = Q.front->next;
	}
	Q.rear = Q.front;
}

bool queueEmpty(LinkQueue& Q)
{
	return Q.front == Q.rear;
}

int queueLength(LinkQueue& Q)
{
	int  count = 1;
	QueuePtr p = Q.front;
	while (p != Q.rear) {
		++count;
		p = p->next;
	}
	return count;
}

void getHead(LinkQueue Q, QelemType& e)
{
	e = Q.front->data;
}


void enQueue(LinkQueue& Q, QelemType e)
{
	QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
	if (!p) exit(-1);
	p->data = e; p->next = nullptr;
	Q.rear->next = p;
	Q.rear= p ;
}

void deQueue(LinkQueue& Q, QelemType& e)
{
	if (Q.front == Q.rear) exit(-1);
	QueuePtr p = Q.front->next;
	e = p->data;
	Q.front->next = p->next;
	if (Q.front == p) Q.rear = Q.front;
	free(p); 
}
