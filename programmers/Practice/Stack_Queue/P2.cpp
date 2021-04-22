#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    for(int i = 0; i < prices.size(); i++){
        int out = 0;
        for(int j = i+1; j<prices.size();j++){
            if(prices[i]>prices[j]){
                answer.push_back(j-i);
                out = 1;
                break;
            }
        }
        if(out==0)answer.push_back(prices.size()-1-i);
    }
    return answer;
}
