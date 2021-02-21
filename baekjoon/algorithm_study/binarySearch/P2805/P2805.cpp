#include <stdio.h>
#include <algorithm>

using namespace std;

int K, N;
long long answer = 0;

int binarySearch(long long* trs, long long low, long long high);
long long sumTree(long long* trs, long long mid);

int main(int argc, char** argv){
	scanf("%d %d", &K, &N);	
	long long trs[1000001];
	
	for(int i = 0; i < K; i++){
		scanf("%lld", &trs[i]);
	}
	sort(trs, trs+K);
	printf("%d\n",binarySearch(trs, 1ll, trs[K-1]));
	return 0;
}

int binarySearch(long long* trs, long long low, long long high){

	if(low > high){
		return answer;
	}

	long long mid = (low+high)/2;

	long long sum = sumTree(trs, mid);
	if(sum >= N){
		answer = mid;
		return binarySearch(trs, mid + 1, high);
	}
	return binarySearch(trs, low, mid - 1);
}

long long sumTree(long long* trs, long long mid){
	long long sum = 0;

	for(int i = 0; i < K; i++){
		if(trs[i] > mid){
			sum += trs[i] - mid;
		}
	}
	return sum;
}
