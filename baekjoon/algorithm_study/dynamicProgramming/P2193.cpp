#include <cstdio>

using namespace std;

int main(){
	long long D[91][2];
	int N;
	scanf("%d", &N);
	D[0][0] = 0;
	D[0][1] = 1;
	for(int i = 1; i<N; i++ ){
		D[i][0] = D[i-1][1]+D[i-1][0];
		D[i][1] = D[i-1][0];
	}
	printf("%lld\n", D[N-1][0]+D[N-1][1]);
}
