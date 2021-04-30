#include <string>
#include <vector>
#include <memory.h>
using namespace std;
int D[501][501];
int solution(vector<vector<int>> triangle) {
    int answer = 0;
    for(int i = 0; i <triangle.size(); i++)D[triangle.size()-1][i] = triangle[triangle.size()-1][i];
    for(int i = triangle.size()-2; i >=0; i--){
        for(int j = 0;j < triangle[i].size(); j++){
            D[i][j]  = (D[i+1][j]>D[i+1][j+1])?D[i+1][j]:D[i+1][j+1];
            D[i][j] += triangle[i][j];
        }
    }
    
    answer = D[0][0];
    return answer;
}
