#ifndef SLL_H
#define SLL_H

#include <stdio.h>
#include <stdlib.h>


typedef int ElementType;

//��� ����ü

typedef struct m_Node {
	ElementType Data;
	struct m_Node* NextNode; //���� ��带 ����Ű�� ������
}Node;

//��� ����
Node* SLL_CreateNode(ElementType NewData);
//��� �Ҹ�
void SLL_DestroyNode(Node* Node);
//��� ��� �Ҹ�
void SLL_DestroyAllNodes(Node** List);
//��� �߰�
void SLL_AppendNode(Node** Head, Node* NewNode);
//��� ����
void SLL_InsertAfter(Node* Current, Node* NewNode);
//��� ���� ����
void SLL_InsertBefore(Node** Head, Node* Current, Node* NewHead);
//��� �߰�
void SLL_InsertNewHead(Node** Head, Node* NewHead);
//��� ����
void SLL_RemoveNode(Node** Head, Node* Remove);
//��� ���
Node* SLL_GetNodeAt(Node* Head, int Location);
//��� ī����
int SLL_GetNodeCount(Node* Head);

#endif // !SLL

