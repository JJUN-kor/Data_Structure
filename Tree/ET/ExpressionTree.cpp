#include "ExpressionTree.h"

ETNode * ET_CreateNode(ElementType NewData)
{
	ETNode* NewNode = (ETNode*)malloc(sizeof(ETNode));

	NewNode->Left = NULL;
	NewNode->Right = NULL;
	NewNode->Data = NewData;

	return NewNode;
}

void ET_DestroyNode(ETNode * Node)
{
	free(Node);
}

void ET_DestroyTree(ETNode * Root)
{
	if (Root == NULL)
		return;

	ET_DestroyNode(Root->Left);
	ET_DestroyNode(Root->Right);
	ET_DestroyNode(Root);
}

void ET_PreorderPrintTree(ETNode * Node)
{
	if (Node == NULL)
		return;

	printf(" %c", Node->Data);
	ET_PreorderPrintTree(Node->Left);
	ET_PreorderPrintTree(Node->Right);

}

void ET_InorderPrintTree(ETNode * Node)
{
	if (Node == NULL)
		return;

	printf("(");
	ET_InorderPrintTree(Node->Left);
	
	printf("%c", Node->Data);

	ET_InorderPrintTree(Node->Right);

	printf(")");
}

void ET_PostorderPrintTree(ETNode * Node)
{
	if (Node == NULL)
		return;
	ET_PostorderPrintTree(Node->Left);
	ET_PostorderPrintTree(Node->Right);
	printf(" %c", Node->Data);
}

void ET_BuildExpressionTree(char * PostfixExpression, ETNode ** Node)
{
	//문자열 길이
	int len = strlen(PostfixExpression);
	
	char Token = PostfixExpression[len - 1];
	PostfixExpression[len - 1] = '\0';

	switch (Token) {
		//연산자 일경우
	case '+': case'-': case '*': case '/':
		(*Node) = ET_CreateNode(Token);
		ET_BuildExpressionTree(PostfixExpression, &(*Node)->Right);
		ET_BuildExpressionTree(PostfixExpression, &(*Node)->Left);

		break;
	default:
		(*Node) = ET_CreateNode(Token);
		break;
	}
}

double ET_Evaluate(ETNode * Tree)
{
	char temp[2];

	double Left = 0;
	double Right = 0;
	double Result = 0;

	if (Tree == NULL)
		return 0;

	switch (Tree->Data) {
		//연산자 일 경우
		case '+': case'-': case '*': case '/':
			Left = ET_Evaluate(Tree->Left);
			Right = ET_Evaluate(Tree->Right);

			if (Tree->Data == '+') Result = Left + Right;
			else if (Tree->Data == '-') Result = Left - Right;
			else if (Tree->Data == '*') Result = Left * Right;
			else if (Tree->Data == '/') Result = Left / Right;

			break;

		//피연산자

		default:
			memset(temp, 0, sizeof(temp));
			temp[0] = Tree->Data;
			Result = atof(temp);
	}

	return Result;
}
