#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> priorities, int location) {
    int P[10] = {0,};
    int answer = 0;
    queue<pair<int, int> > q;
    for(int i = 0; i < priorities.size(); i++){
        if(i==location)q.push(make_pair(priorities[i],1));
        else q.push(make_pair(priorities[i],0));
        P[priorities[i]]++;
    }
    while(!q.empty()){
        int now = q.front().first;
        int mark = q.front().second;
        int out = 0;
        q.pop();
        for(int i = 9; i > now; i--){
            if(P[i]>0){
                out = 1;
                break;
            }
        }
        if(out==1)q.push(make_pair(now,mark));
        else{
            if(mark==1){
                while(!q.empty())q.pop();
            }else{
                answer++;
                P[now]--;
            }
        }
    }
    return answer+1;
}
