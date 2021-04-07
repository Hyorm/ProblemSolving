#include <cstdio>
#include <vector>
using namespace std;

int N, M, ans;
vector<pair<int, int> > C;
void dfs(int id, int** R);
void check(int** R){
	int tmp = 0;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			if(R[i][j]==0)tmp++;
		}
	}
	if(ans>tmp)ans = tmp;
}

void move(int id, int u, int d, int r, int l, int** T){
	int x = C[id].first;
	int y = C[id].second;

	if(u==1){
		for(int i = x-1; i >-1; i--){
			if(T[i][y]==0)T[i][y] = -1;
			else if(T[i][y]==6)break;
		}
	}
	if(d==1){
		for(int i = x+1; i < N; i++){
			if(T[i][y]==0)T[i][y] = -1;
			else if(T[i][y]==6)break;
		}
	}
	if(r==1){
		for(int i = y+1; i < M; i++){
			if(T[x][i]==0)T[x][i] = -1;
			else if(T[x][i]==6)break;
		}
	}
	if(l==1){
		for(int i = y-1; i > -1; i--){
			if(T[x][i]==0)T[x][i] = -1;
			else if(T[x][i]==6)break;
		}

	}
	dfs(id+1, T);
}

int** copy(int** R, int** T){
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			T[i][j] = R[i][j];
		}
	}
	return T;
}

void dfs(int id, int** R){
	if(id < C.size()){
		int x = C[id].first;
		int y = C[id].second;
		int** T = new int*[N];
		for(int i = 0; i < N; i++){
			T[i] = new int[M];
		}
		copy(R, T);
		switch(R[x][y]){
			case 1:
					move(id, 1, 0, 0, 0, T);
					copy(R, T);
					move(id, 0, 1, 0, 0, T);
					copy(R, T);
					move(id, 0, 0, 1, 0, T);
					copy(R, T);
					move(id, 0, 0, 0, 1, T);
					break;
			case 2:
					move(id, 1, 1, 0, 0, T);
					copy(R, T);
					move(id, 0, 0, 1, 1, T);
					break;
			case 3:
					move(id, 1, 0, 1, 0, T);
					copy(R, T);
					move(id, 0, 1, 1, 0, T);
					copy(R, T);
					move(id, 0, 1, 0, 1, T);
					copy(R, T);
					move(id, 1, 0, 0, 1, T);
					break;
			case 4:
					move(id, 1, 1, 1, 0, T);
					copy(R, T);
					move(id, 0, 1, 1, 1, T);
					copy(R, T);
					move(id, 1, 0, 1, 1, T);
					copy(R, T);
					move(id, 1, 1, 0, 1, T);
					break;
			case 5:
					move(id, 1, 1, 1, 1, T);
					break;
		}

	}
	else check(R);
}

int main(){
	int** R;
	
	scanf("%d %d", &N, &M);
	ans = N*M;
	R = new int*[N];
	for(int i = 0; i < N; i++){
		R[i] = new int[M];
		for(int j = 0; j < M; j++){
			scanf("%d", &R[i][j]);
			if(R[i][j]!=0 &&R[i][j]!=6)C.push_back(make_pair(i, j));
		}
	}
	dfs(0, R);

	printf("%d\n", ans);
}
