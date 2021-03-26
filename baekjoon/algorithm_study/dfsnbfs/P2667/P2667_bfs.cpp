#include <cstdio>
#include <algorithm>
#include <queue>
#include <memory.h>
using namespace std;
int M[30][30];
int C[30][30];
int N;
int dx[] = {0, 0, 1, -1};//up down
int dy[] = {1, -1, 0, 0};//right left
int answer[26*26] = {0,};

void bfs(int x, int y, int cnt) {
    queue<pair<int,int> > q;
    q.push(make_pair(x,y));
    C[x][y] = cnt;
    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for (int k=0; k<4; k++) {
            int nx = x+dx[k];
            int ny = y+dy[k];
            if (0 <= nx && nx < N && 0 <= ny && ny < N) {
                if (M[nx][ny] == 1 && C[nx][ny] == 0) {
                    q.push(make_pair(nx,ny));
                    C[nx][ny] = cnt;
                }
            }
        }
    }
}

int main(){
	scanf("%d", &N);
	int gn = 0;
	memset(C, 0, sizeof(int)*30*30);
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			scanf("%1d", &M[i][j]);
		}
	}
    	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(M[i][j] == 1 &&C[i][j] == 0){
				bfs(i, j, ++gn);
			}
		}
	}
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(C[i][j] != 0){
				answer[C[i][j]-1]++;
			}
		}
	}
	sort(answer, answer+gn);
	printf("%d\n", gn);
	for(int i = 0; i < gn; i++){
		printf("%d\n", answer[i]);
	}
}
