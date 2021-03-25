#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

vector<int> G;
void dfs(int A, int P);
int main(){
	int A, P;
	scanf("%d %d", &A, &P);
	G.push_back(A);
	dfs(A, P);
	printf("%lu\n", G.size());
}

void dfs(int A, int P){
	int sum = 0;
	while(A/10 > 0){
		sum += pow((A%10),P);
		A /= 10;
	}
	sum += pow((A%10),P);
	auto it = find(G.begin(), G.end(), sum);
	if(it != G.end()){
		G.erase(it, G.end());
	}else{
		G.push_back(sum);
		dfs(sum, P);
	}
}
