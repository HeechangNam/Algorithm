#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {

	int t, T;
	int strn = 30;
	char* str;
	char* stmt1;
	char* stmt2;
	int i;
	int flag;

	scanf("%d", &T);

	for (t = 0; t < T; t++) {

		str = (char*)malloc(sizeof(char) * (strn + 1));

		scanf("%s", str);

		
		for (i = 0; i < 10; i++) {
			flag = 1;
			stmt1 = (char*)malloc(sizeof(char) * (i + 2));
			stmt2 = (char*)malloc(sizeof(char) * (i + 2));
			
			strncpy(stmt1, str, (i + 1));
			stmt1[i + 1] = 0;

			strncpy(stmt2, &str[i + 1], (i + 1));
			stmt2[i + 1] = 0;

			flag = strcmp(stmt1, stmt2);
			
			free(stmt1);
			free(stmt2);

			if (flag == 0)
				break;
		}

		printf("#%d %d\n", t + 1, i + 1);;

		free(str);
	}

	return 0;
}