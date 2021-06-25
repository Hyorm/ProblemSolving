#include <cstdio>
using namespace std;
char level[4] = {'A','B','C','D'};
int main(){
    int N;
    scanf("%d", &N);
    for(int i = 0;i<4; i++){
        if(N>=(100-10*(i+1))){
            printf("%c\n", level[i]);
            return 0;
        }
    }
    printf("F\n");
}
