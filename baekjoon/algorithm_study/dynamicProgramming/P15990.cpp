#include <cstdio>
#include <memory.h>
using namespace std;

int main(){
	long long DP1[100002];
	long long DP2[100002];
	long long DP3[100002];
	int N, T;
	memset(DP1, 0, sizeof(long long)*100002);
	memset(DP2, 0, sizeof(long long)*100002);
	memset(DP3, 0, sizeof(long long)*100002);
	scanf("%d", &T);
	DP1[1] = 1;
	DP2[2] = 1;
	DP1[3] = 1;
	DP2[3] = 1;
	DP3[3] = 1;

	for(int i = 0; i < T; i++){
		scanf("%d", &N);
		for(int j = 4; j <= N; j++){
			DP1[j] = (DP2[j-1]+DP3[j-1])%1000000009;
			DP2[j] = (DP1[j-2]+DP3[j-2])%1000000009;
			DP3[j] = (DP1[j-3]+DP2[j-3])%1000000009;
		}
		printf("%lld\n",(DP1[N]+DP2[N]+DP3[N])%1000000009);
	}
}	
