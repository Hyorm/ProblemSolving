#include <cstdio>
#include <algorithm>
using namespace std;

int* A;
int* B;
int* C;
int N, M;
void merge(){
	int i = 0, j = 0, id = 0;
	while(id < N+M){
		while(j < M && i < N){
			if(A[i] < B[j])C[id++] = A[i++];
			else if(A[i]==B[j]){
				C[id++] = A[i++];
				C[id++] = B[j++];
			}else C[id++] = B[j++];
		}
		while(j < M){
			C[id++] = B[j++];
		}
		while(i < N){
			C[id++] = A[i++];
		}
	}
}

int main(){
	scanf("%d %d", &N, &M);
	A = new int[N];
	B = new int[M];
	C = new int[N+M];
	for(int i = 0; i < N; i++){
		scanf("%d", &A[i]);
	}
	for(int i = 0; i < M; i++){
		scanf("%d", &B[i]);
	}
	sort(A, A+N);
	sort(B, B+M);
	merge();
	for(int i = 0; i < N+M; i++){
		printf("%d ", C[i]);
	}
	printf("\n");
}

