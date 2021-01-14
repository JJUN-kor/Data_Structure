#ifndef CIRCULARQUEUE_H
#define CIRCULARQUEUE_H

#include <stdio.h>
#include <stdlib.h>


typedef int ElemetType;

//���
typedef struct m_Node {
	ElemetType Data;
}Node;


typedef struct m_Queue {
	int capacity; //�뷮
	int Front; // ���� (�迭���� index)
	int Rear; //�Ĵ� (�迭���� index)
	Node* Nodes; //���迭
}CircluarQueue;
#endif // !CIRCULARQUEUE_H


void CQ_CreateQueue(CircluarQueue ** Queue, int Capacity);
void CQ_DestroyQueue(CircluarQueue * Queue);
void CQ_Enqueue(CircluarQueue* Queue, ElemetType Data);
ElemetType CQ_Dequeue(CircluarQueue* Queue);
int CQ_IsEmpty(CircluarQueue* Queue);
int CQ_IsFull(CircluarQueue* Queue);