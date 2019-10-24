#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int d;
	Node* next;
};

struct Stack
{
	int num;
	Node* head;
};

void SInit(Stack* stack)
{
	stack->num = 0;
	stack->head = NULL; // 중요(전체노드의 마지막 포인터이기 때문)
}

void SInsert(Stack* stack, int d)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->d = d;

	newNode->next = stack->head;
	stack->head = newNode;

	stack->num++;
}

int SPop(Stack* stack)
{
	Node* rnode = stack->head;
	int rdata = rnode->d;

	stack->head = stack->head->next;
	free(rnode);

	stack->num--;
	return rdata;
}

int STop(Stack* stack)
{
	return stack->head->d;
}

int SEmpty(Stack* stack)
{
	if (stack->num == 0)
		return true;
	else
		return false;
}

int main()
{
	Stack stack;

	SInit(&stack);

	SInsert(&stack, 1);
	SInsert(&stack, 2);
	SInsert(&stack, 3);
	SInsert(&stack, 4);
	SInsert(&stack, 5);
	SInsert(&stack, 6);

	printf("스택 들여다보기: %d\n", STop(&stack));
	
	while (!SEmpty(&stack))
		printf("스택 팝: %d\n", SPop(&stack));
	
	return 0;
}