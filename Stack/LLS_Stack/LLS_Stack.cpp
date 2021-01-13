#include "LLS_Stack.h"


//���� ����
void LLS_CreateStack(LinkedListStack** Stack) {
	(*Stack) = (LinkedListStack*)malloc(sizeof(LinkedListStack)); //���� ���� �Ҵ�

	(*Stack)->List = NULL;
	(*Stack)->Top = NULL;

}
//���� �Ҹ�
void LLS_DestroyStack(LinkedListStack* Stack) {

	//��� �Ҹ� 
	while (LLS_isEmpty(Stack)) {
		Node* Node = LLS_Pop(Stack); //��带 ��� Pop -> �Ҹ� 
		LLS_DestroyNode(Node); 
	}

	//���� �Ҹ�
	free(Stack);
}

//��� ����
Node* LLS_CreateNode(char* NewData) {

	Node* NewNode = (Node*)malloc(sizeof(Node)); //��� ���� �Ҵ�

	NewNode->Data = (char*)malloc(sizeof(strlen(NewData) + 1)); //���� ���ڿ� +1 ũ�⸸ŭ ���� �Ҵ�

	strcpy(NewNode->Data, NewData); // ���ڿ� ���� ����

	NewNode->NextNode = NULL;

	return NewNode;

	
}
//��� �Ҹ�
void LLS_DestroyNode(Node* Node) {
	free(Node->Data);
	free(Node);
}

//��� Push
void LLS_Push(LinkedListStack* Stack, Node* NewNode) {

	//Stack�� NULL�϶�
	if (Stack-> List == NULL)
		Stack->List = NewNode;

	else 
	{
		//�ֻ��� ��� �� Top�� ã�ư���.
		Node* TopNode = Stack->List;

		while (TopNode->NextNode != NULL)
			TopNode = TopNode->NextNode;

		TopNode->NextNode = NewNode;
	}
	//��� Top �ּҸ� ���
	Stack->Top = NewNode;
}

//��� Pop
Node* LLS_Pop(LinkedListStack* Stack) {
	Node* TopNode = Stack->Top;

	//��尡 �ϳ��� �����Ҷ�
	if (Stack->List == Stack->Top) {
		Stack->List = NULL;
		Stack->Top = NULL;
	}

	else
	{
		//Pop�� ��� �������� ã�ư���.
		Node *CurrentTop = Stack->List;
		while (CurrentTop != NULL && CurrentTop->NextNode != Stack->Top)
			CurrentTop = CurrentTop->NextNode;

		Stack->Top = CurrentTop;
		CurrentTop->NextNode = NULL;

	}

	return TopNode;
}

Node* LLS_Top(LinkedListStack* Stack) {
	return Stack->Top;
}

int LLS_GetSize(LinkedListStack* Stack) {
	int size = 0;

	Node* Node = Stack->List;

	//ī����
	while (Node!=NULL) {
		Node = Node->NextNode;
		size++;
	}

	return size;
}

bool LLS_isEmpty(LinkedListStack * Stack)
{
	if (Stack->List == NULL)
		return true;
	else
		return false;
}
