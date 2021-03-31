#include <cstdio>

using namespace std;

int N;
int S[16][2];
int ans = 0;
void dfs(int d, int m){
	if(d+S[d][0] <= N)m += S[d][1];
	if(ans < m)ans = m;
	for(int i = d+S[d][0]; i < N; i++){
		dfs(i, m);
	}
}
int main(){
	scanf("%d", &N);
	for(int i = 0; i < N; i++){
		scanf("%d %d",&S[i][0], &S[i][1]);
	}
	for(int i = 0; i < N; i++){
		dfs(i, 0);
	}
	printf("%d\n", ans);
}
