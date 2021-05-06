#include <cstdio>
#include <algorithm>
using namespace std;
int** P;
int N, M;
bool cmp(int* a, int* b){
    return a[0]<b[0];
}
void find(int b, int d, int* a){
    if(d>=M){
        for(int i = 0; i < M; i++)printf("%d ", a[i]);
        printf("\n");
    }else{
        for(int i = 0; i < N; i++){
            if(P[i][1]==0){
                a[d] = P[i][0];
                P[i][1] = 1;
                if(i+1<=N)find(i+1, d+1, a);
                P[i][1] = 0;
            }
        }
    }
}
int main(){
    scanf("%d %d", &N, &M);
    P = new int*[N];
    for(int i = 0; i < N; i++){
        P[i] = new int[2];
        scanf("%d", &P[i][0]);
        P[i][1] = 0;
    }
    sort(P, P+N, cmp);
    int* ans;
    ans = new int[M];
    find(0, 0, ans);
}
