#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAX_QUEUE_SIZE 100


char text[255];
char temp1[255];
char temp2[255];

typedef char element;
typedef struct {
	element data[MAX_QUEUE_SIZE];
	int front, rear;
}DequeType;

void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init_dequeue(DequeType* q) {
	q->front = q->rear = 0;
}

int is_empty(DequeType* q) {
	return(q->front == q->rear);
}

int is_full(DequeType* q) {
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}


void deque_print(DequeType* q) {
	printf("DEQUE(front=%d rear=%d) = ", q->front, q->rear);
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

// 후면에서 넣기
void add_rear(DequeType* q, element item) {
	if (is_full(q))
	{
		printf("큐가 포화상태입니다\n");
		return;
	}
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

// 정면 삭제
element delete_front(DequeType* q) {
	if (is_empty(q))
	{
		printf("큐가 공백상태입니다\n");
		return;
	}
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

// 정면 가져오기
element get_front(DequeType* q) {
	if (is_empty(q))
	{
		printf("큐가 공백상태입니다\n");
		return;
	}
	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}

// 정면에서 넣기
void add_front(DequeType* q, element val) {
	if (is_empty(q))
	{
		printf("큐가 포화상태입니다\n");
		return;
	}
	q->data[q->front] = val;
	q->front = (q->front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}

// 후면 삭제
element delete_rear(DequeType* q) {
	int prev = q->rear;
	if (is_empty(q))
	{
		printf("큐가 공백상태입니다\n");
		return;
	}
	q->rear = (q->rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
	return q->data[prev];
}
// 후면 가져오기
element get_rear(DequeType* q) {
	if (is_empty(q))
	{
		printf("큐가 공백상태입니다\n");
		return;
	}
	return q->data[q->rear];
}

int main() {
	DequeType queue;

	init_dequeue(&queue);
	
	while (1) {
		printf("Enter a string (or input 'exit'): ");
		scanf("%[^\n\r]", &text);
		getchar();


		if (strcmp(text, "exit") == 0 || strcmp(text, "Exit") == 0)
		{
			printf("Program Exit");
			return 0;
		}
		int r = 0;
		for (int i = 0; i < strlen(text); i++) {
			if (!isspace(text[i]) && !ispunct(text[i])) {
				if (isupper(text[i])) {
					temp1[r] = tolower(text[i]);
					add_rear(&queue, tolower(text[i]));
				}
				else {
					temp1[r] = text[i];
					add_rear(&queue, text[i]);
				}
				r++;
			}
		}

		bool result = false;

		for (int j = 0; j < strlen(temp1); j++) {
			if (get_rear(&queue) == temp1[j])
			{
				result = true;
			}
			else {
				result = false;
			}
			delete_rear(&queue);

		}

		if (result) {
			printf("%s is a palindrome.\n\n", text);
		}
		else {
			printf("%s is not a palindrome.\n\n", text);
		}

	}
	return 0;
}

// 정면 넣기 -> 후면 빼기