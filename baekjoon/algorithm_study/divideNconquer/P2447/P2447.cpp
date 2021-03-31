#include <cstdio>
#include <memory.h>
using namespace std;

char** P;
int N;

void rmv(int x, int y, int l){
	int sctr = l/3;
	for(int i = x+sctr; i < x+2*sctr; i++){
		for(int j = y+sctr; j < y+2*sctr; j++){
			P[i][j] = ' ';
		}
	}
	if(sctr>1){
		int block = 0;
		for(int i =x; i < x+l; i+=sctr){
			for(int j = y; j < y+l; j+=sctr){
				rmv(i, j, sctr);
			}
		}
	}
}

int main(){
	scanf("%d", &N);

	P = new char*[N];
	
	for(int i = 0; i < N; i++){
		P[i] = new char[N];
		memset(P[i], '*', sizeof(char)*N);
	}

	rmv(0, 0, N);
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			printf("%c", P[i][j]);
		}
		printf("\n");
	}
}
