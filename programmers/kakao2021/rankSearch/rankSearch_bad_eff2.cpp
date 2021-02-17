#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iostream>

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

vector<int> solution(vector<string> info, vector<string> query);
void printVector(const vector<int> &vec);
int findType(string bf);

int main(){
	
	vector<int> answer(6);
	answer = solution({"java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50"}, {"java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150"});
	
	printVector(answer);
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    
    vector<vector<int>> db(info.size());
    vector<int> db_score(info.size());
    
    for(const string &iter : info){
        stringstream str(iter);
        string bf;
        vector<int> tmp;
        while(getline(str, bf, ' ')){
            int tp = findType(bf);
            if(tp > -1){
				tmp.push_back(tp);
			}
			if(tp == -2){
				db_score.push_back(stoi(bf));
			}
        }
        db.push_back(tmp);
    }

    for(const string &iter : query){
        int count = 0;
        stringstream str(iter);
        string bf;
        vector<int> tmp;
        
        int score = 0;
        while(getline(str, bf, ' ')){
            int tp = findType(bf);
			if(tp > -1){
				tmp.push_back(tp);
			}
			if(tp == -2){
				score = stoi(bf);
			}
        }
        int scId = 0;
        for(const vector<int> &iter_in: db){
            if(db_score[scId++] < score){
                continue;
            }
            vector<int> tmp_in(iter_in.size()+tmp.size());
            auto it = set_difference(tmp.begin(), tmp.end(), iter_in.begin(), iter_in.end(), tmp_in.begin());
            tmp_in.erase(it, tmp_in.end());
			
            if(tmp_in.size() == 0){
		count++;
            }
        }
        answer.push_back(count);
    }
     
    return answer;
}
void printVector(const vector<int> &vec) {
    for (const int &it : vec) {
        cout<<it<<" ";
    }
    cout<<endl;
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
	}else if(bf.compare("-")==0 || bf.compare("and")==0 ){
		tp = -1;
    }else{
        tp = -2;
    }
	return tp;
}
