#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX 100
#define _CRT_SECURE_NO_WARNINGS

typedef char element;
char str[101];
char str2[101];
// 구조체용
typedef struct {
	element data[MAX];
	int top;
}StackType;


// 비어있을 때
int isEmpty(StackType* s)
{
	return (s->top == -1);
}
// 가득 찼을 때
int isFull(StackType* s)
{
	return (s->top == MAX - 1);
}
void Init_Stack(StackType* s)
{
	s->top = -1;
}

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

element peek(StackType* s)
{
	if (isEmpty(s))
	{
		printf("Error, Stack is Empty!");
		return 0;
	}

	return s->data[(s->top)];
}

void Init(StackType* s)
{
	if (isEmpty(s))
	{
		printf("Error, Stack is Empty!");
		return;
	}

	s->top = -1;
}


int Eval(char exp[]) {
	element op1 = 0;
	element op2 = 0;

	// string 길이 
	int len = strlen(exp);
	char ch;
	StackType s;
	Init(&s);


	for (int i = 0; i < len; i++)
	{
		ch = exp[i];
		if (ch >= '0' && ch <= '9')
		{
			ch = ch - '0';
			Push(&s, ch);
		}

		// 숫자가 아닌 경우
		else {
			// 두 값을 가져옴
			op2 = Pop(&s);
			op1 = Pop(&s);

			if (ch == '+') {
				Push(&s, (element)(op1 + op2));

			}
			else if (ch == '-')
			{
				Push(&s, (element)(op1 - op2));

			}
			else if (ch == '*') {

				Push(&s, (element)(op1 * op2));
			}
			else if (ch == '/') {
				if (op2 == 0) {
					printf("0으로는 나눌 수 없습니다.");
				}
				Push(&s, (element)(op1 / op2));

			}
			else {// 2221101+/3*
				printf("잘못된 기호가 들어가 있습니다\n");
				return 0;
			}
		}
	}
	return Pop(&s);
}

int prec(char op) {
	switch (op) {
	case '(': case')': return 0;
	case'+':case'-': return 1;
	case '*': case '/': return 2;
	}
	return -1;
}


void infix_to_postfix(char exp[])
{
	int i = 0;
	char ch, top_op;
	int len = strlen(exp);

	StackType s;
	Init_Stack(&s);
	int index = 0;
	for (int i = 0; i < len; i++)
	{
		ch = exp[i];
		switch (ch) {
		case '+':case'-':case'*':case'/':
			while (!isEmpty(&s) && (prec(ch) <= prec(peek(&s)))) {

				str2[index] = Pop(&s);
				
				index++;
			}
			if (exp[i + 1] == '+' || exp[i + 1] == '-' || exp[i + 1] == '*' || exp[i + 1] == '/' || i == 0) {
				printf("Error: Invalid Expression");
				exit(1);
			}
			Push(&s, ch);
			break;

		case'(':
			Push(&s, ch);
			break;

		case')':
			top_op = Pop(&s);
			while (top_op != '(') {
				str2[index] = top_op;
				index++;
				top_op = Pop(&s);
			}
			break;

		default:
			if (!(ch >= '0' && ch <= '9'))
			{
				printf("Error: Invalid Character");
				exit(1);
			}
			str2[index] = ch;
			index++;
			break;
		}
	}
	while (!isEmpty(&s)) {
		str2[index] = Pop(&s);
		index++;
	}
}

int main() {
	printf("Enter an infix expression: ");
	scanf("%s", str);
	infix_to_postfix(str);
	printf("Postfix expression: %s", str2);
	int result =Eval(str2);
	printf("\nResult %d", result);
	//printf("\n");
	//printf("%s", str);

//	Eval(str);

}