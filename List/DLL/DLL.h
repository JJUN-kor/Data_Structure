#ifndef DLL_H
#define DLL_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct m_Node {
	ElementType Data;
	struct m_Node* PrevNode; //이전 노드 포인터
	struct m_Node* NextNode; //다음 노드 포인터
}Node;

//노드 생성
Node* DLL_CreateNode(ElementType NewData);
//노드 소멸
void DLL_DestroyNode(Node* Node);
//노드 추가
void DLL_AppendNode(Node** Head, Node* NewNode);
//노드 삽입
void DLL_InsertAfter(Node* Current, Node* NewNode);
//노드 삭제
void DLL_RemoveNode(Node** Head, Node* Remove);
//노드 얻기
Node* DLL_GetNodeAt(Node* Head, int Location);
//노드 카운팅
int DLL_GetNodeCount(Node* Head);
//역순 출력
void DLL_PrintReverse(Node* Head);


#endif