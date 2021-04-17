#include <cstdio>
#include <memory.h>
#include <vector>
using namespace std;

int N, M, ans = 0;
vector<int> R[2001];
int V[2001];
bool find(int x, int o, int sum){
	if(sum==4){
		ans = 1;
		return true;
	}
	for(int i = 0; i < R[x].size(); i++){
		if(V[R[x][i]]!=o){
			printf("%d %d %d %d\n", o, x, R[x][i], sum);
			V[R[x][i]]=o;
			if(find(R[x][i], o, sum+1))return true;
			V[R[x][i]]=0;
		}
	}
	return false;
}
int main(){
	scanf("%d %d", &N, &M);
	memset(V, 0, sizeof(int)*N);
	for(int i = 0; i < M; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		R[b].push_back(a);
		R[a].push_back(b);
	}
	for(int i = 0; i < N; i++){
		V[i] = i+1;
		if(find(i, i+1, 0))break;
	}
	printf("%d\n", ans);
}
