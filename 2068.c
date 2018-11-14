#include <stdio.h>

int main() {
	
	int t, T;
	int aray[10];
	int ans;
	int i;

	scanf("%d", &T);
	for (t = 0; t < T; t++) {

		for (i = 0; i < 9; i++) {
			scanf("%d ", &aray[i]);
		}
		scanf("%d", &aray[9]);

		ans = aray[0];
		for (i = 1; i < 10; i++) {
			if (ans < aray[i])
				ans = aray[i];
		}

		printf("#%d %d\n", t + 1, ans);
	}

	return 0;
}