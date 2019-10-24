#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int d;
	Node* next;
};

struct Queue
{
	int num;
	Node* front;
	Node* rear;
};

void QInit(Queue* q)
{
	q->front = NULL;
	q->rear = NULL;
	q->num = 0;
}

void QInsert(Queue* q, int d)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->next = NULL;
	newNode->d = d;

	if (q->front == NULL)
		q->front = newNode; // 맨 첫원소 넣을 때 조심
	
	if(q->rear != NULL)
		q->rear->next = newNode;
	q->rear = newNode;

	q->num++;
}

int QFront(Queue* q)
{
	return q->front->d;
}

bool QEmpty(Queue* q)
{
	if (q->num == 0)
		return true;
	else
		return false;
}

int QPop(Queue* q)
{
	Node* rnode = q->front;
	int rdata = rnode->d;

	q->front = q->front->next;
	free(rnode);

	q->num--;
	return rdata;
}

int main()
{
	Queue q;
	QInit(&q);

	QInsert(&q, 1);
	QInsert(&q, 2);
	QInsert(&q, 3);
	QInsert(&q, 4);
	QInsert(&q, 5);
	QInsert(&q, 6);

	printf("큐 맨앞: %d\n", QFront(&q));

	while (!QEmpty(&q))
		printf("지우는 값: %d\n", QPop(&q));
	
	return 0;
}