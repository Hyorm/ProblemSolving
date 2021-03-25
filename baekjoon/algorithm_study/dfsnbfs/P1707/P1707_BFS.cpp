#include <cstdio>
#include <queue>
#include <vector>
#include <memory.h>
using namespace std;

vector<int> G[20001];
int C[20001];

int ch = 0;
void bfs(int x);

int main(){
	int K;

	scanf("%d", &K);

	for(int i = 0; i < K; i++){
		int V, E;
		scanf("%d %d", &V, &E);
		memset(C, -1, sizeof(int)*20001);
		for(int j = 0; j < E; j++){
			int u, v;
			scanf("%d %d", &u, &v);
			u--;
			v--;
			G[u].push_back(v);
			G[v].push_back(u);
		}

		ch = 0;
		for(int j = 0; j < V; j++){
			if(C[j] == -1){
				bfs(j);
			}
			if(ch != 0){
				printf("NO\n");
				break;
			}
		}
		if(ch < 1){
			printf("YES\n");
		}
		for(int j = 0; j < V; j++){
            G[j].clear();
        }
	}
}
void bfs(int x){
	int c = 2;
	queue<int> q;
	q.push(x);
	C[x] = c;
	while(!q.empty()){
		int now = q.front();q.pop();
		for(int i = 0; i < G[now].size(); i++){
			if(C[G[now][i]] == -1){
				C[G[now][i]] = C[now]*-1;
				q.push(G[now][i]);
			}
			else if(C[G[now][i]] != C[now]*-1){
				ch++;
			}
		}
	}	
}
