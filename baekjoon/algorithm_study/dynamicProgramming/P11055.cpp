#include <cstdio>
using namespace std;
int N;
int D[1001];
long long A[1001];
int main(){
	scanf("%d", &N);
	for(int i = 0; i < N; i++){
		scanf("%d", &D[i]);
	}
	long long max = D[0];
	for(int i = 0; i < N; i++){
		A[i] = D[i];
		for(int j = 0; j < i; j++){
			if(A[i] < A[j]+D[i]&&D[i]>D[j])A[i] = D[i]+A[j];
			if(A[i] < A[j]&&D[i]==D[j])A[i] = A[j];
			if(max < A[i])max = A[i];
		}
	}
	printf("%lld\n", max);
}
