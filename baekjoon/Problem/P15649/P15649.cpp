#include <cstdio>

using namespace std;
int N, M;

void make(int d, int* b){
	for(int i = 1; i <= N; i++){
		int s = 0;
		for(int j = 0; j < d ; j++){
			if(b[j] == i){
				s = 1;
				break;
			}
		}
		if(s==0){
			b[d] = i;
			if(d+1 < M)make(d+1, b);
			else{
				for(int j = 0; j < d+1; j++){
					printf("%d ", b[j]);
				}
				printf("\n");
			}
		}
		
	}
}

int main(){
	scanf("%d %d", &N, &M);
	
	for(int i = 1; i <= N; i++){
		int* A = new int[N+1];
		A[0] = i;
		if(1 < M)make(1, A);
		else printf("%d\n", i);	
	}
}
