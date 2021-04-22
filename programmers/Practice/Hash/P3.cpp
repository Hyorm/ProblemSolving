#include <string>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> C;
    for(const auto& c :clothes){
        auto t = C.find(c[1]);
        if(t==C.end()){
            C.insert(make_pair(c[1], 1));
        }else{
            t->second++;
        }
    }
    for(const auto& c:C)answer*=(c.second+1);
    return answer-1;
}
