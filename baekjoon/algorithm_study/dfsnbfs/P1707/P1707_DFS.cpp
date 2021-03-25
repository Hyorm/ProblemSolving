#include <cstdio>
#include <vector>
#include <memory.h>
using namespace std;
vector<int> G[20001];
int C[20001];
void dfs(int x, int p);
int ch;
int V;
int main(){
	
	int K;
	scanf("%d", &K);
	for(int i = 0; i < K; i++){
		int E;
		scanf("%d %d", &V, &E);
	
		memset(C, -1, sizeof(int)*20001);

		for(int j = 0; j < E; j++){
			int u, v;
			scanf("%d %d", &u, &v);
			u--; v--;
			G[v].push_back(u);
			G[u].push_back(v);
		}
		ch = 0;
		for(int j = 0; j < V; j++){
			if(C[j] == -1){
				dfs(j, 2);
			}
			if(ch!=0){
				printf("NO\n");
				break;
			}
		}
		if(ch <1){
			printf("YES\n");
		}
		for(int j = 0; j < V; j++){
			G[j].clear();
		}
	}

}
void dfs(int x, int p){
	C[x] = p;
	for(int i = 0; i < G[x].size(); i++){
		if(C[G[x][i]] == -1){
			dfs(G[x][i], -p);
		}else if(C[G[x][i]] == p){
			ch++;
		}
	}
}
