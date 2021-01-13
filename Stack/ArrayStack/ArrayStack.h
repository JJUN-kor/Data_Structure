#ifndef AS_H
#define AS_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

//�����͸� ������ ��� ����ü
typedef struct m_Node {
	ElementType Data;
}Node;

//�迭 ����
typedef struct m_ArrayStack {
	int Capacity;
	int Top;
	Node* Nodes; //��� �迭 ������ 
}ArrayStack;

//���� ����
void AS_CreateStack(ArrayStack** Stack, int Capacity);
//���� �Ҹ�
void AS_DestroyStack(ArrayStack* Stack);
//���� ����
void AS_Push(ArrayStack* Stack, ElementType Data);
//���� ��
ElementType AS_Pop(ArrayStack* Stack);
//�ֻ��� ���
ElementType AS_Top(ArrayStack* Stack);
//Size ���ϱ�
int AS_GetSize(ArrayStack* Stack);
//Empty
bool AS_IsEmpty(ArrayStack* Stack);

#endif // !AS
