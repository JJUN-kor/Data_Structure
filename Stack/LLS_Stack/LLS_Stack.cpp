#include "LLS_Stack.h"


//스택 생성
void LLS_CreateStack(LinkedListStack** Stack) {
	(*Stack) = (LinkedListStack*)malloc(sizeof(LinkedListStack)); //스택 동적 할당

	(*Stack)->List = NULL;
	(*Stack)->Top = NULL;

}
//스택 소멸
void LLS_DestroyStack(LinkedListStack* Stack) {

	//노드 소멸 
	while (LLS_isEmpty(Stack)) {
		Node* Node = LLS_Pop(Stack); //노드를 계속 Pop -> 소멸 
		LLS_DestroyNode(Node); 
	}

	//스택 소멸
	free(Stack);
}

//노드 생성
Node* LLS_CreateNode(char* NewData) {

	Node* NewNode = (Node*)malloc(sizeof(Node)); //노드 동적 할당

	NewNode->Data = (char*)malloc(sizeof(strlen(NewData) + 1)); //받은 문자열 +1 크기만큼 동적 할당

	strcpy(NewNode->Data, NewData); // 문자열 복사 저장

	NewNode->NextNode = NULL;

	return NewNode;

	
}
//노드 소멸
void LLS_DestroyNode(Node* Node) {
	free(Node->Data);
	free(Node);
}

//노드 Push
void LLS_Push(LinkedListStack* Stack, Node* NewNode) {

	//Stack이 NULL일때
	if (Stack-> List == NULL)
		Stack->List = NewNode;

	else 
	{
		//최상위 노드 즉 Top을 찾아간다.
		Node* TopNode = Stack->List;

		while (TopNode->NextNode != NULL)
			TopNode = TopNode->NextNode;

		TopNode->NextNode = NewNode;
	}
	//노드 Top 주소를 등록
	Stack->Top = NewNode;
}

//노드 Pop
Node* LLS_Pop(LinkedListStack* Stack) {
	Node* TopNode = Stack->Top;

	//노드가 하나만 존재할때
	if (Stack->List == Stack->Top) {
		Stack->List = NULL;
		Stack->Top = NULL;
	}

	else
	{
		//Pop될 노드 이전까지 찾아간다.
		Node *CurrentTop = Stack->List;
		while (CurrentTop != NULL && CurrentTop->NextNode != Stack->Top)
			CurrentTop = CurrentTop->NextNode;

		Stack->Top = CurrentTop;
		CurrentTop->NextNode = NULL;

	}

	return TopNode;
}

Node* LLS_Top(LinkedListStack* Stack) {
	return Stack->Top;
}

int LLS_GetSize(LinkedListStack* Stack) {
	int size = 0;

	Node* Node = Stack->List;

	//카운팅
	while (Node!=NULL) {
		Node = Node->NextNode;
		size++;
	}

	return size;
}

bool LLS_isEmpty(LinkedListStack * Stack)
{
	if (Stack->List == NULL)
		return true;
	else
		return false;
}
