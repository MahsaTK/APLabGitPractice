﻿#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 200
int arr[MAX_SIZE];

typedef struct alfa* alfaptr;

struct alfa {
	long long x;
	alfaptr next;
};
alfaptr rear = nullptr, front = nullptr;
void push(int x)
{
	alfaptr node;
	node = (alfaptr)malloc(sizeof(struct alfa));
	node->x = x;
	if (!front) {
		rear = node;
		front = node;
	}
	else {
		rear->next = node;
		rear = node;
	}
}

void pop()
{
	alfaptr node;
	if (!front)
		printf("ERROR1");
	else
	{
		node = front->next;
		free(front);
		front = node;
	}
}
void search(int x)
{
	alfaptr node = front;
	int counter = 0;
	while (node && node != rear->next) {
		if (node->x == x) {
			counter++;
			printf("%d", counter);
		}
		else {
			printf("ERROR2");
		}
		node = node->next;
	}
}

void rpop() {//pop last element
	alfaptr node = front;
	while (rear && node->next != rear && front != rear)
		node = node->next;
	free(rear);
	node->next = nullptr;
	rear = node;
}

void set()
{
	alfaptr node = front;
	for (int i = 0; i < MAX_SIZE && node && node != rear->next; i++, node = node->next)
		arr[i] = node->x;
}

int size()
{
	alfaptr node = front;
	int count = 0;
	while (node && node != rear->next) {
		count++;
		node = node->next;
	}
	return count;
}

void show()
{
	if (front) {
		for (int i = 0; i < MAX_SIZE; i++)
			printf("%d ", arr[i]);
	}
	else
	{
		printf("ERROR3");
	}
}

int average()
{

	alfaptr node = front;
	int sum = 0, count = 0;
	while (node && node != rear->next) {
		sum += node->x;
		count++;
		node = node->next;
	}
	return sum / count;
}

void main()
{
	int cmd;
	long long int x;
	while (true)
	{
		scanf_s("%d", &cmd);
		switch (cmd)
		{
		case 1://push
			scanf_s("%lld", &x);
			push(x);
			break;
		case 2://pop
			pop();
			break;
		case 3://rpop
			rpop();
			break;
		case 4://search
			scanf_s("%lld", &x);
			search(x);
			break;
		case 5://set
			set();
			break;
		case 6://show
			show();
			break;
		case 7://size
			printf("%d", size());
			break;
		case 10:
			exit(0);
		}
	}
}