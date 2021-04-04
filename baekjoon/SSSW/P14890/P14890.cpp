#include <cstdio>
#include <cmath>
using namespace std;
int N, L;
int A[101][101];
bool gox(int x){
	int sl = -1;
	for(int i = 1; i < N; i++){
		if(A[x][i]!=A[x][i-1]){
			if(abs(A[x][i]-A[x][i-1])>1)return false;
			if(A[x][i] > A[x][i-1]){//_-
				if((sl==-1 || sl<i-L)&&i-L>= 0){
					for(int j = 1; j <= L; j++){
						if(A[x][i-j]!=A[x][i]-1)return false;
					}
				}
				else return false;
				sl = i-1;
			}
			else{//-_
				if(i-1+L<N){
					for(int j = 1; j <= L; j++){
						if(A[x][i-1+j]!=A[x][i-1]-1)return false;
					}
				}else return false;
				sl = i-1+L;
			}
		}
	}	
	return true;
}
bool goy(int y){
	int sl = -1;
    for(int i = 1; i < N; i++){
        if(A[i][y]!=A[i-1][y]){
            if(abs(A[i][y]-A[i-1][y])>1)return false;
            if(A[i][y] > A[i-1][y]){//_-
                if((sl==-1 || sl<i-L)&&i-L>= 0){
                    for(int j = 1; j <= L; j++){
                        if(A[i-j][y]!=A[i][y]-1)return false;
                    }
                }
                else return false;
                sl = i-1;
            }
            else{//-_
                if(i-1+L<N){
                    for(int j = 1; j <= L; j++){
                        if(A[i-1+j][y]!=A[i-1][y]-1)return false;
                    }
                }else return false;
                sl = i-1+L;
            }
        }
    }
	return true;
}
int main(){
	scanf("%d %d", &N, &L);
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			scanf("%d", &A[i][j]);
		}
	}
	int ans = 0;
	for(int i = 0; i < N; i++){
		if(gox(i))ans++;
	}
	for(int i = 0; i < N; i++){
		if(goy(i))ans++;
	}
	printf("%d\n", ans);
}
