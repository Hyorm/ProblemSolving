#include <cstdio>
#include <stack>
#include <string>
using namespace std;
int main(){
	int T;
	scanf("%d\n", &T);
	for(int i = 0; i < T; i++){
		stack<char> t;
		char c;
		while(scanf("%c",&c)!=EOF){
			if(c!=' '&&c!='\n'){
				t.push(c);
			}else{
				while(!t.empty()){
					printf("%c", t.top());
					t.pop();
				}
				if(c==' ')printf(" ");
				else printf("\n");
			}
		}
	}
}
