#include <cstdio>
#include <memory.h>
using namespace std;
int T[501][501];
long long M[501][501];
int N;
long long find(int d, int id){
	if(d+1<N){
		if(M[d+1][id]==0)M[d+1][id] = find(d+1, id);
		if(M[d+1][id+1]==0)M[d+1][id+1] = find(d+1, id+1);
		M[d][id] = (M[d+1][id]>M[d+1][id+1])?M[d+1][id]:M[d+1][id+1];
		M[d][id]+=T[d][id];
		return M[d][id];
	}
	M[d][id] = T[d][id];
	return M[d][id];
}
int main(){
	scanf("%d", &N);
	memset(M, 0, sizeof(long long)*N);
	for(int i = 0; i < N; i++){
		memset(M[i], 0, sizeof(long long)*N);
		for(int j = 0; j < i+1; j++){
			scanf("%d ", &T[i][j]);
		}
	}
	printf("%lld\n", find(0, 0));
}
