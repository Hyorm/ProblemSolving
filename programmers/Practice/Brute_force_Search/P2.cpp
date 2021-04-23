#include <string>
#include <vector>
#include <set>
#include <memory.h>
using namespace std;
set<pair<int, int>> S;
int* P;
void dfs(int bf, int d, int* A){
    for(int i = 0; i < 10; i++){
        if(A[i]>0){
            if(S.insert(make_pair(bf*10+i, d)).second){
                A[i]--;
                dfs(bf*10+i, d+1,A);
                A[i]++;
            }
        }
    }
}
void prime(int N){
    printf("%d\n", N);
    P = new int[N+1];
    memset(P, 0, sizeof(int)*(N+1));
    P[0] = 1;
    P[1] = 1;
    for(int i = 2; i <= N; i++){
        if(P[i]==0){
            for(int j = 2; i*j <= N; j++){
                if(P[i*j]==0)P[i*j] = 1;
            }
        }
    }
}
int solution(string numbers) {
    int answer = 0;
    int* A;
    A = new int[10];
    memset(A, 0, sizeof(int)*10);
    for(int i = 0; i < numbers.length(); i++)A[(int)(numbers.at(i)-'0')]++;
    for(int i = 0; i < 10;i++){
        if(A[i]>0){
            A[i]--;
            S.insert(make_pair(i, 0));
            dfs(i, 0, A);
            A[i]++;
        }
    }
    prime(S.rbegin()->first);
    int bf = -1;
    for(const auto& i: S){
        if(P[i.first]==0&&bf != i.first){
            bf = i.first;
            printf("%d\n",i.first );
            answer++;
        }
    }
    return answer;
}
