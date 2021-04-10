#include <cstdio>

using namespace std;

int A[11][11];
int L[11][11];
int T[11][11][1011] = {{{0},},};
int D[11][11] = {{0,},};
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int tree = 0;
int N, M, K;

void spring(){
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			int enrg = L[i][j];
			int TMP[1011] = {0,};
			for(int t = 1; t < 1011; t++){
				while(T[i][j][t]>0 && enrg-t>= 0){
					enrg -= t;
					T[i][j][t]--;
					TMP[t+1]++;
				}
				if(T[i][j][t]>0){
					tree -= T[i][j][t];
					D[i][j]+=T[i][j][t]*(t/2);
					T[i][j][t] = 0;
				}
			}
			L[i][j] = enrg;
			for(int t = 1; t < 1011; t++){
				T[i][j][t] += TMP[t];
			}
		}
	}
}
void summer(){
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(D[i][j]>0){
				L[i][j]+=D[i][j];
				D[i][j] = 0;
			}
		}
	}
}
void fall(){
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			for(int t = 5; t < 1011; t+=5){
				if(T[i][j][t]>0){
					for(int k = 0; k < 8; k++){
						int nx = i+dx[k];
						int ny = j+dy[k];
						if(nx>=0 && nx < N&& ny >=0 && ny < N){
							T[nx][ny][1] += T[i][j][t];
							tree += T[i][j][t];
						}
					}
				}
			}
		}
	}
}
void winter(){
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			L[i][j]+= A[i][j];
		}
	}
}

int main(){
	scanf("%d %d %d", &N, &M, &K);
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			scanf("%d", &A[i][j]);
		}
	}
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			L[i][j] = 5;
		}
	}
	for(int i = 0; i < M; i++){
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		T[x-1][y-1][z] = 1;
	}
	tree = M;
	for(int i = 0; i < K; i++){
		spring();
		summer();
		fall();
		winter();
	}

	printf("%d\n", tree);
}
