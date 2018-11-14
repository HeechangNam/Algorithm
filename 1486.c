/* 
check는 점원들의 합으로 만들어질 수 있는 숫자들을 체크한다. 
	ex) check[700] = true 이면, 점원들의 합으로 700을 만들 수 있다는 뜻
people은 점원들의 키를 저장한다.
max는 현재까지 점원들의 키를 더한 값 중 최대값을 저장한다.

1. 
people의 1부터 N까지의 순서로 진행
max부터 시작해서 줄어들면서 check[j]가 참이면, check[j+people[i]]도 참
max는 += people[i]를 해준다.
check[people[i]]도 참으로 바꿈.

2.
check[B]부터 참인 값을 찾는다.

*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool* check;
int* people;
int max;

int main() {
	
	int t, T;
	int N, B;
	bool flag = true;
	int result;
	int i;

	freopen("input.txt", "r", stdin);

	scanf("%d", &T);
	for (t = 1; t <= T; t++) {
		scanf("%d %d", &N, &B);
		
		check = (bool*)malloc(sizeof(bool)*(N * 10000 + 1));
		people = (int*)malloc(sizeof(int) * N);

		for (i = 1; i <= N; i++) {
			scanf("%d", &people[i]);
			check[i] = false;
		}
		for (i = N + 1; i <= N * 10000; i++) {
			check[i] = false;
		}

		max = 0;
		for (i = 1; i <= N; i++) {
			for (int j = max; j > 0; j--) {
				if (check[j] == true) {
					check[j + people[i]] = true;
				}
			}
			max += people[i];
			check[people[i]] = true;
		}

		i = B; flag = true;
		while (flag) {
			if (check[i] == true) {
				result = i;
				flag = false;
			}
			i++;
		}

		printf("#%d %d\n", t, result-B);
	}
	return 0;
}