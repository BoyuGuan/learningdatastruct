#include "SLinkList.h"

void InitSpace_SL(SLinkList& space) {
	for (size_t i = 0; i < MAXSIZE - 1; i++) space[i].cur = i + 1;
	space[MAXSIZE - 1].cur = 0;
}//游标初始化

int MallocNode(SLinkList& space) {
	int i = space[0].cur;
	if (i) 	space[0].cur = space[i].cur;
	return i;
}

void FreeNode(SLinkList& space, int k) {
	space[k].cur = space[0].cur;
	space[0].cur = k;
}//回收未使用的空闲节点

void UnitAAndBdifference(SLinkList& space, elt& s) {
	InitSpace_SL(space);//此种链接一般选取固定开头，如本题中的K，而备用空间一般选取space[0].cur为头指针
	s = MallocNode(space);
	elt r = s;
	int m, n;
	cin >> m >> n;//A和B的元素个数
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
			space[i].data = b;//备用空间足够大
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
