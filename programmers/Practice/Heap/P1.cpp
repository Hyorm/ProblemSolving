#include <string>
#include <vector>
#include <queue>
using namespace std;
int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> F;
    for(const auto& it: scoville)F.push(it);
    while(F.top()<K){
        if(F.size()==1)return -1;
        int first = F.top();F.pop();
        int second = F.top();F.pop();
        F.push(first+second*2);
        answer++;
    }
    return answer;
}
