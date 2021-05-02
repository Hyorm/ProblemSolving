#include <cstdio>
#include <algorithm>
using namespace std;
bool cmp(int* a, int* b){
	if(a[1]==b[1])return a[0]<b[0];
	return a[1]<b[1];
}
int main(){
	int N;
	int** T;
	scanf("%d", &N);
	T = new int*[N];
	for(int i = 0; i < N; i++){
		T[i] = new int[2];
		scanf("%d %d", &T[i][0], &T[i][1]);
	}
	sort(T, T+N, cmp);
	int id = T[0][1], ans = 1;
	for(int i = 1; i < N; i++){
		if(T[i][0]>=id){
			id = T[i][1];
			ans++;
		}
	}
	printf("%d\n", ans);
}
