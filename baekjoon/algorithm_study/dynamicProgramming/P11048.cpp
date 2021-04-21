#include <cstdio>
using namespace std;
int N, M;
int O[1001][1001];
int D[1001][1001];
int main(){
	scanf("%d %d", &N, &M);
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			scanf("%d", &O[i][j]);
		}
	}
	D[0][0] = O[0][0];
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			int nx = i+1;
			int ny = j+1;
			if(i+1<N)D[i+1][j] = (O[i+1][j]+D[i][j]>D[i+1][j])?O[i+1][j]+D[i][j]:D[i+1][j];
			if(j+1<M)D[i][j+1] = (O[i][j+1]+D[i][j]>D[i][j+1])?O[i][j+1]+D[i][j]:D[i][j+1];
		}
	}
	printf("%d\n", D[N-1][M-1]);
}
