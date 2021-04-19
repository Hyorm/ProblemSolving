#include <string>
#include <vector>

using namespace std;
int answer = 0;
void dfs(int sum, int d, vector<int> numbers, int target){
    if(d==numbers.size()){
        if(sum==target)answer++;
        
    }else{
        dfs(sum+numbers[d], d+1, numbers, target);
        dfs(sum-numbers[d], d+1, numbers, target);
    }
}

int solution(vector<int> numbers, int target) {
    dfs(0, 0, numbers, target);
    return answer;
}
