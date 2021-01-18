#include "SBT.h"

SBTNode * SBT_CreateNode(ElementType NewData)
{
	SBTNode* NewNode = (SBTNode*)malloc(sizeof(SBTNode));

	NewNode->Left = NULL;
	NewNode->Right = NULL;
	NewNode->Data = NewData;

	return NewNode;

}

void SBT_DestroyNode(SBTNode * Node)
{
	free(Node);
}

void SBT_PreorderPrintTree(SBTNode * Node)
{
	//노드가 비었을때
	if (Node == NULL)
		return;

	//Root
	printf(" %c", Node->Data);

	//Left Tree
	SBT_PreorderPrintTree(Node->Left);

	//Right Tree
	SBT_PreorderPrintTree(Node->Right);
}

void SBT_InorderPrintTree(SBTNode * Node)
{
	if (Node == NULL)
		return;

	//Left Tree
	SBT_InorderPrintTree(Node->Left);

	// Root
	printf(" %c", Node->Data);

	//Right Tree
	SBT_InorderPrintTree(Node->Right);

}

void SBT_PostorderPrintTree(SBTNode * Node)
{
	if (Node == NULL)
		return;

	//Left
	SBT_PostorderPrintTree(Node->Left);

	//Right
	SBT_PostorderPrintTree(Node->Right);

	//Root
	printf(" %c", Node->Data);
}

void SBT_DestroyTree(SBTNode * Node)
{
	if (Node == NULL)
		return;

	SBT_DestroyNode(Node->Left);
	SBT_DestroyNode(Node->Right);
	SBT_DestroyNode(Node);
}
