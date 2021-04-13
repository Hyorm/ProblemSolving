#include <cstdio>
#include <cmath>
#include <memory.h>

using namespace std;

int MAP[101][101];
int** S;
int ans = 0;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int R, C, M;

void moveS(){
	int TMP[101][101];
	for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            TMP[i][j] = -1;
        }
    }
	for(int i = 0; i < M; i++){
		if(S[i][0]!=-1){
			//move
			int nr = S[i][0];
			int nc = S[i][1];
			for(int j = 0; j < S[i][2]; j++){
				int r = nr + dx[S[i][3]];
				int c = nc + dy[S[i][3]];
				if(r>=0&&r<R&&c>=0&&c<C){
					nr = r;nc = c;
				}
				else{
					if(S[i][3]==0|| S[i][3] == 1){
						S[i][3] = (S[i][3]==1)?0:1;
						nr += dx[S[i][3]];
					}
					if(S[i][3]==2|| S[i][3] == 3){
						S[i][3] = (S[i][3]==3)?2:3;
						nc += dy[S[i][3]];
					}
				}
			}
			S[i][0] = nr;S[i][1] = nc;
			if(TMP[nr][nc]!=-1){
				if(S[TMP[nr][nc]][4]<S[i][4]){
					S[TMP[nr][nc]][0] = -1;
					TMP[nr][nc] = i;
				}else{
					S[i][0] = -1;
				}
			}else TMP[nr][nc] = i;
		}
	}
	for(int i = 0; i < R; i++){
		memcpy(MAP[i], TMP[i], sizeof(int)*C);
	}
}
void getS(int H){
	for(int i = 0; i < R; i++){
		if(MAP[i][H]!= -1){
			ans += S[MAP[i][H]][4];
			S[MAP[i][H]][0] = -1;
			MAP[i][H] = -1;
			break;
		}
	}
}

int main(){
	scanf("%d %d %d", &R, &C, &M);
	S = new int*[M];
	for(int i = 0; i < M; i++){
		S[i] = new int[5];
		memset(S[i], 0, sizeof(int)*5);
	}
	for(int i = 0; i < R; i++){
		for(int j = 0; j < C; j++){
			MAP[i][j] = -1;
		}
	}
	for(int i = 0; i < M; i++){
		scanf("%d %d %d %d %d", &S[i][0], &S[i][1], &S[i][2], &S[i][3], &S[i][4]);
		S[i][0]--;S[i][1]--;S[i][3]--;S[i][2]%=(S[i][3]==0||S[i][3]==1)?((R-1)*2):((C-1)*2);
		MAP[S[i][0]][S[i][1]] = i;
	}
	
	for(int i = 0; i < C; i++){
		getS(i);
		moveS();
	}
	printf("%d\n", ans);
}
