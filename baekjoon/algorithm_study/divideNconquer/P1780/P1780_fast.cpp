#include <cstdio>
using namespace std;
int N;
int** P;
int F[3] = {0,};//-1:0 0:1 1:2
bool div(int x, int y, int l);

int main(){
	scanf("%d", &N);
	P = new int*[N];
	for(int i = 0; i < N; i++){
		P[i] = new int[N];
		for(int j = 0; j < N; j++){
			scanf("%d", &P[i][j]);
		}
	}
	div(0, 0, N);
	for(int i = 0; i < 3; i++){
		printf("%d\n", F[i]);
	}
}
bool div(int x, int y, int l){//l/3>0
	int cmp = P[x][y];
	bool f = true;
	for(int i = 0; i < l; i++){
		for(int j = 0; j < l; j++){
			if(cmp != P[x+i][y+j]){
				if(l/3>0){
					for(int k = 0; k < 3; k++){
						div(x + l/3*k, y, l/3);
					}
					for(int k = 0; k < 3; k++){
                        div(x + l/3*k, y+ l/3, l/3);
                    }
					for(int k = 0; k < 3; k++){
                        div(x + l/3*k, y+ l/3*2, l/3);
                    }
				}
				f = false;
				break;
			}
		}
		if(!f)break;
	}
	if(f){
		F[cmp+1]++;
		return true;
	}
	return false;
}
