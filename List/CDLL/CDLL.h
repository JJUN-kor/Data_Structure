#ifndef CDLL_H
#define CDLL_H

#include <stdio.h>
#include <stdlib.h>


typedef int ElementType;

typedef struct m_Node {
	ElementType Data;
	struct m_Node* PrevNode; //이전 노드 포인터
	struct m_Node* NextNode; //다음 노드 포인터
}Node;


//노드 생성
Node* CDLL_CreateNode(ElementType NewData);
//노드 소멸
void CDLL_DestroyNode(Node* Node);
//노드 추가
void CDLL_AppendNode(Node** Head, Node* NewNode);
//노드 삽입
void CDLL_InsertAfter(Node* Current, Node* NewNode);
//노드 삭제
void CDLL_RemoveNode(Node** Head, Node* Remove);
//노드 얻기
Node* CDLL_GetNodeAt(Node* Head, int Location);
//노드 카운팅
int CDLL_GetNodeCount(Node* Head);


#endif // !CLL
