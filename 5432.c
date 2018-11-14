/*
레이저를 쏘았을 때 현재 막대기가 얼마나 깔려있는지를 체크한다.
stack을 사용!
입력데이타가 (이면 스택에 쌓는다.
)일때, 이전 값에 따라서 처리를 해준다음
	(이면 레이저가 쏘였다는 뜻 -> top의 인덱스를 보고 쌓인 막대기의 수 만큼 조각이 생긴다
	)이면 막대기가 끝났다는 뜻 -> 조각이 하나 생긴다
현재 top의 (를 pop한다.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char input[100000];
int input_size;

char* stack;
int top;

void push(char* stack, char data) {
	top++;
	stack[top] = data;
}
void pop(char* stack) {
	top--;
}

int empty(char* stack) {
	if (top == 0)
		return 1;
	else
		return 0;
}

int main(void)
{
	int test_case;
	int T;
	int ans;
	int flag; // 이전 데이터가 (인지 )인지 구분

	freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);
	scanf("%d", &T);

	for (test_case = 1; test_case <= T; ++test_case)
	{
		scanf("%s", &input);
		input_size = strlen(input);

		stack = (char*)malloc(sizeof(char) * input_size);
		ans = top = 0;

		for (int i = 0; i < input_size; i++) {
			char temp = input[i];
			if (temp == '(') {
				push(stack, temp);
				flag = 0;
			}
			else {
				pop(stack);
				if (flag == 0) {
					ans += top;
				}
				else {
					ans++;
				}
				flag = 1;
			}
		}
		free(stack);

		printf("#%d %d\n", test_case, ans);
	}
	return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}