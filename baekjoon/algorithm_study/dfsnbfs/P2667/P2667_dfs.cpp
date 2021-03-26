#include <cstdio>
#include <algorithm>
#include <memory.h>

using namespace std;

int N;
int M[26][26];
int C[26][26];
int answer[26*26];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
void dfs(int x, int y, int gn){
	C[x][y] = gn;
	for(int i = 0; i < 4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(nx >= 0 && nx < N && ny >= 0 && ny < N){
			if(M[nx][ny] == 1 && C[nx][ny] == 0){
				C[nx][ny] = gn;
				dfs(nx, ny, gn);
			}
		}
	}
}

int main(){
	int gn = 0;
	scanf("%d", &N);
	memset(C, 0, sizeof(int)*26*26);
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			scanf("%1d", &M[i][j]);
		}
	}
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(M[i][j] == 1 && C[i][j]==0){
				dfs(i, j, ++gn);
			}
		}
	}
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(C[i][j]!=0)answer[C[i][j]-1]++;
		}   
	}
	sort(answer, answer + gn);
	printf("%d\n", gn);
	for(int i = 0; i < gn; i++){
		printf("%d\n", answer[i]);
	}
}
