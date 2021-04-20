#include <cstdio>
#include <queue>
#include <set>
using namespace std;
int S;
int main(){
	scanf("%d",&S);
	queue<pair<pair<long long, long long>, long long> >q;
	q.push(make_pair(make_pair(1, 0), 0));
	set<pair<long long, long long> > V;
	V.insert(make_pair(1, 0));
	long long min = -1;
	while(!q.empty()){
		long long x = q.front().first.first;
		long long clip = q.front().first.second;
		long long time = q.front().second;
		q.pop();
		time++;
		if(min==-1||(min!=-1&&time<min)){
			if(V.insert(make_pair(x, x)).second)q.push(make_pair(make_pair(x, x),time));
			if(clip!=0){
				long long n = x + clip;
				if(n==S)min = time;
				if(V.insert(make_pair(n, clip)).second)q.push(make_pair(make_pair(n, clip),time));
			}
			if(x-1>=0&&x-1==S)min = time;
			if(x-1>=0)if(V.insert(make_pair(x-1, clip)).second)q.push(make_pair(make_pair(x-1, clip),time));
		}
	}
	printf("%lld\n", min);
}
