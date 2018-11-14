#include <stdio.h>

int main() {

	long long seq[68];
	int T, t;
	int i, n;

	seq[0] = 1;
	seq[1] = 1;
	seq[2] = 2;
	seq[3] = 4;
	for (i = 4; i < 68; i++) {
		seq[i] = seq[i - 1] + seq[i - 2] + seq[i - 3] + seq[i - 4];
	}

	scanf("%d", &T);

	for (t = 0; t < T; t++) {
		scanf("%d", &n);
		printf("%lld\n", seq[n]);
	}
	

	return 0;
}