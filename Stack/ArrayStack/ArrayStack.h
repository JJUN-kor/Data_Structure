#ifndef AS_H
#define AS_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

//데이터를 저장할 노드 구조체
typedef struct m_Node {
	ElementType Data;
}Node;

//배열 스택
typedef struct m_ArrayStack {
	int Capacity;
	int Top;
	Node* Nodes; //노드 배열 포인터 
}ArrayStack;

//스택 생성
void AS_CreateStack(ArrayStack** Stack, int Capacity);
//스택 소멸
void AS_DestroyStack(ArrayStack* Stack);
//스택 삽입
void AS_Push(ArrayStack* Stack, ElementType Data);
//스택 팝
ElementType AS_Pop(ArrayStack* Stack);
//최상위 노드
ElementType AS_Top(ArrayStack* Stack);
//Size 구하기
int AS_GetSize(ArrayStack* Stack);
//Empty
bool AS_IsEmpty(ArrayStack* Stack);

#endif // !AS
