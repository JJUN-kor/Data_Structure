#include "ExpressionTree.h"

int main() {

	ETNode* Root = NULL;

	char PostfixExpression[20] = "71*52-/";
	ET_BuildExpressionTree(PostfixExpression, &Root);

	//Ʈ�� ���

	printf("___Preorder___\n");
	ET_PreorderPrintTree(Root);
	printf("\n");

	printf("___Inorder___\n");
	ET_InorderPrintTree(Root);
	printf("\n");

	printf("___Postorder___\n");
	ET_PostorderPrintTree(Root);
	printf("\n");


	//Ʈ�� �Ҹ�
	ET_DestroyNode(Root);


	return 0;
}