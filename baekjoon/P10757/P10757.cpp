#include <cstdio>
#include <stack>
#include <string>
#include <iostream>
using namespace std;

int main(){
	stack<int> A, B, C;
	string str1, str2;
	cin >> str1 >> str2;
	if(str1.length() < str2.length()){
		string tmp = str2;
		str2 = str1;
		str1 = tmp;
	}
	for(int i = 0 ; i < str1.length(); i++){
		A.push(str1.at(i)-'0');
	}
	for(int i = 0 ; i < str2.length(); i++){
		B.push(str2.at(i)-'0');
	}
	int tmp = 0;
	while(!A.empty()){
		int a, b, c;
		while(!B.empty()){
			a = A.top();A.pop();
			b = B.top();B.pop();
			if(a + b + tmp!= 0)c = (a + b + tmp)%10;
			else c = 0;
			if(a+b+tmp != 0)tmp = (a + b + tmp)/10;
			else tmp = 0;
			C.push(c);
		}
		if(!A.empty()){
			a = A.top();A.pop();
			if(a +tmp!= 0)c = (a+tmp)%10;
			else c = 0;
			if(a+tmp != 0)tmp = (a + tmp)/10;
			else tmp = 0;
			C.push(c);
		}
	}
	if(tmp!=0)C.push(tmp);
	while(!C.empty()){
		printf("%d", C.top());
		C.pop();
	}
	printf("\n");
}
