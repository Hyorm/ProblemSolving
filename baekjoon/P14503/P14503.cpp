#include <stdio.h>
#include <iostream>
#include <memory.h>

using namespace std;
enum Cmps{
	CMPS_N,
	CMPS_E,
	CMPS_S,
	CMPS_W
};

int max_clean = 0;
int row, col;//dir = +1 %4
int clean = 0;
int cur_r, cur_c, dir, spin = 0;
void printRoom();
void cleaning(int go);
int** room;

int main(int argv, char** argc){
	cin>>row>>col;
	cin>>cur_r>>cur_c>>dir;

	room = new int*[row];


	for(int i = 0 ; i < row; i++){
		room[i] = new int[col];
		for(int j = 0; j < col; j++){
			cin>>room[i][j];
			if(room[i][j]==0){
				max_clean++;
			}
		}
	}
	clean++;
	cleaning(2);
	cout<<clean<<endl;
	for(int i = 0 ; i < row; i++){
		delete[] room[i];
	}

	delete room;

}

void printRoom(){
	for(int i = 0 ; i < row; i++){
		for(int j = 0; j < col; j++){
			cout<<room[i][j]<<" ";
		}
		cout<<endl;
	}
}

void cleaning(int go){
	cout<<"cur ("<<cur_r<<", "<<cur_c<<") - "<<room[cur_r][cur_c]<<" dir: "<<dir<<" spin: "<<spin<<endl;
	if(go == 2){
		room[cur_r][cur_c] = 2;
	}

	if(spin == 4){
		//backstep
		spin = 0;
		if(dir == CMPS_N){
			if((cur_r + 1) < row){
				if(room[cur_r + 1][cur_c] == 0){
					cur_r++;
					clean++;
					spin = 0;
					cleaning(2);
				}
				else{
					cur_r++;
					spin = 0;
					cleaning(0);
				}
			}
		}
		else if(dir ==CMPS_E){
			if((cur_c - 1) > 0){
				if(room[cur_r][cur_c - 1] == 0){
					cur_c--;
					clean++;
					spin = 0;
					cleaning(2);
				}
				else{
					cur_c--;
					spin = 0;
					cleaning(0);
				}
			}
		}
		else if(dir == CMPS_S){
			if((cur_r - 1) > 0){
				if(room[cur_r - 1][cur_c] == 0){
					cur_r--;
					clean++;
					spin = 0;
					cleaning(2);
				}
				else{
					cur_r--;
					spin = 0;
					cleaning(0);
				}
			}
		}else{
			if((cur_c + 1) < col){
				if(room[cur_r][cur_c + 1] == 0){
					cur_c++;
					clean++;
					spin = 0;
					cleaning(2);
				}
				else{
					cur_c++;
					spin = 0;
					cleaning(0);
				}
			}
		}
		
	}
	//N
	else{
		if(dir == CMPS_S){
			dir = CMPS_E;
			if((cur_c + 1) < col && room[cur_r][cur_c + 1] == 0){
				cur_c++;
				clean++;
				spin = 0;
				cleaning(2);
			}else{
				spin++;
				cleaning(0);
			}
		}
		//E
		else if(dir == CMPS_W){
			dir = CMPS_S;
			if((cur_r + 1) < row && room[cur_r + 1][cur_c] == 0){
				cur_r++;
				clean++;
				spin = 0;
				cleaning(2);
			}else{
				spin++;
				cleaning(0);
			}
		}
		//S
		else if(dir == CMPS_N){
			dir = CMPS_W;
			if((cur_c - 1) > 0 && room[cur_r][cur_c - 1] == 0){
				cur_c--;
				clean++;
				spin = 0;
				cleaning(2);
			}
			else{
				spin++;
				cleaning(0);
			}
		}
		//W
		else{
			dir = CMPS_N;
			if((cur_r - 1) > 0 && room[cur_r - 1][cur_c] == 0){
				cur_r--;
				clean++;
				spin = 0;
				cleaning(2);
			}else{
				spin++;
				cleaning(0);
			}
		}
	}
}
