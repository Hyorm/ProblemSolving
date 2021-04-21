#include <cstdio>
using namespace std;
int N;
int O[101][101];
long long V[101][101];
int main(){
    scanf("%d", &N);
    long long ans = 0; 
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            scanf("%d", &O[i][j]);
        }
    }
    V[0][0] = 1;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(i+O[i][j]<N&&(i!=N-1||j!=N-1))V[i+O[i][j]][j] += V[i][j];
			if(j+O[i][j]<N&&(i!=N-1||j!=N-1))V[i][j+O[i][j]] += V[i][j];
		}
	}
    printf("%lld\n", V[N-1][N-1]);
}
