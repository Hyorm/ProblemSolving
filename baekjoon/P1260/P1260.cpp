#include <cstdio>
#include <algorithm>
#include <queue>
#include <memory.h>

using namespace std;

void dfs(int x);
void bfs(int x);
bool* check;
vector<int>* G;
int main(){
	int N, M, V;
	scanf("%d %d %d", &N, &M, &V);
	check = new bool[N];
	G = new vector<int>[N];

	for(int i = 0; i<M; i++){
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		t1--;
		t2--;
		G[t1].push_back(t2);
		G[t2].push_back(t1);
	}
	for(int i = 0; i<N; i++){
		printf("%d\n", i);
		sort(G[i].begin(), G[i].end());
	}
	dfs(V-1);
	memset(check, false, sizeof(bool)*N);
	printf("\n");
	bfs(V-1);
}

void dfs(int x){
	check[x] = true;
	printf("%d ", x+1);

	for(int i = 0; i < G[x].size();i++){
		if(check[G[x][i]]==false){
			dfs(G[x][i]);
		}
	}

}
void bfs(int x){
	queue<int> bf;
	bf.push(x);
	check[x] = true;

	while(!bf.empty()){
		int now = bf.front();bf.pop();
		printf("%d ",now+1);
		for(int i = 0; i < G[now].size(); i++){
			if(check[G[now][i]]==false){
				check[G[now][i]] = true;
				bf.push(G[now][i]);
			}
		}
	}
}
