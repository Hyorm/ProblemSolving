#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	int N;
	scanf("%d", &N);
	vector<long long> v;
	for(int i = 0; i < N; i++){
		long long tmp;
		scanf("%lld", &tmp);
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());
	int n = v.size()-1;
	for(int i = n-1;i>=0;i--){
		if(v[n]%v[i]!=0){
			for(int j = i-1; j >= 0; j--){
				if(v[n]%v[j]==0&&v[i]%v[j]==0){
					printf("%lld\n", (v[n]/v[j]*v[i]));
					return 0;
				}
			}
		}
	}
	printf("%lld\n", v[0]*v[n]);
}
