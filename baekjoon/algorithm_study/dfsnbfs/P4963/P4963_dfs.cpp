#include <cstdio>
#include <memory.h>

using namespace std;

int W, H;
int M[51][51];
int C[51][51];
int dx[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dy[] = {0, 0, 1, -1, 1, -1, 1, -1};
void dfs(int x, int y){

	C[x][y] = 1;

	for(int i = 0; i < 8; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(nx >= 0 && nx < H && ny >= 0 && ny < W){
			if(M[nx][ny] == 1&&C[nx][ny] == 0){
				C[nx][ny] = 1;
				dfs(nx, ny);
				
			}
		}
	}

}

int main(){
	int end = 0;
	while(end == 0){
		scanf("%d %d", &W, &H);
		if(W == 0 && H == 0)break;
		memset(M, 0, sizeof(int)*51*51);
		memset(C, 0, sizeof(int)*51*51);
		for(int i = 0 ; i < H; i++){
			for(int j = 0 ; j < W; j++){
				scanf("%d ", &M[i][j]);
			}	
		}
		int answer = 0;
		for(int i = 0 ; i < H; i++){
			for(int j = 0 ; j < W; j++){
				if(M[i][j] == 1 && C[i][j] == 0){
					dfs(i, j);
					answer++;
				}
			}
		}
		printf("%d\n", answer);
	}
}
