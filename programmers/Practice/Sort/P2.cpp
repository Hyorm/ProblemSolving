#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
bool cmp(string a, string b){
    string ta ="", tb="";
    for(int i = 0; i < 6; i++){
        ta += a;
        tb += b;
    }
    return ta>tb;
}
string solution(vector<int> numbers) {
    string answer = "";
    vector<string> S;
    sort(numbers.begin(), numbers.end(), greater<int>());
    for(const auto &i: numbers){
        S.push_back(to_string(i));
    }
    sort(S.begin(), S.end(), cmp);
    for(const auto &i: S){
        if(answer.compare("")==0&&i.compare("0")==0)continue;
        answer+=i;
    }
    if(answer.compare("")==0)answer = "0";
    return answer;
}
