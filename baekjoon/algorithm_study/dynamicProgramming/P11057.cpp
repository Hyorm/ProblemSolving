#include <cstdio>
#include <memory.h>
using namespace std;
int D[1001][10];
int main(){
	int D[1001][10];
	int N;
	scanf("%d", &N);
	for(int i = 0; i < 10;i++){
		D[0][i] = 1;
	}
	for(int i = 1; i < N;i++){
		for(int j = 0; j < 10; j++){
			D[i][j] = 0;
			for(int k = j; k <10; k++){
				D[i][j]= (D[i][j]+D[i-1][k])%10007;
			}
		}
	}
	long long ans = 0;
	for(int i = 0; i < 10;i++){
		ans=(ans+D[N-1][i])%10007;
	}
	printf("%lld\n", ans);
}
