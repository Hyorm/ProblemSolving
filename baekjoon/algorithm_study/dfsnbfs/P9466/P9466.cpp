#include <cstdio>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;

int G[100000];
int C[100000];
int N;
int d = 0;
bool dfs(int v){
	bool b;
	if(C[G[v]] == -1){
		d++;
		C[v] = d;
		b = dfs(G[v]);
	}else if(C[G[v]] > 0){
		d++;
		d = d - C[G[v]];//find cycle!
		if(G[v]==v){
			d = 1;
			return true;
		}
		C[v] = 0;
		return true;
	}else{
		C[v] = -2;
		return false;
	}
	if(b && d > 0){
		C[v] = 0;
		d--;
		return true;
	}else{
		C[v] = -2;
		return false;
	}
}

int main(){
	int T;
	scanf("%d",&T);
	for(int i = 0; i < T; i++){
		scanf("%d", &N);
		int answer = 0;
		memset(G, 0, sizeof(int)*100000);
		memset(C, -1, sizeof(int)*100000);
		for(int j = 0; j < N; j++){
			scanf("%d", &G[j]);
			G[j] = G[j]-1;
		}
		for(int j = 0; j < N; j++){
			d = 0;
			if(C[j] == -1){
				dfs(j);
			}
		}
		for(int j = 0; j < N; j++){
			if(C[j]==-2)answer++;
		}
		printf("%d\n",answer);
	}
}
