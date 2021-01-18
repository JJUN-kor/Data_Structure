#include "LCRS.h"

LCRSNode * LCRS_CreateNode(ElementType NewData)
{
	LCRSNode* NewNode = (LCRSNode*)malloc(sizeof(LCRSNode));
	NewNode->LeftChild = NULL;
	NewNode->RightSibling = NULL;
	NewNode->Data = NewData;
	return NewNode;
}

void LCRS_DestroyNode(LCRSNode * Node)
{
	free(Node);
}

void LCRS_DestroyTree(LCRSNode * Root)
{
	if (Root->RightSibling != NULL) {
		LCRS_DestroyTree(Root->RightSibling);
	}
	if (Root->LeftChild != NULL) {
		LCRS_DestroyNode(Root->LeftChild);
	}

	Root->LeftChild = NULL;
	Root->RightSibling = NULL;

	LCRS_DestroyNode(Root);
}

void LCRS_AddChildNode(LCRSNode * Parent, LCRSNode * Child)
{
	//자식 노드가 없을때
	//Root 노드만 존재할때
	if (Parent->LeftChild == NULL) {
		Parent->LeftChild = Child;
	}

	else{
		LCRSNode* TempNode = Parent->LeftChild;
		//형제 노드로 이동
		while (TempNode->RightSibling != NULL) {
			TempNode = TempNode->RightSibling;
		}

		TempNode->RightSibling = Child;

	}

}

void LCRS_PrintTree(LCRSNode * Node, int Depth)
{
	int i = 0;

	for (i = 0; i < Depth; i++)
		printf(" ");

	printf("%c\n", Node->Data);

	if (Node->LeftChild != NULL)
		LCRS_PrintTree(Node->LeftChild, Depth + 1);

	if (Node->RightSibling != NULL)
		LCRS_PrintTree(Node->RightSibling, Depth);
}

void LCRS_PrintNodeAtLevel(LCRSNode* Root, int Level) {

	if (Root->LeftChild != NULL && Level > 0) {
		LCRS_PrintNodeAtLevel(Root->LeftChild, Level-1);
	}
	if (Level == 0) printf("%c ", Root->Data);
	if (Root->RightSibling != NULL) {
		LCRS_PrintNodeAtLevel(Root->RightSibling, Level);
	}

}







