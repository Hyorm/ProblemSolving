#include <stdio.h>
#include <iostream>
#include <memory.h>
#include <queue>
using namespace std;

int** room;
int R, C, T;
int airx1 = 0, airx2 = 0;

int calc(){

	int c = 2;

	for(int i = 0; i < R; i++){
		for(int j = 0; j < C; j++){
			c += room[i][j];
		}
	}

	return c;
}

void print(){
	for(int i = 0; i < R; i++){
		for(int j = 0; j < C; j++){
			printf("%d ", room[i][j]);
		}
		printf("\n");
	}
}

void aftertime(){
		queue<int> x, y, org;
		//TODO: spread
		for(int i = 0; i < R; i++){
			for(int j = 0; j < C; j++){
				if(room[i][j] != 0 && room[i][j]!= -1){
					x.push(i);
					y.push(j);
					org.push(room[i][j]);
				}
			}
			memset(room[i], 0, sizeof(int)*C);
		}
		room[airx1][0]= -1;
		room[airx2][0]= -1;

		while(!org.empty()){
			int nox = x.front();
			int noy = y.front();
			int noorg = org.front();
			int cap = noorg / 5;
			
			int h = 0;
			//UP
			if(nox > 0){
				if(room[nox - 1][noy] != -1){
					h++;
					room[nox - 1][noy] += cap;
				}
			}
			//DOWN
			if(nox < R - 1){
				if(room[nox + 1][noy] != -1){
					h++;
					room[nox + 1][noy]+= cap;
				}
			}
			//RIGHT
			if(noy < C - 1){
				if(room[nox][noy + 1] != -1){
					h++;
					room[nox][noy + 1] += cap;
				}
			}
			//LEFT
			if(noy > 0){
				if(room[nox][noy - 1] != -1){
					h++;
					room[nox][noy - 1] += cap;
				}
			}
			room[nox][noy] += noorg - cap * h;
			x.pop();
			y.pop();
			org.pop();
		}
		//UP

		//>left
		int bf = room[airx1][1];
		room[airx1][1] = 0;		
		for(int i = 2; i < C; i++){
			int tmp = room[airx1][i];
			room[airx1][i] = bf;
			bf = tmp;
		}
		
		//>up

		for(int i = airx1 - 1; i > -1 ; i-- ){
			int tmp = room[i][C - 1];
			room[i][C - 1] = bf;
			bf = tmp;
		}

		//>right
		for(int i = C - 2; i > -1; i--){
			int tmp = room[0][i];
			room[0][i] = bf;
			bf = tmp;
		}
		//>down(check air)
		for(int i = 1; i < airx1 ; i++ ){
			int tmp = room[i][0];
			room[i][0] = bf;
			bf = tmp;
		}
		
		//DOWN
		bf = room[airx2][1];
		room[airx2][1] = 0;
		//>right
		for(int i = 2; i < C; i++){
			int tmp = room[airx2][i]; 
			room[airx2][i] = bf;
			bf = tmp;
		}
		//>down
		for(int i = airx2 + 1; i < R ; i++ ){
			int tmp = room[i][C - 1];
			room[i][C - 1] = bf;
			bf = tmp;
		}
		//>left

		for(int i = C -2 ; i > -1; i--){
			int tmp = room[R - 1][i];
			room[R - 1][i] = bf;
			bf = tmp;
		}
		//>up(check air)
		for(int i = R - 2 ; i > airx2; i--){
			int tmp = room[i][0];
			room[i][0] = bf;
			bf = tmp;
		}
}

int main(int argc, char** argv){

	scanf("%d %d %d", &R, &C, &T);

	room = new int*[R];

	for(int i = 0 ; i < R; i++){
		room[i] = new int[C];
		for(int j = 0; j < C; j++){
			cin >> room[i][j];
			if(room[i][j] == -1){
				if(airx1 == 0){
					airx1 = i;
				}
				else{
					airx2 = i;
				}
			}
		}
	}
	for(int i = 0; i < T; i++){
		aftertime();
	}

	printf("%d\n", calc());
	return 0;
}
