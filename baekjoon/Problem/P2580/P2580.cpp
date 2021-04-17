#include <cstdio>
#include <vector>
using namespace std;
vector<pair<int, int> > Z;
bool check_x(int x, int y, int v, int** S){
	for(int i = 0; i < 9; i++){
		if(i!= x && S[i][y]==v)return false;
	}
	return true;
}
bool check_y(int x, int y,int v, int** S){
	for(int i = 0; i < 9; i++){
		if(i!= y && S[x][i]==v)return false;
	}
	return true;
}
bool check_c(int x, int y, int v, int** S){
	for(int i = (x/3)*3; i < (x/3)*3+3; i++){
		for(int j = (y/3)*3; j < (y/3)*3+3; j++){
			if(i!= x && j != y && S[i][j]==v)return false;
		}
	}
	return true;
}
bool find(int id, int** S){
	if(id < Z.size()){
		int x = Z[id].first;
		int y = Z[id].second;
		for(int i = 0; i < 9; i++){
			if(check_x(x, y, i, S)&&check_y(x, y, i, S)&&check_c(x, y, i, S)){
				S[x][y] = i;
				if(!find(id+1, S)){
					S[x][y] = -1;
				}else return true;
			}
		}return false;
	}
	return true;
}
int main(){
	int** S = new int*[9];
	for(int i = 0; i < 9; i++){
		S[i] = new int[9];
		for(int j = 0; j < 9; j++){
			scanf("%d", &S[i][j]);
			S[i][j]--;
			if(S[i][j]==-1)Z.push_back(make_pair(i, j));
		}
	}
	find(0, S);
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			printf("%d ", S[i][j]+1);
		}
		printf("\n");
	}
}
