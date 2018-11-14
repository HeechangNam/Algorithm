#include <stdio.h>
#include <stdlib.h>

int* input;

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
			while (input[i] <= input[pivot] && i < last)
			{
				i++;
			}
			while (input[j] > input[pivot])
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

		quickSort(first, j - 1);
		quickSort(j + 1, last);
	}
}

int main() {

	int n;
	int mid;
	int i,j;

	scanf("%d", &n);
	input = (int*)malloc(sizeof(int) * n);
	mid = (n / 2);
	for (i = 0; i < n - 1; i++) {
		scanf("%d ", &input[i]);
	}
	scanf("%d", &input[i]);

	quickSort(0, n - 1);

	printf("%d", input[mid]);
}