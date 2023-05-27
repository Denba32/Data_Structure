#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define _CRT_SECURE_NO_WARNINGS


typedef struct {
	char name[100];
}element;

element item;

int moveCount;

int index;

typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;

ListNode* trashBox = NULL;


void error(char* message) {
	printf("%s\n", message);
	exit(1);
}

void print_list(ListNode* head)
{
	for (ListNode* p = head; p != NULL; p = p->link)
		printf("%s->", p->data.name);
	printf("NULL \n\n");
}

// head에 Node 연결
ListNode* insert_first(ListNode* head, element value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head;
	head = p;
	return head;
}


ListNode* insert(ListNode* head, element item) {

	ListNode* p = head;
	ListNode* d = (ListNode*)malloc(sizeof(ListNode));
	bool check = true;
	while (p->link != NULL) {
		if (strcmp(p->data.name, item.name) == 0) {
			printf("%s already existed.\n\n", item.name);

			check = false;
			break;
		}
		else {
			check = true;
		}
		p = p->link;
	}
	if (check) {
		d->data = item;
		d->link = NULL;
		p->link = d;
		printf("%s has benn added.\n\n", item.name);

	}
	return head;
}


// 0번 위치의 노드 삭제
ListNode* delete_first(ListNode* head) {
	ListNode* removed;
	if (head == NULL) return NULL;
	removed = head;
	head = removed->link;

	free(removed);

	return head;
}



ListNode* delete(ListNode* head, element item) {
	ListNode* p = head;

	ListNode* prev = NULL;

	ListNode* d = (ListNode*)malloc(sizeof(ListNode));
	
	bool check = false;
	while (p->link != NULL) {
		if (strcmp(p->data.name, item.name) == 0) {
			printf("%s has been deleted.\n\n", p->data.name);

			d->data = item;
			d->link = trashBox;
			trashBox = d;

			if (prev == NULL) {
				head = p->link;
			}
			else {
				prev->link = p->link;
			}

			check = true;
			break;
		}
	
		prev = p;
		p = p->link;
	}

	if (!check)
		printf("%s is not on the list\n\n", &item.name);

	return head;
}


int main() {
	ListNode* head = NULL;

	element data;
	strcpy(data.name, "Peach");
	head = insert_first(head, data);	
	strcpy(data.name, "Banana");
	head = insert_first(head, data);	
	strcpy(data.name, "Raspberry");
	head = insert_first(head, data);	
	strcpy(data.name, "Guava");
	head = insert_first(head, data);	
	strcpy(data.name, "Plum");
	head = insert_first(head, data);	
	strcpy(data.name, "Cherry");
	head = insert_first(head, data);	
	strcpy(data.name, "Grape");
	head = insert_first(head, data);	
	strcpy(data.name, "Apple");
	head = insert_first(head, data);	
	strcpy(data.name, "Orange");
	head = insert_first(head, data);	
	strcpy(data.name, "Mango");
	head = insert_first(head, data);


	while (true) {
		printf("1. Insert new fruit\n2. Delete the fruit\n3. Print the deleted list\n4. Exit\nEnter the menu: ");
		scanf("%d", &index);
		getchar();

		// Insert
		if (index == 1) {
			printf("Fruit name to add: ");
			scanf("%s", &item.name);
			getchar();

			head = insert(head, item);
		}
		// Delete 삭제된 리스트만 출력해도 됨
		else if (index == 2) {
			printf("Fruit name to delete: ");
			scanf("%s", &item.name);
			getchar();

			head = delete(head, item);
			print_list(head);


		}
		// Print
		else if (index == 3) {
			printf("Fruit List\n");
			print_list(head);
			printf("List of the deleted fruits\n");
			print_list(trashBox);
		}

		// Exit
		else if (index == 4) {
			printf("Exit the program.\n");
			return;
		}

		// Exception
		else {
			printf("잘못된 숫자를 입력했습니다\n");
		}
	}

}