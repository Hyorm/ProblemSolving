#include <cstdio>
#include <algorithm>
using namespace std;
long long N, C, ans;
long long *X;

void brs(long long low, long long high);
bool calc(long long mid);

int main(){
	scanf("%lld %lld", &N, &C);
	X = new long long[N];
	for(int i = 0; i < N; i++){
		scanf("%lld", &X[i]);
	}
	sort(X, X+N);
	brs(1ll, X[N-1]);
	printf("%lld\n", ans);
}

void brs(long long low, long long high){
	if(low <= high){
		long long mid = (low + high)/2;
		if(calc(mid)){
			if(ans < mid)ans = mid;
			brs(mid+1, high);
		}else brs(low, mid-1);
	}
}

bool calc(long long mid){
	int bf = 0;
	long long tmp = 1;
	for(int i = 1; i < N; i++){
		if(X[i]-X[bf] >= mid){
			bf = i;
			tmp++;
			if(tmp >= C)return true;
		}
	}
	return false;
}
