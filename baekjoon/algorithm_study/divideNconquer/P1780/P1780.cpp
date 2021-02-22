#include <stdio.h>
#include <memory.h>

using namespace std;

void div(int x, int y, int size);
bool check(int x, int y, int size);

int** P;

int min_one, zero, one; 

int main(int argc, char** argv){

	int size;

	scanf("%d", &size);

	P = new int*[size];

	for(int i = 0; i < size; i++){
		P[i] = new int[size];
		for(int j = 0; j < size; j++){
			scanf("%d", &P[i][j]);
		}
	}
	div(0, 0, size);
	printf("%d\n%d\n%d\n", min_one, zero, one);
	return 0;
}

void div(int x, int y, int size){
	if(!check(x, y, size)){
		int tmp = size/3;
		for(int i = 0; i < 3; i++){
			for(int j = 0; j < 3; j++){
				div(i * tmp + x, j * tmp + y, size/3);
			}
		}
	}
}

bool check(int x, int y, int size){
	int tmp = P[x][y];
	for(int i = x; i < size+x; i++){
		for(int j = y; j < size+y; j++){
			if(tmp != P[i][j]){
				return false;
			}
		}
	}
	if(tmp == -1){
		min_one++;
	}
	else if(tmp == 0){
		zero++;
	}
	else{
		one++;
	}
	return true;
}
