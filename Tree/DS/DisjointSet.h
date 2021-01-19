#ifndef DISJOINTSET_H
#define DISJOINTSET_H

#include <stdio.h>
#include <stdlib.h>

typedef struct m_Set {
	struct m_Set* Parent;
	void* Data; //� �ڷ����̵� ������ ���� void ����
}DisjointSet;

//������
void DS_UnionSet(DisjointSet* Set1, DisjointSet* Set2);
//���� ã��
DisjointSet* DS_FindSet(DisjointSet* Set);
//���� ����
DisjointSet* DS_MakeSet(void* NewData);
//���� �Ҹ�
void DS_DestroySet(DisjointSet* Set);

#endif