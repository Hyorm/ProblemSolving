#include <cstdio>
#include <cmath>

bool isAP(int x){
    if(x < 10)return true;
    int f = x%10;
    x /= 10;
    int s = x%10;
    x /= 10;
    int diff = f-s;
    while(x > 0){
        f = x%10;
        x /= 10;
        if(s-f != diff)return false;
        s = f;
    }
    return true;
}

int main(){
    int N, ans = 0;
    scanf("%d", &N);
    for(int i = 1; i <= N; i++){
        if(isAP(i))ans++;
    }
    printf("%d\n", ans);
}
