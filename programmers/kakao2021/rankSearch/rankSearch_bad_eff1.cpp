#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

bool isDigit(string str);

vector<int> solution(vector<string> info, vector<string> query);
void printVector(const vector<int> &vec);

int main(){

    vector<int> answer(6);
    answer = solution({"java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50"}, {"java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150"});
    
    printVector(answer);
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;

    for(const string &it: query){
        
        vector<string> q_db;
        int score = 0;
        int count = 0;
        stringstream str(it);
        string bf;
        while(getline(str, bf, ' ')){
            if(!isDigit(bf)){
                if(bf.compare("and")!= 0){
                    q_db.push_back(bf);
                }
            }else{
                score = stoi(bf);
            }
        }
        
        for(const string &it_in: info){
            
            stringstream in_str(it_in);
            int check = 0;
            int item = 0;
            while(getline(in_str, bf, ' ')){
                if(isDigit(bf)){
                    if(stoi(bf)<score){
                        check++;
                        break;
                    }
                }else if(q_db[item].compare("-") == 0 || q_db[item].compare(bf) == 0){
                    item++;
                    continue;
                }
                else{
                    check++;
                    break;
                }
            }
            if(check == 0){
                count++;
            }
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
