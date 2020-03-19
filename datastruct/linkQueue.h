#ifndef _QUEUE_H
#define _QUEUE_H
#include <stdlib.h>
typedef int QelemType;

typedef struct QNode {
	QelemType data;
	struct QNode* next;
	   
}*QueuePtr;

typedef struct {
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;

void InitQueue(LinkQueue& Q);

void destoryQueue(LinkQueue& Q);

void clearQueue(LinkQueue& Q);

bool queueEmpty(LinkQueue& Q);

int queueLength(LinkQueue& Q);

void getHead(LinkQueue Q, QelemType& e);

void enQueue(LinkQueue& Q, QelemType e);

void deQueue(LinkQueue& Q, QelemType& e);










#endif // !_QUEUE.H_

