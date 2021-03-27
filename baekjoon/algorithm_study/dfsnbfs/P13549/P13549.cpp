#include <cstdio>
#include <queue>
#include <memory.h>
using namespace std;
#define COT 100001
int main(){
	int V[COT];
	int N, K;
	scanf("%d %d", &N, &K);
	
	queue<pair<int,int> > q;
	q.push(make_pair(N, 0));
	memset(V, -1, sizeof(int)*COT);
	V[N] = 0;
	while(!q.empty()){
		N = q.front().first;
		int time = q.front().second;
		q.pop();
		if(2*N < COT && (V[2*N] == -1||V[2*N] > time)){
			V[2*N] = time;
            if(2*N != K){
                q.push(make_pair(2*N, time));
            }
        }
		if(N+1<COT && (V[N+1]== -1 || V[N+1] > time+1)){
			V[N+1] = time+1;
			if(N+1!=K){
				q.push(make_pair(N+1, time+1));
			}
		}
		if(N-1 >= 0 && (V[N-1] == -1 || V[N-1] > time+1)){
			V[N-1] = time+1;
			if(N-1!=K){
				q.push(make_pair(N-1, time+1));
			}
		}
	}
	printf("%d\n", V[K]);
}
