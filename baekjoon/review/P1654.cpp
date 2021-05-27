#include <cstdio>
#include <vector>
using namespace std;
long long ans = 0;
vector<long long> L;
bool check(long long mid, int N){
	int tmp = 0;
	for(const auto &i: L){
		tmp += i/mid;
		if(tmp>=N)return true;
	}
	return false;
}
void bin(long long low, long long high, int N){
	if(low<=high){
		long long mid = (low+high)/2;
		if(check(mid, N)){
			if(ans<mid)ans = mid;
			bin(mid+1, high, N);
		}
		else bin(low, mid-1, N);
	}
}
int main(){
	int K, N, max = 0;
	scanf("%d %d", &K, &N);
	for(int i = 0; i < K; i++){
		int k;
		scanf("%d", &k);
		L.push_back(k);
		if(max<k)max = k;
	}
	bin(1, max, N);
	printf("%lld\n", ans);
}
