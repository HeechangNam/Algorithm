#include <stdio.h>
#include <string.h>

int main() {
	
	char buff[12];
	int t, T;
	int flag, ans;
	int strn;
	int i;

	scanf("%d", &T);
	for (t = 0; t < T; t++) {
		
		scanf("%s", &buff);
		strn = strlen(buff);

		flag = 0;
		for (i = 0; i < strn / 2; i++) {
			if (buff[i] != buff[strn - 1 - i])
				flag++;
		}

		ans = 0;
		if (flag == 0) ans = 1;

		printf("#%d %d\n", t + 1, ans);
	}
}