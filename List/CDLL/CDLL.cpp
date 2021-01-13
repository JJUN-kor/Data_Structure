#include <stdio.h>
#include <stdlib.h>

#include "CDLL.h"

//��� ����
Node* CDLL_CreateNode(ElementType NewData) {
	Node* NewNode = (Node*)malloc(sizeof(Node));

	NewNode->Data = NewData;
	NewNode->NextNode = NULL;
	NewNode->PrevNode = NULL;

	return NewNode;
}

//��� �Ҹ�
void CDLL_DestroyNode(Node* Node) {
	free(Node);
}
//��� �߰�
void CDLL_AppendNode(Node** Head, Node* NewNode) {
	//Head�� NULL�϶�
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
//��� ����
void CDLL_InsertAfter(Node* Current, Node* NewNode) {
	NewNode->NextNode = Current->NextNode;
	NewNode->PrevNode = Current;

	Current->NextNode->PrevNode = NewNode;
	Current->NextNode = NewNode;
}
//��� ����
void CDLL_RemoveNode(Node** Head, Node* Remove) {
	//��带 ���� �� ���
	if (Remove == *Head) {
		//DLL���� ������
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
//��� ���
Node* CDLL_GetNodeAt(Node* Head, int Location) {
	Node *Current = Head;

	while (Current != NULL && --Location >= 0) {
		Current = Current->NextNode;
	}
}
//��� ī����
int CDLL_GetNodeCount(Node* Head) {
	int count = 0;
	Node* Current = Head;

	while (Current != NULL) {
		Current = Current->NextNode;
		count++;

		//�ϳ��� ���
		if (Current == Head)
			break;
	}

	return count;
}
