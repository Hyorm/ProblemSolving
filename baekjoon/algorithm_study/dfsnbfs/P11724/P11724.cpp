#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
using namespace std;

int N, M;
vector<int>* G;
bool* C;
void dfs(int x);
void bfs(int x);
int main(){
	int da = 0, ba = 0;
	scanf("%d %d", &N, &M);
	G = new vector<int>[N];
	C = new bool[N];
	for(int i = 0; i < M; i++){
		int u, v;
		scanf("%d %d", &u, &v);
		u--;v--;
		G[u].push_back(v);G[v].push_back(u);
	}


	for(int i = 0 ; i < N; i++){
		if(!C[i]){
			dfs(i);
			da++;
		}
	}	
	/*memset(C, false, sizeof(bool)*N);
	for(int i = 0 ; i < N; i++){
		if(!C[i]){
			bfs(i);
			ba++;
		}
	}
	printf("%d %d\n", da, ba);
	*/
	printf("%d\n", da);
}

void dfs(int x){
	C[x] = true;
	for(int i = 0; i < G[x].size(); i++){
		if(!C[G[x][i]]){
			dfs(G[x][i]);
		}
	}
}

void bfs(int x){
	queue<int> q;
	C[x] = true;
	q.push(x);
	while(!q.empty()){
		int now = q.front();q.pop();
		for(int i = 0; i < G[now].size(); i++){
			if(!C[G[now][i]]){
				C[G[now][i]] = true;
				q.push(G[now][i]);
			}
		}
	}
}
