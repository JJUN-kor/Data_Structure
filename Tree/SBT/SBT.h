#ifndef SBT_H
#define SBT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char ElementType;

typedef struct m_Node {
	struct m_Node* Left;
	struct m_Node* Right;

	ElementType Data;
}SBTNode;

//��� ����
SBTNode* SBT_CreateNode(ElementType NewData);
//��� �Ҹ�
void SBT_DestroyNode(SBTNode* Node);
//���� ��ȸ ( Root -> Left Tree -> Right Tree)
void SBT_PreorderPrintTree(SBTNode* Node);
//���� ��ȸ ( Left Tree -> Root -> Right Tree)
void SBT_InorderPrintTree(SBTNode* Node);
//���� ��ȸ ( Left Tree -> Right Tree -> Root)
void SBT_PostorderPrintTree(SBTNode* Node);
//Ʈ�� �Ҹ�
void SBT_DestroyTree(SBTNode* Node);

#endif