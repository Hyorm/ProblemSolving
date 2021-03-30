#include <cstdio>
#include <memory.h>
using namespace std;
long long N;
int M;
int O[10001];
int R[10001];

int main(){
	long long T = 0;
	int ans = 0;
	scanf("%lld %d", &N, &M);
	for(int i = 0; i < M; i++){
		scanf("%d", &O[i]);
	}
	memcpy(R, O, sizeof(int)*10001);
	if(N > M)N -= M;
	else{
		printf("%lld\n", N);
		return 0;
	}
	while(N > 0){
		for(int i = 0; i < M; i++){
			R[i]--;
			if(R[i]==0){
				N--;
				if(N==0){
					ans = i+1;
					break;
				}
				R[i] = O[i];
			}
		}
		T++;
	}
	printf("%d\n", ans);
}
