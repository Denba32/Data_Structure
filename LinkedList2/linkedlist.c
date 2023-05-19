#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define _CRT_SECURE_NO_WARNINGS

typedef int element;

element item;

int moveCount;

int index;

typedef struct ListNode{
	element data;
	struct ListNode* link;
}ListNode;


void error(char* message) {
	printf("%s\n", message);
	exit(1);
}

// head에 Node 연결
ListNode* insert_first(ListNode* head, element value) {

	ListNode* p;
	p =(ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head;
	head = p;
	return head;
}

// 특정 위치의 노드 삽입
ListNode* insert(ListNode* head, int pos, element value) {
	// 값이 존재하는 상태에서 0번 위치에 값을 넣을 때
	if (pos == 0) {
		printf("\nMove Along the Link: 0\n");
		head = insert_first(head, value);
		return head;
	}

	else {
		// 입력할 Node 생성
		ListNode* addNode = (ListNode*)malloc(sizeof(ListNode));
		addNode->data = value;
		addNode->link = NULL;


		ListNode* p = head;
		int count = 1;

		while (p != NULL) {
			// 해당 위치에 도달하기 전, NULL을 조우한 경우
			if (count != pos && p->link == NULL) {
				printf("The last index is %d. Insert at the end of the list..\n", count -1);
				// 해당 Node에 추가할 노드를 Link시킴
				p->link = addNode;
				printf("\nMove along the link: %d\n", count);
				break;
			}

			// 해당 위치에 도달 후 Link가 존재하는 경우
			else if (count == pos && p->link != NULL) {
				printf("\nMove Along the Link: %d\n", count);

				addNode->link = p->link;
				p->link = addNode;
				break;
			}

			// 해당 위치에 도달 후 LINK가 NULL인 경우
			else if (count == pos && p->link == NULL) {
				printf("\nMove Along the Link: %d\n", count);

				p->link = addNode;
				break;
			}

			count++;
			p = p->link;
		}
	}
	return head;
}
/*
ListNode* insert(ListNode* head, ListNode* pre, element value) {

	ListNode* p = (ListNode*)malloc(sizeof(ListNode));

	p->data = value;
	p->link = pre->link;
	pre->link = p;
	return head;
}
*/

// 0번 위치의 노드 삭제
ListNode* delete_first(ListNode* head) {
	ListNode* removed;
	if (head == NULL) return NULL;
	removed = head;
	head = removed->link;

	free(removed);

	return head;
}

// 특정 위치의 Node 삭제
ListNode* delete(ListNode* head, int pos) {
	
	ListNode* prevNode = NULL;

	ListNode* p = head;

	int count = 0;
	while (p != NULL) {

		if (p->link == NULL && pos != count) {
			printf("The last index is %d. Delete this Node of the list..\n", count);
			prevNode->link = NULL;
			free(p);
			break;

		}
		else if (pos == count && p->link == NULL) {
			printf("\nMove Along the Link: %d\n", count);
			prevNode->link = NULL;
			free(p);
			break;
		}
		
		else if (pos == count && p->link != NULL) {
			printf("\nMove Along the Link: %d\n", count);
			prevNode->link = p->link;

			free(p);

			break;
		}

		prevNode = p;
		p = p->link;
		count++;
	}
	return head;
}

/*
ListNode* delete(ListNode* head, ListNode* pre) {
	ListNode* removed;
	removed = pre->link;
	pre->link = removed->link;
	free(removed);
	return head;
}
*/

// LinkedNode 출력
void print_list(ListNode* head) {
	printf("List: ");
	for (ListNode* p = head; p != NULL; p = p->link)
		printf("%d->", p->data);
	printf("NULL \n");
}

int main() {
	int selector = 0;
	index = 0;

	ListNode* head = NULL;

	while (1) {
		printf("Menu\n(1) Insert\n(2) Delete\n(3) Print\n(0) Exit\nEnter the menu: ");
		scanf("%d", &selector);
		getchar();


		// Insert
		if (selector == 1) {
			printf("Enter the number and position: ");
			scanf("%d %d", &item, &index);

			getchar();

			// Empty List이지만 Pos가 0이 아닌 경우
			if (head == NULL && index != 0) {
				printf("List is empty. Insert at position 0..\n");
				printf("\nMove along the link: 0\n");
				head = insert_first(head, item);
			}

			// Empty List이며 0번에 값을 넣는 경우
			else if (head == NULL && index == 0) {
				head = insert_first(head, item);
			}

			// 값이 존재하는 경우
			else if (head != NULL) {
				head = insert(head, index, item);
			}
		}

		// Delete
		else if (selector == 2) {

			// List가 존재하지 않는 경우
			if (head == NULL) {
				printf("List is empty.\n\n");
			}

			// 값이 존재하는 경우
			else {
				printf("Enter the position: ");
				scanf("%d", &index);
				getchar();

				// 0번을 없애는 경우 head의 Link를 끊는 delete_first를 사용
				if (index == 0) {
					printf("\nMove along the link: %d", index);
					head = delete_first(head);
				}
				// 그 외
				else if (index > 0) {
					head = delete(head, index);
				}
			}
		}

		// Print
		else if (selector == 3) {
			print_list(head);
		}

		// Exit
		else if (selector == 0) {
			printf("Exit the program.\n----------------------------");
			exit(1);
		}

		// 잘못된 값 방지
		else {
			printf("Invalid Menu. Please select again..\n\n");
			continue;
		}
		printf("\n");
	}
}