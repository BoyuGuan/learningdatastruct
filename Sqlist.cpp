#include "Sqlist.h"

void CreateSqList(SqList& L) {
	L.elem = (elt*)malloc(LIST_INIT_SIZE * sizeof(elt));
	if (!L.elem) exit(OVERFLOW);
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
}

bool SqListInsert(SqList& L, int i, elt e) {
	int j;
	if (i<1 || i>(L.length + 1)) { return 0; }
	if (L.length >= L.listsize) { // 当前存储空间已满，增加分配
		elt* newbase = (elt*)realloc(L.elem, (L.listsize + LISTINCREMENT) * sizeof(elt));
		if (!newbase) exit(OVERFLOW); // 存储分配失败
		L.elem = newbase;                // 新基址
		L.listsize += LISTINCREMENT; // 增加存储容量
	}
	i--;
	for (j = L.length; j > i; j--)
	{
		L.elem[j] = L.elem[j - 1];
	}
	L.elem[i] = e;
	L.length++;
	return 1;
}

void SqListByArrary(SqList& L, elt a[], int n) {
	for (size_t i = 0; i < n; i++)
	{
		if (L.length >= L.listsize) { // 当前存储空间已满，增加分配
			elt* newbase = (elt*)realloc(L.elem, (L.listsize + LISTINCREMENT) * sizeof(elt));
			if (!newbase) exit(OVERFLOW); // 存储分配失败
			L.elem = newbase;                // 新基址
			L.listsize += LISTINCREMENT;
		}// 增加存储容量
		L.elem[i] = a[i];
		L.length++;
	}
}

void DestoryList(SqList*& L) {
	free(L);//传递的是指针，所以直接free掉就行
}

bool ListEmpty(SqList& L) {
	return L.length;
}

int Listlength(SqList& L) {
	return L.length;
}

void DispSqList(SqList& L) {

	for (int i = 0; i < L.length; i++)
		std::cout << L.elem[i] << " ";
}

bool GetElm(SqList* L, int i, elt& e) {
	if (i<1 || i>L->length) return 0;
	else
	{
		e = L->elem[i - 1];
		return 1;
	}
}

int LocateElm(SqList* L, elt e) {
	int i = 0;
	while (i < L->length && L->elem[i] != e)
	{
		++i;
	}
	if (i >= L->length) return 0;
	else
	{
		return i + 1;
	}
}

bool ListDelete_Single(SqList*& L, int i, elt& e) {
	int j;
	if (i<1 || i>(L->length + 1)) { return 0; }
	i--;
	e = L->elem[i];
	for (j = i; i < L->length; j++)
	{
		L->elem[j] = L->elem[j + 1];
	}
	L->length--;
	return 1;
}

void DeleteInCase(SqList& L, elt min, elt max) {
	int k = 0;
	for (int i = 0; i < L.length; i++)
	{
		if (L.elem[i] >= max || L.elem[i] <= min)
		{
			L.elem[k] = L.elem[i];
			++k;
		}
	}
	L.length = k;
}


void task2_10(SqList& L, int i, int k) {
	i--;	int j = i; int m = L.length - 1;
	while (j + k <= m)
	{
		L.elem[j] = L.elem[j + k];
		++j;
	}
	L.length -= k;
}

void task2_11(SqList& L, int a) {
	int i = 0;
	while (a > L.elem[i] && i < L.length - 1) { i++; }
	if (i != L.length - 1) i--;
	++i;
	SqListInsert(L, ++i, a);
}