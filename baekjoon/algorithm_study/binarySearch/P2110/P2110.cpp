#include <stdio.h>
#include <algorithm>
#include <memory.h>

using namespace std;

int binarySearch(long long low, long long high);

long long* home; 
int N, C, answer = 0;


int main(int argc, char** argv){
	scanf("%d %d", N, C);

	home = new long long[N];
	
	for(int i = 0; i < N; i++){
		scanf("%lld", &home[i]);
	}

	sort(home, home + N);

	printf("%d", binarySearch(1ll, home[N-1]));
	
	delete[] home;

	return 0;
}

int binarySearch(long long low, long long high){


}
