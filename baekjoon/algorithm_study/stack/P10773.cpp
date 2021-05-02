#include<cstdio>
#include<stack>
using namespace std;
int main(){
	int N;
	long long ans = 0;
	scanf("%d", &N);
	stack<int> s;
	for(int i = 0; i < N; i++){
		int t;
		scanf("%d", &t);
		if(t==0&&!s.empty())s.pop();
		else s.push(t);
	}
	while(!s.empty()){
		ans += s.top();
		s.pop();
	}
	printf("%lld\n", ans);
}
