#include <cstdio>
#include <queue>
using namespace std;
int main(){
    int N;
    scanf("%d", &N);
    queue<int> q;
    for(int i = 1; i <= N; i++)q.push(i);
    while(q.size()>1){
        q.pop();
        q.push(q.front());
        q.pop();
    }
    printf("%d\n", q.front());
}
