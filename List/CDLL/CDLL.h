#ifndef CDLL_H
#define CDLL_H

#include <stdio.h>
#include <stdlib.h>


typedef int ElementType;

typedef struct m_Node {
	ElementType Data;
	struct m_Node* PrevNode; //���� ��� ������
	struct m_Node* NextNode; //���� ��� ������
}Node;


//��� ����
Node* CDLL_CreateNode(ElementType NewData);
//��� �Ҹ�
void CDLL_DestroyNode(Node* Node);
//��� �߰�
void CDLL_AppendNode(Node** Head, Node* NewNode);
//��� ����
void CDLL_InsertAfter(Node* Current, Node* NewNode);
//��� ����
void CDLL_RemoveNode(Node** Head, Node* Remove);
//��� ���
Node* CDLL_GetNodeAt(Node* Head, int Location);
//��� ī����
int CDLL_GetNodeCount(Node* Head);


#endif // !CLL
