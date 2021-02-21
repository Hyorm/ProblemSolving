#include <stdio.h>
#include <algorithm>
#include <set>
using namespace std;

int main(){

	int O, S;
	scanf("%d", &O);
	multiset<int> own;

	for(int i = 0 ; i < O; i++){
		int tmp;
		scanf("%d", &tmp);
		own.insert(tmp);
	}
	
	scanf("%d", &S);
	
	for(int i = 0; i < S; i++){
		int tmp;
		scanf("%d", &tmp);
		printf("%lu ", own.count(tmp)); 
	}	
	printf("\n");
	
	return 0;
}
