#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	Node* next;
};

struct List
{
	int num;
	Node* head;
	Node* cur;
	Node* bfr;
};

void LInit(List* list)
{
	list->head = (Node*)malloc(sizeof(Node));
	list->head->next = NULL; // ��.�߿�, ����� ����� �������� NULL�� �ؾ� ����Ʈ ��ȸ�� ����
	list->num = 0;
}

int LCount(List* list)
{
	return list->num;
}

void LInsert(List* list, int d)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	//newNode->next = NULL; // ���̸���Ʈ���� �ʿ�X
	newNode->data = d;
	
	newNode->next = list->head->next;
	list->head->next = newNode;
	list->num++;
}

bool LFirst(List* list, int* d)
{
	if (list->head->next == NULL)
		return false;

	list->bfr = list->head;
	list->cur = list->head->next;
	*d = list->cur->data;

	return true;
}

bool LNext(List* list, int* d)
{
	if (list->cur->next == NULL)
		return false;

	list->bfr = list->cur;
	list->cur = list->cur->next;
	*d = list->cur->data;

	return true;
}

int LRemove(List* list)
{
	Node* rnode = list->cur;
	int rdata = rnode->data;

	list->bfr->next = list->cur->next;
	list->cur = list->bfr;
	list->num--;

	free(rnode);

	return rdata;
}


int main()
{
	List list;
	int d;

	LInit(&list);

	LInsert(&list, 1);
	LInsert(&list, 2);
	LInsert(&list, 3);
	LInsert(&list, 4);
	LInsert(&list, 5);
	LInsert(&list, 6);
	
	// ���
	if (LFirst(&list, &d))
	{
		printf("%d ", d);

		while (LNext(&list, &d))
			printf("%d ", d);		
	}
	printf("\n");

	printf("����Ʈ ����: %d\n", LCount(&list));

	// ����
	printf("1,3,6 ���� \n");
	if (LFirst(&list, &d))
	{
		if (d == 1 || d == 3 || d == 6)
			LRemove(&list);

		while (LNext(&list, &d))	
			if (d == 1 || d == 3 || d == 6)
				LRemove(&list);	
	}
	
	// ���
	printf("����Ʈ ����: %d\n", LCount(&list));
	if (LFirst(&list, &d))
	{
		printf("%d ", d);

		while (LNext(&list, &d))	
			printf("%d ", d);		
	}
	printf("\n");
	
	return 0;
}