#include <stdio.h>

using namespace std;

int f(int x){//too slow to use up to 30
	if(x < 2)return 1;
	return f(x - 1) + f(x - 2);
}

int main(int argc, char** argv){
	int n;
	scanf("%d", &n);
	int dp[1001];
	dp[0] = 1;
	dp[1] = 1;
	for(int i = 2; i <= n; i++){
		dp[i] = dp[i-1] + dp[i-2];
		dp[i] %= 10007;
	}

	printf("%d\n",dp[n]);
}
