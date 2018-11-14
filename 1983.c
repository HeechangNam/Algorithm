#include <stdio.h>
#include <stdlib.h>

void quickSort(double* input, int first, int last)
{
	int pivot;
	int i;
	int j;
	double temp;

	if (first < last)
	{
		pivot = first;
		i = first;
		j = last;

		while (i < j)
		{
			while (input[i] >= input[pivot] && i < last)
			{
				i++;
			}
			while (input[j] < input[pivot])
			{
				j--;
			}
			if (i < j)
			{
				temp = input[i];
				input[i] = input[j];
				input[j] = temp;
			}
		}

		temp = input[pivot];
		input[pivot] = input[j];
		input[j] = temp;

		quickSort(input, first, j - 1);
		quickSort(input, j + 1, last);
	}
}

int main() {

	int t, T;
	int n, k;
	double K;
	double* score;
	int rank, per;
	int i;
	int mid, fin, report;
	char grade[10][3] = { "A+", "A0", "A-", "B+", "B0", "B-", "C+", "C0", "C-", "D0" };

	scanf("%d", &T);

	for (t = 0; t < T; t++) {

		scanf("%d %d", &n, &k);

		score = (double*)malloc(sizeof(double) * n);

		for (i = 0; i < n; i++) {
			scanf("%d %d %d", &mid, &fin, &report);
			score[i] = (mid*0.35) + (fin*0.45) + (report*0.2);
		}

		K = score[k - 1];
		quickSort(score, 0, n - 1);

		rank = 0;
		while (1) {
			if ((K == score[rank]) || (rank > n))
				break;
			rank++;
		}

		per = (rank / (double)n) * 10;
		printf("#%d %s\n", t + 1, grade[per]);
	}

	return 0;
}