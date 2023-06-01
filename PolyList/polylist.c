#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define _CRT_SECURE_NO_WARNINGS


typedef struct ListNode {
	// 계스
	int coef;
	// 지수
	int expon;

	// 연결 링크
	struct ListNode* link;
}ListNode;

typedef struct ListType {
	// 그럼 인건?
	int size;

	// head르 향한 좌표?
	ListNode* head;

	// 마지막을 향한 좌표?
	ListNode* tail;
}ListType;

ListType* create() {
	ListType* plist = (ListType*)malloc(sizeof(ListType));
	plist->size = 0;
	plist->head = plist->tail = NULL;
	return plist;
}

void insert_last(ListType* plist, int coef, int expon) {

	// ListNode 형태로 임시 필드 선언
	ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
	
	if (temp == NULL) return;
	temp->coef = coef;
	temp->expon = expon;
	temp->link = NULL;

	if (plist->tail == NULL)
	{
		plist->head = plist->tail = temp;
	}

	else {
		plist->tail->link = temp;
		plist->tail = temp;
	}
	plist->size++;
}

void poly_print(ListType* plist)
{
	ListNode* p = plist->head;
	printf("polynomial = ");
	for (; p; p = p->link) {
		printf("%d^%d + ", p->coef, p->expon);
	}
	printf("\n");
}

// a와 b 다항식 중 하나라도 NULL이 되기 전까지 작업개시
// While문에서 하나라도 문제가 NULL이 발생시 중단
// 나머지를 for문으로 전부 넣음
void poly_add(ListType* plist1, ListType* plist2, ListType* plist3) {
	ListNode* a = plist1->head;
	ListNode* b = plist2->head;

	int sum;

	while (a && b) {
		if (a->expon == b->expon) {
			sum = a->coef + b->expon;
			if (sum != 0) insert_last(plist3, sum, a->expon);
			a = a->link; b = b->link;
		}
		else if (a->expon > b->expon) {
			insert_last(plist3, a->coef, a->expon);
			a = a->link;
		}
		else {
			insert(plist3, b->coef, b->expon);
			b = b->link;
		}
	}

	for (; a != NULL; a = a->link)
		insert_last(plist3, a->coef, a->expon);
	for (; b != NULL; b = b->link)
		insert_last(plist3, b->coef, b->expon);
}


int main(){
	ListType* list1, * list2, * list3;

	list1 = create();
	list2 = create();
	list3 = create();

	insert_last(list1, 3, 12);
	insert_last(list1, 2, 8);
	insert_last(list1, 1, 0);

	insert_last(list2, 8, 12);
	insert_last(list2, -3, 10);
	insert_last(list2, 10, 6);

	poly_print(list1);
	poly_print(list2);

	poly_add(list1, list2, list3);

	poly_print(list3);

	free(list1); free(list2); free(list3);
}