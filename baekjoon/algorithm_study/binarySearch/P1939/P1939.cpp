#include <cstdio>
#include <queue>
#include <memory.h>
using namespace std;
vector<pair<int, long long> > MAP[10001];
int C[10001] = {0,};
int N, M, X, Y;
long long ans = 0;
void bsr(long long low, long long high);
bool bfs(long long mid);
int main(){
	scanf("%d %d", &N, &M);
	long long max = 0;
	for(int i = 0; i < M; i++){
		int x, y;
		long long w;
		scanf("%d %d %lld", &x, &y, &w);
		if(w > max)max = w;
		MAP[x-1].push_back(make_pair(y-1, w));
		MAP[y-1].push_back(make_pair(x-1, w));
	}
	scanf("%d %d", &X, &Y);
	X--;Y--;
	bsr(1ll, max);
	printf("%lld\n", ans);
}
void bsr(long long low, long long high){
	if(low <= high){
		long long mid = (low + high)/2;
		if(bfs(mid)){
			if(mid > ans)ans = mid;
			bsr(mid+1, high);
		}else bsr(low, mid-1);
	}
}
bool bfs(long long mid){
	queue<int> q;
	q.push(X);
	C[X] = mid;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		for(int i = 0; i < MAP[x].size(); i++){
			if(MAP[x][i].second >= mid && C[MAP[x][i].first] != mid){
				if(MAP[x][i].first == Y)return true;
				C[MAP[x][i].first] = mid;
				q.push(MAP[x][i].first);
			}
		}
	}
	return false;
}
