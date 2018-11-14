#include <stdio.h>

int calcA(int p, int w) {

	return (p*w);
}

int calcB(int q, int r, int s, int w) {

	int result;
	int over;

	if (r >= w)
		result = q;
	else {
		over = w - r;

		result = q + (s*over);
	}

	return result;
}

int main() {

	int t, T;
	int p, q, r, s, w;
	int a, b;
	int ans;

	scanf("%d", &T);

	for (t = 0; t < T; t++) {

		scanf("%d %d %d %d %d", &p, &q, &r, &s, &w);

		a = calcA(p, w);
		b = calcB(q, r, s, w);

		if (a <= b)
			ans = a;
		else
			ans = b;

		printf("#%d %d\n", t + 1, ans);;
	}

	return 0;
}