#include <stdio.h>
#include <stdlib.h>

//#define MAX(a,b) (((a) > (b))? (a):(b))
//#define DEGREE 10

typedef struct {
	// 행
	int row;
	// 열
	int col;
	// 값
	int value;
} element;


// 행렬 출력
void print_matrix(element *b)
{
	printf("The transposed matrix is:\n");

	for (int i = 1; i <= b[0].value; i++) {
		printf("%d %d %d\n", b[i].row, b[i].col, b[i].value);
	}
}

// 전치 메서드
void transpose(element *a, element *b) {
	b[0].col = a[0].row; 
	b[0].row = a[0].col; 
	b[0].value = a[0].value;
	
	int p = 1;

	// 값이 있는 경우 전치를 진행
	if (b[0].value > 0)
	{
		for(int i = 0; i < a[0].col; i++)
			for (int j = 1; j <= a[0].value; j++)
			{
				if (a[j].col == i)
				{
					b[p].row = a[j].col;
					b[p].col = a[j].row;
					b[p].value = a[j].value;
					p++;
				}
			}
	}
}

int main() {
	int row, col, index;
	
	printf("Enter the size of rows and columns, the number of non-zero terms: ");
	// 2차원 행렬의 행, 열, 0이 아닌 항의 값을 입력
	scanf_s("%d %d %d", &row, &col, &index);

	// 항의 개수에 충분하게 +1을 한 동적 메모리 할당을 하여 생성
	element* a = (element*)malloc(sizeof(element) * (index + 1));
	element* b = (element*)malloc(sizeof(element) * (index + 1));
	
	// 행렬 크기 저장
	a[0].row = row;
	a[0].col = col;
	a[0].value = index;

	printf("Enter row, column, and value pairs in order:\n");
	
	// 0이 아닌 항의 개수 만큼 2차원 행렬에 값을 입력
	for (int i = 1; i <= index; i++)
	{
		scanf_s("%d %d %d", &a[i].row, &a[i].col, &a[i].value);
	}

	// 전치 행렬 실행
	transpose(a, b);

	// 행렬 결과 출력
	print_matrix(b);

	// 동적 메모리 해제
	free(a);
	free(b);

	getch();
	return 0;
}
/*
*void hanoi_tower(int n,  char A, char B, char C) 
{
	if (n == 1) printf("원한 1을 %c 에서 %c으로 옮긴다.\n", A, C);
	else {
		hanoi_tower(n - 1, A, C, B);
		printf("원판 %d을 %c 에서 %c으로 옮긴다.\n", n, A, C);
		hanoi_tower(n - 1, C, A, B);
	}
}

void matrix_transpose(int A[ROWS][COLS], int B[ROWS][COLS]) 
{
	for (int r = 0; r < ROWS; r++)
	{
		for (int c = 0; c < COLS; c++)
		{
			B[c][r] = A[r][c];
		}
	}
}

typedef struct
{
	int degree;
	int coef[DEGREE];
}polynomials;

// 0부터 100까지의 소수를 구하는 메서드
int Demical() 
{
	// 나누어 떨어짐을 카운팅 하는 필드
	int count = 0;

	// 소수의 합을 저장하는 필드
	int result = 0;

	// 0과 1은 소수가 아니므로 제외하고 반복문으로 100까지 
	for (int i = 2; i < 101; i++) {
		// count 초기화
		count = 0;

		// 0으로 수를 나눌 수 없기에 1부터 시작하여 해당 수 까지 나눔
		// 소수는 1과 자기 자신만으로 나누어 떨어짐
		for (int j = 1; j <= i; j++)
		{
			// 나누어 떨어지면 count를 1 올림
			if (i % j == 0) {
				count++;
			}

			// 나누어 떨어지는 횟수가 2 이상일 경우 반복에서 벗어남
			if (count > 2)
			{
				break;
			}
		}
		
		// 2번만 나누어 떨어질 경우 result에 해당 수를 누적
		if (count == 2) {
			result += i;
		}
	}
	// 해당 결과 result를 반환
	return result;
}

// 재귀 함수 사용
double factorial_rec(int n)
{
	if (n <= 1) return 1;
	else return n * factorial_rec(n - 1);
}

// 반복문을 사용한 반복 구조
double factorial_iter(int n)
{
	// 팩토리얼의 규칙인 1부터 시작해서
	double result = 1;

	// a번째 값까지 계속해서 곱해가는 구조 사용
	for (int i = 1; i <= n; i++)
	{
		result *= i;
	}
	// 1부터 1, 2, 1, 본래 수, 리셋 1, 2, 1
	// 1 2 1 3 1 2 1 4 1 2 1 
	return result;
}
void hanoi_iter(int n, char A, char B, char C)
{
	while (n > 0)
	{
		for (int i = 0; i < n; i++)
		{
			if (n == 1)
			{
				printf("원판 1을 %c에서 %c으로 옮긴다.\n", A, C);
			}

			else if (n > 1)
			{
				n = n - 1;
			}
		}
	}
}

polynomials poly_add(polynomials A, polynomials B)
{
	polynomials C;

	C.degree = MAX(A.degree, B.degree);
	
	for (int i = 0; i < C.degree +1; i++)
	{
		C.coef[i] = A.coef[i];
		C.coef[i] += B.coef[i];
	}

	return C;
}

void matrix_print(int A[ROWS][COLS])
{
	printf("===================\n");
	for (int r = 0; r < ROWS; r++) {
		for (int c = 0; c < COLS; c++)
		{
			printf("%d ", A[r][c]);
		}
		printf("\n");
	}

	printf("===================\n");
}

void poly_print(polynomials C)
{
	for (int i = C.degree; i > 0; i--)
	{
		if (C.coef[i] == 0)
		{
			continue;
		}
		if (C.coef[i] == 1)
		{
			printf("x^%d + ", i);
			continue;
		}
		printf("%dx^%d + ", C.coef[i], i);
	}
	printf("%d\n", C.coef[0]);
}
*/