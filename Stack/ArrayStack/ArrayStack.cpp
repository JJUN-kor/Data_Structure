#include "ArrayStack.h"

//���� ����
void AS_CreateStack(ArrayStack** Stack, int Capacity) {
	*Stack = (ArrayStack*)malloc(sizeof(ArrayStack)); //���� ���� ����
	
	(*Stack)->Nodes = (Node*)malloc(sizeof(Node)*Capacity); // ��� �迭 ����

	(*Stack)->Capacity = Capacity;
	(*Stack)->Top = 0;

}
//���� �Ҹ�
void AS_DestroyStack(ArrayStack* Stack) {
	free(Stack->Nodes);

	free(Stack);
}
//���� ����
void AS_Push(ArrayStack* Stack, ElementType Data) {
	int Position = Stack->Top; //Top 

	Stack->Nodes[Position].Data = Data; //�ֻ��� ��忡 Data�ֱ�
	Stack->Top++; // Top + 1
}
//���� ��
ElementType AS_Pop(ArrayStack* Stack) {
	//int Position = --(Stack->Top);
	
	Stack->Top -= 1;
	int Position = Stack->Top;
	
	return Stack->Nodes[Position].Data;
}
//�ֻ��� ���
ElementType AS_Top(ArrayStack* Stack) {
	int Position = Stack->Top - 1;

	return Stack->Nodes[Position].Data;

}
//Size ���ϱ�
int AS_GetSize(ArrayStack* Stack) {
	return Stack->Top;
}
//Empty
bool AS_IsEmpty(ArrayStack* Stack) {
	if (Stack->Top - 1 < 0) {
		return true;
	}
	else
		return false;
}
