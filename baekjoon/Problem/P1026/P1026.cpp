#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int N;

bool cmp(int* a, int* b){
	return a[0] > b[0];
}

int main(int argc, char** argv){
	int answer = 0;
	scanf("%d", &N);
	int* A = new int[N];
	int* B = new int[N];//do not sort
	int** sort_B = new int*[N];
	for(int i = 0; i < N; i++){
		cin >> A[i];
	}
	for(int i = 0; i < N; i++){
		sort_B[i] = new int[2];
		int tmp;
		cin >> B[i];
		sort_B[i][0] = B[i];
		sort_B[i][1] = i;
    }
	sort(A, A+N);

	sort(sort_B, sort_B+N, cmp);

	for(int i = 0; i < N; i++){
        answer += A[i]*B[sort_B[i][1]];
    }
	printf("%d\n", answer);
}
