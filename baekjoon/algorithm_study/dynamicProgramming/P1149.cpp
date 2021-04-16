#include <cstdio>

using namespace std;
long long M[1001][3];
int main(){
	int N;
	scanf("%d", &N);
	scanf("%lld %lld %lld",&M[0][0], &M[0][1], &M[0][2]);
	for(int i = 1; i < N; i++){
		int R, G, B;
		scanf("%d %d %d", &R, &G, &B);
		M[i][0] = (M[i-1][1]>M[i-1][2])?M[i-1][2]:M[i-1][1];
		M[i][0] += R;
		M[i][1] = (M[i-1][0]>M[i-1][2])?M[i-1][2]:M[i-1][0];
		M[i][1] += G;
		M[i][2] = (M[i-1][0]>M[i-1][1])?M[i-1][1]:M[i-1][0];
		M[i][2] += B;
	}	
	printf("%lld\n", (M[N-1][0]>M[N-1][1])?(M[N-1][1]>M[N-1][2])?M[N-1][2]:M[N-1][1]:(M[N-1][0]>M[N-1][2])?M[N-1][2]:M[N-1][0]);
}
