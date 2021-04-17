#include <cstdio>

using namespace std;

int N, M;

void find(int d, int b, int* A){
	if(d >= M){
		for(int i = 0; i < d; i++){
			printf("%d ", A[i]);
		}
		printf("\n");
	}
	else{
		for(int i = b+1; i <= N; i++){
			A[d] = i;
			find(d+1, i, A);
		}
	}
}

int main(){
	scanf("%d %d",&N, &M);
	for(int i = 1; i <= N; i++){
		int* A = new int[N];
		A[0] = i;
		if(M>1)find(1, i, A);
		else printf("%d\n", i);
	}
}
