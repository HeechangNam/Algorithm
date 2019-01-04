#include <stdio.h>
  
int dp[10001][16];
  
int main(void)
{
    int test_case;
    int T;
  
    setbuf(stdout, NULL);
    scanf("%d", &T);
  
    for (test_case = 1; test_case <= T; ++test_case)
    {
        char str[10001];
        int day = 1;
        int result = 0;
          
        scanf("%s", str);
          
        for (int i=0; i<10001; i++) {
            for (int j=0; j<16; j++) {
                dp[i][j] = 0;
            }
        }
          
        dp[0][1] = 1;
          
        while (str[day-1] != '\0') {
            int director = 1 << (str[day-1] - 'A');
              
            for (int i=1; i<16; i++) {
                for (int j=1; j<16; j++) {
                    if ((i & director) > 0 && (i & j) > 0) {    //director and key
                        dp[day][i] += dp[day-1][j];
                        dp[day][i] %= 1000000007;
                    }
                }
            }
              
            day += 1;
        }
          
        for (int i=1; i<16; i++) {
            result += dp[day-1][i];
            result %= 1000000007;
        }
          
        printf("#%d %d\n", test_case, result);
    }
      
    return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}
