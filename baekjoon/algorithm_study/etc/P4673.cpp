#include <cstdio>
using namespace std;
int S[10001] = {0,};
void d(int n){
    if(n<=10000){
        int t = n;
        while(n>0){
            t += n%10;
            n /= 10;
        }
        if(t<=10000&&S[t]==0){
            S[t] = 1;
            d(t);
        }
    }
}
int main(){
    for(int i = 1; i <= 10000; i++){
        if(S[i]==0)d(i);
    }
    for(int i = 1; i <= 10000; i++)if(S[i]==0)printf("%d\n", i);

}
