#include <cstdio>
#include <stack>
#include <iostream>
using namespace std;
int main(){
	while(true){
		stack<char> s;
		string str;
		getline(cin, str);
		if(str[0]=='.')break;
		for(int i = 0 ; i < str.length(); i++){
			if(i==str.length()-1){
				if(!s.empty())printf("no\n");
				else printf("yes\n");
				break;
			}
			if(str[i]=='('||str[i]=='[')s.push(str[i]);
			else if(str[i]==')'){
				if(!s.empty() && s.top()=='(')s.pop();
				else{
					printf("no\n");
					break;
				}
			}
			else if(str[i]==']'){
				if(!s.empty()&&s.top()=='[')s.pop();
				else{
					printf("no\n");
					break;
				}
			}
		}
	}
}
