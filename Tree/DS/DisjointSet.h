#ifndef DISJOINTSET_H
#define DISJOINTSET_H

#include <stdio.h>
#include <stdlib.h>

typedef struct m_Set {
	struct m_Set* Parent;
	void* Data; //어떤 자료형이든 저장을 위해 void 선언
}DisjointSet;

//합집합
void DS_UnionSet(DisjointSet* Set1, DisjointSet* Set2);
//집합 찾기
DisjointSet* DS_FindSet(DisjointSet* Set);
//집합 생성
DisjointSet* DS_MakeSet(void* NewData);
//집합 소멸
void DS_DestroySet(DisjointSet* Set);

#endif