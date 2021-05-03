#include <cstdio>
using namespace std;
int gcd(int a, int b){
	if(b==0)return a;
	return gcd(b, a%b);
}
int main(){
	int T;
	scanf("%d", &T);
	for(int i = 0; i < T; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", a*b/gcd(a, b));
	}
}
