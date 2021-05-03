#include <cstdio>
using namespace std;
int gcd(int a, int b){
	if(b==0)return a;
	return gcd(b, a%b);
}
int main(){
	int a, b, c;
	scanf("%d %d", &a, &b);
	c = gcd(a,b);
	printf("%d\n%d",c, a*b/c);
}
