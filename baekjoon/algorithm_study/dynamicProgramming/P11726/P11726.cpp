#include <stdio.h>

using namespace std;
int memo[1001];
int f(int x){
	if(x < 2)return 1;
	if(memo[x] > 0){
		return memo[x];
	}
	memo[x] = f(x - 1) + f(x - 2);
	return memo[x];
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

	printf("%d\n",f(n));
}
