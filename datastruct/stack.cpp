#include "stack.h"

int Createstack(stack& S){
S.base = (Selemtype*)malloc(STACK_INIT_SIZE * sizeof(Selemtype));
if (!S.base) exit(OVERFLOW);
S.top = S.base;
S.size = STACK_INIT_SIZE;
return 1;
}


int GetTop(SqStack S, Selemtype& e){
	if (S.top = S.base)return 0;
	e = *(S.top - 1);
	return 1;
}

int push(SqStack& S, Selemtype e){
	if (S.top - S.base >= S.size) {
		S.base = (Selemtype*)realloc(S.base, (STACKINCREMENT + S.size) * sizeof(Selemtype));
		if (!S.base) exit(OVERFLOW);
		S.top = S.base + S.size;
		S.size += STACKINCREMENT;
	}
	*S.top++ = e;
}

int pop(stack& S, Selemtype& e) {
	if (S.top == S.base) return 0;
	S.top--;
	assign_e(e, S.top->ord, S.top->seat, S.top->di);
	return 1;
}

bool StackEmpty(stack S) {
	if (S.base == S.top)
	{
		return 1;
	}
	else return 0;
}

void assign_a(int a[], int a1, int b) {
	a[0] = a1;
	a[1] = b;
}

void assign_e(Selemtype& e, int curstep, int curpos[], int  di){
	e.di = di; e.ord = curstep;
	e.seat[0] = curpos[0];
	e.seat[1] = curpos[1];
}
bool equal(int a[], int b[]){
	int* a1 = a; int* b1 = b;
	if ((*a1 == *b1) && (*(++b1) == *(++a1))) return 1;
	else return 0;
}

bool pass(stack S, int curpos[], bool maze[10][10]) {
	Selemtype* p = S.base;
	while (p != S.top) {
		if (equal(p->seat, curpos))  return 0;
		p++;
	}
	if (maze[curpos[0]][curpos[1]] == 1) return 0;

	return 1;
}

void move(int a[], int b) {
	switch (b)
	{
	case 1: a[1]++; break;
	case 2: a[0]++; break;
	case 3: a[1]--; break;
	case 4:	a[0]--; break;
	}
}

void MarkPrint(int a, int b, bool maze[][10]) {
	maze[a][b] = 1;
}

void showthepath(stack S) {
	Selemtype* p = S.base;
	while (p != S.top)
	{
		cout << p->seat[0] << "and" << p->seat[1] << "     ";
		p++;
	}
}


int MazePath(bool maze[][10], int start[], int end[]) {
	stack S;	Createstack(S);		int curpos[2] = { -1,-1 };	memcpy(curpos, start, sizeof(curpos));  int curstep = 1;	 Selemtype e;
	do {
		if (pass(S, curpos, maze)) {
			assign_e(e, curstep, curpos, 1);
			push(S, e);
			if (equal(curpos, end)) {
				showthepath(S);
				return 1;
			}
			move(curpos, 1);
			curstep++;
		}
		else
		{
			if (!StackEmpty(S))
			{
				pop(S, e);
				while (e.di == 4 && !StackEmpty(S)) {
					MarkPrint(e.seat[0], e.seat[1], maze); pop(S, e);
				}
				if (e.di < 4)
				{
					e.di++; push(S, e);
					memcpy(curpos, e.seat, sizeof(e.seat));
					move(curpos, e.di);
				}
			}
		}
	} while (!StackEmpty(S));
	return -1;
}