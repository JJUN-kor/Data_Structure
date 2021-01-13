#include <stdio.h>
#include <stdlib.h>
#include "SLL.h"

//노드생성
Node* SLL_CreateNode(ElementType NewData) {
	Node* NewNode = (Node*)malloc(sizeof(Node)); //동적 할당

	NewNode->Data = NewData; // 데이터
	NewNode->NextNode = NULL; // 다음 노드 포인터
	
	return NewNode;
}
//노드 소멸
void SLL_DestroyNode(Node* Node) {
	free(Node);
}

//노드 추가
void SLL_AppendNode(Node** Head, Node* NewNode) {
	//Head가 NULL이면 NewNode가 Head
	if ((*Head) == NULL)
		*Head = NewNode;
	else
	{
		Node* Tail = (*Head);
		//Tail 노드를 찾아감
		while (Tail->NextNode != NULL)
			Tail = Tail->NextNode;

		Tail->NextNode = NewNode;
	}
}
//노드 삽입
void SLL_InsertAfter(Node* Current, Node* NewNode) {
	NewNode->NextNode = Current->NextNode; //새 노드의 다음 노드는 현재 노드의 다음 노드
	Current->NextNode = NewNode; //새 노드의 다음 노드는 현재 노드
}

//노드 이전 삽입
void SLL_InsertBefore(Node** Head, Node* Current, Node* NewHead) {
	//Head가 NULL이면 NewHead가 Head
	if ((*Head) == NULL)
		*Head = NewHead;
	
	//Head만 존재 할시에
	if ((*Head) != NULL && (*Head)->NextNode == NULL) {
		(*Head) = NewHead;
		NewHead->NextNode = (*Head);

	}
	else {
		Node *Before = *Head;
		
		//Current의 이전의 노드로 이동
		while (Before != NULL && Before->NextNode != Current) {
			Before = Before->NextNode;
		}

		Before->NextNode = NewHead;
		NewHead->NextNode = Current;
	}


}

//헤드 추가
void SLL_InsertNewHead(Node** Head, Node* NewHead) {
	if (*Head == NULL)
	{
		(*Head) = NewHead;
	}
	
	else 
	{
		NewHead->NextNode = (*Head);
		(*Head) = NewHead;
	}
}
//노드 제거
void SLL_RemoveNode(Node** Head, Node* Remove) {
	if (*Head == Remove) {
		*Head = Remove->NextNode;
	}
	else {
		Node* Current = *Head;
		//삭제할 이전의 노드를 찾음
		while (Current != NULL && Current->NextNode != Remove)
			Current = Current->NextNode;
		
		//삭제할 이전의 노드의 다음 노드를 삭제할 다음의 노드를 가르킴
		if (Current != NULL)
			Current->NextNode = Remove->NextNode;
	}
	

}
//노드 얻기
Node* SLL_GetNodeAt(Node* Head, int Location) {
	Node* Current = Head;

	while (Current != NULL && (--Location) >= 0) {
		Current = Current->NextNode;
	}
	return Current;
}
//노드 카운팅
int SLL_GetNodeCount(Node* Head) {
	int count = 0;
	Node* Current = Head;

	while (Current != NULL) {
		Current = Current->NextNode;
		count++;
	}

	return count;
}
