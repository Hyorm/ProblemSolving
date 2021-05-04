#include <cstdio>
#include <queue>
using namespace std;
int main(){
    int N, K;
    scanf("%d %d", &N, &K);
    queue<int> q;
    for(int i = 1; i <= N; i++)q.push(i);
     printf("<");
    while(!q.empty()){
        for(int i = 0; i < K-1; i++){
            q.push(q.front());
            q.pop();
        }
        printf("%d",q.front());
        if(q.size()>1)printf(", ");
        q.pop();
    }   
    printf(">\n");
}  
