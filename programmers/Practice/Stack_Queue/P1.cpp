#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<int> left;
    queue<pair<int, int> > on;
    int on_weight = 0;
    for(const auto& it: truck_weights){
        left.push(it);
    }
    on.push(make_pair(left.front(), 0));
    on_weight+=left.front();
    left.pop();
    answer++;
    while(!on.empty()){
        if(answer-on.front().second==bridge_length){
            on_weight-=on.front().first;
            on.pop();
        }
        if(!left.empty()&&on_weight+left.front()<=weight){
            on.push(make_pair(left.front(), answer));
            on_weight+=left.front();
            left.pop();
        }
        answer++;
    }
    return answer;
}
