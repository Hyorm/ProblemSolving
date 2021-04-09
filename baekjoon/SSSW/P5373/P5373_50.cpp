#include <cstdio>
#include <memory.h>
using namespace std;
char C[6][3][3];
char color[6] = {'w','r','y','o','g','b'};

void ft(int to, int from, int dx1, int dx2, int dy1, int dy2){
	if(dx1==-1){
		if(dx2==-1){
			if(dy1!= dy2){
				for(int i = 2; i > -1; i--)C[to][(i==2)?0:(i==0)?2:i][dy1] = C[from][i][dy2];
			}else for(int i = 0; i < 3; i++)C[to][i][dy1] = C[from][i][dy2];
		}
		else{
			if(dy1== dx2){
				for(int i = 2; i > -1; i--)C[to][(i==2)?0:(i==0)?2:i][dy1] = C[from][dx2][i];
			}else for(int i = 0; i < 3; i++)C[to][i][dy1] = C[from][dx2][i];
		}
	}else{
		if(dx2 == -1){
			if(dy2== dx1){
				for(int i = 2; i > -1; i--)C[to][dx1][(i==2)?0:(i==0)?2:i] = C[from][i][dy2];
			}else for(int i = 0; i < 3; i++)C[to][dx1][i] = C[from][i][dy2];
		}
		else{
			if(dx2!= dx1){
				for(int i = 2; i > -1; i--)C[to][dx1][(i==2)?0:(i==0)?2:i] = C[from][dx2][i];
			}else for(int i = 0; i < 3; i++)C[to][dx1][i] = C[from][dx2][i];
		}
	}
}

void chg(int c1, int c2, int c3, int c4, int dx1, int dx2, int dx3, int dx4, int dy1, int dy2, int dy3, int dy4){
	char tmp[3];
	for(int i = 0; i < 3; i++){
		if(dx4==-1)tmp[i] = C[c4][i][dy4];
		else tmp[i] = C[c4][dx4][i];
	}
	ft(c4, c3, dx4, dx3, dy4, dy3);
	ft(c3, c2, dx3, dx2, dy3, dy2);
	ft(c2, c1, dx2, dx1, dy2, dy1);
	if(dx1==-1){
		if(dx4==-1){
			if(dy1!=dy4)for(int i = 2; i > -1; i--)C[c1][(i==2)?0:(i==0)?2:i][dy1] = tmp[i];
			else for(int i = 0; i < 3; i++)C[c1][i][dy1] = tmp[i];
		}else{
			if(dy1==dx4)for(int i = 2; i > -1; i--)C[c1][(i==2)?0:(i==0)?2:i][dy1] = tmp[i];
			else for(int i = 0; i < 3; i++)C[c1][i][dy1] = tmp[i];
		}
	}
	else{
		if(dx4==-1){
			if(dx1==dy4)for(int i = 2; i > -1; i--)C[c1][dx1][(i==2)?0:(i==0)?2:i] = tmp[i];
			else for(int i = 0; i < 3; i++)C[c1][dx1][i] = tmp[i];
		}else{
			if(dx1!= dx4)for(int i = 2; i > -1; i--)C[c1][dx1][(i==2)?0:(i==0)?2:i] = tmp[i];
			else for(int i = 0; i < 3; i++)C[c1][dx1][i] = tmp[i];
		}
	}
}

int main(){
	int T;
	scanf("%d", &T);
	for(int j = 0; j < 6; j++)memset(C[j], color[j], sizeof(char)*9);
	for(int i = 0; i < T; i++){
		int N;
		printf("\n");
		scanf("%d", &N);
		//for(int j = 0; j < 6; j++)memset(C[j], color[j], sizeof(char)*9);
		for(int j = 0; j < N; j++){
			char c, d;
			int p;
			scanf("%c", &c);
			if(c==' '||c=='\n')scanf("%c", &c);
			scanf("%c", &d);
			switch(c){
				case 'U':p = 0;
						switch(d){
							case '+':chg(1, 4, 3, 5, 0, 0, 2, 0, -1, -1, -1, -1);
									break;
							case '-':chg(1, 5, 3 ,4, 0, 0, 2, 0, -1, -1, -1, -1);
									break;
						}
						break;
				case 'D':p = 2;
						switch(d){
							case '+':chg(1, 5, 3, 4, 2, 2, 0, 2, -1, -1, -1, -1);
									break;
							case '-':chg(1, 4, 3, 5, 2, 2, 0, 2, -1, -1, -1, -1);
									break;
						}
						break;
				case 'F':p = 1;
						switch(d){
							case '+':chg(0, 5, 2, 4, 2, -1, 0, -1, -1, 0, -1, 2);
									break;
							case '-':
									 chg(0, 4, 2, 5, 2, -1, 0, -1, -1, 2, -1, 0);
									break;
						}
						break;
				case 'B':p = 3;
						switch(d){
							case '+':chg(0, 4, 2, 5, 0, -1, 0, -1, -1, 0, -1, 2);
									break;
							case '-':chg(0, 5, 2, 4, 0, -1, 2, -1, -1, 2, -1, 0);
									break;
						}
						break;
				case 'L':p = 4;
						switch(d){
							case '+':chg(0, 1, 2, 3, -1, -1, -1, -1, 0, 0, 0, 0);
									break;
							case '-':chg(0, 3, 2, 1, -1, -1, -1, -1, 0, 0, 0, 0);
									break;
						}
						break;
				case 'R':p = 5;
						switch(d){
							case '+':chg(0, 3, 2, 1, -1, -1, -1, -1, 2, 2, 2, 2);
									break;
							case '-':chg(0, 1, 2, 3, -1, -1, -1, -1, 2, 2, 2, 2);
									break;
						}
						break;
			}

			//mine:
			char TUP[3][3];
			for(int k = 0; k < 3; k++){
				for(int l = 0; l < 3; l++){
					if(d=='+'){
						int a = l;
						int b = (k-2)*-1;
						TUP[a][b] = C[p][k][l];
					}else{
						int a = (l-2)*-1;
						int b = k;
						TUP[a][b] = C[p][k][l];
					}
				}
			}
			memcpy(C[p], TUP, sizeof(char)*9);
		}
		printf("0\n");
		for(int j = 0; j < 3; j++){
			for(int k = 0; k < 3; k++){
				printf("%c", C[0][j][k]);
			}
			printf("\n");
		}
	}
}
