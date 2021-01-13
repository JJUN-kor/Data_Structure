#include "ArrayStack.h"

int ArrayStack_main() {

	ArrayStack* Stack = NULL;

	AS_CreateStack(&Stack, 10); // 배열 스택 생성

	AS_Push(Stack, 20);
	AS_Push(Stack, 3);
	AS_Push(Stack, 46);
	AS_Push(Stack, 13);
	AS_Push(Stack, 62);


	printf("Capacity: %d , Size: %d , Top:%d \n\n", Stack->Capacity, AS_GetSize(Stack), AS_Top(Stack));


	int i = 0;
	int Position = AS_GetSize(Stack);
	//printf("%d", Position);
	
	for (i = 0; i < Position; i++) {

		if (AS_IsEmpty(Stack))
			break;

		printf("Popped : %d", AS_Pop(Stack));

		if (!AS_IsEmpty(Stack))
			printf("\t Current Top: %d\n", AS_Top(Stack));
		else
			printf("\t Stack Is Empty.\n");
	}

	AS_DestroyStack(Stack);

	return 0;
}