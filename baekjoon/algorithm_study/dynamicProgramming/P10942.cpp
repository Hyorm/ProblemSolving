#include <cstdio>
using namespace std;
bool D[2001][2001];
int O[2001];
int N, M;
int main(){
	scanf("%d", &N);
	for(int i = 0; i < N; i++){
		scanf("%d", &O[i]);
		D[i][i] = true;
	}
	for(int k = 1; k < N; k++){
		for(int i = 0; i < N; i++){
			if(k==1&&i+1<N&&O[i]==O[i+1])D[i][i+1] = true;
			if(k!=1&&i+k<N&&D[i+1][(i+k)-1])if(O[i]==O[i+k])D[i][i+k] = true;
		}
	}
	scanf("%d", &M);
	for(int i = 0; i < M; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		if(D[a-1][b-1])printf("1\n");
		else printf("0\n");
	}
}
