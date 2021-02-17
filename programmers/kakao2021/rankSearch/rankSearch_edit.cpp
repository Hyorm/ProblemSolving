#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <memory.h>

using namespace std;

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
int findType(string bf);
void printVector(const vector<int> &vec);
vector<int> solution(vector<string> info, vector<string> query);

int main(){

    vector<int> answer(6);
    answer = solution({"java backend junior pizza 140","python frontend senior chicken 210","python frontend senior chicken 140","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 40"}, {"java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 240","- and backend and senior and - 140","- and - and - and chicken 100","- and - and - and - 140"});

    printVector(answer);
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;

    int** db = new int*[info.size()];

    for(int i = 0; i < info.size(); i++){
        db[i] = new int[4];
        memset(db[i], 0, sizeof(int)*4);
    }

    int db_score[info.size()];
    int db_row = 0; 
    for(const string &iter : info){
        int pos = 0;
        string tok;
        string tmp = iter.c_str();
        string del = " ";
		int db_col = 0;
        while((pos = tmp.find(" ")) != string::npos){
			tok = tmp.substr(0, pos);
            tmp.erase(0, pos + del.length());
            int tp = findType(tok);
            if(tp > -2 && db_col < 4){
				db[db_row][db_col++] = tp;
			}
        }
        db_score[db_row++] = stoi(tmp.substr(0, pos));
    }
    for(const string &iter : query){
        int pos = 0;
        string tok;
        string tmp = iter.c_str();
        string del = " ";
        int qu_find[4];
        int qu_id = 0;
        int score = 0;
        int count = 0;
        while((pos = tmp.find(" ")) != string::npos){
            tok = tmp.substr(0, pos);
			if(tok.compare("and") == 0){
                tmp.erase(0, pos + del.length());
				continue;
            }
            int tp = findType(tok);
            qu_find[qu_id++] = tp;
            tmp.erase(0, pos + del.length());
        }
        score = stoi(tmp.substr(0, pos));

        for(int i = 0; i < db_row; i++){
            if(db_score[i] < score){
                continue;
            }
            int check = 0;
            for(int j = 0; j < qu_id; j++){
                if(qu_find[j] == -1 || qu_find[j] == db[i][j]){
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

