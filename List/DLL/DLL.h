#ifndef DLL_H
#define DLL_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct m_Node {
	ElementType Data;
	struct m_Node* PrevNode; //���� ��� ������
	struct m_Node* NextNode; //���� ��� ������
}Node;

//��� ����
Node* DLL_CreateNode(ElementType NewData);
//��� �Ҹ�
void DLL_DestroyNode(Node* Node);
//��� �߰�
void DLL_AppendNode(Node** Head, Node* NewNode);
//��� ����
void DLL_InsertAfter(Node* Current, Node* NewNode);
//��� ����
void DLL_RemoveNode(Node** Head, Node* Remove);
//��� ���
Node* DLL_GetNodeAt(Node* Head, int Location);
//��� ī����
int DLL_GetNodeCount(Node* Head);
//���� ���
void DLL_PrintReverse(Node* Head);


#endif