#include <iostream>
using namespace std;

#include "LinkList.h"
#include "SLinkList.h"
#include "Sqlist.h"
#include "polyn.h"
#include "stack.h"



int main( ){
	bool maze[10][10]{ {1,1,1,1,1,1,1,1,1,1},{1,0,0,1,0,0,0,1,0,1},{1,0,0,1,0,0,0,1,0,1},{1,0,0,0,0,1,1,0,0,1}, {1,0,1,1,1,0,0,0,0,1}, \
	{1,0,0,0,1,0,0,0,0,1}, {1,0,1,0,0,0,1,0,0,1}, { 1,0,1,1,1,0,1,1,0,1 }, { 1,1,0,0,0,0,0,0,0,1 }, { 1,1,1,1,1,1,1,1,1,1 } };
	int start[2]{ 1,1 }; int end[2] = { 8,8 };
	MazePath(maze, start, end);
	
}

              	