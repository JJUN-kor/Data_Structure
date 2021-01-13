#include <stdio.h>
#include <stdlib.h>
#include "SLL.h"


int SLL_main() {

	int i = 0;
	int count = 0;
	Node *List = NULL;
	Node *Current = NULL;
	Node *NewNode = NULL;

	for (int i = 0; i < 5; i++) {
		NewNode = SLL_CreateNode(i);
		SLL_AppendNode(&List, NewNode);
	}
	NewNode = SLL_CreateNode(-1);
	SLL_InsertNewHead(&List, NewNode);
	
	NewNode = SLL_CreateNode(-2);
	SLL_InsertNewHead(&List, NewNode);

	//출력
	count = SLL_GetNodeCount(List);
	
	//printf("%d", count);
	
	for (i = 0; i < count; i++) {
		Current = SLL_GetNodeAt(List, i);
		printf("List[%d] : %d\n", i, Current->Data);
	}

	//리스트의 5번째 노드 뒤에 노드 삽입
	printf("\n====Insert 100 After [5]====\n\n\n");
	Current = SLL_GetNodeAt(List, 5);
	NewNode = SLL_CreateNode(100);
	
	SLL_InsertAfter(Current, NewNode);

	for (i = 0; i < count; i++) {
		Current = SLL_GetNodeAt(List, i);
		printf("List[%d] : %d\n", i, Current->Data);
	}
	

	//리스트의 3번째 노드 앞에 노드 삽입
	printf("\n====Insert 1000 Before [3]====\n\n\n");
	Current = SLL_GetNodeAt(List, 3);
	NewNode = SLL_CreateNode(1000);

	SLL_InsertBefore(&List, Current, NewNode);

	count = SLL_GetNodeCount(List);

	for (i = 0; i < count; i++) {
		Current = SLL_GetNodeAt(List, i);
		printf("List[%d] : %d\n", i, Current->Data);
	}
	
	//리스트의 3번째 노드 삭제
	printf("\n===Remove List [3] Node ====\n\n\n");
	Current = SLL_GetNodeAt(List, 3);
	SLL_RemoveNode(&List, Current);
	SLL_DestroyNode(Current);

	count = SLL_GetNodeCount(List);

	for (i = 0; i < count; i++) {
		Current = SLL_GetNodeAt(List, i);
		printf("List[%d] : %d\n", i, Current->Data);
	}



	printf("\n====Destroy All of List====\n\n\n");
	
	count = SLL_GetNodeCount(List);


	for (i = 0;  i < count; i++) {
		Current = SLL_GetNodeAt(List, 0);

		if (Current != NULL) {
			SLL_RemoveNode(&List, Current);
			SLL_DestroyNode(Current);
		}
	}

	return 0;
}