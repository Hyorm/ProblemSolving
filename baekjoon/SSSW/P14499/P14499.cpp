#include <cstdio>
#include <queue>

using namespace std;

int MAP[21][21];
int dice[6] = {0,};
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
int main(){
	int N, M, X, Y, T;
	int C= 0;
	scanf("%d %d %d %d %d", &N, &M, &X, &Y, &T);
	//3D cube
	for(int i = 0 ; i < N; i++){
		for(int j = 0; j < M; j++){
			scanf("%d", &MAP[i][j]);
		}
	}
	int dir;
	for(int i = 0; i < T; i++){
		scanf("%d", &dir);
		dir--;
		if(X+dx[dir] >= 0 && X+dx[dir] < N && Y+dy[dir] >= 0 && Y+dy[dir] < M){
			X = X+dx[dir];
			Y = Y+dy[dir];
		}else{
			continue;
		}
		int tmp;	
		switch(dir){
			case 0:
					tmp = dice[5];
					dice[5] = dice[3];
					dice[3] = dice[0];
					dice[0] = dice[2];
					dice[2] = tmp;
					break;
			case 1:
					tmp = dice[5];
					dice[5] = dice[2];
					dice[2] = dice[0];
					dice[0] = dice[3];
					dice[3] = tmp;
					break;
			case 2:
					tmp = dice[5];
					dice[5] = dice[4];
					dice[4] = dice[0];
					dice[0] = dice[1];
					dice[1] = tmp;
					break;
			case 3:
					tmp = dice[5];
					dice[5] = dice[1];
					dice[1] = dice[0];
					dice[0] = dice[4];
					dice[4] = tmp;
					break;

		}

		printf("%d\n", dice[C]);
		if(MAP[X][Y]==0)MAP[X][Y] = dice[5];
		else{
			dice[5] = MAP[X][Y];
			MAP[X][Y] = 0;
		}
	}
}
