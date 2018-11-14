/*
우선 B를 내림차순으로 정렬함.
A를 기준으로 앞에서 부터 B[b]들과 비교를 함.
A[a]이상인 B[b]들의 갯수를 카운트해서 vote[a]에 저장한다. A[a+1]는 B[b+1]부터 비교한다.
vote의 값 중 가장 큰 값의 인덱스+1 값 출력

*/

#include <stdio.h>
#include <stdlib.h>

int N, M;
int* A;
int* B;
int* vote;

void quickSort(int first, int last)
{
	int pivot;
	int i;
	int j;
	int temp;

	if (first < last)
	{
		pivot = first;
		i = first;
		j = last;

		while (i < j)
		{
			while (B[i] >= B[pivot] && i < last)
			{
				i++;
			}
			while (B[j] < B[pivot])
			{
				j--;
			}
			if (i < j)
			{
				temp = B[i];
				B[i] = B[j];
				B[j] = temp;
			}
		}

		temp = B[pivot];
		B[pivot] = B[j];
		B[j] = temp;

		quickSort(first, j - 1);
		quickSort(j + 1, last);
	}
}

int main(void)
{
	int test_case;
	int T;
	int b;
	int result;
	

	 freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);
	scanf("%d", &T);

	for (test_case = 1; test_case <= T; ++test_case)
	{
		scanf("%d %d", &N, &M);
		A = (int*)malloc(sizeof(int) * N);
		vote = (int*)malloc(sizeof(int) * N);
		B = (int*)malloc(sizeof(int) * M);

		for (int i = 0; i < N; i++) {
			scanf("%d", &A[i]);
			vote[i] = 0;
		}
			
		for (int i = 0; i < M; i++)
			scanf("%d", &B[i]);

		quickSort(0, M - 1);

		b = 0;
		for (int a = 0; a < N; a++) {
			while (A[a] <= B[b]) {
				vote[a]++;
				b++;
			}
		}

		result = 0;
		for (int i = 0; i < N; i++) {
			if (vote[result] < vote[i]) {
				result = i;
			}
		}
		printf("#%d %d\n", test_case, result + 1);

	}
	return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}