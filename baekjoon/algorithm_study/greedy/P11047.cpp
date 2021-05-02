#include <cstdio>
using namespace std;
long long P[10];
int main(){
	long long N, K, ans = 0;
	scanf("%lld %lld", &N, &K);
	for(int i = 0; i < N; i++)scanf("%lld", &P[i]);
	for(int i = N-1; i >= 0; i--){
		while(K>=P[i]&&K-P[i]>=0){
			K-= P[i];
			ans++;
		}
	}
	printf("%lld\n", ans);
}
