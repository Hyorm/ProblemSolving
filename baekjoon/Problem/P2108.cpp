#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	
	int N, tmp;
	double sum = 0;
	int* A;
	int D[8001] = {0,};
	scanf("%d", &N);
	A = new int[N];
	for(int i = 0; i < N; i++){
		scanf("%d", &tmp);
		sum += tmp;
		A[i] = tmp;
		D[(tmp==0)?0:(tmp>0)?tmp+4000:tmp*-1]++;
	}
	
	int max = 0;
	int id = 0;
	int count = 0;

	for(int i = 0; i < 8001; i++){
		if(D[i]!=0 && max < D[i])max = D[i];
	}

	for(int i = 4000; i >= 0; i--){
		if(count<2){
			if(D[i]!=0 && max == D[i]){
				id = i*-1;
				count++;
			}
		}else break;
	}
	for(int i = 4001; i<8001; i++){
		if(count<2){
			if(D[i]!=0 && max == D[i]){
				id = i-4000;
				count++;
			}
		}else break;
	}

	sort(A, A+N);
	printf("%.0f\n",(sum!=0)?(sum/N <0 && sum/N>=-0.5)?0:sum/N:0);
	printf("%d\n", A[N/2]);
	printf("%d\n", id);
	printf("%d\n", A[N-1]-A[0]);
}
