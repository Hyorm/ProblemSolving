#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<pair<int, int>> PS;
    for(int i = 0; i < progresses.size(); i++){
        PS.push(make_pair(progresses[i],speeds[i]));
    }
    while(!PS.empty()){
        int now = 1;
        int tmp = (100-PS.front().first)/PS.front().second;
        int time = ((100-PS.front().first)%PS.front().second>0)?tmp+1:tmp;
        PS.pop();
        while(!PS.empty()&&PS.front().first+(PS.front().second*time)>=100){
            now++;
            PS.pop();
        }
        answer.push_back(now);
    }
    return answer;
}
