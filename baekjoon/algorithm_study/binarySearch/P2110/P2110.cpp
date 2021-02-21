#include <stdio.h>
#include <algorithm>
#include <memory.h>

using namespace std;

long long binarySearch(long long low, long long high);
int findDist(long long mid);

long long* home; 
int N, C;
long long answer = 0;

int main(int argc, char** argv){
	scanf("%d %d", &N, &C);

	home = new long long[N];
	
	for(int i = 0; i < N; i++){
		scanf("%lld", &home[i]);
	}

	sort(home, home + N);

	printf("%lld\n", binarySearch(1ll, home[N-1]));
	
	delete[] home;

	return 0;
}

long long binarySearch(long long low, long long high){

	if(low > high){
		return answer;
	}
	long long mid = (low+high)/2;

	int check = findDist(mid);
	if(check >= C){
		answer = mid;
		return binarySearch(mid+1,high);
	}
	return binarySearch(low, mid-1);
}

int findDist(long long mid){
	int check = 1;
	int bf_h = home[0];

	for(int i = 1; i < N; i++){
		if(home[i] >= check * mid && (home[i] - bf_h) >= mid){
			bf_h = home[i];
			check++;
		}
	}
	return check;
}
