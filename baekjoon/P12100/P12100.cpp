#include <iostream>
#include <stdio.h>
using namespace std;

void check(int** room);
void up(int** room, int times);
void down(int** room, int times);
void left(int** room, int times);
void right(int** room, int times);
void print(int** room);
int max_b;

int N;

void check(int** room){
	//printf("\n");
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(room[i][j]>max_b){
				max_b = room[i][j];
			}
			//printf("%d ", room[i][j]);
		}
		//printf("\n");
	}
	//printf("\n");
}

void up(int** room, int times){
	//printf("up\n");
	for(int i = 0; i < N; i++){//y
		bool* ch = new bool[N];
		memset(ch, true, sizeof(bool)*N);
		for(int j = 1; j < N; j++){//x
			if(room[j][i] == 0){
                continue;
            }
			int tmp = j;
			int m = 1;
			while(tmp - 1 > -1){//can move
				if(room[tmp - 1][i] == room[j][i] && ch[tmp - 1]){//can merge
					ch[tmp - 1] = false;
					room[tmp - 1][i] += room[j][i];
					m = 1;
					room[j][i] = 0;
					break;
				}

				if(room[tmp - 1][i] == 0){
					m = 0;
					tmp--;
				}else{
					break;
				}
			}
			if(m == 0){
				room[tmp][i] = room[j][i];
				room[j][i] = 0;
			}
		}
	}
	check(room);
	times++;
	if(times < 5){
		up(room, times);
		down(room, times);
		right(room, times);
		left(room, times);
	}
}

void down(int** room, int times){
	//printf("down\n");
	for(int i = 0; i < N; i++){//y
        bool* ch = new bool[N];
        memset(ch, true, sizeof(bool)*N);
        for(int j = N - 2; j > - 1; j--){//x
            if(room[j][i] == 0){
                continue;
            }
			int tmp = j;
            int m = 1;
            while(tmp + 1 < N){//can move range
                if(room[tmp + 1][i] == room[j][i] && ch[tmp + 1]){//can merge
                    ch[tmp + 1] = false;
                    room[tmp + 1][i] += room[j][i];
                    m = 1;
					room[j][i] = 0;
                    break;
                }

                if(room[tmp + 1][i] == 0){//can move
                    m = 0;
					tmp++;
                }else{//can't move
                    break;
                }
            }
            if(m == 0){
                room[tmp][i] = room[j][i];
				room[j][i] = 0;
            }
        }
    }

	check(room);
    times++;
    if(times < 5){
        up(room, times);
        down(room, times);
        right(room, times);
        left(room, times);
    }
}

void left(int** room, int times){
	//printf("left\n");
	for(int i = 0; i < N; i++){//x
        bool* ch = new bool[N];
        memset(ch, true, sizeof(bool)*N);
        for(int j = 1; j < N; j++){//y
			if(room[i][j] == 0){
				continue;
			}
            int tmp = j;
            int m = 1;
            while(tmp - 1 > -1){//can move
                if(room[i][tmp - 1] == room[i][j] && ch[tmp - 1]){//can merge
                    ch[tmp - 1] = false;
                    room[i][tmp - 1] += room[i][j];
                    m = 1;
					room[i][j] = 0;
                    break;
                }

                if(room[i][tmp - 1] == 0){
                    tmp--;
					m = 0;
                }else{
                    break;
                }
            }
            if(m == 0){
                room[i][tmp] = room[i][j];
				room[i][j] = 0;
            }
			
        }
    }

	check(room);
    times++;
    if(times < 5){
        up(room, times);
        down(room, times);
        right(room, times);
        left(room, times);
    }
}

void right(int** room, int times){
	//printf("right\n");
	for(int i = 0; i < N; i++){//x
        bool* ch = new bool[N];
        memset(ch, true, sizeof(bool)*N);
        for(int j = N-2; j > -1; j--){//y
			if(room[i][j] == 0){
                continue;
            }
            int tmp = j;
            int m = 1;
            while(tmp + 1 < N){//can move
                if(room[i][tmp + 1] == room[i][j] && ch[tmp + 1]){//can merge
                    ch[tmp + 1] = false;
                    room[i][tmp + 1] += room[i][j];
                    m = 1;
					room[i][j] = 0;
                    break;
                }

                if(room[i][tmp + 1] == 0){
                    tmp++;
					m = 0;
                }else{
                    break;
                }
            }
            if(m == 0){
                room[i][tmp] = room[i][j];
				room[i][j] = 0;
            }
        }
    }

	check(room);
    times++;
    if(times < 5){
        up(room, times);
        down(room, times);
        right(room, times);
        left(room, times);
    }
}

int main(int argc, char** argv){
	scanf("%d", &N);

	int** room = new int*[N];
	for(int i = 0 ; i < N; i++){
		room[i] = new int[N];
		for(int j = 0; j < N; j++){
			cin >> room[i][j];
		}
	}

	//UP
	up(room, 0);
	//DOWN
	down(room, 0);
	//RIGHT
	right(room, 0);
	//LEFT
	left(room, 0);
	printf("%d\n", max_b);
}
