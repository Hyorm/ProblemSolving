#include <cstdio>

using namespace std;

int main(){
	int P[1001];
	long long DP[1001];
	int N;
	scanf("%d", &N);
	for(int i = 1 ; i <= N; i++){
		scanf("%d", &P[i]);
	}
	DP[0] = 0;
	for(int i = 1 ; i <= N; i++){
		DP[i] = P[i];
		for(int j = 1 ; j <= i; j++){
			DP[i] = (P[j]+DP[i-j]<DP[i])?P[j]+DP[i-j]:DP[i];
		}
	}
	printf("%lld\n", DP[N]);
}
