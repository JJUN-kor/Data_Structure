#include<stdio.h>
#include<stdlib.h>
#include "DLL.h"

//��� ����
Node* DLL_CreateNode(ElementType NewData) {
	Node* NewNode = (Node*)malloc(sizeof(Node));
	NewNode->Data = NewData;
	NewNode->PrevNode = NULL;
	NewNode->NextNode = NULL;

	return NewNode;
}

//��� �Ҹ�
void DLL_DestroyNode(Node* Node) {
	free(Node);
}

//��� �߰�
void DLL_AppendNode(Node** Head, Node* NewNode) {
	//Head�� �������� ���� ���
	if (*Head == NULL) {
		*Head = NewNode;
	}
	else
	{
		//Tail�� ã�� NewNode�� ����
		Node* Tail = *(Head);

		while (Tail->NextNode != NULL) {
			Tail = Tail->NextNode;
		}
		Tail->NextNode = NewNode;
		NewNode->PrevNode = Tail; //���ο� ��尡 Tail
	}
}

//��� ����
void DLL_InsertAfter(Node* Current, Node* NewNode) {
	NewNode->NextNode = Current->NextNode; //���ο� ����� �������� ������ �������
	NewNode->PrevNode = Current; //���ο� ����� �������� ����

	if (Current->NextNode != NULL)
		Current->NextNode->PrevNode = NewNode; //���� ������ �������� ���ο� ���

	Current->NextNode = NewNode;
}

//��� ����
void DLL_RemoveNode(Node** Head, Node* Remove) {
	//Head�� ���� �� ���
	if (*Head == Remove) {
		*Head = Remove->NextNode;

		if ((*Head) != NULL)
			(*Head)->PrevNode = NULL;

		Remove->NextNode = NULL;
		Remove->PrevNode = NULL;

	}

	else {
		Node* Temp = Remove;

		Remove->PrevNode->NextNode = Temp->NextNode; //������ ������ �������� ������ ���� ���
		if (Remove->NextNode != NULL) {
			Remove->NextNode->PrevNode = Temp->PrevNode; // ������ ������ �������� ������ ���� ���
		
			Remove->PrevNode = NULL;
			Remove->NextNode = NULL;

		}
	}
}
//��� ���
Node* DLL_GetNodeAt(Node* Head, int Location) {
	Node *Current = Head;

	while (Current != NULL && (--Location) >= 0) {
		Current = Current->NextNode;
	}

	return Current;
}

//��� ���� ���
void DLL_PrintReverse(Node* Head) {
	Node *Tail = Head;
	int count = 0;
	
	//��尡 ��� �ϳ� ���� ���
	if (Tail->NextNode == NULL) {
		printf("\n====Print Node Reverse====\n\n\n");
		printf("List[0] :%d\n", Tail->Data);
	}
	//Tail to Head ����
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
//��� ī����
int DLL_GetNodeCount(Node* Head) {
	int count = 0;
	Node* Current = Head;
	
	while (Current != NULL) {
		Current = Current->NextNode;
		count++;
	}
	return count;

}