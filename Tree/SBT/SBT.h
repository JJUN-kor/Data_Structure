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

//노드 생성
SBTNode* SBT_CreateNode(ElementType NewData);
//노드 소멸
void SBT_DestroyNode(SBTNode* Node);
//전위 순회 ( Root -> Left Tree -> Right Tree)
void SBT_PreorderPrintTree(SBTNode* Node);
//중위 순회 ( Left Tree -> Root -> Right Tree)
void SBT_InorderPrintTree(SBTNode* Node);
//후위 순회 ( Left Tree -> Right Tree -> Root)
void SBT_PostorderPrintTree(SBTNode* Node);
//트리 소멸
void SBT_DestroyTree(SBTNode* Node);

#endif