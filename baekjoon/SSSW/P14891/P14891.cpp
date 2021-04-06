#include <cstdio>
#include <cmath>
using namespace std;

int T[4][8];

void move(int id, int dir, int d){
	if(d == 0){
		if(id+1 < 4 && T[id][2] != T[id+1][6])move(id+1, dir*-1, 1);
		if(id-1 > -1 && T[id][6] != T[id-1][2])move(id-1, dir*-1, -1);
	}else if(d == 1){//right
		if(id+1 < 4 && T[id][2] != T[id+1][6])move(id+1, dir*-1, 1);
	}
	else if(d == -1){//left
		if(id-1 > -1 && T[id][6] != T[id-1][2])move(id-1, dir*-1, -1);
	}
	int tmp;
	if(dir==1){
		tmp = T[id][7];
		for(int i = 7; i > 0; i--){
			T[id][i] = T[id][i-1];
		}
		T[id][0] = tmp;
	}else{
		tmp = T[id][0];
		for(int i = 0; i < 7; i++){
			T[id][i] = T[id][i+1];
		}
		T[id][7] = tmp;
	}
}

int main(){
	int N;
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 8; j++){
			scanf("%1d", &T[i][j]);
		}
	}
	scanf("%d",&N);
	for(int i = 0; i <N; i++){
		int id, dir;
		scanf("%d %d", &id, &dir);
		move(id-1, dir, 0);
	}
	int sum = 0;
	for(int i = 0; i < 4; i++){
		sum += T[i][0]*pow(2,i);
	}
	printf("%d\n", sum);
}
