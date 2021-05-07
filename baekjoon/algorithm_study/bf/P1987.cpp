#include <cstdio>
using namespace std;
int A[27];
int M[21][21];
int R, C;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int ans = 1;
void find(int x, int y, int d){
	for(int i = 0; i < 4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(nx>=0&&nx<R&&ny>=0&&ny<C){
			if(A[M[nx][ny]]==0){
				A[M[nx][ny]] = 1;
				if(ans<d+1)ans = d+1;
				find(nx, ny, d+1);
				A[M[nx][ny]] = 0;
			}
		}
	}
}
int main(){
	scanf("%d %d", &R, &C);
	for(int i = 0; i < R; i++){
		for(int j = 0; j < C; j++){
			char c;
			scanf("%c", &c);
			if(c=='\n')scanf("%c", &c);
			M[i][j] = c - '\0' - 65;
		}
	}
	A[M[0][0]] = 1;
	find(0, 0, 1);
	printf("%d\n", ans);
}
