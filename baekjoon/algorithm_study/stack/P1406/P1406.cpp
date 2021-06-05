#include <cstdio>
#include <stack>
using namespace std;
int main(){
    stack<char> left;
    stack<char> right;
    char c;
    int d;
    while(scanf("%c", &c)!=EOF){
        if(c!='\n'&&c!=' ')left.push(c);
        else break;
    }
    scanf("%d", &d);
    while(d-->0){
        while(scanf("%c", &c)!=EOF)if(c!='\n'&&c!=' ')break;
        switch(c){
            case 'L':
                    if(!left.empty()){
                        right.push(left.top());
                        left.pop();
                    }
                    break;
            case 'D':
                    if(!right.empty()){
                        left.push(right.top());
                        right.pop();
                    }
                    break;
            case 'B':
                    if(!left.empty()){
                        left.pop();
                    }
                    break;
            case 'P':
                    while(scanf("%c", &c)!=EOF)if(c!='\n'&&c!=' ')break;

                    left.push(c);
                    break;
        }
    }
    while(!left.empty()){
        right.push(left.top());
        left.pop();
    }
    while(!right.empty()){
        printf("%c", right.top());
        right.pop();
    }
}
