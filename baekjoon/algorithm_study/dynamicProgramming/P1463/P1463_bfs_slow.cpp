#include <cstdio>
#include <queue>
using namespace std;

int N;
int M[1000001] = {0,};
int main(){
	scanf("%d", &N);
	queue<int> q;
	q.push(N);
	M[N] = 0;
	while(!q.empty()){
		int n = q.front();
		q.pop();
		if(n%3 == 0 && M[n/3]==0){
			if(n/3 > 1){
				q.push(n/3);
			}
			M[n/3] = M[n] + 1;
		}
		if(n%2 == 0 && M[n/2]==0){
			if(n/2 > 1){
				q.push(n/2);
			}
			M[n/2] = M[n] + 1;
		}
		if(M[n-1]==0){
			if(n - 1 > 1){
				q.push(n-1);
			}
			M[n-1] = M[n] + 1;
		}
	}
	printf("%d\n", M[1]);
}
