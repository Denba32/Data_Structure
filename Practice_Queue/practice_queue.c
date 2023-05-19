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

// 에러
void error(char* message)
{
	printf("%s\n", message);
	exit(1);
}

// 초기화
void init_queue(QueueType* q)
{
	q->front = q->rear = 0;
}

// 큐 Empty 상태
int is_empty(QueueType* q)
{
	return (q->front == q->rear);
}

// 큐 Full 상태
int is_full(QueueType* q) {
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}


// 큐 전체 출력
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

// 추가 함수
void enqueue(QueueType* q, element item)
{
	if (is_full(q))
		printf("큐가 포화상태입니다\n");
	else {
		q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
		q->data[q->rear] = item;
		printf("Enqueue: %d\n\n", item);
	}
}
// 삭제 함수
element dequeue(QueueType* q)
{
	if (is_empty(q))
		printf("큐가 비어있습니다\n");
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


		// 추가 기능
		if (selectCount == 1) {
			printf("\n");
			printf("Input the data: ");
			scanf("%d", &data);
			enqueue(&queue, data);
		}

		// 2번 삭제 기능
		else if (selectCount == 2) {
			if (!is_empty(&queue))
			{
				printf("Dequeue: %d\n\n", dequeue(&queue));

			}
			else {
				printf("Queue is empty.\n");
			}
		}

		// 3번 내용 출력 기능
		else if (selectCount == 3)
		{
			queue_print(&queue);
		}
		
		// 4번 프로그램 종료 기능
		else if (selectCount == 4)
		{
			printf("Exit the program.\n");
			exit(1);
		}

		// 그 외 오입력 예외 처리
		else {
			printf("잘못된 값을 입력하였습니다.\n");
		}
	}	
}