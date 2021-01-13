#include <stdio.h>
#include <stdlib.h>
#include "DLL.h"

int DLL_main() {
	int i = 0;
	int count = 0;
	Node *List = NULL;
	Node *Current = NULL;
	Node *NewNode = NULL;


	for (int i = 0; i < 5; i++) {
		NewNode = DLL_CreateNode(i);
		DLL_AppendNode(&List, NewNode);
	}
	
	count = DLL_GetNodeCount(List);
	
	for (i = 0; i < count; i++) {
		Current = DLL_GetNodeAt(List, i);
		printf("List[%d] : %d\n", i, Current->Data);
	}

	//리스트의 3번째 노드 뒤에 노드 삽입
	printf("\n====Insert 100 After [3]====\n\n\n");
	NewNode = DLL_CreateNode(100);
	Current = DLL_GetNodeAt(List, 3);
	DLL_InsertAfter(Current, NewNode);

	count = DLL_GetNodeCount(List);

	for (i = 0; i < count; i++) {
		Current = DLL_GetNodeAt(List, i);
		printf("List[%d] : %d\n", i, Current->Data);
	}


	//리스트의 3번째 노드 삭제
	printf("\n====Remove Node at [3]====\n\n\n");
	Current = DLL_GetNodeAt(List, 3);
	DLL_RemoveNode(&List, Current);

	count = DLL_GetNodeCount(List);

	for (i = 0; i < count; i++) {
		Current = DLL_GetNodeAt(List, i);
		printf("List[%d] : %d\n", i, Current->Data);
	}


	//거꾸로 출력
	DLL_PrintReverse(List);

	//노드 제거
	printf("\n====Destroy All of List====\n\n\n");

	count = DLL_GetNodeCount(List);

	for (int i = 0; i < count; i++) {
		Current = DLL_GetNodeAt(List, 0);

		if (Current != NULL) {
			DLL_RemoveNode(&List, Current);
			DLL_DestroyNode(Current);
		}
	}
}