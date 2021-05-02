#include <cstdio>
#include <algorithm>
using namespace std;
bool cmp1(int* a, int* b){
	return a[1]<b[1];
}
bool cmp0(int* a, int* b){
    return a[0]<b[0];
}
int main(){
	int N;
	scanf("%d", &N);
	int** A;
	A = new int*[N];
	for(int i = 0; i < N; i++){
		A[i] = new int[3];
		A[i][0] = i;
		scanf("%d", &A[i][1]);
	}
	sort(A, A+N, cmp1);
	A[0][2] = 0;
	for(int i = 1; i<N;i++){
		if(A[i][1]==A[i-1][1])A[i][2] = A[i-1][2];
		else A[i][2] = A[i-1][2]+1;
	}
	sort(A, A+N, cmp0);
	for(int i = 0; i < N; i++){
		printf("%d ", A[i][2]);
	}
}
