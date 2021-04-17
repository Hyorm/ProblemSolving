#include <cstdio>

using namespace std;

int main(){
	long long M[1001];
	int O[1001];
	int N;
	scanf("%d", &N);
	for(int i = 1; i <= N; i++){
		scanf("%d",&O[i]);
	}
	M[0] = 0;
	O[0] = 0;
	for(int i = 1; i <= N; i++ ){
		M[i] = 0;
		for(int j = 1; j <= i; j++ ){
			M[i] = (M[i]>M[i-j]+O[j])?M[i]:M[i-j]+O[j];
		}
	}
	printf("%lld\n", M[N]);
}
