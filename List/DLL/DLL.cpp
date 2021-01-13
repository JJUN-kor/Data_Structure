#include<stdio.h>
#include<stdlib.h>
#include "DLL.h"

//노드 생성
Node* DLL_CreateNode(ElementType NewData) {
	Node* NewNode = (Node*)malloc(sizeof(Node));
	NewNode->Data = NewData;
	NewNode->PrevNode = NULL;
	NewNode->NextNode = NULL;

	return NewNode;
}

//노드 소멸
void DLL_DestroyNode(Node* Node) {
	free(Node);
}

//노드 추가
void DLL_AppendNode(Node** Head, Node* NewNode) {
	//Head가 존재하지 않을 경우
	if (*Head == NULL) {
		*Head = NewNode;
	}
	else
	{
		//Tail을 찾아 NewNode와 연결
		Node* Tail = *(Head);

		while (Tail->NextNode != NULL) {
			Tail = Tail->NextNode;
		}
		Tail->NextNode = NewNode;
		NewNode->PrevNode = Tail; //새로운 노드가 Tail
	}
}

//노드 삽입
void DLL_InsertAfter(Node* Current, Node* NewNode) {
	NewNode->NextNode = Current->NextNode; //새로운 노드의 다음노드는 현재의 다음노드
	NewNode->PrevNode = Current; //새로운 노드의 이전노드는 현재

	if (Current->NextNode != NULL)
		Current->NextNode->PrevNode = NewNode; //현재 다음의 이전노드는 새로운 노드

	Current->NextNode = NewNode;
}

//노드 삭제
void DLL_RemoveNode(Node** Head, Node* Remove) {
	//Head를 삭제 할 경우
	if (*Head == Remove) {
		*Head = Remove->NextNode;

		if ((*Head) != NULL)
			(*Head)->PrevNode = NULL;

		Remove->NextNode = NULL;
		Remove->PrevNode = NULL;

	}

	else {
		Node* Temp = Remove;

		Remove->PrevNode->NextNode = Temp->NextNode; //삭제할 이전의 다음노드는 삭제할 다음 노드
		if (Remove->NextNode != NULL) {
			Remove->NextNode->PrevNode = Temp->PrevNode; // 삭제할 다음의 이전노드는 삭제할 이전 노드
		
			Remove->PrevNode = NULL;
			Remove->NextNode = NULL;

		}
	}
}
//노드 얻기
Node* DLL_GetNodeAt(Node* Head, int Location) {
	Node *Current = Head;

	while (Current != NULL && (--Location) >= 0) {
		Current = Current->NextNode;
	}

	return Current;
}

//노드 역순 출력
void DLL_PrintReverse(Node* Head) {
	Node *Tail = Head;
	int count = 0;
	
	//노드가 헤드 하나 뿐인 경우
	if (Tail->NextNode == NULL) {
		printf("\n====Print Node Reverse====\n\n\n");
		printf("List[0] :%d\n", Tail->Data);
	}
	//Tail to Head 역순
	while (Tail->NextNode != NULL) {
		count++;
		Tail = Tail->NextNode;
	}


	printf("\n====Print Node Reverse====\n\n\n");
	if (Tail->NextNode == NULL) {
		while (Tail != NULL) {
			printf("List[%d] :%d\n", count, Tail->Data);
			Tail = Tail->PrevNode;
			count--;
		}
	}
	

}
//노드 카운팅
int DLL_GetNodeCount(Node* Head) {
	int count = 0;
	Node* Current = Head;
	
	while (Current != NULL) {
		Current = Current->NextNode;
		count++;
	}
	return count;

}