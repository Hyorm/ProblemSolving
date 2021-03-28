#include <cstdio>
using namespace std;
long long A[1000000];
long long N, B, C;
long long answer = (long long)1000000*(long long)1000000;
long long bsr(long long low, long long high);
bool find(long long mid);
int main(){
	scanf("%lld", &N);
	for(long long i = 0; i < N; i++){
		scanf("%lld", &A[i]);
	}
	scanf("%lld %lld", &B, &C);
	long long sum = 0;
	for(long long i = 0; i < N; i++){
		A[i] -= B;
		if(A[i] < 0)A[i] = 0;
		sum += A[i];
	}
	if(sum != 0){
		bsr(0, answer);
	}else{
		answer = 0;
	}
	printf("%lld", N + answer);
}
long long bsr(long long low, long long high){
	if(low > high)return -1;
	long long mid = (low + high)/2;
	if(find(mid)){
		if(mid < answer){
			answer = mid;
		}
		bsr(low, mid-1);
	}
	else {
		bsr(mid+1, high);
	}
	return 1;
}
bool find(long long mid){
	for(long long i = 0; i < N; i++){
		if(mid > 0){
			if(A[i] != 0){
				mid -= A[i]/C;
				if(A[i]%C>0)mid--;
			}
		}else{
			if(A[i]!= 0){
				return false;
			}
		}
	}
	if(mid < 0)return false;
	return true;
}
