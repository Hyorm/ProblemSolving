#include <cstdio>
#include <cmath>
using namespace std;
int A[21][21];
int N;
int ans = 100*21;
void check(int* S){
	int L[21] = {0,};
	int s = 0, l = 0;
	for(int i = 0; i < N/2; i++){
		L[S[i]] = 1;
		for(int j = 0; j < N/2; j++){
			s+= A[S[i]][S[j]];
		}
	}
	for(int i = 0; i < N; i++){
		if(L[i]==0){
			for(int j = 0; j < N; j++){
				if(L[j]==0){
					l+=A[i][j];
				}
			}
		}
	}
	if(abs(l-s) < ans)ans = abs(l-s);
}
void make(int d, int b, int* S){
	if(d >= N/2)check(S);
	else{
		for(int i = b+1; i < N; i++){
			S[d] = i;
			make(d+1, i, S);
		}
	}
}
int main(){
	scanf("%d", &N);
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			scanf("%d", &A[i][j]);
		}
	}	
	for(int i = 0; i < N; i++){
		int* S = new int[N/2];
		S[0] = i;
		make(1, i, S);
	}
	printf("%d\n", ans);
}
