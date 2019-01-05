#include <stdio.h>
#include <string.h>

int main(void)
{
	int test_case;
	int T,i;
	char str[2501];
	int stack[5];
	int flag;

	freopen("input.txt", "r", stdin);
	
	setbuf(stdout, NULL);
	scanf("%d", &T);
	
	for (test_case = 1; test_case <= T; ++test_case)
	{	
		scanf("%s", &str);
		
		for (i = 0; i < 5; i++) {
			stack[i] = 0;
		}

		flag = 1;
		i = 0;
		while(i < strlen(str) && flag) {

			switch (str[i]) {
			case 'c' :
				stack[0]++;
				if (stack[4] > 0)
					stack[4]--;
				break;
			case 'r' :
				if (stack[0] > 0) {
					stack[0]--;
					stack[1]++;
				}
				else
					flag = 0;
				break;

			case 'o' :
				if (stack[1] > 0) {
					stack[1]--;
					stack[2]++;
				}
				else
					flag = 0;
				break;

			case 'a' :
				if (stack[2] > 0) {
					stack[2]--;
					stack[3]++;
				}
				else
					flag = 0;
				break;

			case 'k' :
				if (stack[3] > 0) {
					stack[3]--;
					stack[4]++;
				}
				else
					flag = 0;
				break;
			}

			i++;
		}

		for (i = 0; i < 4; i++) {
			if (stack[i] != 0)
				flag = 0;
		}

		printf("#%d %d\n", test_case, flag ? stack[4] : -1);

	}
	return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}