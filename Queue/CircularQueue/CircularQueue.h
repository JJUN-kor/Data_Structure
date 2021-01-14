#ifndef CIRCULARQUEUE_H
#define CIRCULARQUEUE_H

#include <stdio.h>
#include <stdlib.h>


typedef int ElemetType;

//노드
typedef struct m_Node {
	ElemetType Data;
}Node;


typedef struct m_Queue {
	int capacity; //용량
	int Front; // 전단 (배열내의 index)
	int Rear; //후단 (배열내의 index)
	Node* Nodes; //노드배열
}CircluarQueue;
#endif // !CIRCULARQUEUE_H


void CQ_CreateQueue(CircluarQueue ** Queue, int Capacity);
void CQ_DestroyQueue(CircluarQueue * Queue);
void CQ_Enqueue(CircluarQueue* Queue, ElemetType Data);
ElemetType CQ_Dequeue(CircluarQueue* Queue);
int CQ_IsEmpty(CircluarQueue* Queue);
int CQ_IsFull(CircluarQueue* Queue);