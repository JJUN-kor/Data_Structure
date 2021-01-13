#ifndef LLS_Stack_H
#define LLS_Stack_H
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//��� ����
typedef struct m_Node {
	char* Data; //���ڿ�
	struct m_Node* NextNode;

}Node;

//LL ���� ����
typedef struct m_Stack {
	Node* List;
	Node* Top;

}LinkedListStack;


//���� ����
void LLS_CreateStack(LinkedListStack** Stack);
//���� �Ҹ�
void LLS_DestroyStack(LinkedListStack* Stack);
//��� ����
Node* LLS_CreateNode(char* NewData);
//��� �Ҹ�
void LLS_DestroyNode(Node* Node);
//��� Push
void LLS_Push(LinkedListStack* Stack, Node* NewNode);
//��� Pop
Node* LLS_Pop(LinkedListStack* Stack);
//Top ���
Node* LLS_Top(LinkedListStack* Stack);
//GetSize
int LLS_GetSize(LinkedListStack* Stack);
//isEmpty
bool LLS_isEmpty(LinkedListStack* Stack);
#endif