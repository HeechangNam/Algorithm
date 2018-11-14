#include <stdio.h>


void printyear(int num) {
	if (num < 10)
		printf("000%d", num);
	else if (num < 100)
		printf("00%d", num);
	else if (num < 1000)
		printf("0%d", num);
	else
		printf("%d", num);
}
void print(int num) {
	if (num < 10)
		printf("0%d", num);
	else
		printf("%d", num);
}
int main() {
	
	int t, T;
	int date;
	int year, month, day;
	int flag ;

	scanf("%d", &T);
	for (t = 0; t < T; t++) {

		scanf("%d", &date);

		day = date % 100;

		date = date / 100;

		month = date % 100;
		year = date / 100;

		flag = 1;
		if ((month < 1) || (month > 12))
			flag = 0;

		if ((flag == 1)) {
			if ((month == 4) || (month == 6) || (month == 9) || (month == 11)) {
				if ((day < 1) || (day > 30))
					flag = 0;
			}
			else if (month == 2) {
				if ((day < 1) || (day > 28))
					flag = 0;
			}
			else {
				if ((day < 1) || (day > 31))
					flag = 0;
			}
		}

		printf("#%d ", t + 1);
		if (flag == 0)
			printf("-1\n");
		else {
			printyear(year);
			printf("/");
			print(month);
			printf("/");
			print(day);
			printf("\n");
		}
		
	}
}