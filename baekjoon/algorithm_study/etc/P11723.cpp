#include <cstdio>
using namespace std;
void rmvBuffer(){
    char c;
    while(true){
        scanf("%c", &c);
        if(c==' '||c=='\n')break;
    }
}
int main(){
    int N, S;
    scanf("%d\n", &N);
    S = 0;
    for(int i = 0; i < N; i++){
        char c;
        int d;
        scanf("%c", &c);
        switch(c){
            case 'a':
                    scanf("%c", &c);
                    switch(c){
                        case 'd':
                                rmvBuffer();
                                scanf("%d\n", &d);
                                S |= (1<<d);
                                break;
                        case 'l':
                                rmvBuffer();
                                S = (1<<21)-1;
                                break;
                    }
                    break;
            case 'r':
                    rmvBuffer();
                    scanf("%d\n", &d);
                    S &=~(1<<d);
                    break;
            case 'c':
                    rmvBuffer();
                    scanf("%d\n", &d);
                    if(S&(1<<d))printf("1\n");
                    else printf("0\n");
                    break;
            case 't':
                    rmvBuffer();
                    scanf("%d\n", &d);
                    S ^= (1<<d);
                    break;
            case 'e':
                    rmvBuffer();
                    S = 0;
                    break;
        }
    }
}
