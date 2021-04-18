#include <cstdio>
using namespace std;
int N;
int D[1001];
int A[1001][2];
int main(){
	scanf("%d", &N);
	for(int i = 0; i < N; i++){
		scanf("%d", &D[i]);
	}
	int max = 1;
	//UP
	for(int i = 0; i < N; i++){
		A[i][0] = 1;
		for(int j = 0; j < i; j++){
			if(A[i][0]<A[j][0]+1&&D[i]>D[j])A[i][0] = A[j][0]+1;
			if(A[i][0]<A[j][0]&&D[i]==D[j])A[i][0] = A[j][0];
		}
	}
	for(int i = N-1; i>=0; i--){
		A[i][1] = 1;
		for(int j = N-1; j > i; j--){
			if(A[i][1]<A[j][1]+1&&D[i]>D[j])A[i][1] = A[j][1]+1;
			if(A[i][0]<A[j][1]&&D[i]==D[j])A[i][1] = A[j][1];
		}
	}
	for(int i = 0; i < N; i++){
		if(max<A[i][1]+A[i][0]&&(A[i][1]>1||A[i][0]> 1))max = A[i][1]+A[i][0]-1;
	}
	printf("%d\n", max);
}
