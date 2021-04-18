#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
int N;
int D[100002];
int main(){
	scanf("%d", &N);
	D[1]=1;
	vector<int> R;
	R.push_back(1);
	for(int i = 2; i <= N; i++){
		double T = sqrt(i);
		for(int j = 0; j < R.size();j++){
			if((T-sqrt(R[j]))==1){
				R.push_back(i);
				D[i] = 1;
				break;
			}
			else D[i] = (D[i]!=0&&D[i]<D[R[j]]+D[i-R[j]])?D[i]:D[R[j]]+D[i-R[j]];
		}
	}
	printf("%d\n", D[N]);
}
