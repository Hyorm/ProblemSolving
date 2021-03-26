#include <cstdio>
#include <queue>
#include <memory.h>
using namespace std;

int N, M;
int Z[100][100] = {0,};
int C[100][100] = {0,};
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main(){
	scanf("%d %d", &N, &M);
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			scanf("%1d", &Z[i][j]);
		}
	}
	queue<pair<int, int> > q;
	q.push(make_pair(0, 0));
	C[0][0] = 1;
	while(!q.empty()){
	    int x = q.front().first;
	    int y = q.front().second;
	    q.pop();
	    for(int i = 0 ; i < 4; i++){
	        int nx = x + dx[i];
	        int ny = y + dy[i];
	        if(nx >= 0 && nx < N && ny >= 0 && ny < M){
	            if(Z[nx][ny] == 1 && C[nx][ny] == 0){
	                q.push(make_pair(nx, ny));
	                C[nx][ny] = C[x][y]+1;
	            }
	        }
	    }
	}
	
	printf("%d\n", C[N-1][M-1]);
}
