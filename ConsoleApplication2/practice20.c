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
		printf("���ڿ��� �Է��Ͻÿ�: ");
		scanf("%[^\n\r]", &data);
		getchar();

		int r = 0;

		
		for (int i = 0; i < strlen(data); i++)
		{
			// ����, ��ȣ�� ������ ���� ���ڿ� üũ �� ����
			if (!isspace(data[i]) && !ispunct(data[i]))
			{
				// �빮���� ��� �ҹ��ڷ� ġȯ�Ͽ� ����
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
		// temp�� ���� üũ
		int length = strlen(temp);

		// �� ���ھ� ���ÿ� ����
		for (int i = 0; i < length; i++)
		{
			Push(&s, temp[i]);
		}

		// �� ���ھ� ���ÿ��� ��
		for (int i = 0; i < length; i++)
		{
			element tip = Pop(&s);
			if (tip == temp[i])
			{
				result = true;
			}
			else {
				result = false;
				printf("ȸ���� �ƴմϴ�\n");
				break;
			}
		}
		if (result)
			printf("ȸ���Դϴ�.\n");

		printf("��� �Է��Ͻðڽ��ϱ�(Yes/No): ");
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
			printf("�߸��� ���� �Է��߽��ϴ�.");
			return 0;
		}

	}
}
// �����͸� ����
// Push �� ���Ͽ� ���� Element �迭�� ���� �ϳ��� �� �� �����ϸ� ȸ���Դϴ�
// �������� ������ ȸ���� �ƴմϴ�.�� �亯