#include <cstdio>
#include <stack>
#include <iostream>
using namespace std;
int main(){
	int T;
	scanf("%d", &T);
	stack<int> s;
	for(int i = 0; i < T; i++){
		string str;
		int N;
		cin>>str;
		if(str.compare("push")==0){
			cin>>N;
			s.push(N);
		}
		else if(str.compare("pop")==0){
			if(s.empty())printf("-1\n");
			else{
				printf("%d\n", s.top());
				s.pop();
			}
		}
		else if(str.compare("size")==0){
			printf("%lu\n", s.size());
		}
		else if(str.compare("empty")==0){
			if(s.empty())printf("1\n");
			else printf("0\n");
		}
		else{
			if(s.empty())printf("-1\n");
			else{
				printf("%d\n", s.top());
			}
		}
	}
}
