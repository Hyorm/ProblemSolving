#include <string>
#include <vector>
#include <memory.h>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    int S[31];
    for(int i = 1; i <= n; i++){
        S[i] = 1;
    }
    for(int i = 0; i < reserve.size(); i++){
        S[reserve[i]] = 2;
    }
    for(int i = 0; i < lost.size(); i++){
        if(S[lost[i]]==2)S[lost[i]] = 1;
        else S[lost[i]] = 0;
    }
    for(int i = 0; i < lost.size(); i++){
        if(S[lost[i]]>0)continue;
        if(lost[i]-1>0){
            if(S[lost[i]-1]==2){
                S[lost[i]] = 1;
                S[lost[i]-1] = 1;
                continue;
            }
        }
        if(lost[i]+1<=n){
            if(S[lost[i]+1]==2){
                S[lost[i]] = 1;
                S[lost[i]+1] = 1;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        if(S[i]>0)answer++;
    }
    return answer;
}
