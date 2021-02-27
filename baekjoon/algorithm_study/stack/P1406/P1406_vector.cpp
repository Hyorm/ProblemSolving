#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
using namespace std;
void printVector(const vector<char> s);
int main(int argc, char** argv){
	string str;
	cin >> str;
	vector<char> s;
	for(int i = 0; i < str.length(); i++){
		s.push_back(str.at(i));
	}
	int N;
	scanf("%d", &N);
	
	int iter = str.length();
	for(int i = 0; i < N; i++){
		char ch;
		do{
			scanf("%c", &ch);
		}while(!isalpha(ch));
		switch(ch){
			case 'P':	
						char t;
						scanf("%c", &t);
						scanf("%c", &t);
						s.insert(s.begin() + iter, t);
						iter++;
						break;
			case 'L':
						iter = (iter > 0)? iter - 1: iter;
						break;
			case 'D':
						iter = (iter < s.size())? iter + 1: iter;
						break;
			case 'B':
						if(iter > 0){
							iter--;
							s.erase(s.begin() + iter);
						}
						break;
		}
	}
	printVector(s);
}

void printVector(const vector<char> s){
	for(const char &it: s){
		printf("%c", it);
	}
	printf("\n");
}
