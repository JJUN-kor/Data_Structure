#include <stdio.h>
#include <stdlib.h>

#include "CDLL.h"

//노드 생성
Node* CDLL_CreateNode(ElementType NewData) {
	Node* NewNode = (Node*)malloc(sizeof(Node));

	NewNode->Data = NewData;
	NewNode->NextNode = NULL;
	NewNode->PrevNode = NULL;

	return NewNode;
}

//노드 소멸
void CDLL_DestroyNode(Node* Node) {
	free(Node);
}
//노드 추가
void CDLL_AppendNode(Node** Head, Node* NewNode) {
	//Head가 NULL일때
	if ((*Head) == NULL) {
		*Head = NewNode;

		(*Head)->NextNode = *Head;
		(*Head)->PrevNode = *Head;

	}
	else {
		Node* Tail = (*Head)->PrevNode; 

		Tail->NextNode->PrevNode = NewNode;
		Tail->NextNode = NewNode;

		NewNode->NextNode = (*Head);
		NewNode->PrevNode = Tail;
		
	}
}
//노드 삽입
void CDLL_InsertAfter(Node* Current, Node* NewNode) {
	NewNode->NextNode = Current->NextNode;
	NewNode->PrevNode = Current;

	Current->NextNode->PrevNode = NewNode;
	Current->NextNode = NewNode;
}
//노드 삭제
void CDLL_RemoveNode(Node** Head, Node* Remove) {
	//헤드를 삭제 할 경우
	if (Remove == *Head) {
		//DLL과의 차이점
		(*Head)->NextNode->PrevNode = Remove->PrevNode;
		(*Head)->PrevNode->NextNode = Remove->NextNode;

		*Head = Remove->NextNode;

		Remove->NextNode = NULL;
		Remove->PrevNode = NULL;
	}

	else {
		Node * Temp = Remove;

		Temp->NextNode->PrevNode = Remove->PrevNode;
		Temp->PrevNode->NextNode = Remove->NextNode;

		Remove->PrevNode = NULL;
		Remove->NextNode = NULL;
	}
}
//노드 얻기
Node* CDLL_GetNodeAt(Node* Head, int Location) {
	Node *Current = Head;

	while (Current != NULL && --Location >= 0) {
		Current = Current->NextNode;
	}
}
//노드 카운팅
int CDLL_GetNodeCount(Node* Head) {
	int count = 0;
	Node* Current = Head;

	while (Current != NULL) {
		Current = Current->NextNode;
		count++;

		//하나일 경우
		if (Current == Head)
			break;
	}

	return count;
}
