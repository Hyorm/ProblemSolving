#include <cstdio>
#include <cctype>
using namespace std;

int main(){
    char C;
    scanf("%c", &C);
    int d = C - '0';
    if(isdigit(C))printf("%d\n", d+48);
    else{
        if(isupper(C))printf("%d\n", d+48);
        else printf("%d\n", d+48);
    }
}
