#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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
	QueueType queue;

	int element;

	init_queue(&queue);
	
	srand(time(NULL));

	for (int i = 0; i < 100; i++) {
		if (rand() % 5 == 0) {
			enqueue(&queue, rand() % 100);
		}
		queue_print(&queue);
		if (rand() % 10 == 0) {
			int data = dequeue(&queue);
		}
		queue_print(&queue);
	}
	return 0;
}