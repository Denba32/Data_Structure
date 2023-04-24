#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>


#define MAX 101

typedef char element;

element data[MAX];
bool result = false;
typedef struct {
	element data[MAX];
	int top;
}StackType;


// Stack Empty Check
int isEmpty(StackType* s)
{
	return (s->top == -1);
}

// Stack Full Check
int isFull(StackType* s)
{
	return (s->top == MAX - 1);
}


// Push Item in Stack
void Push(StackType* s, element datas)
{
	if (isFull(s))
	{
		printf("Error, Stack is Full!");
		return;
	}
	else {
		s->data[++(s->top)] = datas;
	}
}

// Pop Item in Stack
element Pop(StackType* s)
{
	if (isEmpty(s))
	{
		printf("Error, Stack is Empty!");
		exit(1);
	}
	else {
		return s->data[(s->top)--];
	}
}

// peek Item in Stack
element peek(StackType* s)
{
	if (isEmpty(s))
	{
		printf("Error, Stack is Empty!");
		return;
	}

	return s->data[(s->top)];
}

// Stack Initializing
void Init(StackType* s)
{
	if (isEmpty(s))
	{
		printf("Error, Stack is Empty!");
		return;
	}

	s->top = -1;
}


int main() {
	StackType s;
	bool repeat = true;
	char question[MAX];
	char temp[MAX];

	Init(&s);
	while (repeat)
	{
		printf("\n");
		printf("문자열을 입력하시오: ");
		scanf("%[^\n\r]", &data);
		getchar();

		int r = 0;

		
		for (int i = 0; i < strlen(data); i++)
		{
			// 공백, 기호를 제외한 순수 문자열 체크 및 저장
			if (!isspace(data[i]) && !ispunct(data[i]))
			{
				// 대문자일 경우 소문자로 치환하여 저장
				if (isupper(data[i]))
				{
					temp[r] = tolower(data[i]);
				}
				else {
					temp[r] = data[i];
				}
				r++;
			}
		}
		temp[r] = '\0';
		// temp의 길이 체크
		int length = strlen(temp);

		// 한 글자씩 스택에 넣음
		for (int i = 0; i < length; i++)
		{
			Push(&s, temp[i]);
		}

		// 한 글자씩 스택에서 뺌
		for (int i = 0; i < length; i++)
		{
			element tip = Pop(&s);
			if (tip == temp[i])
			{
				result = true;
			}
			else {
				result = false;
				printf("회문이 아닙니다\n");
				break;
			}
		}
		if (result)
			printf("회문입니다.\n");

		printf("계속 입력하시겠습니까(Yes/No): ");
		scanf("%[^\n\r]", &question);
		getchar();
		if (strcmp(question, "Yes") == 0 || strcmp(question, "yes") == 0)
		{
			repeat = true;
		}
		else if (strcmp(question, "No") == 0 || strcmp(question, "no") == 0)
		{
			repeat = false;
		}
		else {
			printf("잘못된 값을 입력했습니다.");
			return 0;
		}

	}
}
// 데이터를 받음
// Push 후 팝하여 기존 Element 배열과 값을 하나씩 비교 후 동일하면 회문입니다
// 동일하지 않으면 회문이 아닙니다.로 답변