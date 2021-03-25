#include <cstdio>
#include <vector>
#include <iostream>
#include <memory.h>
using namespace std;

//int* G;
//int* C;
int G[1001];//use problem constraint for memory
int C[1001];
int ch;

void dfs(int x, int h);

int main(){
	int T;
	scanf("%d",&T);
	for(int i = 0 ; i < T; i++){
		int N;
		scanf("%d", &N);
		//G = new int[N];
		//C = new int[N];
		memset(G, 0, sizeof(int)*1001);
		memset(C, 0, sizeof(int)*1001);
		int an = 0;
		for(int j = 0; j < N;j++){
			int u;
			cin >> u;
			G[j] = u-1;
		}
		for(int j = 0; j < N; j++){
			ch = 0;
			if(C[j]==0){
				dfs(j, j);
				an += ch;
			}
		}
		printf("%d\n", an);
	}
}
void dfs(int x, int h){
	C[x] = 1;
	if(C[G[x]]==0){
		dfs(G[x], h);
	}else if(G[x]==h){
		ch++;
	}
}
