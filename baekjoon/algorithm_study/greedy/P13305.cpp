#include <cstdio>
using namespace std;
long long W[100000], O[100000];
int N;
int main(){
	scanf("%d", &N);
	for(int i = 0; i < N-1; i++)scanf("%lld", &W[i]);
	for(int i = 0; i < N; i++)scanf("%lld", &O[i]);
	long long ans = 0;
	int n = 0;
	int p = 0;
	while(n < N-1){
		ans+= W[n]*O[p];
		if(n+1<N-1&&O[n+1]<O[p]){
			p = n+1;
		}
		n++;
	}
	printf("%lld\n", ans);
}
