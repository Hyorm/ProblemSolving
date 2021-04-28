#include <cstdio>
using namespace std;
long long D[10001];
int C[100001];
int main(){
    long long ans;
    int N, K;
    scanf("%d %d", &N, &K);
    for(int i = 0; i < N; i++){
        scanf("%d", &C[i]);
    }
    D[0] = 1;
    for(int i = 0; i < N; i++){
        for(int j = C[i]; j <= K; j++){
            if(j - C[i] >= 0) D[j] += D[j - C[i]];
        }
    }
    printf("%lld\n", D[K]);
}
