#include <stdio.h>

#define MAX 1000001

long long f[MAX];
long long sum[MAX];
void get_f(int X)
{
	for (int i = 1; i*i <= X; i++)
	{
		if (X%i == 0)
		{
			if (i % 2 == 1)
				f[X] += i;

			if (i != (X / i)) {
				if ((X / i) % 2 == 1)
					f[X] += (X / i);
			}
		}
	}
}

int main()
{
	int test_case;
	int T;
	int L, R;
	long long ans;

	freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);
	scanf("%d", &T);


	for (int i = 1; i < MAX; i++)
	{
		get_f(i);
		sum[i] += (sum[i - 1] + f[i]);
	}

	for (test_case = 1; test_case <= T; ++test_case)
	{

		scanf("%d %d", &L, &R);


		printf("#%d %lld\n", test_case, sum[R] - sum[L - 1]);

	}
	return 0;
}