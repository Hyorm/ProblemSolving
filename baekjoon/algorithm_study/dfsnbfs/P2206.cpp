#include <cstdio>
#include <queue>
using namespace std;
int N, M;
int A[1001][1001];
int V[1001][1001][2];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int main(){
	int ans = -1;
	scanf("%d %d", &N, &M);
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			scanf("%1d", &A[i][j]);
			V[i][j][0] = -1;
			V[i][j][1] = -1;
		}
	}
	if(N==M==1){
		printf("1\n");
		return 0;
	}
	queue<pair<int, int> >q1;
	queue<pair<int, int> >q2;
	q1.push(make_pair(0,0));
	q2.push(make_pair(0,1));
	V[0][0][0]= 1;
	V[0][0][1]= 1;
	while(!q1.empty()){
		int x = q1.front().first;
		int y = q1.front().second;
		int b = q2.front().first;
		int d = q2.front().second;
		q1.pop();
		q2.pop();
		if(ans==-1||(ans!=-1&&ans>d)){
			for(int i= 0; i < 4; i++){
				int nx = x + dx[i];
				int ny = y + dy[i];
				if(nx==N-1 && ny==M-1){
					ans = d+1;
					while(!q1.empty()){q1.pop();q2.pop();}
					break;
				}else{
					if(nx>=0&&nx<N&&ny>=0&&ny<M){
						int nb = b;
						if(A[nx][ny]==1){
							if(b==1)continue;
							nb = 1;
						}
						if(V[nx][ny][nb]==-1){
							V[nx][ny][nb] = 1;
							q1.push(make_pair(nx, ny));
							q2.push(make_pair(nb, d+1));
						}
					}
				}
			}
		}
	}
	printf("%d\n", ans);
}
