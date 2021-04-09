#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
int MAP[51][51];
int N, M, C = 0;
int m = 51*51;
vector<pair<int, int> > CP;
int fd(int ox, int oy){
	int md = 51*51;
	for(int i = 0; i < CP.size(); i++){
		int x = CP[i].first;
		int y = CP[i].second;
		if(MAP[x][y]==2){
			int d = abs(ox - x)+abs(oy - y);
			if(md > d)md = d;
		}
	}
	return md;
}
void sc(int d, int bx, int by){
	if(d==C-M){
		int sum = 0;
		for(int k = 0; k < N; k++){
			for(int l = 0; l < N; l++){
				if(MAP[k][l]==1){
					sum += fd(k, l);
				}
			}
		}
		if(sum < m)m = sum;
	}
	else{
		for(int i = bx; i < N; i++){
			if(i>bx)by = -1;
			for(int j = by+1; j < N; j++){
				if(MAP[i][j]==2){
					MAP[i][j] = 0;
					sc(d+1, i, j);
					MAP[i][j] = 2;
				}
			}
		}	
	}
}
int main(){
	scanf("%d %d", &N, &M);
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			scanf("%d", &MAP[i][j]);
			if(MAP[i][j] == 2){
				CP.push_back(make_pair(i, j));
				C++;
			}
		}
	}
	int cd = 0;
	if(M==C){
		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				if(MAP[i][j]==1){
					cd += fd(i, j);
				}
			}
		}
		printf("%d\n", cd);
		return 0;
	}
	sc(0, -1, -1);
	printf("%d\n", m);
}
