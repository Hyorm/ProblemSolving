#include <cstdio>
#include <vector>
using namespace std;
vector<long long> S;
void f(int x){
	if(S.size() <= x-1)f(x-1);
	S.push_back((S[x-3]+S[x-2]+S[x-1])%1000000009);
}
int main(){
	int T;
	scanf("%d", &T);
	S.push_back(0);
	S.push_back(1);
	S.push_back(2);
	S.push_back(4);
	for(int i = 0; i <T; i++){
		int N;
		scanf("%d", &N);
		if(S.size() <= N)f(N);
		printf("%lld\n", S[N]);
	}
}
