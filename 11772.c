#include <stdio.h>

long long power(int integer, int pot) {
	long long output = 1;
	for (int i = 0; i < pot; i++) {
		output *= integer;
	}

	return output;
}

int main() {

	int N,num;
	int integer, pot;
	long long ans = 0;

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		pot = num % 10;
		integer = num / 10;
		ans += power(integer, pot);
	}

	printf("%lld\n", ans);
	return 0;
}