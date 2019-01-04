#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(void)
{
	int test_case;
	int T;
	
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &T);

	for (test_case = 1; test_case <= T; ++test_case)
	{
		char str[10000];
		bool yeday[4] = { true,true,true,true };
		bool today[4] = { true,false,false,false };
		int mask;
		int ans = 1;
		int temp = 1;
		int except = 0;

		scanf("%s", &str);
		for (int i = 0; i < strlen(str); i++) {
			today[str[i] - 'A'] = true;
			
			temp = 1;
			for (int j = 0; j < 4; j++) {
				if (today[j] == false)
					temp *= 2;
			}

			if (i != 0) {
				mask = 0;
				for (int j = 0; j < 4; j++) {
					if (yeday[j] == true && yeday[j] == today[j])
						break;
					if (!(yeday[j] || today[j]))
						mask++;
				}

				switch (mask) {
				case 0:
					except = 0;
					break;
				case 1:
					except = 3;
					break;
				case 2:
					except = 9;
					break;
				}
			}

			for (int j = 0; j < 4; j++) {
				yeday[j] = today[j];
				today[j] = false;
			}
			ans *= temp;
			ans -= except;
		}
		printf("#%d %d\n", test_case, ans % 1000000007);

	}
	return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}