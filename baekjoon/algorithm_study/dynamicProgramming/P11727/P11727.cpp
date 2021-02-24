#include <stdio.h>

using namespace std;

int memo[1001];

int f(int x){
	if(x < 2)return 1;
	
	if(memo[x] > 0)return memo[x];

	memo[x] = (2 * f(x-2) + f(x - 1))%10007;
	return memo[x];
}

int main(int argc, char** argv){
	int N;
	scanf("%d", &N);
	printf("%d\n", f(N));
	return 0;
}
