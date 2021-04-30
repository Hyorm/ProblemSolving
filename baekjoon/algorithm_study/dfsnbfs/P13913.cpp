#include <cstdio>
#include <queue>
#include <stack>
using namespace std;
int V[100002][2];
int main(){
	int N, K;
	scanf("%d %d", &N, &K);
	queue<pair<int, int> > q;
	q.push(make_pair(1, N));
	int time = -1, end = -1;
	if(N==K){printf("0\n%d\n", N);return 0;}
	V[N][0] = N;
	V[N][1] = 0;
	while(!q.empty()){
		int t = q.front().first;
		int d = q.front().second;
		q.pop();
		if(time==-1 || t<time){
			if(d-1>=0&&(V[d-1][0]==0||V[d-1][1]>=t)){
				V[d-1][0] = d;
				V[d-1][1] = t;
				if(d-1!=K)q.push(make_pair(t+1, d-1));
				else{
					time = t;end = d-1;continue;
				}
			}
			if(d+1<=100002&&(V[d+1][0]==0||V[d+1][1]>=t)){
				V[d+1][0] = d;
				V[d+1][1] = t;
				if(d+1!=K)q.push(make_pair(t+1, d+1));
				else{
					time = t;end = d+1;continue;
				}
			}
			if(2*d<=100002&&(V[2*d][0]==0||V[2*d][1]>=t)){
				V[2*d][0] = d;
				V[2*d][1] = t;
				if(2*d!=K)q.push(make_pair(t+1, 2*d));
				else{
					time = t;end = 2*d;continue;
				}
			}
		}
	}
	printf("%d\n", time);
	stack<int> path;
	path.push(end);
	while(end!=N){
		end = V[end][0];path.push(end);
	}
	while(!path.empty()){
		printf("%d ", path.top());path.pop();
	}
	printf("\n");
}
