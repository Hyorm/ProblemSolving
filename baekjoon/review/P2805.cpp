#include <cstdio>
#include <vector>
using namespace std;
long long ans = 0;
int N, M;
vector<int> T;
bool check(long long mid){
	long long sum = 0;
	for(const auto &i: T){
		sum += (i-mid>=0)?i-mid:0;
		if(sum>=M)return true;
	}
	return false;
}
void bin(long long low, long long high){
	if(low <= high){
		long long mid = (low+high)/2;
		if(check(mid)){
			if(ans < mid)ans = mid;
			bin(mid+1, high);
		}
		else bin(low, mid-1);
	}

}
int main(){
	int max = 0;
	scanf("%d %d", &N, &M);
	for(int i = 0; i < N; i++){
		int tmp;
		scanf("%d", &tmp);
		if(tmp>max)max = tmp;
		T.push_back(tmp);
	}
	bin(1, max-1);
	printf("%lld\n", ans);
}
