#pragma once
#define MAXSIZE 100
typedef  int sqElemtype ;
typedef struct {
	sqElemtype* base;
	int front;
	int rear;
}sqQueue;

void InitsqQueueI(sqQueue& Q);

inline int sqQueuelength(sqQueue Q);

bool ensqQueue(sqQueue& Q, sqElemtype e); 

bool desqQueue(sqQueue& Q, sqElemtype e);