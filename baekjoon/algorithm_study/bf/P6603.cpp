#include <cstdio>
#include <set>
#include <vector>
using namespace std;
set<vector<int> >S;
void comb(int d, int bf, int* tmp, vector<int> org){
	if(d< 6){
		for(int i = bf; i<org.size(); i++){
			tmp[d] = org[i];
			comb(d+1, i+1, tmp, org);
		}
	}
	else{
		vector<int> t;
		for(int i = 0; i < 6; i++){
			t.push_back(tmp[i]);
		}
		S.insert(t);
	}
}
int main(){
	int T = 1, id = 0;
	scanf("%d", &T);
	do{
		if(id++!=0)printf("\n");
		vector<int> org;
		int * tmp;
		tmp = new int[6];
		for(int i = 0; i < T; i++){
			int tmp;
			scanf("%d", &tmp);
			org.push_back(tmp);
		}
		comb(0, 0, tmp, org);
		for(const vector<int>& s:S){
			for(const int&i : s){
				printf("%d ", i);
			}
			printf("\n");
		}
		S.clear();
		scanf("%d", &T);
	}while(T!=0);
}
