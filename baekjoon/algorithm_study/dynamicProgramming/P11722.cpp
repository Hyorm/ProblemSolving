#include <cstdio>
using namespace std;
int N;
int D[1001];
int A[1001];
int main(){
	scanf("%d", &N);
	for(int i = 0; i < N; i++){
		scanf("%d", &D[i]);
	}
	int max = 1;
	for(int i = N-1; i>= 0; i--){
		A[i] = 1;
		for(int j = N-1; j > i; j--){
			if(A[i]<A[j]+1&&D[i]>D[j])A[i] = A[j]+1;
			if(A[i]<A[j]&&D[i]==D[j])A[i] = A[j];
			if(A[i]>max)max = A[i];
		}
	}
	printf("%d\n", max);
}
