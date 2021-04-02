#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <memory.h>

using namespace std;

map<int, int> AP;
map<int, int> TD;
vector<int> DM;

int N;
int dir = 0;

int move(int time, int bf_dir);

int main(){
	
	scanf("%d", &N);
	
	int tmp;
	scanf("%d", &tmp);

	for(int i = 0; i<tmp; i++){
		int tmp_x, tmp_y;
		cin >> tmp_x;
		cin >> tmp_y;
		AP.insert(pair<int, int>((tmp_x-1) * N + tmp_y-1, 1));
	}

	scanf("%d", &tmp);
	for(int i = 0; i<tmp; i++){
		int tmp_t;
		char tmp_c;
		cin >> tmp_t;
		cin >> tmp_c;
		TD.insert(pair<int, int>(tmp_t, tmp_c=='L'? 1:0));
	}
	DM.push_back(0);
	printf("%d\n", move(1, 3));
}

int move(int time, int bf_dir){
	//TODO: move
	int cur = DM.back();
	int ntx = cur/N;
	int nty = cur%N;
	int ch_dir = -1;
	//TODO:CHANGE DIR
	if(TD.find(time-1)!= TD.end()){
		ch_dir = TD.find(time-1)->second;
	}
	switch(bf_dir){
		case 0://UP
				if(ch_dir != -1){
					dir = ch_dir;
					switch(dir){
						case 0:
							nty++;
							bf_dir = 3;
							break;
						case 1:
							nty--;
							bf_dir = 2;
							break;
					}
				}
				else{
					ntx--;
				}
				break;
		case 1://DOWN
				if(ch_dir != -1){
					dir = ch_dir;
					switch(dir){
						case 0:
							nty--;
							bf_dir = 2;
							break;
						case 1:
							nty++;
							bf_dir = 3;
							break;
					}
				}
				else{
					ntx++;
				}
				break;
		case 2:	//LEFT
				if(ch_dir != -1){
					dir = ch_dir;
				 	switch(dir){
						case 0:
							ntx--;
							bf_dir = 0;
							break;
						case 1:
							ntx++;
							bf_dir = 1;
							break;
				 	}
				}
				else{
					nty--;
				}
				 break;
		case 3:	//RIGHT
				 if(ch_dir != -1){
					dir = ch_dir;
				 	switch(dir){
						case 0:
							ntx++;
							bf_dir = 1;
							break;
						case 1:
							ntx--;
							bf_dir = 0;
							break;
					}
				 }
				 else{
					nty++;
				 }
				 break;
	}
	//BODY?
	for(const int &it :DM){
		if(it == ntx*N+nty){
			return time;
		}
	}
	//WALL?
	if(ntx < 0 || ntx > N-1 || nty < 0 || nty > N-1){
		return time;
	}
	else{
		DM.push_back(ntx*N+nty);
	}
	//APPLE?
	if(AP.find(ntx*N+nty) == AP.end()){
		DM.erase(DM.begin());
	}else{
		AP.erase(ntx*N+nty);
	}
	return move(time+1, bf_dir);
}
