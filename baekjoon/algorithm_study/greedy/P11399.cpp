#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
	int N;
	scanf("%d", &N);
	int* P;
	P = new int[N];
	for(int i = 0; i < N; i++){
		scanf("%d", &P[i]);
	}
	sort(P, P+N);
	long long ans = 0;
	for(int i = 0; i < N; i++){
		for(int j = 0; j<=i;j++){
			ans += P[j];
		}
	}
	printf("%lld\n", ans);
}
