#include "CircularQueue.h"

void CQ_CreateQueue(CircluarQueue ** Queue, int Capacity)
{
	//Queue 생성
	(*Queue) = (CircluarQueue*)malloc(sizeof(CircluarQueue));

	//노드 생성 (DummyQueue 포함)
	(*Queue)->Nodes = (Node*)malloc(sizeof(Node)*(Capacity + 1)); 

	(*Queue)->capacity = Capacity;
	(*Queue)->Front = 0;
	(*Queue)->Rear = 0;
}

//Queue 소멸
void CQ_DestroyQueue(CircluarQueue * Queue)
{
	free(Queue->Nodes);
	free(Queue);
}

//Enqueue
void CQ_Enqueue(CircluarQueue * Queue, ElemetType Data)
{
	int Position = 0;

	//후단이 배열의 끝에 도달했다면
	//Rear = 0
	if (Queue->Rear == Queue->capacity) {
		Position = Queue->Rear;
		Queue->Rear = 0;
	}
	else
		Position = Queue->Rear++;
	Queue->Nodes[Position].Data = Data;
}

ElemetType CQ_Dequeue(CircluarQueue * Queue)
{
	int Position = Queue->Front;

	//전단이 배열의 끝에 도달 하였을때
	if (Queue->Front == Queue->capacity)
		Queue->Front = 0;
	else
		Queue->Front++;

	return Queue->Nodes[Position].Data;
}

int CQ_IsEmpty(CircluarQueue * Queue)
{
	return (Queue->Front == Queue->Rear);
}

int CQ_IsFull(CircluarQueue* Queue) {
	//전단이 후단보다 앞에 있을때
	if (Queue->Front < Queue->Rear)
		return (Queue->Rear - Queue->Front) == Queue->capacity;
	//전단이 후단보다 뒤에 있을때
	else
		return (Queue->Rear + 1) == Queue->Front;
}




