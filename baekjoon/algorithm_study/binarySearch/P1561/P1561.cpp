#include <cstdio>

using namespace std;

long long N, ans;
int M;
int O[10001];
void brs(long long low, long long high);
int calc(long long mid);//-1 down 0 return 1 up
int main(){
	scanf("%lld %d", &N, &M);
	int max = 0;
	for(int i = 0 ; i < M; i++){
		scanf("%d", &O[i]);
		if(O[i]>max)max = O[i];
	}
	brs(0, N*max);
	printf("%lld\n", ans);
}

void brs(long long low, long long high){
	if(low <= high){
		long long mid = (low + high)/2;
		int ck = calc(mid);
		if(ck < 0)brs(low, mid - 1);
		else if(ck > 0)brs(mid + 1, high);
	}
}
int calc(long long mid){
	long long bf = 0;
	if(mid > 0){
		bf += M;
		for(int i = 0; i < M; i++){
			bf += (mid-1)/O[i];
		}
	}
	if(bf == N)return -1;
	for(int i = 0; i < M; i++){
		if(mid != 0) bf += (mid%O[i] == 0)? 1:0;
		else bf++;
		if(bf == N){
			ans = i+1;
			return 0;
		}
	}
	if(bf > N)return -1;
	return 1;
}
