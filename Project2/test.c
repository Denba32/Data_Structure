#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100
#define MAZE_SIZE 10

//typedef char element;
char str[101];
int count = 0;

char maze[MAZE_SIZE][MAZE_SIZE] = {
		{'1','1','1','1','1','1','1','1','1','1'},
		{'e','1','0','1','0','0','0','1','0','1'},
		{'0','0','0','1','0','0','0','1','0','1'},
		{'0','1','0','0','0','1','1','0','0','1'},
		{'1','0','0','0','1','0','0','0','0','1'},
		{'1','0','0','0','1','0','0','0','0','1'},
		{'1','0','0','0','0','0','1','0','1','1'},
		{'1','0','1','1','1','0','1','1','0','1'},
		{'1','1','0','0','0','0','0','0','0','x'},
		{'1','1','1','1','1','1','1','1','1','1'}
};


typedef struct {
	short r;
	short c;
}element;
element here = { 1,0 };
element entry = { 1,0 };
// 구조체용
typedef struct {
	element data[MAX];
	int top;
}StackType;


// 비어있을 때
int isEmpty(StackType *s)
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
		return;
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
		return;
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
/*
int Eval(char exp[]) {
	int op1 = 0;
	int op2 = 0;

	// string 길이 
	int len = strlen(exp);
	char ch;
	StackType s;
	Init_Stack(&s);


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
				Push(&s, (op1 + op2));

			}
			else if (ch == '-')
			{
				Push(&s, (op1 - op2));

			}
			else if (ch == '*') {
				Push(&s, (op1 - op2));

			}
			else if (ch == '/') {
				Push(&s, (op1 / op2));

			}
			else {
				printf("잘못된 기호가 들어가 있습니다\n");
				return 0;
			}
		}
	}
	return Pop(&s);
}

int prec(char op)
{
	switch (op) {
	case'(':case')':return 0; break;
	case'+':case'-':return 1; break;
	case'*':case'/':return 2; break;
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
	
	for (int i = 0; i < len; i++)
	{
		ch = exp[i];
		switch (ch) {
		case '+':case'-':case'*':case'/':
			while (!isEmpty(&s) && (prec(ch) <= prec(peek(&s)))) {
				printf("%c", Pop(&s));
				Push(&s, ch);
				break;
			}
		case'(':
			Push(&s, ch);
			break;
		case')':
			top_op = Pop(&s);
			while (top_op != '(') {
				printf("%c", top_op);
				top_op = Pop(&s);
			}
			break;
			
		default:
			printf("%c", ch);
			break;
		}
	}
	int index = 0;
	while (!isEmpty(&s)) {
		str[index] = Pop(&s);
		printf("%c", str[index]);
		index++;	
	}
		
}

*/


// 0 미만이거나 1 초과일 경우
void push_loc(StackType* s, int r, int c) {
	if (r < 0 || c < 0) return;
	if (maze[r][c] != '1' && maze[r][c] != '.') {
		element tmp;
		tmp.r = r;
		tmp.c = c;
		Push(s, tmp);
	}
}



void maze_print(char maze[MAZE_SIZE][MAZE_SIZE])
{
	printf("\n");
	for (int r = 0; r < MAZE_SIZE; r++) {
		for (int c = 0; c < MAZE_SIZE; c++) {
			printf("%c", maze[r][c]);
		}
		printf("\n");
	}
}


int main() 
{
	int r, c;
	StackType s;
	Init(&s);
	here = entry;
	while (maze[here.r][here.c] != 'x') {
		r = here.r;
		c = here.c;
		maze[r][c] = '.';
		maze_print(maze);

		//0 1
		push_loc(&s, r - 1, c);
		push_loc(&s, r + 1, c);
		push_loc(&s, r, c - 1);
		push_loc(&s, r, c + 1);

		if (isEmpty(&s)) {
			printf("실패\n");
			return;
		}
		else
		{
			here = Pop(&s);
			if (maze[here.r][here.c] == '.') {
				count++;
			}
		}
	}

	printf("Success\n");
	printf("Back count :  %d\n", count);

	return 0;
}