#include "CircularQueue.h"

void CQ_CreateQueue(CircluarQueue ** Queue, int Capacity)
{
	//Queue ����
	(*Queue) = (CircluarQueue*)malloc(sizeof(CircluarQueue));

	//��� ���� (DummyQueue ����)
	(*Queue)->Nodes = (Node*)malloc(sizeof(Node)*(Capacity + 1)); 

	(*Queue)->capacity = Capacity;
	(*Queue)->Front = 0;
	(*Queue)->Rear = 0;
}

//Queue �Ҹ�
void CQ_DestroyQueue(CircluarQueue * Queue)
{
	free(Queue->Nodes);
	free(Queue);
}

//Enqueue
void CQ_Enqueue(CircluarQueue * Queue, ElemetType Data)
{
	int Position = 0;

	//�Ĵ��� �迭�� ���� �����ߴٸ�
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

	//������ �迭�� ���� ���� �Ͽ�����
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
	//������ �Ĵܺ��� �տ� ������
	if (Queue->Front < Queue->Rear)
		return (Queue->Rear - Queue->Front) == Queue->capacity;
	//������ �Ĵܺ��� �ڿ� ������
	else
		return (Queue->Rear + 1) == Queue->Front;
}




