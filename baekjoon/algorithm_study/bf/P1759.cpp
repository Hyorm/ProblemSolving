#include <cstdio>
#include <string>
#include <set>
#include <algorithm>
using namespace std;
int L, C;
set<char>A;
char Aa[5] = {'a', 'e', 'i', 'o', 'u'};
void find(char* S, int a, int b, int l, int d, string str){
    if(l>=L){
        if(a>=1&&b>=2){
            for(const auto& c: str)printf("%c", c);
            printf("\n");
        }
    }else{
        for(int i = d; i < C; i++){
            if(A.find(S[i])!=A.end())find(S, a+1, b, l+1, i+1, str+S[i]);
            else find(S, a, b+1, l+1, i+1, str+S[i]);
        }
    }
}
int main(){
    scanf("%d %d\n", &L, &C);
    char* S;
    S = new char[C];
    for(int i = 0; i < C; i++){
        scanf("%c",&S[i]);
        if(S[i]==' '||S[i]=='\n')scanf("%c",&S[i]);
    }
    sort(S, S+C);
    for(int i = 0; i < 5; i++)A.insert(Aa[i]);
    find(S, 0, 0, 0, 0, "");
}
