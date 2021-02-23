#include <stdio.h>
#include <math.h>
using namespace std;

int idx = 0;
void move(int n, int x, int y);

int main(int argc, char** argv){
	int n;

	scanf("%d", &n);
	int row = pow(2,n) - 1;
	printf("%d\n", row);

	move(n, 1, 3);

}

void move(int n, int x, int y){
	if(n == 0){
		return;
	}
	move(n - 1, x, 6 - x - y);
	printf("%d %d\n", x, y);
	move(n - 1, 6 - x - y, y);
}
