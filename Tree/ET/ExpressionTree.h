#ifndef EXPRESSION_TREE_H
#define EXPRESSION_TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char ElementType;

typedef struct m_Node {
	struct m_Node* Left;
	struct m_Node* Right;

	ElementType Data;
}ETNode;

ETNode* ET_CreateNode(ElementType NewData);
void ET_DestroyNode(ETNode* Node);
void ET_DestroyTree(ETNode* Root);

void ET_PreorderPrintTree(ETNode* Node);
void ET_InorderPrintTree(ETNode* Node);
void ET_PostorderPrintTree(ETNode* Node);

//���� Ʈ�� ����
void ET_BuildExpressionTree(char* PostfixExpression, ETNode** Node);
//���� Ʈ�� ���
double ET_Evaluate(ETNode* Tree);


#endif // !EXPRESSION_TREE_H
