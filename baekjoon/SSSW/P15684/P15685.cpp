#include <cstdio>

using namespace std;
int S[11][31]= {0,};
int N, M, H, ans = -1;

bool check(int d, int** ab){
	for(int i = 0; i < N; i++){//starting point
		int now = i;
		for(int j = 0; j < H; j++){//go under
			for(int k = 0; k < d; k++){
				if(ab[k][0]==now && ab[k][1]==j){
					now++;break;
				}
				if(ab[k][0]==now-1 && ab[k][1]==j){
					now--;break;
				}
			}
			if(S[now][j]==1){
				now++;continue;
			}
			if(now>0&&S[now-1][j]==1){
				now--;continue;
			}
		}

		if(now != i)return false;
	}
	return true;
}

void dfs(int d, int** ab){
	if(d<3){
		int sti = 0, stj = 0;
		if(d > 0){
			sti = ab[d-1][0];
			stj = ab[d-1][1]+1;
		}
		for(int i = sti; i < N-1; i++){
			if(i>sti)stj = 0;
			for(int j = stj; j < H; j++){
				if(S[i][j] == 0){
					int f = 0;
					for(int k = 0; k < d; k++){
						if(ab[k][0]==i-1&&ab[k][1]==j){
							f = 1; break;
						}
					}
					if(f==1)continue;
					ab[d][0] = i;
					ab[d][1] = j;
					if(check(d+1, ab)){
						if(ans==-1||ans>d+1)ans = d+1;
						return;
					}
					dfs(d+1, ab);
				}
			}
		}

	}
}

int main(){
	scanf("%d %d %d", &N, &M, &H);
	for(int i = 0; i < M; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		if(b-1>0)S[b-2][a-1] = -1;
		S[b-1][a-1] = 1;
		if(b-1 < N-1)S[b][a-1] = -1;
	}
	int** ab;
	ab = new int*[3];
	for(int i = 0; i < 3; i++){
		ab[i] = new int[2];
	}
	if(check(0, ab))ans = 0;
	else dfs(0, ab);
	printf("%d\n", ans);
}
