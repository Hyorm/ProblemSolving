#include <cstdio>
using namespace std;
int N;
int D[100001];
long long A[100001][2];
int main(){
	scanf("%d", &N);
	for(int i = 0; i < N; i++){
		scanf("%d", &D[i]);
	}
	long long max = D[0];
	A[0][0] = D[0];
	A[0][1] = D[0];
	for(int i = 1; i < N; i++){
		A[i][0] = (D[i]+A[i-1][0]>D[i])?D[i]+A[i-1][0]:D[i];
		A[i][1] = (A[i-1][0]>A[i-1][1]+D[i])?A[i-1][0]:A[i-1][1]+D[i];
		long long tmp = (A[i][0]>A[i][1])?A[i][0]:A[i][1];
		if(tmp>max)max = tmp;
	}
	printf("%lld\n", max);
}
