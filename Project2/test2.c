#include <stdio.h>
#include <stdlib.h>


double recursion(int a)
{

}


double Iterator(int a) 
{
	double result = (double)a;
	for (int i = a-1; i >= 1; i--)
	{
		result = result * a;
	}

	return result;
}



int main() 
{
	double result_iter = Iterator(20);
	double result_rec = 0.0f;
}