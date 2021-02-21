#include <stdio.h>
#include <memory.h>
#include <algorithm>

using namespace std;

int O, S;

long long* own;
long long* srv;

int answer;

long long binarySearch(long long val, long long low, long long high);
int findIdx(long long mid);

int main(){
	scanf("%d", &O);
	
	own = new long long[O];

	for(int i = 0 ; i < O; i++){
		scanf("%lld", &own[i]);
	}
	
	scanf("%d", &S);
	
	srv = new long long[S];

	for(int i = 0; i < S; i++){
		scanf("%lld", &srv[i]);
	}	

	sort(own, own+O);
	
	for(int i = 0 ; i < S; i++){
		answer = 0;
		printf("%lld ", binarySearch(srv[i], 0, O - 1));
	}
	printf("\n");
	
	delete[] own;
	delete[] srv;

	return 0;
}

long long binarySearch(long long val, long long low, long long high){
	if(low > high){
		return 0;
	}
	long long mid = (low + high)/2;
	if(val == own[mid]){
		return 1;
	}
	if(val > own[mid]){
		return binarySearch(val, mid + 1, high);
	}

	return binarySearch(val, low, mid - 1);
}
