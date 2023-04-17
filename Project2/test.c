#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX 100
#define MAZE_SIZE 10

char str[101];
int count = 0;
int turnUp = 0;
int check = 0;

// 미로의 전체 범위
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


typedef struct {
	element data[MAX];
	int top;
}StackType;


// Stack Empty Check
int isEmpty(StackType *s)
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

// 상 하 좌 우의 길 체크
void push_loc(StackType* s, int r, int c) {
	if (r < 0 || c < 0) return;
	// 막혔거나 지나온 길이 아닌 경우
	if (maze[r][c] != '1' && maze[r][c] != '.' && maze[r][c] != 'p') {
		element tmp;
		tmp.r = r;
		tmp.c = c;
		Push(s, tmp);
	}

	// 막히거나 지나온 길일 경우 check count를 증가시킴
	else {
		check++;
	}
}

// 이동할 때 마다 미로 상황을 출력하는 함수
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


// data의 근처까지 되돌아가는 함수
void BackPass(StackType* s, element data)
{
	element tmp;
		
	while (true)
	{
		if (isEmpty(&s)) break;
		// B Stack의 값을 계속해서 추출
		tmp = Pop(s);
		printf("Data 값 출력[%d, %d]\n", data.r, data.c);

		printf("tmp 값 출력[%d, %d]\n", tmp.r, tmp.c);
		// 원하는 위치까지 Pop을 했음
		if ((data.r == tmp.r && data.c == tmp.c) || ((data.r == tmp.r-1) && (data.c == tmp.c))
			||((data.r == tmp.r+1) && (data.c == tmp.c) || ((data.r == tmp.r)&&(data.c == tmp.c-1))
				|| (data.r == tmp.r) && (data.c == tmp.c+1)))
		{
			break;
		}
		// 원하는 위치까지 되돌아가지 못했을 경우 현재 위치에 P를 적고 지나왔던 길을 되돌아왔다는 표시를 해줌
		else {
			printf("here값 확인하기 [%d, %d]\n", here.r, here.c);
			maze[tmp.r][tmp.c] = 'p';
			maze_print(maze);
			count++;

		}
	}
}

// A Stack에서 쌓여있는 Data를 통해서 되돌아가야할 Dest를 찾는 메소드
element CheckPass(StackType* A) {

	element prevData;
	while (true)
	{	// Empty State까지 다다른 경우 해당 미로를 빠져나갈 수 없음을 판단하고 프로그램을 종료
		if (isEmpty(A))
		{
			printf("더 이상 움직일 수 있는 공간이 없습니다. 해당 미로는 목적지까지 갈 수 없게 설계되었습니다.\n");
			exit(1);
		}
		// 남아있는 잔존 데이터를 Pop
		prevData = Pop(A);

		// 상 하 좌 우의 데이터를 상세하게 검색 후 이동할 수 있는 공간이 있는지 확인하는 메소드
		if ((maze[prevData.r - 1][prevData.c] == '.' || maze[prevData.r - 1][prevData.c] == '1' || maze[prevData.r - 1][prevData.c] == 'p') &&
			(maze[prevData.r + 1][prevData.c] == '.' || maze[prevData.r + 1][prevData.c] == '1' || maze[prevData.r + 1][prevData.c] == 'p') &&
			(maze[prevData.r][prevData.c - 1] == '.' || maze[prevData.r][prevData.c - 1] == '1' || maze[prevData.r][prevData.c - 1] == 'p') &&
			(maze[prevData.r][prevData.c + 1] == '.' || maze[prevData.r][prevData.c + 1] == '1' || maze[prevData.r][prevData.c + 1] == 'p'))
		{
			;
		}
		// 계속해서 움직일 수 있는 공간임을 판단 시 
		else
		{
			// 이를 알리고
			printf("드디어 움직일 수 있는 공간 발견");
			
			// while문을 break하여 해당 값을 반환
			break;
		}
	}
	return prevData;
}

// Back 표시를 삭제해서 표시, 이 외의 방법으로는 StackType temp값 만을 출력하는 방식도 있지만 비슷할거 같기에 이 기능을 택함
void ConfirmMaze(char maze[MAZE_SIZE][MAZE_SIZE])
{
	printf("\n");
	for (int r = 0; r < MAZE_SIZE; r++) {
		for (int c = 0; c < MAZE_SIZE; c++) {
			if (maze[r][c] == 'p') maze[r][c] = '0';
			printf("%c", maze[r][c]);
		}
		printf("\n");
	}
}

int main() 
{
	int r, c;
	// 기본 미로를 이동하는 데이터를 관리하는 중점 스택
	StackType s;

	// 이동했던 경로만을 저장하는 스택
	StackType temp;

	Init(&temp);
	Init(&s);
	here = entry;

	while (maze[here.r][here.c] != 'x') {
		r = here.r;
		c = here.c;

		printf("[%d, %d]", r, c);
		maze[r][c] = '.';

		maze_print(maze);


		// 상 하 좌 우로 이동할 수 있는지 검증
		push_loc(&s, r - 1, c);
		push_loc(&s, r, c - 1);
		push_loc(&s, r + 1, c);
		push_loc(&s, r, c + 1);


		// check가 4라는 것은 상하좌우로 이동할 수 없는 상태를 의미
		if (check == 4)
		{
			// 최종적으로 움직일 수 있는 공간 좌표를 Get
			here = CheckPass(&s);
			// 되돌아온 길을 표시
			BackPass(&temp, here);
			// 그대로 s 스택의 값을 Pop하는 것을 방지하는 용도
			turnUp++;
		}

		// check가 4가 아닌 경우 이를 0으로 초기화
		check = 0;

		if (isEmpty(&s)) {
			printf("실패\n");
			return;
		}

		// s 스택이 비어있지 않는 경우
		else
		{
			// 되돌아왔던 상태가 아닐 시
			if (turnUp != 1) {
				// 해당 값을 현 위치로 저장
				here = Pop(&s);

				// 이동한 경로를 temp에 저장
				Push(&temp, here);
			}
		}
		// Back State 초기화
		turnUp = 0;
	}

	// 최종 최단 루트 출력 + 되돌아갔던 길 삭제
	ConfirmMaze(maze);
	printf("Success\n");
	// 초반 자신이 있던 위치는 BackCount로 취급하지 않기때문에 -1을함.
	printf("Back count :  %d\n", count-1);
	return 0;
}