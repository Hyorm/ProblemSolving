#include <cstdio>
using namespace std;
int N;
int D[100001];
long long A[100001];
int main(){
	scanf("%d", &N);
	for(int i = 0; i <N; i++){
		scanf("%d", &D[i]);
	}
	long long max = D[0];
	A[0] = D[0];
	for(int i = 1; i < N; i++){
		A[i] = (A[i-1]+D[i]>D[i])?A[i-1]+D[i]:D[i];
		if(max<A[i])max = A[i];
	}
	printf("%lld\n", max);
}
