#include <cstdio>

using namespace std;

long long A[2][100000];
long long V[2][100000];
int N;

void dp(int x, int y){
	int nx = (x==0)?1:0;
	int a = 0, b = 0;
	if(y+1<N){
		if(V[nx][y+1]==-1)dp(nx, y+1);
		a = V[nx][y+1];
	}
	if(y+2<N){
		if(V[nx][y+2]==-1)dp(nx, y+2);
		b = V[nx][y+2];
	}
	V[x][y] = (a>b)?a:b;
	V[x][y]+=A[x][y];
}

int main(){
	int T;
	scanf("%d", &T);
	for(int i = 0; i < T; i++){
		scanf("%d", &N);
		for(int j = 0; j < 2; j++){
			for(int k = 0; k < N; k++){
				scanf("%lld", &A[j][k]);
				V[j][k] = -1;
			}
		}
		for(int j = 0; j < 2; j++){
			dp(j, 0);
		}
		printf("%lld\n", (V[0][0]>V[1][0])?V[0][0]:V[1][0]);
	}
}
