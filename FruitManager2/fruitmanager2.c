#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define _CRT_SECURE_NO_WARNINGS


typedef char element[255];

element item;

int moveCount;

char index; 

typedef struct DListNode {
	element data;
	struct DListNode* llink;
	struct DListNode* rlink;
}DListNode;

DListNode* current;

void error(char* message) {
	printf("%s\n", message);
	exit(1);
}

void print_dlist(DListNode* phead, DListNode* current)
{
	DListNode* p = phead;
	
	for (p = phead->llink; p != phead; p = p->llink) {
		if (strcmp(p->data, current->data) == 0) {
			printf("%s [O]\n", p->data);
		}
		else {
			printf("%s\n", p->data);
		}
	}
	printf("\n");
	
}


void dinsert(DListNode* before, element data)
{
	DListNode* newnode = (DListNode*)malloc(sizeof(DListNode));
	strcpy(newnode->data, data);
	newnode->llink = before;
	newnode->rlink = before->rlink;
	before->rlink->llink = newnode;
	before->rlink = newnode;
}

void ddelete(DListNode* head) {
	if (current == head) {
		printf("List is Empty");
		return;
	}
	int count = 0;
	DListNode* p = head;
	
	// 선택된 값까지 이동
	while (p->llink != head) {
		count++;
		p = p->llink;
	}
	while (p != current) {
		p = p->llink;
	}

	if (count == 2) {
		current = head->llink;
	}
	else if(count > 2) {
		if (p->llink == head) {
			current = p->rlink;
		}
		else {
			current = p->llink;
		}
	}

	DListNode* removed = p;

	removed->llink->rlink = removed->rlink;
	removed->rlink->llink = removed->llink;

	free(removed);
	printf("\n");
}

DListNode* OnNext(DListNode* p, DListNode* current) {

	// 리스트에 값이 없는 경우
	if (p->llink == p) {
		printf("리스트에 값이 존재하진 않습니다\n\n");
		return p;
	}

	// 리스트에 값이 있는 경우
	else {
		if (p->llink == current) {
			if (p->llink->llink == p) {
				printf("넘어갈 값이 존재하지 않습니다.\n\n");
				return current;
			}
			else {
				return p->llink->llink;
			}
		}
		else {
			while (true) {
				if (p->rlink == current) {
					printf("다음 값은 존재하지 않습니다\n");
					return current;
				}
				else {
					p = p->llink;

					if (p->llink == current) {
						return p->llink->llink;
					}
				}
			}
		}
	}
}
DListNode* OnPrevious(DListNode* p, DListNode* current) {
	// 리스트에 값이 없는 경우
	if (p->llink == p) {
		printf("리스트에 값이 존재하진 않습니다\n\n");
		return p;
	}

	// 리스트에 값이 있는 경우
	else {
		if (p->llink == current) {
			printf("넘어갈 값이 존재하지 않습니다.\n\n");
			return current;
		}
		else {
			while (true) {
				p = p->llink;

				if (p->llink == current) {
					return p;
				}
			}
		}
	}
}

void Init(DListNode* phead) {
	phead->llink = phead;
	phead->rlink = phead;
}

int main() {
	DListNode* head = (DListNode*)malloc(sizeof(DListNode));
	current = (DListNode*)malloc(sizeof(DListNode));

	Init(head);
	Init(current);


	while (true) {
		printf("n) next fruit\np) previous fruit\nd) delete the current fruit\ni) insert fruit after current fruit\no) output the fruit list(Output [0] at the end of the currnetly selected fruit)\ne) exit the program\n===============\nSelect a menu: ");
		scanf("%c", &index);
		getchar();

		if (index == 'n') {
			current = OnNext(head, current);
		}
		else if (index == 'p') {
			current = OnPrevious(head, current);
		}
		else if (index == 'd') {
			ddelete(head);
		}
		else if (index == 'i') {
			printf("Enter the name of the fruit to add: ");
			scanf("%[^\n]", item);
			getchar();

			if (head->llink == head || head->rlink == head) {
				dinsert(head, item);
				current = head->rlink;
			}
			else {
				dinsert(head, item);
			}

			printf("\n");
		}
		else if (index == 'o') {
			print_dlist(head, current);
		}
		
		else if (index == 'e') {
			printf("Exit the program.\n\n");
			return;
		}

		// Exception
		else {
			printf("Invalid menu?\n\n");
			index = ' ';
		}
	}

}