#include <stdio.h>


int pow(int i, int j) {
	int k;
	int result;

	result = i;
	for (k = 1; k < j; k++) {
		result *= i;
	}

	return result;
}
int main() {

	int t, T;
	int N;
	int i;
	int sum;

	scanf("%d", &T);

	for (t = 0; t < T; t++) {
		
		scanf("%d", &N);

		sum = 0;
		for (i = 1; i <= N; i++) {
			sum -= i * (pow(-1, i));
		}
		printf("#%d %d\n", t + 1, sum);
	}

}