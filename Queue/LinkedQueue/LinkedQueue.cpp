#include "LinkedQueue.h"

//Queue 생성
void LQ_CreateQueue(LinkedQueue ** Queue)
{
	(*Queue) = (LinkedQueue*)malloc(sizeof(LinkedQueue));
	(*Queue)->Front = NULL;
	(*Queue)->Rear = NULL;
	(*Queue)->Count = 0;
}

//Node 생성
Node * LQ_CreateNode(char * NewData)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));
	NewNode->Data = (char*)malloc(strlen(NewData) + 3);

	strcpy(NewNode->Data, NewData);

	NewNode->NextNode = NULL;

	return NewNode;
}

//Node 소멸
void LQ_NodeDestroy(Node * Node)
{
	free(Node->Data);
	free(Node);
}

void LQ_QueueDestroy(LinkedQueue * Queue)
{

	while (!LQ_isEmpty(Queue)) {
		Node* Popped = LQ_Dequeue(Queue);
		free(Popped);
	}

	free(Queue);

}

//Node Enqueue
void LQ_Enqueue(LinkedQueue * Queue, Node * NewNode)
{
	//Queue가 비어있을때
	if (Queue->Front == NULL) {
		Queue->Front = NewNode;
		Queue->Rear = NewNode;
		Queue->Count++;
	}
	else {
		Queue->Rear->NextNode = NewNode;
		Queue->Rear = NewNode;
		Queue->Count++;
	}
}
//Node Dequeue
Node * LQ_Dequeue(LinkedQueue * Queue)
{

	//최상위 노드
	Node* Front = Queue->Front;

	//Queue에 Node가 하나일때
	if (Front->NextNode == NULL) {
		Queue->Front = NULL;
		Queue->Rear = NULL;
	}
	else {
		Queue->Front = Queue->Front->NextNode;
	}

	Queue->Count--;

	return Front;
}

bool LQ_isEmpty(LinkedQueue * Queue)
{
	if (Queue->Front == NULL)
		return true;
	else
		return false;

}


