#include <stdio.h>

typedef struct timecard {
	int h;
	int m;
	int s;
}timecard;

int main() {
	timecard in[3];
	timecard out[3];
	timecard ans[3];

	for (int i = 0; i < 3; i++) {
		scanf("%d %d %d %d %d %d", &in[i].h, &in[i].m, &in[i].s, &out[i].h, &out[i].m, &out[i].s);

		if (out[i].s < in[i].s) {
			out[i].m--;
			out[i].s += 60;
		}
		ans[i].s = out[i].s - in[i].s;

		if (out[i].m < in[i].m) {
			out[i].h--;
			out[i].m += 60;
		}
		ans[i].m = out[i].m - in[i].m;

		ans[i].h = out[i].h - in[i].h;
	}

	for(int i = 0; i < 3; i++) 
		printf("%d %d %d\n", ans[i].h, ans[i].m, ans[i].s);
}