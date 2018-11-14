#include <stdio.h>

int main() {
	
	char ans;
	int t, T;
	int n1, n2;

	scanf("%d", &T);
	for (t = 0; t < T; t++) {
		scanf("%d %d", &n1, &n2);

		if (n1 > n2)
			ans = '>';
		else if (n1 < n2)
			ans = '<';
		else
			ans = '=';

		printf("#%d %c\n", t + 1, ans);
	}
}