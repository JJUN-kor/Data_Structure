#include "ExpressionTree.h"

int main() {

	ETNode* Root = NULL;

	char PostfixExpression[20] = "71*52-/";
	ET_BuildExpressionTree(PostfixExpression, &Root);

	//트리 출력

	printf("___Preorder___\n");
	ET_PreorderPrintTree(Root);
	printf("\n");

	printf("___Inorder___\n");
	ET_InorderPrintTree(Root);
	printf("\n");

	printf("___Postorder___\n");
	ET_PostorderPrintTree(Root);
	printf("\n");


	//트리 소멸
	ET_DestroyNode(Root);


	return 0;
}