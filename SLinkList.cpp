#include "SLinkList.h"

void InitSpace_SL(SLinkList& space) {
	for (size_t i = 0; i < MAXSIZE - 1; i++) space[i].cur = i + 1;
	space[MAXSIZE - 1].cur = 0;
}//�α��ʼ��

int MallocNode(SLinkList& space) {
	int i = space[0].cur;
	if (i) 	space[0].cur = space[i].cur;
	return i;
}

void FreeNode(SLinkList& space, int k) {
	space[k].cur = space[0].cur;
	space[0].cur = k;
}//����δʹ�õĿ��нڵ�

void UnitAAndBdifference(SLinkList& space, elt& s) {
	InitSpace_SL(space);//��������һ��ѡȡ�̶���ͷ���籾���е�K�������ÿռ�һ��ѡȡspace[0].curΪͷָ��
	s = MallocNode(space);
	elt r = s;
	int m, n;
	cin >> m >> n;//A��B��Ԫ�ظ���
	for (size_t j = 1; j <= m; j++)
	{
		int i = MallocNode(space);
		cin >> space[i].data;
		space[r].cur = i; r = i;
	}
	space[r].cur = 0;
	for (size_t j = 0; j <= n; j++)
	{
		elt b;	cin >> b; int k = space[s].cur; int p;
		while (k != space[r].cur && space[k].data != b)
		{
			p = k;
			k = space[k].cur;
		}

		if (k == space[r].cur)
		{
			int i = MallocNode(space);
			space[i].data = b;//���ÿռ��㹻��
			space[i].cur = space[r].cur;
			space[r].cur = i;
		}
		else
		{
			space[p].cur = space[k].cur;
			FreeNode(space, k);
			if (r == k) r = p;
		}
	}
}
