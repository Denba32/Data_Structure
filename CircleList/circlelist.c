#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>


typedef int element;

typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;

ListNode* insert_first(ListNode* head, element data) {

	ListNode* node = (ListNode*)malloc(sizeof(ListNode));

	node->data = data;
	if (head == NULL) {
		head = node;
		node->link = head;
	}
	else {
		node->link = head->link;
		head->link = node;
	}
	return head;
}

ListNode* insert_last(ListNode* head, element data) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	if (head == NULL) {
		head = node;
		node->link = head;
	}
	else {
		node->link = head->link;
		head->link = node;
		head = node;
	}
	return head;
}

ListNode* delete_first(ListNode* head) {
	if (head == NULL) {
		return;
	}
	else if (head->link == head)
	{
		free(head);
		return;
	}
	else {
		ListNode* removed = head->link;

		head->link = removed->link;

		free(removed);
	}

	printf("First node has been deleted\n");
	return head;
}

ListNode* delete_last(ListNode* head) {
	if (head == NULL) {
		return;
	}
	else if(head->link == head) {
		free(head);
		return NULL;
	}
	else {
		ListNode* p = head;

		while (p->link != head) {
			p = p->link;
		}
		ListNode* removed = p->link;
		p->link = head->link;
		head = p;
		free(removed);
	}

	printf("Last node has been deleted\n");
	return head;
}

void print_list(ListNode* head)
{
	ListNode* p;

	if (head == NULL) return;
	p = head->link;
	do {
		printf("%d->", p->data);
		p = p->link;
	} while (p != head->link);

	printf("\n");
}

int main() {
	ListNode* head = NULL;

	int count = 0;
	int num = 0;


	while (true) {
		printf("***** Menu *****\n(1) Insert First\n(2) Insert Last\n(3) Delete First\n(4) Delete Last\n(5) Print List\n(0) Exit\nEnter the menu: ");
		scanf("%d", &count);
		getchar();
		if (count == 1) {
			printf("Input a number: ");
			scanf("%d", &num);
			getchar();

			head = insert_first(head, num);

		}
		else if (count == 2) {
			printf("Input a number: ");
			scanf("%d", &num);
			getchar();

			head = insert_last(head, num);

		}
		else if (count == 3) {
			head = delete_first(head);
		}
		else if (count == 4) {
			head = delete_last(head);
		}
		else if (count == 5) {
			print_list(head);

		}
		else if (count == 0) {
			printf("Exit the Program\n");
			exit(1);
		}
		else {
			printf("잘못 입력하셨습니다");
		}

		printf("\n");
	}
	
	return 0;
}