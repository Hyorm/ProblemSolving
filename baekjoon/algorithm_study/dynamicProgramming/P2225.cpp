#include <cstdio>
using namespace std;
long long D[201][201];
int main(){
	int N, K;
	scanf("%d %d", &N, &K);
	for(int i = 0; i <= N; i++)D[1][i] = 1;

	for(int i = 1; i <= K; i++){
		for(int j = 0; j <= N; j++){
			for(int l = 0; l<=j; l++){
				D[i][j] += D[i-1][j-l];
				D[i][j]%=1000000000;
			}
		}
	}
	printf("%lld\n", D[K][N]);
}
