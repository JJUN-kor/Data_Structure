#ifndef SLL_H
#define SLL_H

#include <stdio.h>
#include <stdlib.h>


typedef int ElementType;

//노드 구조체

typedef struct m_Node {
	ElementType Data;
	struct m_Node* NextNode; //다음 노드를 가르키는 포인터
}Node;

//노드 생성
Node* SLL_CreateNode(ElementType NewData);
//노드 소멸
void SLL_DestroyNode(Node* Node);
//모든 노드 소멸
void SLL_DestroyAllNodes(Node** List);
//노드 추가
void SLL_AppendNode(Node** Head, Node* NewNode);
//노드 삽입
void SLL_InsertAfter(Node* Current, Node* NewNode);
//노드 이전 삽입
void SLL_InsertBefore(Node** Head, Node* Current, Node* NewHead);
//헤드 추가
void SLL_InsertNewHead(Node** Head, Node* NewHead);
//노드 제거
void SLL_RemoveNode(Node** Head, Node* Remove);
//노드 얻기
Node* SLL_GetNodeAt(Node* Head, int Location);
//노드 카운팅
int SLL_GetNodeCount(Node* Head);

#endif // !SLL

