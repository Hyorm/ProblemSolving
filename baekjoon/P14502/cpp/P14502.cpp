#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

int** lab;
int** lab_wall;
int* safe;
int* virus;

int row, col, safeSize = 0, virusSize = 0, max_safe = 0;

void printLab(int** tmp_lab);

void findVirus();
void setVirus(int cur_row, int cur_col);
void countSafe(int** tmp_lab);
int checkMaxSafe(int tmp);

int main(int argc, char** argv){
	//DONE 1: stdin	
	cin >> row >> col;

	lab = new int*[row];
	lab_wall = new int*[row];

	safe = new int[row*col];
	virus = new int[row*col];

	for(int i = 0; i < row; i++){
		lab[i] = new int[col];
		memset(lab[i], 0, sizeof(int)*col);

		lab_wall[i] = new int[col];
		memset(lab_wall[i], 0, sizeof(int)*col);
	}

	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			cin>>lab[i][j];
			if(lab[i][j] == 0){
				safe[safeSize++] = i * col + j;
			}
			if(lab[i][j] == 2){
				virus[virusSize++] = i * col + j;
			}
		}
	}

	//TODO 2: Add Wall
	for(int i = 0; i < safeSize - 2; i++){//
		//ADD
		lab[safe[i]/col][safe[i]%col] = 1;
		
		for(int j = i + 1; j < safeSize - 1; j++){
			//ADD
			lab[safe[j]/col][safe[j]%col] = 1;
			
			for(int k = j + 1; k < safeSize; k++){
				//ADD
				lab[safe[k]/col][safe[k]%col] = 1;
				//cp lab to lab_wall
				
				for(int l = 0; l < row; l++){
					memcpy(lab_wall[l], lab[l], sizeof(int)*col);
				}
				
				findVirus();
				countSafe(lab_wall);
				//RMV
				lab[safe[k]/col][safe[k]%col] = 0;
			}
			
			//RMV
			lab[safe[j]/col][safe[j]%col] = 0;
		}
		
		//RMV
		lab[safe[i]/col][safe[i]%col] = 0;
	}
	//DONE : Clear

	cout <<max_safe<< endl ;

	for(int i = 0; i < row; i++){
		delete[] lab[i];
		delete[] lab_wall[i];
	}

	delete lab;
	delete lab_wall;

	return 0;
}

void printLab(int** tmp_lab){

	for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cout << tmp_lab[i][j]<<" ";
        }
        cout << endl;
    }
	cout << endl;

}

void findVirus(){
	//TODO 3: set Virust in lab with recursion

	int cur = 0;
	for(int i = 0; i < virusSize; i++){
		cur = virus[i];
		setVirus(cur/col, cur%col);
	}
}

void setVirus(int cur_row, int cur_col){

	//UP
	if(cur_row - 1 > -1){
		if(lab_wall[cur_row - 1][cur_col] == 0){
			lab_wall[cur_row - 1][cur_col] = 2;
			setVirus(cur_row - 1, cur_col);
		}
	}

	//DOWN
	if(cur_row + 1 < row){
		if(lab_wall[cur_row + 1][cur_col] == 0){
			lab_wall[cur_row + 1][cur_col] = 2;
			setVirus(cur_row + 1, cur_col);
		}	
	}
	
	//RIGHT

	if(cur_col + 1 < col){
		if(lab_wall[cur_row][cur_col + 1] == 0){
			lab_wall[cur_row][cur_col + 1] = 2;
			setVirus(cur_row, cur_col + 1);
		}
	}

	//LEFT

	if(cur_col - 1 > -1){
		if(lab_wall[cur_row][cur_col - 1] == 0){
			lab_wall[cur_row][cur_col - 1] = 2;
			setVirus(cur_row, cur_col - 1);
		}
	}
}

void countSafe(int** tmp_lab){
	//TODO 4: Count Safe Zone

	int tmp = 0;

	for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(tmp_lab[i][j] == 0){
				tmp++;
			}
        }
    }
	max_safe = checkMaxSafe(tmp);
}

int checkMaxSafe(int tmp){
	//TODO 5: Check whether max or not	
	return (max_safe > tmp)? max_safe : tmp;
}
