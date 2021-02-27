#include <stdio.h>
#include <stack>
#include <string>
#include <iostream>

using namespace std;

int main(int argc, char** argv){
	string str;
	cin >> str;
	stack<char> st;
	int l = 0;
	int answer = 0;
	for(int i = 0; i < str.length(); i++){
		if(str.at(i) == '('){
			st.push('(');
			l = 0;
		}
		else{
			if(l == 0){
				st.pop();
				answer += st.size();
				l = 1;
			}else{
				answer += 1;
				st.pop();
			}
		}
	}
	printf("%d\n",answer);
}
