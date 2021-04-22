#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
bool vcmp(const pair<string, int> &a, const pair<string, int> &b){
    return a.second>b.second;
}
bool cmp(const pair<int, int> &a, const pair<int, int> &b){
    return a.second>b.second;
}
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, vector<pair<int, int> > >JSP;
    map<string, int > JN;
    for(int i = 0; i < genres.size(); i++){
        JN[genres[i]]+=plays[i];
        JSP[genres[i]].push_back(make_pair(i, plays[i]));
    }
    vector<pair<string, int> > VJN(JN.begin(), JN.end());
    sort(VJN.begin(), VJN.end(), vcmp);
    for(const auto& vjn: VJN){
        auto f = JSP.find(vjn.first);
        vector<pair<int, int> >T(f->second.begin(), f->second.end());
        stable_sort(T.begin(), T.end(),cmp);
        int i = 0;
        for(const auto & it: T){
            answer.push_back(it.first);
            if(i==1)break;
            i++;
        }
    }
    return answer;
}
