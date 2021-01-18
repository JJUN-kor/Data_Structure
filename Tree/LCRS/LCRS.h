#ifndef LSCRS_H
#define LSCRS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char ElementType;

typedef struct m_Node {
	struct m_Node* LeftChild; // 좌측 자식
	struct m_Node* RightSibling; // 우측 형제

	ElementType Data;

}LCRSNode;

//노드 생성
LCRSNode* LCRS_CreateNode(ElementType NewData);
//노드 소멸
void LCRS_DestroyNode(LCRSNode* Node);
//트리 소멸
void LCRS_DestroyTree(LCRSNode* Root);

//노드 연결
void LCRS_AddChildNode(LCRSNode* Parent, LCRSNode * Child);
//트리 출력
void LCRS_PrintTree(LCRSNode* Node, int Depth);
//일정 Level 노드 출력
void LCRS_PrintNodeAtLevel(LCRSNode* Root, int Level);



#endif
