#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE_SIZE 5

typedef int element;

typedef struct {
	element data[MAX_QUEUE_SIZE];
	int front, rear;
}QueueType;

// ����
void error(char* message)
{
	printf("%s\n", message);
	exit(1);
}

// �ʱ�ȭ
void init_queue(QueueType* q)
{
	q->front = q->rear = 0;
}

// ť Empty ����
int is_empty(QueueType* q)
{
	return (q->front == q->rear);
}

// ť Full ����
int is_full(QueueType* q) {
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}


// ť ��ü ���
void queue_print(QueueType* q) {
	printf("Queue(front = %d rear = %d) = ", q->front, q->rear);

	if (!is_empty(q)) {
		int i = q->front;
		do {
			i = (i + 1) % (MAX_QUEUE_SIZE);
			printf("%d | ", q->data[i]);
			if (i == q->rear)
				break;
		} while (i != q->front);
	}
	printf("\n");
}

// �߰� �Լ�
void enqueue(QueueType* q, element item)
{
	if (is_full(q))
		printf("ť�� ��ȭ�����Դϴ�\n");
	else {
		q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
		q->data[q->rear] = item;
		printf("Enqueue: %d\n\n", item);
	}
}
// ���� �Լ�
element dequeue(QueueType* q)
{
	if (is_empty(q))
		printf("ť�� ����ֽ��ϴ�\n");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

int main() {
	int selectCount = 0;

	QueueType queue;

	element data;
	
	init_queue(&queue);

	while (1) {
		printf("===== Menu =====\n1. Input data and Enqueue\n2. Dequeue and Print data\n3. Print Queue\n4. Exit \nSelect number: ");
		scanf("%d", &selectCount);


		// �߰� ���
		if (selectCount == 1) {
			printf("\n");
			printf("Input the data: ");
			scanf("%d", &data);
			enqueue(&queue, data);
		}

		// 2�� ���� ���
		else if (selectCount == 2) {
			if (!is_empty(&queue))
			{
				printf("Dequeue: %d\n\n", dequeue(&queue));

			}
			else {
				printf("Queue is empty.\n");
			}
		}

		// 3�� ���� ��� ���
		else if (selectCount == 3)
		{
			queue_print(&queue);
		}
		
		// 4�� ���α׷� ���� ���
		else if (selectCount == 4)
		{
			printf("Exit the program.\n");
			exit(1);
		}

		// �� �� ���Է� ���� ó��
		else {
			printf("�߸��� ���� �Է��Ͽ����ϴ�.\n");
		}
	}	
}