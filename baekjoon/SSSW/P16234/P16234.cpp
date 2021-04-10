#include <cstdio>
#include <cmath>
#include <memory.h>
using namespace std;

int N, l, R;
int A[51][51];
int V[51][51] = {{0,},};
int L[51][51] = {{0,},};
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int avr[51*51] = {0,};
bool open(){
	bool re = false;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			for(int k = 0 ; k < 4; k++){
				L[i][j]*=10;
				int ni = i + dx[k];
				int nj = j + dy[k];
				if(ni>=0&&ni<N&&nj>=0&&nj<N){
					int diff = abs(A[i][j]-A[ni][nj]);
					if(diff>=l&&diff<=R){
						L[i][j]++;
						re = true;
					}
				}
			}
		}
	}
	return re;
}
int* dfs(int* data, int x, int y){
	int op = L[x][y];
	for(int k = 3 ; k >=0; k--){
		if(op%10 == 1){
			int nx = x + dx[k];
			int ny = y + dy[k];
			if(V[nx][ny]==0){
				V[nx][ny] = data[0];
				data[1] += A[nx][ny];
				data[2]++;
				data = dfs(data, nx, ny);
			}
		}
		op/=10;
	}
	return data;
}

void calc(){
	int id = 1;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(L[i][j]!=0 && V[i][j]==0){
				int* data = new int[3];
				V[i][j] = id;
				data[0] = id;
				data[1] = A[i][j];
				data[2] = 1;
				data = dfs(data, i, j);
				avr[id] = data[1]/data[2];
				id++;
			}
		}
	}

}
void control(){
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(V[i][j]!=0)A[i][j] = avr[V[i][j]];
		}
	}
	memset(V, 0, sizeof(int)*51*51);
	memset(L, 0, sizeof(int)*51*51);
}

int main(){
	scanf("%d %d %d", &N, &l, &R);	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			scanf("%d", &A[i][j]);
		}
	}
	int day = 0;
	while(open()){
		calc();
		control();
		day++;
	}
	printf("%d\n", day);
}
