#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H
#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct m_Node {
	char* Data;
	struct m_Node* NextNode;
}Node;

typedef struct m_LinkedQueue {
	Node* Front;
	Node* Rear;
	int Count;
}LinkedQueue;

void LQ_CreateQueue(LinkedQueue** Queue);
Node* LQ_CreateNode(char* NewData);
void LQ_NodeDestroy(Node* Node);
void LQ_QueueDestroy(LinkedQueue* Queue);
void LQ_Enqueue(LinkedQueue * Queue, Node* NewNode);
Node* LQ_Dequeue(LinkedQueue* Queue);
bool LQ_isEmpty(LinkedQueue* Queue);

#endif // !LINKEDQUEUE_H

