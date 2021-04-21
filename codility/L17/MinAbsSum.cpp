#include <set>
#include <algorithm>
int solution(vector<int> &A) {
    set<int> P[20001];
    int ans = 20000;
    if(A.size()==0)return 0;
    P[0].insert(A[0]);
    P[0].insert(A[0]*-1);
    for(int i = 1; i < (int)A.size(); i++){
        for(const auto&it: P[i-1]){
            P[i].insert(it+A[i]);
            P[i].insert(it+A[i]*-1);
        }
    }
    for(const auto&it:P[A.size()-1]){
        if(it>=0){
            ans = it;
            break;
        }
    }
    return ans;
}
