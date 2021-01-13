#include "ArrayStack.h"

//스택 생성
void AS_CreateStack(ArrayStack** Stack, int Capacity) {
	*Stack = (ArrayStack*)malloc(sizeof(ArrayStack)); //스택 동적 생성
	
	(*Stack)->Nodes = (Node*)malloc(sizeof(Node)*Capacity); // 노드 배열 생성

	(*Stack)->Capacity = Capacity;
	(*Stack)->Top = 0;

}
//스택 소멸
void AS_DestroyStack(ArrayStack* Stack) {
	free(Stack->Nodes);

	free(Stack);
}
//스택 삽입
void AS_Push(ArrayStack* Stack, ElementType Data) {
	int Position = Stack->Top; //Top 

	Stack->Nodes[Position].Data = Data; //최상위 노드에 Data넣기
	Stack->Top++; // Top + 1
}
//스택 팝
ElementType AS_Pop(ArrayStack* Stack) {
	//int Position = --(Stack->Top);
	
	Stack->Top -= 1;
	int Position = Stack->Top;
	
	return Stack->Nodes[Position].Data;
}
//최상위 노드
ElementType AS_Top(ArrayStack* Stack) {
	int Position = Stack->Top - 1;

	return Stack->Nodes[Position].Data;

}
//Size 구하기
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
