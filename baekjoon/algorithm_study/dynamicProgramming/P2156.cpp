#include <cstdio>
using namespace std;
int D[10002];
long long V[10002];
int N;
int main(){
	scanf("%d", &N);
	for(int i = 1; i <= N; i++){
		scanf("%d", &D[i]);
	}
	V[0] = 0;
	V[1] = D[1];
	V[2] = D[1] + D[2];
	long long max = V[2];
	for(int i = 3; i <= N; i++){
		long long a = V[i-2]+D[i], b = V[i-3]+D[i-1]+D[i], c = D[i]+D[(i-1>0)?i-1:0]+V[i-4];
		V[i] = (a>b)?(a>c)?a:c:(b>c)?b:c;
		if(V[i]>max)max = V[i];
	}
	printf("%lld\n", max);
	
}
