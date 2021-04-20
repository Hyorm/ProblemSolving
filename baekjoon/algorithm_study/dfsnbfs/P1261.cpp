#include <cstdio>
#include <queue>
using namespace std;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int V[101][101] = {{0,},};
int D[101][101] = {{0,},};
int N, M;
int main(){
	scanf("%d %d", &M, &N);
	for(int i = 0; i <N; i++){
		for(int j = 0; j < M; j++){
			scanf("%1d", &D[i][j]);
			V[i][j] = -1;
		}
	}
	queue<pair<pair<int, int>, int> > q;
	q.push(make_pair(make_pair(0, 0), 0));
	int min = -1;
	V[0][0] = 0;
	while(!q.empty()){
		int x = q.front().first.first;
		int y = q.front().first.second;
		int times = q.front().second;
		q.pop();
		if(min==-1 ||(min!=-1&&min>times)){
			for(int i = 0; i < 4; i++){
				int nx = x + dx[i];
				int ny = y + dy[i];
				if(nx == N-1 && ny==M-1){
					min = times;
					continue;
				}
				if(nx>=0&&nx<N&&ny>=0&&ny<M&&(V[nx][ny]==-1||V[nx][ny]>times)){
					V[nx][ny] = times;
					if(D[nx][ny]==1)q.push(make_pair(make_pair(nx, ny),times+1));
					else q.push(make_pair(make_pair(nx, ny), times));
				}
			}
		}	
	}
	printf("%d\n", (min==-1)?0:min);
}
