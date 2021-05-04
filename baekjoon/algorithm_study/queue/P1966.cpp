#include <cstdio>
#include <queue>
#include <memory.h>
using namespace std;
int main(){
	int T;
	scanf("%d", &T);
	for(int i = 0; i < T; i++){
		int N, M, ans = 0;
		int P[10] = {0,};
		queue<pair<int, int> > q;
		scanf("%d %d", &N, &M);
		for(int j = 0; j < N; j++){
			int tmp;
			scanf("%d", &tmp);
			q.push(make_pair(j, tmp));
			P[tmp]++;
		}
		while(!q.empty()){
			int now = q.front().first;
			int prio = q.front().second;
			int f = 0;
			for(int j = 9; j > prio; j--){
				if(P[j]>0){
					f = 1;
					break;
				}
			}
			if(f==1){
				q.pop();
				q.push(make_pair(now, prio));
			}else{
				ans++;
				q.pop();
				P[prio]--;
				if(M==now){
					printf("%d\n", ans);
					break;
				}
			}
		}
	}
}
