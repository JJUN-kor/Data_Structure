#include "SBT.h"

int SRT_main() {

	//노드 생성
	SBTNode* A = SBT_CreateNode('A');
	SBTNode* B = SBT_CreateNode('B');
	SBTNode* C = SBT_CreateNode('C');
	SBTNode* D = SBT_CreateNode('D');
	SBTNode* E = SBT_CreateNode('E');
	SBTNode* F = SBT_CreateNode('F');
	SBTNode* G = SBT_CreateNode('G');


	A->Left = B;
	B->Left = C;
	B->Right = D;

	A->Right = E;
	E->Left = F;
	E->Right = G;

	printf("___Preorder___\n");
	SBT_PreorderPrintTree(A);
	printf("\n");

	printf("___Inorder___\n");
	SBT_InorderPrintTree(A);
	printf("\n");

	printf("___Postorder___\n");
	SBT_PostorderPrintTree(A);
	printf("\n");

	SBT_DestroyTree(A);


	return 0;
}