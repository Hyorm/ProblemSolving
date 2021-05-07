#include <cstdio>
#include <algorithm>
using namespace std;
int* P;
int N, M;
void find(int d, int* a){
    if(d>=M){
        for(int i = 0; i < M; i++)printf("%d ", a[i]);
        printf("\n");
    }
    else{
        for(int i = 0; i < N; i++){
            a[d] = P[i];
            find(d+1, a);
        }
    }
}
int main(){
    scanf("%d %d", &N, &M);
    P = new int[N];
    for(int i = 0; i < N; i++)scanf("%d", &P[i]);
    sort(P, P+N);
    int* a = new int[M];
    find(0, a);
}
