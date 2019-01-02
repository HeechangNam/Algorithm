#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int test_case;
	int T;

	freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);
	scanf("%d", &T);

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N, K;
		int* array;
		double ans = 0.0;

		scanf("%d %d", &N, &K);
		array = (int*)malloc(sizeof(int) * N);
		for (int i = 0; i < N; i++) {
			scanf("%d", &array[i]);
		}

		for (int i = 0; i < N - 1; i++) {
			for (int j = 0; j < N - 1 - i; j++) {
				if (array[j] > array[j + 1]) {
					int temp = array[j];
					array[j] = array[j + 1];
					array[j + 1] = temp;
				}
			}
		}

		for (int i = N - K; i < N; i++) {
			ans = (ans + array[i]) / 2;
		}

		free(array);
		printf("#%d %lf\n", test_case, ans);
	}
	return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}