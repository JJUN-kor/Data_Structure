#include "LinkedQueue.h"

int main() {

	Node* Popped;
	LinkedQueue* Queue;

	LQ_CreateQueue(&Queue);

	LQ_Enqueue(Queue, LQ_CreateNode("가나다"));
	LQ_Enqueue(Queue, LQ_CreateNode("라마바"));
	LQ_Enqueue(Queue, LQ_CreateNode("사자차"));
	LQ_Enqueue(Queue, LQ_CreateNode("카타파"));

	printf("Queue Size:%d \n", Queue->Count);

	while (!LQ_isEmpty(Queue)) {
		Popped = LQ_Dequeue(Queue);

		printf("Dequeue: %s \n", Popped->Data);

		LQ_NodeDestroy(Popped);
	}

	LQ_QueueDestroy(Queue);



	return 0;
}