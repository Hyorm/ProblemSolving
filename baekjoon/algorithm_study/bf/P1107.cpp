#include <cstdio>
#include <cmath>
using namespace std;
long long R[10];
long long ans = 500001;
bool calc(long long mid, long long N){
	long long m = mid;
	long long tmp = abs(mid - N);
	while(m!=100&&mid > 0){
		if(R[mid%10]==1)return false;
		mid /= 10;
		tmp++;
	}
	if(m==0&&R[0]==1)return false;
	if(m==0)tmp++;
	if(tmp < ans)ans = tmp;
	return true;
}
int main(){
	int N, M;
	scanf("%d\n%d",&N, &M);
	for(int i = 0; i < M; i++){
		int t;
		scanf("%d", &t);
		R[t] = 1;
	}
	if(100 == N){printf("0\n");return 0;}
	if(101 == N||99==N){printf("1\n");return 0;}
	if(102 == N||98==N){printf("2\n");return 0;}
	for(long long i = 0; i < 1000000; i++)calc(i, N);
	printf("%lld\n", ans);
}
