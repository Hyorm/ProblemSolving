#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;
int answer = 0;
long long binarySearch(long long* list, int K, int N, long long low, long long high);
int sumTree(long long* list, int K, long long len);
long long up = 0;
int main(int argv, char** argc){
	int K, N;

	scanf("%d %d", &K, &N);
	
	long long * list = new long long[K];
	for(int i = 0; i<K; i++){
		scanf("%lld",&list[i]);
	}
	sort(list, list+K);
	printf("%lld\n",binarySearch(list, K, N, 1ll, list[K-1]));
	delete[] list;

	return 0;
}

long long binarySearch(long long* list, int K, int N, long long low, long long high){
	if(low > high){
		return answer;
	}
	long long len = (low+high)/2;
	int sum = sumTree(list, K, len);
	//cout<<" "<<sum<<endl;
	
	if(sum >= N){
		answer = len;
		return binarySearch(list, K, N, len + 1, high);
	}
	return binarySearch(list, K, N, low, len - 1);
}

int sumTree(long long* list, int K, long long len){
	int sum = 0;
	for(int i = 0; i < K; i++){
		sum += list[i] / len;
	}
	return sum;
}
