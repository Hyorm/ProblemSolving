#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
int main(){
	string str;
	getline(cin, str);
	int ans = 0;
	string tmp = "";
	bool m = false;
	for(int i = 0; i < str.length(); i++){
		if(str.at(i)!='+'&&str.at(i)!='-')tmp+=str.at(i);
		else{
			int t = stoi(tmp);
			if(m)ans -= t;
			else{
				ans += t;
				if(str.at(i)=='-')m = true;
			}
			tmp = "";
		}
	}
	int t = stoi(tmp);
	if(m)ans -= t;
	else ans += t;
	printf("%d\n", ans);
}
