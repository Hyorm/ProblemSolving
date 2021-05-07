#include <cstdio>
#include <algorithm>
using namespace std;
int* P;
int N, M;
void find(int b, int d, int* a){
    if(d>=M){
        for(int i = 0; i < M; i++)printf("%d ", a[i]);
        printf("\n");
    }else{
        for(int i = b; i < N; i++){
            a[d] = P[i];
            if(i+1<=N)find(i+1, d+1, a);
        }
    }
}
int main(){
    scanf("%d %d", &N, &M);
    P = new int[N];
    for(int i = 0; i < N; i++)scanf("%d", &P[i]);
    sort(P, P+N);
    int* ans;
    ans = new int[M];
    find(0, 0, ans);
}
