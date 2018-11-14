#include <stdio.h>

int main() {
	int n;
	int ans;
	int i;

	scanf("%d", &n);
		ans = 0;
	for (i = 0; i < 3; i++) {
		ans += n % 10;
		n = n / 10;
	}
	ans += n;

	printf("%d\n", ans);
	
}