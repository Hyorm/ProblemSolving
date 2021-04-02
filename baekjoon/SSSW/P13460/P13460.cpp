#include <stdio.h>
#include <iostream>
#include <memory.h>
using namespace std;

int N, M;

int answer = 11;
void print(char* MP);
void move(char* MP, int times, int R, int B);
int up(char* MP, int C);
int down(char* MP, int C);
int right(char* MP, int C);
int left(char* MP, int C);

int main(){
	scanf("%d %d", &N, &M);

	char* MP = new char[N*M];
	int R, B;
	for(int i = 0; i < N*M; i++){
		cin >> MP[i];
		if(MP[i] == 'R'){
			R = i;
		}
		if(MP[i] == 'B'){
			B = i;
		}
	}
	move(MP, 0, R, B);
	if(answer == 11)answer = -1;else answer++;
	printf("%d\n", answer);
}

void move(char* MP, int times, int R, int B){
	//printf("----------\n");
	//print(MP);
	
	char* UP = new char[N*M];
	char* DOWN = new char[N*M];
	char* RIGHT = new char[N*M];
	char* LEFT = new char[N*M];

	memcpy(UP, MP, sizeof(char)*N*M);
	memcpy(DOWN, MP, sizeof(char)*N*M);
	memcpy(RIGHT, MP, sizeof(char)*N*M);
	memcpy(LEFT, MP, sizeof(char)*N*M);
	
	int upR, upB, dnR, dnB, rgR, rgB, lfR, lfB;
	if(R/M < B/M){
		upR = up(UP, R);
		upB = up(UP, B);
	}
	else{
		upB = up(UP, B);
		upR = up(UP, R);
	}
	if(upR == -1 && upB != -1){
		if(times<answer)answer = times;
	}

	if(R/M > B/M){
		dnR = down(DOWN, R);
		dnB = down(DOWN, B);
	}
	else{
		dnB = down(DOWN, B);
		dnR = down(DOWN, R);
	}
	
	if(dnR == -1 && dnB != -1){
		if(times<answer)answer = times;
	}
	
	if(R%M > B%M){
		rgR = right(RIGHT, R);
		rgB = right(RIGHT, B);
	}
	else{
		rgB = right(RIGHT, B);
		rgR = right(RIGHT, R);
	}
	
	if(rgR == -1 && rgB != -1){
		if(times<answer)answer = times;
	}
	
	if(R%M < B%M){
		lfR = left(LEFT, R);
		lfB = left(LEFT, B);
	}
	else{
		lfB = left(LEFT, B);
		lfR = left(LEFT, R);
	}
	if(lfR == -1 && lfB != -1){
		if(times<answer)answer = times;
	}
	
	if(times < 9){
		if(upR != -1 && upB != -1){
			move(UP, times+1, upR, upB);
		}
		if(dnR != -1 && dnB != -1){
			move(DOWN, times+1, dnR, dnB);
		}
		if(rgR != -1 && rgB != -1){
			move(RIGHT, times+1, rgR, rgB);
		}
		if(lfR != -1 && lfB != -1){
			move(LEFT, times+1, lfR, lfB);
		}
	}
	delete[] UP;
	delete[] DOWN;
	delete[] RIGHT;
	delete[] LEFT;
}

int up(char* MP, int C){
	int tpC = C;

	while((tpC-M)/M > 0){
		if(MP[tpC-M] == '.'){
			tpC -= M;
		}
		else if(MP[tpC-M] == 'O'){
			tpC = -1;
			MP[C] = '.';
			break;
		}
		else{
			break;
		}
	}
	if(tpC != -1 && tpC != C){
		MP[tpC] = MP[C];
		MP[C] = '.';
	}
	return tpC;
}

int down(char* MP, int C){
	int tpC = C;
	while((tpC+M)/M < N-1){
		if(MP[tpC+M] == '.'){
			tpC += M;
		}
		else if(MP[tpC+M] == 'O'){
			tpC = -1;
			MP[C] = '.';
			break;
		}
		else{
			break;
		}
	}
	if(tpC != -1 && tpC != C){
		MP[tpC] = MP[C];
		MP[C] = '.';
	}
	return tpC;
}

int right(char* MP, int C){

	int tpC = C;

	while((tpC+1)%M < M-1){
		if(MP[tpC+1] == '.'){
			tpC += 1;
		}
		else if(MP[tpC+1] == 'O'){
			tpC = -1;
			MP[C] = '.';
			break;
		}
		else{
			break;
		}
	}

	if(tpC != -1 && tpC != C){
		MP[tpC] = MP[C];
		MP[C] = '.';
	}
	return tpC;
}
int left(char* MP, int C){

	int tpC = C;

	while((tpC-1)%M > 0){
		if(MP[tpC-1] == '.'){
			tpC -= 1;
		}
		else if(MP[tpC-1] == 'O'){
			tpC = -1;
			MP[C] = '.';
			break;
		}
		else{
			break;
		}
	}

	if(tpC != -1 && tpC != C){
		MP[tpC] = MP[C];
		MP[C] = '.';
	}
	
	return tpC;
}

void print(char* MP){
	for(int i = 0; i < N*M; i++){
		if(i%M == 0)printf("\n");
		printf("%c ", MP[i]);
	}
	printf("\n");
}
