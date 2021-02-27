#include <stdio.h>
#include <stack>
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char** argv){

	stack<char> left;
	stack<char> right;

	string str;

	cin >> str;

	int N;

	scanf("%d", &N);
	for(int i = 0 ; i < str.length(); i++){
		left.push(str.at(i));
	}
	for(int i = 0 ; i < N ; i++){
		char ch ;
		do{
			scanf("%c", &ch);
		}
		while(!isalpha(ch));
		switch(ch){
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
					char t;
					do{
						scanf("%c", &t);
					}
					while(!isalpha(t));
					left.push(t);
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
	printf("\n");

}
