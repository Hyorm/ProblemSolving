#include <cstdio>

using namespace std;
long long N, M, ans;
long long L[1000000];

void brs(long long low, long long high);
bool calc(long long mid);

int main(){
	scanf("%lld %lld", &N, &M);
	long long max = 0;
	for(int i = 0; i < N; i++){
		scanf("%lld", &L[i]);
		if(L[i] > max)max = L[i];
	}

	brs(1ll, max);
	printf("%lld\n", ans);
}

void brs(long long low, long long high){
	if(low <= high){
		long long mid = (low+high)/2;
		if(calc(mid)){
			if(mid > ans)ans = mid;
			brs(mid+1, high);
		}else brs(low, mid-1);
	}
}

bool calc(long long mid){
	long long tmp = 0;
	for(int i = 0 ; i < N; i++){
		if(L[i]-mid > 0)
			tmp += L[i] - mid;
		if(tmp >= M)return true;
	}
	return false;
}
