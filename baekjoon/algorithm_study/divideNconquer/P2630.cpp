#include <cstdio>
using namespace std;
int** P;
long long ansb = 0;
long long answ = 0;
void cut(int x, int y, int w){
    int z = 0, h = 0;
    for(int i = x; i < w+x; i++){
         for(int j = y; j < w+y; j++){
            if(P[i][j]==0)z = 1;
            if(P[i][j]==1)h = 1;
         }
    }
    if(h==0)answ++;
    else if(z==1){
        for(int i = x; i<w+x; i+=w/2){
            for(int j = y; j < w+y; j+=w/2)cut(i, j, w/2);
        }
    }
    else ansb++;
}
int main(){
    int N;
    scanf("%d", &N);
    P = new int*[N];
    for(int i = 0; i < N; i++){
        P[i] = new int[N];
        for(int j = 0; j < N; j++)scanf("%d", &P[i][j]);
    }
    cut(0, 0, N);
    printf("%lld\n%lld\n", answ, ansb);
}
