/*
H[i]는 hi들의 값을 저장한다.
Dp[i]는 hi까지의 우뚝 선 산이 될 수 있는 구간의 갯수를 저장한다.
curve는 구간의 추세를 결정한다. 커지고 있는 추세면 UP, 작아지고 있으면 DOWN
check는 구간의 시작점이 될 수 있는 값을 저장한다.

i<j일때, dp[j] = dp[i]이고, curve[i]==curve[j]이면 check += 1; 아니면 check = 0; 
i>j이면, dp[j] = dp[i] + check;
*/
#include <stdio.h>
#include <stdlib.h>

#define UP 1
#define DOWN 0

int* H;
int* DP;
int* curve;
int check;

int main(void)
{
	int test_case;
	int T;

	int N;
	
	freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);
	scanf("%d", &T);
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		scanf("%d", &N);
		
		H = (int*)malloc(sizeof(int) * N);
		DP = (int*)malloc(sizeof(int) * N);
		curve = (int*)malloc(sizeof(int)*N);

		for (int i = 0; i < N; i++) {
			scanf("%d", &H[i]);
			if (i > 0) {
				if (H[i - 1] > H[i]) curve[i] = DOWN;
				else curve[i] = UP;
			}
			else
				curve[i] = UP;
		}

		DP[0] = 0;
		check = 0;
		for (int i = 1; i < N; i++) {
			if (curve[i] == UP) {
				DP[i] = DP[i - 1];
				if (curve[i - 1] == curve[i])
					check++;
				else
					check = 1;
			}
			else {
				DP[i] = DP[i - 1] + check;
			}
		}

		printf("#%d %d\n", test_case, DP[N - 1]);
	}
	return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}