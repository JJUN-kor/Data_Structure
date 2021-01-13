#include "LLS_Stack.h"

int LLS_Stack_main() {

	int count = 0;
	Node* Popped;

	LinkedListStack* Stack;

	LLS_CreateStack(&Stack); //스택 생성

	LLS_Push(Stack, LLS_CreateNode("abc"));
	LLS_Push(Stack, LLS_CreateNode("def"));
	LLS_Push(Stack, LLS_CreateNode("ghi"));
	LLS_Push(Stack, LLS_CreateNode("jkl"));


	printf("Size: %d, Top:%s\n\n", LLS_GetSize(Stack), LLS_Top(Stack)->Data);


	LLS_Pop(Stack);

	printf("Size: %d, Top:%s\n\n", LLS_GetSize(Stack), LLS_Top(Stack)->Data);
}