#include <stdio.h>
#include <math.h>

int main() {
	int T;
	int ans;

	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		int x1, y1, r1, x2, y2, r2;
		double dist;
		int sum;
		int diff;
		scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);

		dist = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
		sum = r1 + r2;
		diff = abs(r1 - r2);

		if (dist == 0) {
			if (r1 == r2)
				ans = -1;
			else
				ans = 0;
		}
		else if (sum > dist && diff < dist) {
			ans = 2;
		}
		else if (sum == dist || diff == dist) {
			ans = 1;
		}
		else if (sum < dist || diff > dist) {
			ans = 0;
		}
		printf("%d\n", ans);
	}

	
	return 0;
}