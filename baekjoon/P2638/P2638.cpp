#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int N, M;
int* MAP;
bool* check;
bool out(int cur, int dir);
int main(){
	
	int answer = 0;
	int cc = 0;
	scanf("%d %d", &N, &M);
	MAP = new int[N*M];
	check= new bool[N*M];
	for(int i = 0; i < N * M; i++){
		int tmp;
		cin >> tmp;
		if(tmp == 1)cc++;
		MAP[i] = tmp;
	}
	while(cc > 0){
		for(int i = 0; i < N*M; i++){
			if(MAP[i] == 1){
				int ck = 0;
			
            	if((MAP[i-M]== 0) && out(i-M, 0))ck++;
            	if((MAP[i+M]== 0) && out(i+M, 1))ck++;
            	if((MAP[i+1]== 0) && out(i+1, 2))ck++;
            	if((MAP[i-1]== 0) && out(i-1, 3))ck++;
				
				if(ck >= 2){
					MAP[i] = 2;
				}
			}

		}
		answer++;
		for(int i = 0; i < N*M; i++){
			if(MAP[i]==2){
				check[i] = true;
				MAP[i] = 0;
				cc--;
			}
		}
	}
	printf("%d\n", answer);
}
bool out(int cur, int dir){
	if(cur/M < 1 || cur/M >= N-1 || cur%M < 1 || cur%M >= M-1 ||check[cur]==true){
		check[cur] = true;
		return true;
	}
	else{
		if((dir != 1)&&((cur-M)/M > -1)&&(MAP[cur-M]==0)){
			check[cur-M] = out(cur-M, 0);
			return check[cur-M];
		}
		if((dir != 0)&&((cur+M)/M < N)&&(MAP[cur+M]== 0)){
			check[cur+M] = out(cur+M, 1);
			return check[cur+M];
		}
		if((dir != 3)&&((cur+1)%M < M)&&(MAP[cur+1]==0)){
			check[cur+1] = out(cur+1, 2);
			return check[cur+1];
		}
		if((dir != 2)&&((cur-1)%M > -1)&&(MAP[cur-1]==0)){
			check[cur-1] = out(cur-1, 3);
			return check[cur-1];
		}
	}
	return false;
}
