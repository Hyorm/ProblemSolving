#include <stdio.h>

using namespace std;

int main(int argc, char** argv){

	int n;
	int min[1000001];

	scanf("%d", &n);
	min[0] = 0;
	min[1] = 0;
	
	for(int i = 2; i <= n; i++){
		min[i] = min[i - 1] + 1;//for n--
		if(i % 3 == 0 && min[i] > min[i/3] + 1){//for n/3
			min[i] = min[i/3] + 1;
		}
		if(i % 2 == 0 && min[i] > min[i/2] + 1){//for n/2
			min[i] = min[i/2] + 1;
		}
	}
	printf("%d \n", min[n]);

	return 0;
}
