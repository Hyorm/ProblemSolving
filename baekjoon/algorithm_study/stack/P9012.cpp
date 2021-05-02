#include <stdio.h>
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(int argc, char**argv){

    int N;
    scanf("%d", &N);

    for(int i = 0; i<N ; i++){
        string str;
        stack<char> r;
        cin>>str;

        int ck = 0;
        for(int j = 0; j < str.length(); j++){
            if(str.at(j) == '('){
                r.push(str.at(j));
            }
            else{
                if(!r.empty()){
                    r.pop();
                }else{
                    ck = 1;
                    break;
                }
            }
        }
        if(r.empty() && ck != 1){
            printf("YES\n");
        }else{
            printf("NO\n");
        }

    }

}
