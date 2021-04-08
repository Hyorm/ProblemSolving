#include <cstdio>
#include <vector>
using namespace std;

int A[101][101] = {0,};
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

void gen(vector<pair<int, int> > D, int C, int M){
	if(C>M)return;
	int ox = D[D.size()-1].first;
	int oy = D[D.size()-1].second;
	int DS = D.size();
	for(int i = DS-2; i >= 0; i--){
		int cx = (D[i].second - oy) * -1 + ox;
		int cy = D[i].first - ox + oy;
		D.push_back(make_pair(cx, cy));
		A[cy][cx] = 1;
	}
	gen(D, C+1, M);
}

int main(){
	int N;
	scanf("%d", &N);

	for(int i = 0; i < N; i++){
		int x, y, d, g;
		vector<pair<int, int> > D;
		scanf("%d %d %d %d", &x, &y, &d, &g);
		D.push_back(make_pair(x, y));
		D.push_back(make_pair(x+dx[d], y+dy[d]));
		A[y][x] = 1;
		A[y+dy[d]][x+dx[d]] = 1;
		gen(D, 1, g);
	}
	int ans = 0;
	for(int j = 0; j < 101; j++){
		for(int i = 0; i < 101; i++){
			int ulx = i, uly = j;
			int urx = i+1, ury = j;
			int dlx = i, dly = j+1;
			int drx = i+1, dry = j+1;
			if(ulx>=0&&ulx<101&&uly>=0&&uly<101&&urx>=0&&urx<101&&ury>=0&&ury<101&&dlx>=0&&dlx<101&&dly>=0&&dly<101&&drx>=0&&drx<101&&dry>=0&&dry<101){
				if(A[uly][ulx]==1&&A[ury][urx]==1&&A[dly][dlx]==1&&A[dry][drx]==1){
					ans++;
				}
			}
		}
	}
	printf("%d\n", ans);
}
