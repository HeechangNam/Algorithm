/*
A,B 입력받고 B-A-1 함(A~B까지의 층수에다가 0층이 없으므로 -1)
0~|A|까지의 4가 들어가는 층수 , 0~|B|까지의 4가 들어가는 층수를 각각 뺌

*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define SUBMIT 1


long long A, B;
long long a, b;
long long result;

long long calc(long long input) {
	long long output, num, degree;
	int temp;
	
	if (input > 0)
		num = input;
	else
		num = -input;

	output = 0;
	degree = 1;
	while (num != 0) {
		temp = num % 10;
		num /= 10;

		if (degree == 1) {
			if (temp > 4)
				output = 1;
			else
				output = 0;
		}
		else {
			output += temp * degree / 10;
		}

		degree *= 10;
		
	}
	return output;
}

int main(void)
{
	int test_case;
	int T;

#if SUBMIT
	freopen("input.txt", "r", stdin);
#endif

	setbuf(stdout, NULL);
	scanf("%d", &T);

	for (test_case = 1; test_case <= T; ++test_case)
	{
		scanf("%lld %lld\n", &A, &B);
		result = B - A - 1;
		a = calc(A);
		b = calc(B);
		result -= a + b;

		printf("#%d %lld\n", test_case, result);
	}
	return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}