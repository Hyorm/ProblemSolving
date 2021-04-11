#include <cstdio>
#include <queue>

using namespace std;

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

int MAP[21][21];
int S = 2, F = 0, N, dist=0, EF = 0;

void eat(int x, int y){
	int e = 0;
	while(F>0){
		e = 0;
		for(int i = 0; i<4; i++){
			int nx = x+dx[i];
			int ny = y+dy[i];
			if(nx>=0 && nx < N && ny >=0&&ny<N){
				if(MAP[nx][ny]!= 0&&MAP[nx][ny]<S){
					MAP[nx][ny] = 0;
					e = 1;
					EF++;
					if(EF==S){
						S++;
						EF = 0;
					}
					F--;
					dist++;
					x = nx;
					y = ny;
					break;
				}
			}
		}
		if(e==0){
			queue<pair<int, int> > mv;
			queue<int > ds;
			int V[21][21] = {{0,},};
			int f = 0;
			mv.push(make_pair(x, y));
			ds.push(0);
			int cx, cy, mx = N, my = N, md = 0;
			V[x][y] = 1;
			while(!mv.empty()){
				int ox = mv.front().first;
				int oy = mv.front().second;
				int d = ds.front();
				mv.pop(); ds.pop();
				if(f==1&&md<d)continue;
				for(int i = 0; i < 4; i++){
					int nx = ox + dx[i];
					int ny = oy + dy[i];
					if(nx>=0 && nx < N && ny >=0&&ny<N){
						if(V[nx][ny]==0){
							V[nx][ny] = 1;
							if(MAP[nx][ny]!= 0&&MAP[nx][ny]<S){
								f = 1;
								md = d;
								if(mx > nx){
									mx = nx;
									my = ny;
									cx = ox;
									cy = oy;
								}
								if(mx == nx && my>ny){
									mx = nx;
									my = ny;
									cx = ox;
									cy = oy;
								}
							}
							if(MAP[nx][ny]==S||MAP[nx][ny]==0){
								mv.push(make_pair(nx, ny));
								ds.push(d+1);
							}
						}
					}
				}
			}
			dist += md;
			x = cx;
			y = cy;
			if(f!=1)break;
		}
	}
}

int main(){
	int sx, sy;
	scanf("%d", &N);
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			scanf("%d", &MAP[i][j]);
			if(MAP[i][j]== 9){
				sx = i;
				sy = j;
				MAP[i][j] = 0;
			}
			if(MAP[i][j]>0 && MAP[i][j]<7){
				F++;
			}
		}
	}
	eat(sx, sy);
	printf("%d\n", dist);
}
