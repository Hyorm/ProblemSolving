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
bool compare(vector<int> a, vector<int> b);

int main(){

    vector<int> answer(6);
    answer = solution({"java backend junior pizza 140","python frontend senior chicken 210","python frontend senior chicken 140","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 40"}, {"java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 240","- and backend and senior and - 140","- and - and - and chicken 100","- and - and - and - 140"});

    printVector(answer);
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;

    int db[info.size()][4];

    vector<vector<int>> db_score;
    int db_row = 0;
    for(const string &iter : info){ //N
        int pos = 0;
        int db_col = 0;
        string tok;
        string tmp = iter.c_str();
        string del = " ";
        while((pos = tmp.find(" ")) != string::npos){ //4
            tok = tmp.substr(0, pos);
            tmp.erase(0, pos + del.length());
            int tp = findType(tok);
            if(tp > -2 && db_col < 4){
				db[db_row][db_col++] = tp;
			}
        }
        vector<int> tdb;
        tdb.push_back(stoi(tmp.substr(0, pos)));
        tdb.push_back(db_row++);
		db_score.push_back(tdb);
    }
	for(int i = 0; i<db_row;i++){
        cout<<db_score[i][1]<<" "<<db_score[i][0]<<endl;
    }
    cout<<endl;
	sort(db_score.begin(), db_score.end(), compare);
	for(int i = 0; i<db_row;i++){
		cout<<db_score[i][1]<<" "<<db_score[i][0]<<endl;
	}
	cout<<endl;
    for(const string &iter : query){ // M
        int pos = 0;
        string tok;
        string tmp = iter.c_str();
        string del = " ";
        int qu_find[4];
        int qu_id = 0;
        int score = 0;
        int count = 0;
        while((pos = tmp.find(" ")) != string::npos){ // 4
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

        for(int i = 0; i < db_row; i++){ // N
			if(db_score[i][0] < score){
				cout<<db_score[db_score[i][1]][0]<<" "<<score<<endl;
				break;
            }
            int check = 0;
            for(int j = 0; j < qu_id; j++){ //4
                if(qu_find[j] == -1 || qu_find[j] == db[db_score[i][1]][j]){
					cout<<qu_find[j]<<" "<<db[db_score[i][1]][j]<<endl;
                    continue;
                }else{
                    check++;
                }
				cout<<endl;
            }
            if(check == 0){
                count++;
				cout<<"find!"<<endl<<endl;
            }
        }
        answer.push_back(count);
		cout<<"check!"<<endl<<endl;
    }

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
bool compare(vector<int> a, vector<int> b){
    return a[0] > b[0];
}
void printVector(const vector<int> &vec) {
    for (const int &it : vec) {
        cout<<it<<" ";
    }
    cout<<endl;
}
