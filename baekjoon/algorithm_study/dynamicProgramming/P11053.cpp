#include <cstdio>
#include <memory.h>
using namespace std;
int N;
int D[1001];
int A[1001];
int main(){
	scanf("%d", &N);
	memset(A, -1, sizeof(int)*1001);
	for(int i = 0; i < N; i++){
		scanf("%d", &D[i]);
	}
	int max = 1;
	for(int i = 0; i < N; i++){
		A[i] = 1;
		for(int j = 0; j < i; j++){
			if(D[j]<D[i]&&A[i]<A[j]+1)A[i] = A[j]+1;
			if(D[j]==D[i]&&A[i]<A[j])A[i] = A[j];
		}
		if(A[i]>max)max = A[i];
	}
	printf("%d\n", max);
}
