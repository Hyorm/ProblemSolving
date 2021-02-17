#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <memory.h>

enum type{
    TYPE_JAVA,
    TYPE_CPP,
    TYPE_PYT,
    
    TYPE_BE,
    TYPE_FE,
    
    TYPE_JUN,
    TYPE_SEN,
    
    TYPE_CHI,
    TYPE_PIZ
};

using namespace std;
void printVector(const vector<int> &vec);
int findType(string bf);
vector<int> solution(vector<string> info, vector<string> query);

int main(){

    vector<int> answer(6);
    answer = solution({"java backend junior pizza 140","python frontend senior chicken 210","python frontend senior chicken 140","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 40"}, {"java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 240","- and backend and senior and - 140","- and - and - and chicken 100","- and - and - and - 140"});

	printVector(answer);
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    
    int** db = new int*[info.size()];
    int db_score[info.size()];
    
    for(int i = 0; i < info.size(); i++){
        db[i] = new int[4];
        memset(db[i], 0, sizeof(int)*4);
    }
    
    int db_i = 0;
    for(const string &iter : info){
        int db_j = 0;
        stringstream str(iter);
        string bf;
        while(db_j < 5){
            getline(str, bf, ' ');
            int tp = findType(bf);
            if(tp > -2 && db_j < 4){
				db[db_i][db_j] = tp;
			}
			if(tp == -3){
				db_score[db_i] = stoi(bf);
			}
            db_j++;
        }
        db_i++;
    }
    for(const string &iter : query){
        int count = 0;
        stringstream str(iter);
        string bf;
        int tmp[4];
        
        int score = 0;
        int tmp_i = 0;
        while(getline(str, bf, ' ')){
            int tp = findType(bf);
			if(tp > -2){
				tmp[tmp_i++] = tp;
			}
			if(tp == -3){
				score = stoi(bf);
			}
        }

        for(int i = 0; i < info.size(); i++){
            if(db_score[i] < score){
                continue;
            }
            int check = 0;
            for(int j = 0; j < 4; j++){
                if(tmp[j] == -1 || tmp[j] == db[i][j]){
                    continue;
                }else{
                    check++;
                }
            }
            if(check == 0){
                count++;
            }
        }
        answer.push_back(count);
    }
   
    for(int i = 0; i < info.size(); i++){
        delete db[i];
    }
    delete[] db;
    
    return answer;
}

int findType(string bf){
	int tp = 0;
	if(bf.compare("java")==0){
		tp = TYPE_JAVA;
	}else if(bf.compare("cpp")==0){
		tp = TYPE_CPP;
	}else if(bf.compare("python")==0){
		tp = TYPE_PYT;
	}else if(bf.compare("backend")==0){
		tp = TYPE_BE;
	}else if(bf.compare("frontend")==0){
		tp = TYPE_FE;
	}else if(bf.compare("chicken")==0){
		tp = TYPE_CHI;
	}else if(bf.compare("pizza")==0){
		tp = TYPE_PIZ;
	}else if(bf.compare("junior")==0){
		tp = TYPE_JUN;
	}else if(bf.compare("senior")==0){
		tp = TYPE_SEN;
	}else if(bf.compare("-")==0){
        tp = -1;
    }else if(bf.compare("and")==0 ){
		tp = -2;
    }else{
        tp = -3;
    }
	return tp;
}

void printVector(const vector<int> &vec) {
    for (const int &it : vec) {
        cout<<it<<" ";
    }
    cout<<endl;
}
