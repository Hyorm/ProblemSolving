#include <cstdio>
#include <cmath>
using namespace std;
int A, B, C;
int pow_e(int b){
    if(b==0)return 1;
    long long tmp = pow_e(b/2)%C;
    long long ans = tmp*tmp%C;
    if(b%2==1)ans = ans*A%C;
    return (int)ans;
}
int main(){
    scanf("%d %d %d", &A, &B, &C);
    int ans = pow_e(B); 
    printf("%d\n", ans);
}
