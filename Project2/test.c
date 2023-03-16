#include <stdio.h>
#include <stdlib.h>


void hanoi_tower(int n,  char one, char two, char three) 
{
	if (n == 1) printf("원한 1을 %c 에서 %c으로 옮긴다.\n", one, three);
	else {
		// (3, A, C ,B) => 원판 4를 A에서 C로 옮긴다.
		// (2, A, B, C) => 원판 3을 A에서 B로 옮긴다.
		hanoi_tower(n - 1, one, three, two);
		printf("원판 %d을 %c 에서 %c으로 옮긴다.\n", n, one, three);
		hanoi_tower(n - 1, three, one, two);
	}
}
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

	return result;
}

// 맨 마지막 가장 큰 원판을 최우선으로 옮김
// 각자 하나씩 옮기고 다음 위에 쌓고
// 
// 메인 스레드
int main() {
	int n = 20;
	double result_rec = factorial_rec(n);
	double result_iter = factorial_iter(n);
	printf("Iterative factorial result: %0.f\n Recursive factorial result: %0.f", result_iter, result_rec);
	return 0;
}