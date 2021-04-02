#include <cstdio>

using namespace std;

int N, mf = 0;
int A[11];
long long max = 0;
long long min = 0;

void calc(long long bf, int depth, int p, int m, int x, int d){
	if(depth == N){
		if(mf == 0 || max < bf)max = bf;
		if(mf++ == 0 || min > bf)min = bf;
	}else{
		if(p > 0)calc(bf+A[depth], depth+1, p-1, m, x, d);
		if(m > 0)calc(bf-A[depth], depth+1, p, m-1, x, d);
		if(x > 0)calc(bf*A[depth], depth+1, p, m, x-1, d);
		if(d > 0)calc(bf/A[depth], depth+1, p, m, x, d-1);
	}
}

int main(){
	int p, m, x, d;
	scanf("%d", &N);
	for(int i = 0; i < N; i++){
		scanf("%d", &A[i]);
	}
	scanf("%d %d %d %d", &p, &m, &x, &d);
	calc(A[0], 1, p, m, x, d);
	printf("%lld\n%lld\n", max, min);
}
