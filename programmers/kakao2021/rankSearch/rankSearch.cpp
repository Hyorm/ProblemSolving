#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <memory.h>

using namespace std;

void printVector(const vector<int> &vec);
vector<int> solution(vector<string> info, vector<string> query);
bool isDigit(string str);

int main(){

    vector<int> answer(6);
    answer = solution({"java backend junior pizza 140","python frontend senior chicken 210","python frontend senior chicken 140","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 40"}, {"java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 240","- and backend and senior and - 140","- and - and - and chicken 100","- and - and - and - 140"});

	printVector(answer);
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    
    int db_score[info.size()];
    int db_id = 0;
    for(const string &iter : info){
        int pos = 0;
        string tok;
        string tmp = iter.c_str();
        string del = " ";
        while((pos = tmp.find(" ")) != string::npos){
            tok = tmp.substr(0, pos);
            tmp.erase(0, pos + del.length());
        }
        db_score[db_id++] = stoi(tmp.substr(0, pos));
    }
    
    for(const string &iter : query){
        int pos = 0;
        string tok;
        string tmp = iter.c_str();
        string del = " ";
        string qu_find[4];
        int qu_id = 0;
        int score = 0;
        while((pos = tmp.find(" ")) != string::npos){
            tok = tmp.substr(0, pos);
            if(tok.compare("-") == 0 || tok.compare("and") == 0){
                tmp.erase(0, pos + del.length());
				continue;
            }
            qu_find[qu_id++] = tok;
            tmp.erase(0, pos + del.length());
        }
		
        score = stoi(tmp.substr(0, pos));
        int count = 0;
        int check_id = 0;
        for(const string &it : info){
			int check = 0;
			string in = it.c_str();
			if(db_score[check_id] >= score){	
            	for(int i = 0; i < qu_id; i++){
                	if(in.find(qu_find[i]) != string::npos){
						check++;
                	}else{
						break;
					}
            	}
            	if(check == qu_id){
                	count++;
            	}
			}
            check_id++;
        }
        answer.push_back(count);
    }
    
    return answer;
}

bool isDigit(string str){
    return atoi(str.c_str()) != 0 || str.compare("0") == 0;
}
void printVector(const vector<int> &vec) {
    for (const int &it : vec) {
        cout<<it<<" ";
    }
    cout<<endl;
}
