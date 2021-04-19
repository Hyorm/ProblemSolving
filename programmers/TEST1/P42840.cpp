#include <queue>
#include <vector>

using namespace std;
int f1[5] = {1, 2, 3, 4, 5};
int f2[8] = {2, 1, 2, 3, 2, 4, 2, 5};
int f3[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int A[3] = {0,0,0};
    int max = 0;
    queue<int>  an[3];
    for(int i = 0; i < 5; i++)an[0].push(f1[i]);
    for(int i = 0; i < 8; i++)an[1].push(f2[i]);
    for(int i = 0; i < 10; i++)an[2].push(f3[i]);
    for(const int &it:answers){
        int a[3];
        for(int i =0;i<3; i++){
            a[i] = an[i].front();
            an[i].pop();
            an[i].push(a[i]);
            if(it==a[i])A[i]++;
            if(max<A[i])max = A[i];
        }
    }
    for(int i =0;i<3; i++){
        if(A[i]==max)answer.push_back(i+1);
    }
    return answer;
}
