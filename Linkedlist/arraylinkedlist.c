#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define _CRT_SECURE_NO_WARNINGS
#define MAX_LIST_SIZE 100

typedef int element;

int moveCount;

element data;
int index;

typedef struct {
	element datas[MAX_LIST_SIZE];
	int size;
}ArrayListType;

void error(char* message) {
	printf("%s\n", message);
	exit(1);
}

void init(ArrayListType* L) {
	L->size = 0;
}

int is_emtpy(ArrayListType* L) {
	return L->size == 0;
}

int is_full(ArrayListType* L) {
	return L->size == MAX_LIST_SIZE;
}

element get_entry(ArrayListType* L, int pos) {
	if (pos < 0 || pos >= L->size) {
		printf("List size is zero. please enter the again(number position): ");
	}
	return L->datas[pos];
}

void print_list(ArrayListType* L) {
	for (int i = 0; i < L->size; i++)
		printf("%d ->", L->datas[i]);
	printf("\n");
}

void insert_last(ArrayListType* L, element item) {
	if (L->size >= MAX_LIST_SIZE) {
		error("리스트 오버플로우");
	}
	L->datas[L->size++] = item;
}

void insert(ArrayListType* L, int pos, element item) {
	if (pos < 0 || pos > L->size)
	{
		printf("List size is zero. please enter the again(number position): ");
		scanf("%d, %d", &data, &index);
	}
	if (!is_full(L) && (pos >= 0) && (pos <= L->size)) {
		for (int i = (L->size - 1); i >= pos; i--) {
			L->datas[i + 1] = L->datas[i];
			moveCount++;
		}

		L->datas[pos] = item;
		L->size++;

		printf("\nMove: %d\n\n", moveCount);
	}
}

element delete(ArrayListType* L, int pos) {
	element item;

	if (pos < 0 || pos >= L->size)
		error("위치 오류")
		;
	item = L->datas[pos];
	for (int i = pos; i < (L->size - 1); i++) {
		L->datas[i] = L->datas[i + 1];
		moveCount++;
	}

	printf("\nMove : %d\n\n", moveCount);
	L->size--;
	return item;
}

int main() {
	int selector = 0;

	ArrayListType list;

	init(&list);

	while (1) {
		printf("Menu\n(1) Insert\n(2) Delete\n(3) Print\n(0) Exit\nEnter the menu: ");
		scanf("%d", &selector);
		getchar();

		
		// insert
		if (selector == 1) {

			printf("Enter the number and position: ");
			scanf("%d ,%d", &data, &index);
			getchar();
			
			insert(&list, index, data);
			moveCount = 0;
		}

		// Delete
		else if (selector == 2) {
			printf("Enter the position: ");
			scanf("%d", &index);

			delete(&list, index);
			
		}

		// Print
		else if (selector == 3) {
			print_list(&list);

		}

		// Exit
		else if (selector == 0) {
			printf("Exit the program.\n");
			exit(1);
		}

		else {
			printf("Invalid Menu. Please select again..\n\n");
			continue;

		}
		printf("\n");

	}
}