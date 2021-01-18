#ifndef LSCRS_H
#define LSCRS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char ElementType;

typedef struct m_Node {
	struct m_Node* LeftChild; // ���� �ڽ�
	struct m_Node* RightSibling; // ���� ����

	ElementType Data;

}LCRSNode;

//��� ����
LCRSNode* LCRS_CreateNode(ElementType NewData);
//��� �Ҹ�
void LCRS_DestroyNode(LCRSNode* Node);
//Ʈ�� �Ҹ�
void LCRS_DestroyTree(LCRSNode* Root);

//��� ����
void LCRS_AddChildNode(LCRSNode* Parent, LCRSNode * Child);
//Ʈ�� ���
void LCRS_PrintTree(LCRSNode* Node, int Depth);
//���� Level ��� ���
void LCRS_PrintNodeAtLevel(LCRSNode* Root, int Level);



#endif
