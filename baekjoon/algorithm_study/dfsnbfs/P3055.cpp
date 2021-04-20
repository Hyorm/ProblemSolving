#include <cstdio>
#include <queue>
#include <memory.h>
using namespace std;
char M[51][51];
int V[51][51];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int R, C;
void water(){
	int F[51][51];
	for(int i = 0; i < R; i++)memset(F[i], 0, sizeof(int)*C);
	for(int i = 0; i < R; i++){
		for(int j = 0; j < C; j++){
			if(M[i][j]=='*'&&F[i][j]==0){
				for(int k = 0; k < 4; k++){
					int nx = i + dx[k];
					int ny = j + dy[k];
					if(nx >= 0&& nx<R&& ny>=0 && ny < C){
						if(M[nx][ny]=='.'){
							F[nx][ny] = 1;
							M[nx][ny]='*';
						}
					}
				}
			}
		}
	}
}
int main(){
	queue<pair<pair<int, int>, int> >q;
	scanf("%d %d", &R, &C);
	for(int i = 0; i < R; i++){
		for(int j = 0; j < C; j++){
			scanf("%c", &M[i][j]);
			while(M[i][j]=='\n')scanf("%c", &M[i][j]);
			if(M[i][j]=='S'){
				q.push(make_pair(make_pair(i, j),0));
				M[i][j] = '.';
				V[i][j] = 1;
			}
		}
	}
	int KAK = 0;
	int cur = 0;
	while(!q.empty()){
		int x = q.front().first.first;
		int y = q.front().first.second;
		int time = q.front().second;
		if(cur==time){
			water();
			cur++;
		}
		q.pop();
		for(int i = 0; i < 4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(nx >= 0&& nx<R&& ny>=0 && ny < C){
				if(V[nx][ny]==0){
					switch(M[nx][ny]){
						case '.':V[nx][ny] = 1;
								 q.push(make_pair(make_pair(nx, ny),time+1));
							break;
						case 'X':
						case '*':
							break;
						case 'D':KAK = 1;
								 while(!q.empty())q.pop();
							break;
					}
				}
			}
			if(KAK==1)break;
		}
	}
	if(KAK==1)printf("%d\n", cur);
	else printf("KAKTUS\n");
}
