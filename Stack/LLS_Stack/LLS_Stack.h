#ifndef LLS_Stack_H
#define LLS_Stack_H
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//노드 생성
typedef struct m_Node {
	char* Data; //문자열
	struct m_Node* NextNode;

}Node;

//LL 스택 생성
typedef struct m_Stack {
	Node* List;
	Node* Top;

}LinkedListStack;


//스택 생성
void LLS_CreateStack(LinkedListStack** Stack);
//스택 소멸
void LLS_DestroyStack(LinkedListStack* Stack);
//노드 생성
Node* LLS_CreateNode(char* NewData);
//노드 소멸
void LLS_DestroyNode(Node* Node);
//노드 Push
void LLS_Push(LinkedListStack* Stack, Node* NewNode);
//노드 Pop
Node* LLS_Pop(LinkedListStack* Stack);
//Top 노드
Node* LLS_Top(LinkedListStack* Stack);
//GetSize
int LLS_GetSize(LinkedListStack* Stack);
//isEmpty
bool LLS_isEmpty(LinkedListStack* Stack);
#endif