#include <cstdio>
using namespace std;
int main(){
	int X, Y;
	scanf("%d\n%d", &X, &Y);
	if(X>0&&Y>0){printf("1\n");}
	else if(X<0&&Y>0){printf("2\n");}
	else if(X<0&&Y<0){printf("3\n");}
	else printf("4\n");
}
