#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int N, M;
map<int, int> C;

bool* check;
bool out(int cur, int dir);
int main(){
	
	int answer = 0;

	scanf("%d %d", &N, &M);
	
	check= new bool[N*M];
	
	for(int i = 0; i < N * M; i++){
		int tmp;
		cin >> tmp;
		if(tmp == 1){
			C.insert(pair<int, int>(i, 0));
		}
	}
	while(!C.empty()){
		vector<int> R;
		for(auto it = C.begin();it != C.end(); it++){
			int ck = 0;
			int cur = it->first;
			if(C.find(cur-M)==C.end() && out(cur-M, 0))ck++;
			if(C.find(cur+M)==C.end() && out(cur+M, 1))ck++;
			if(C.find(cur+1)==C.end() && out(cur+1, 2))ck++;
			if(C.find(cur-1)==C.end() && out(cur-1, 3))ck++;
			if(ck >= 2){
				R.push_back(cur);
			}

		}
		answer++;
		for(const int &it: R){
			check[it] = true;
			C.erase(it);
		}
	}
	printf("%d\n", answer);
}
bool out(int cur, int dir){
	if(cur/M < 1 || cur/M >= N-1 || cur%M < 1 || cur%M >= M-1){
		check[cur] = true;
		return true;
	}
	
	if(check[cur]==true){
		return true;
	}
	else{
		if((dir != 1)&&((cur-M)/M > -1) && (C.find(cur-M)==C.end())){
			check[cur-M] = out(cur-M, 0);
			return check[cur-M];
		}
		if((dir != 0)&&((cur+M)/M < N)&&(C.find(cur+M)==C.end())){
			check[cur+M] = out(cur+M, 1);
			return check[cur+M];
		}
		if((dir != 3)&&((cur+1)%M < M)&&(C.find(cur+1)==C.end())){
			check[cur+1] = out(cur+1, 2);
			return check[cur+1];
		}
		if((dir != 2)&&((cur-1)%M > -1)&&(C.find(cur-1)==C.end())){
			check[cur-1] = out(cur-1, 3);
			return check[cur-1];
		}
	}
	return false;
}
