#include "sqQueue.h"
#include <stdlib.h>

void InitsqQueueI(sqQueue& Q)
{
	Q.base = (qElemtype*)malloc(MAXSIZE * sizeof(qElemtype));
	if (!Q.base) exit(-1);
	Q.front = Q.rear = 0;
}

inline int sqQueuelength(sqQueue Q)
{
	return (Q.rear - Q.front + MAXSIZE)%MAXSIZE;
}

bool ensqQueue(sqQueue& Q, sqElemtype e)
{
	if ((Q.rear + 1) % MAXSIZE == Q.front) return 0;
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAXSIZE;
	return 1;
}

bool desqQueue(sqQueue& Q, sqElemtype e)
{
	if(Q.front==Q.rear)	return false;
	e = Q.base[Q.front];
	Q.front = (Q.front + 1) % MAXSIZE;
	return 1;
}
