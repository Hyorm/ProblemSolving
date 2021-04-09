#include <cstdio>
#include <memory.h>
using namespace std;
char C[6][3][3];
char color[6] = {'w','r','y','o','g','b'};
int MV[8][4] = {{3,2,1,0},{0,1,2,3},{3,0,1,2},{2,1,0,3},{3,5,1,4},{4,1,5,3},{3,4,1,5},{5,1,4,3}};
void move(int id, int T){
	char TMP[3][3];
	for(int t = 0; t < T; t++){
		memcpy(TMP, C[MV[id][0]], sizeof(char)*9);
		for(int i = 1; i < 4; i++){
			memcpy(C[MV[id][i-1]], C[MV[id][i]], sizeof(char)*9);
		}
		memcpy(C[MV[id][3]], TMP, sizeof(char)*9);  
	}
}

void rotate(char ck){
	char TMP[3];
	if(ck == '+'){
		memcpy(TMP, C[0][2], sizeof(char)*3);
		for(int i = 0; i < 3; i++){
			C[0][2][(i==2)?0:(i==0)?2:i] = C[4][i][2];
		}
		for(int i = 0; i < 3; i++){
			C[4][i][2] = C[2][0][i];
		}
		for(int i = 0; i < 3; i++){
			C[2][0][i] = C[5][(i==2)?0:(i==0)?2:i][0];
		}
		for(int i = 0; i < 3; i++){
			C[5][i][0] = TMP[i];
		}
	}else{
		memcpy(TMP, C[0][2], sizeof(char)*3);
		for(int i = 0; i < 3; i++){
			C[0][2][i] = C[5][i][0];
		}
		for(int i = 0; i < 3; i++){
			C[5][(i==2)?0:(i==0)?2:i][0] = C[2][0][i];
		}
		for(int i = 0; i < 3; i++){
			C[2][0][i] = C[4][i][2];
		}
		for(int i = 0; i < 3; i++){
			C[4][(i==2)?0:(i==0)?2:i][2] = TMP[i];
		}
	}
}

void face(char ck, int id, int T){
	char TUP[3][3];
	for(int i = 0; i < T; i++){
		for(int k = 0; k < 3; k++){
			for(int l = 0; l < 3; l++){
				if(ck=='+'){
					int a = l;
					int b = (k-2)*-1;
					TUP[a][b] = C[id][k][l];
				}else{
					int a = (l-2)*-1;
					int b = k;
					TUP[a][b] = C[id][k][l];
				}
			}
		}
		memcpy(C[id], TUP, sizeof(char)*9);
	}
}

int main(){
	int T;
	scanf("%d", &T);
	for(int i = 0; i < T; i++){
		int N;
		scanf("%d", &N);
		for(int j = 0; j < 6; j++)memset(C[j], color[j], sizeof(char)*9);
		for(int j = 0; j < N; j++){
			char c, d;
			int p;
			scanf("%c", &c);
			if(c==' '||c=='\n')scanf("%c", &c);
			scanf("%c", &d);
			switch(c){
				case 'U':
						 face('+',4,1);face('-', 5, 1);
						 move(0, 1);
						 rotate(d);
						 face(d, 1, 1);
						 move(1, 1);
						 face('-', 4, 1);face('+', 5, 1);
						break;
				case 'D':
						 face('+', 5, 1);face('-', 4, 1);
                         move(2, 1);
                         rotate(d);
						 face(d, 1, 1);
                         move(3, 1);
                         face('+',4,1);face('-', 5, 1);
						break;
				case 'F':rotate(d);
						face(d, 1, 1);
						break;
				case 'B':
						 face('+', 5, 2);face('-', 4, 2);
                         move(0, 2);
                         rotate(d);
						 face(d, 1, 1);
                         move(1, 2);
                         face('-', 5, 2);face('+', 4, 2);
						break;
				case 'L':
						 face('+', 3, 2);face('-', 0, 1);face('+', 2, 1);
                         move(4, 1);
                         rotate(d);
						 face(d, 1, 1);
                         move(5, 1);
                         face('+', 3, 2);face('+', 0, 1);face('-', 2, 1);
						break;
				case 'R':
						 face('+', 3, 2);face('+',0,1);face('-',2,1);
                         move(6, 1);
                         rotate(d);
						 face(d, 1, 1);
                         move(7, 1);
                         face('+', 3, 2);face('-',0,1);face('+',2,1);
						break;
			}
		}
		for(int j = 0; j < 3; j++){
			for(int k = 0; k < 3; k++){
				printf("%c", C[0][j][k]);
			}
			printf("\n");
		}
	}
}
