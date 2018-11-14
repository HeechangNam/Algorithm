#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

int N;
typedef struct star {
	double x;
	double y;
}star;

star* stars;

double min_sum;

double distance(star a, star b) {
	return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

double calc(int i, double num) {

	double dist;

	for (int j = 0; j < N; j++) {
		if (j != i) {
			dist = distance(stars[i], stars[j]);
			num = num < dist ? num : dist;
		}
	}

	return num;
}

int main() {

	double min;

	scanf("%d", &N);
	stars = (star*)malloc(sizeof(double) * N);
	for (int i = 0; i < N; i++) {
		scanf("%lf %lf", &stars[i].x, &stars[i].y);
	}

	min_sum = 0.0;
	for (int i = 0; i < N; i++) {
		min = calc(i, DBL_MAX);
		min_sum += min;
	}

	printf("%.2lf\n", min_sum);

	return 0;
}