#include <cstdio>

using namespace std;

int D[1001];
int A[1001];
int N;
int main(){
	scanf("%d", &N);
	for(int i = 0; i < N; i++){
		scanf("%d", &D[i]);
	}
	int max = 1;
	for(int i = 0; i < N; i++){
		A[i] = 1;
		for(int j = 0; j < i; j++){
			if(A[i]<A[j]+1&&D[i]>D[j])A[i] = A[j]+1;
			if(A[i]<A[j]&&D[i]==D[j])A[i] = A[j]+1;
			if(max<A[i])max = A[i];
		}
	}
	int bf = 1001;
	printf("%d\n", max);
	for(int i = N-1; i > -1; i--){
		if(A[i]==max && D[i]<bf){
			A[i] = 1001;
			bf = D[i];
			max--;
		}
	}
	for(int i = 0; i < N; i++){
		if(A[i]==1001)printf("%d ",D[i]);
	}
}
