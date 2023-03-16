#include <stdio.h>
#include <stdlib.h>


void hanoi_tower(int n,  char one, char two, char three) 
{
	if (n == 1) printf("���� 1�� %c ���� %c���� �ű��.\n", one, three);
	else {
		// (3, A, C ,B) => ���� 4�� A���� C�� �ű��.
		// (2, A, B, C) => ���� 3�� A���� B�� �ű��.
		hanoi_tower(n - 1, one, three, two);
		printf("���� %d�� %c ���� %c���� �ű��.\n", n, one, three);
		hanoi_tower(n - 1, three, one, two);
	}
}
// 0���� 100������ �Ҽ��� ���ϴ� �޼���
int Demical() 
{
	// ������ �������� ī���� �ϴ� �ʵ�
	int count = 0;

	// �Ҽ��� ���� �����ϴ� �ʵ�
	int result = 0;

	// 0�� 1�� �Ҽ��� �ƴϹǷ� �����ϰ� �ݺ������� 100���� 
	for (int i = 2; i < 101; i++) {
		// count �ʱ�ȭ
		count = 0;

		// 0���� ���� ���� �� ���⿡ 1���� �����Ͽ� �ش� �� ���� ����
		// �Ҽ��� 1�� �ڱ� �ڽŸ����� ������ ������
		for (int j = 1; j <= i; j++)
		{
			// ������ �������� count�� 1 �ø�
			if (i % j == 0) {
				count++;
			}

			// ������ �������� Ƚ���� 2 �̻��� ��� �ݺ����� ���
			if (count > 2)
			{
				break;
			}
		}
		
		// 2���� ������ ������ ��� result�� �ش� ���� ����
		if (count == 2) {
			result += i;
		}
	}
	// �ش� ��� result�� ��ȯ
	return result;
}

// ��� �Լ� ���
double factorial_rec(int n)
{
	if (n <= 1) return 1;
	else return n * factorial_rec(n - 1);
}

// �ݺ����� ����� �ݺ� ����
double factorial_iter(int n)
{
	// ���丮���� ��Ģ�� 1���� �����ؼ�
	double result = 1;

	// a��° ������ ����ؼ� ���ذ��� ���� ���
	for (int i = 1; i <= n; i++)
	{
		result *= i;
	}

	return result;
}

// �� ������ ���� ū ������ �ֿ켱���� �ű�
// ���� �ϳ��� �ű�� ���� ���� �װ�
// 
// ���� ������
int main() {
	int n = 20;
	double result_rec = factorial_rec(n);
	double result_iter = factorial_iter(n);
	printf("Iterative factorial result: %0.f\n Recursive factorial result: %0.f", result_iter, result_rec);
	return 0;
}