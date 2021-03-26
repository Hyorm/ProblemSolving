#include <cstdio>
#include <memory.h>
#include <queue>
using namespace std;

int T[1000][1000] = {0, };
int C[1000][1000] = {0,};

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main(){
	int N, M;
	int answer = 0;
	scanf("%d %d", &M, &N);
	queue<pair<int,int> > q;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			scanf("%d", &T[i][j]);
			if(T[i][j] == 1){
				q.push(make_pair(i, j));
			}
		}
	}
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for(int i = 0; i < 4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(nx >= 0 && nx < N && ny >= 0 && ny < M){
				if(T[nx][ny] == 0 && C[nx][ny] == 0){
					T[nx][ny] = 1;
					C[nx][ny] = C[x][y] + 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}

	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			if(T[i][j] == 0){
				answer = -1;
				i = N;
				break;
			}
			else{
				if(C[i][j] > answer)answer = C[i][j];
			}
		}
	}

	printf("%d\n", answer);
}
