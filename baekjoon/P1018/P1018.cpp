#include <cstdio>
using namespace std;
int main(){
	int N, M;
	char A[51][51];
	scanf("%d %d", &N, &M);
	for(int i = 0; i<N; i++){
		for(int j = 0; j < M; j++){
			char tmp;

			scanf("%c", &tmp);
			if(tmp=='W'||tmp=='B')A[i][j] = tmp;
			else{
				scanf("%c", &tmp);
				A[i][j] = tmp;
			}
		}
	}
	int min = N*M;	
	for(int i = 0; i<N-7; i++){
		for(int j = 0; j < M-7; j++){
			char fc = 'W';
			int tmp = 0;
			for(int k = i; k < i+8; k++){
				for(int l = j; l < j + 8; l++){
					if(fc != A[k][l]){
						tmp++;
					}
					if(l!= j+7){
						fc = (fc=='B')?'W':'B';
					}
				}
			}
			if(tmp < min)min = tmp;
			fc = 'B';
			tmp = 0;
			for(int k = i; k < i+8; k++){
				for(int l = j; l < j + 8; l++){
					if(fc != A[k][l]){
						tmp++;
					}
					if(l!= j+7){
						fc = (fc=='B')?'W':'B';
					}
				}
			}
			if(tmp < min)min = tmp;
		}
	}
	printf("%d\n", min);
}
