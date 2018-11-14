#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long long a;
long long b;

int num[19];

int cnt = 0;

int main() {

	scanf("%lld %lld", &a, &b);

	for (long long i = a; i <= b; i++) {
		int max;
		int dex = 0;
		long long n = i;
		while (n > 9) {
			num[dex] = n % 10;
			n = n / 10;
			dex++;
		}
		num[dex++] = n;
		max = dex;

		int flag = 0;
		for (int j = 0; j < max; j++) {
			if (num[j] == 0 || num[j] == 1 || num[j] == 8) {
				if (num[abs(max - j - 1)] != num[j]) {
					flag = 1;
					break;
				}
			}
			else if (num[j] == 2) {
				if (num[abs(max - j - 1)] != 5) {
					flag = 1;
					break;
				}
			}
			else if (num[j] == 5) {
				if (num[abs(max - j - 1)] != 2) {
					flag = 1;
					break;
				}
			}
			else {
				flag = 1;
				break;
			}	
		}
		if (flag == 0) {
			cnt++;
			printf("%lld\n", i);
		}
	}

	printf("%d\n", cnt);
	return 0;
}