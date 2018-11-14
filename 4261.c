/*
strings[N][1000]에 주어진 문자열을 다 저장한다.

number의 숫자가 각 문자열의 글자와 매치되는지 비교한다.
매치가 되지 않으면 flag를 differ로 바꾼다.
비교할 떄는 flag가 same인 문자열들만 비교
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define same 1
#define differ 0

char** strings;
int* flags;

char numbers[1001];
int num_len;
int str_len;

int N;
int result;
char match(char c) {
	char ans;
	switch (c) {
	case 'a': case 'b': case 'c':
		ans = '2';
		break;
	case 'd': case 'e': case 'f':
		ans = '3';
		break;
	case 'g': case 'h': case 'i':
		ans = '4';
		break;
	case 'j': case 'k': case 'l':
		ans = '5';
		break;
	case 'm': case 'n': case 'o':
		ans = '6';
		break;
	case 'p': case 'q': case 'r': case 's':
		ans = '7';
		break;
	case 't': case 'u': case 'v':
		ans = '8';
		break;
	case 'w': case 'x': case 'y': case 'z':
		ans = '9';
		break;
	}

	return ans;
}

int main(void)
{
	int test_case;
	int T;
	
	freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);
	scanf("%d", &T);
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		scanf("%s %d\n", &numbers, &N);
		num_len = strlen(numbers);
		strings = (char**)malloc(sizeof(char*) * N);
		flags = (int*)malloc(sizeof(int) * N);

		for (int i = 0; i < N; i++) {
			strings[i] = (char*)malloc(sizeof(char) * 1001);
			scanf("%s", strings[i]);
			str_len = strlen(strings[i]);

			if (str_len == num_len)
				flags[i] = same;
			else
				flags[i] = differ;
		}

		num_len = strlen(numbers);
		for (int i = 0; i < num_len; i++) {
			for (int j = 0; j < N; j++) {
				if (flags[j] == same) {
					if (numbers[i] != match(strings[j][i]))
						flags[i] = differ;
				}
			}
		}

		result = 0;
		for (int i = 0; i < N; i++) {
			free(strings[i]);
			if (flags[i] == same)
				result++;
		}
			
		free(strings); free(flags);
		printf("#%d %d\n", test_case, result);
	}
	return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}