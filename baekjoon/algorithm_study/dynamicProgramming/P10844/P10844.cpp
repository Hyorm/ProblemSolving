#include <stdio.h>

using namespace std;

int main(int argc, char** argv){
	int N;
	long long memo[101][10];
	scanf("%d", &N);
	memo[1][0] = 0;
	for(int i = 1; i <= 9; i++){
		memo[1][i] = 1;
	}

	for(int i = 2; i <= N; i++){
		for(int j = 0; j <= 9; j++){
			memo[i][j] = 0;
			if(j-1 >= 0)memo[i][j] += memo[i - 1][j - 1];
			if(j+1 <= 9)memo[i][j] += memo[i - 1][j + 1];
			memo[i][j] = memo[i][j] % 1000000000;
		}
	}

	long long answer = 0;
	for(int i = 0; i <= 9; i++){
		answer += memo[N][i];
	}
	printf("%lld\n", answer%1000000000);
}
