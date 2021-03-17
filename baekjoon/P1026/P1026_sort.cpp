#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int N;

int main(int argc, char** argv){
	int answer = 0;
	scanf("%d", &N);
	int* A = new int[N];
	int* B = new int[N];
	for(int i = 0; i < N; i++){
		cin >> A[i];
	}
	for(int i = 0; i < N; i++){
        cin >> B[i];
    }
	sort(A, A+N);
	sort(B, B+N);
	for(int i = 0; i < N; i++){
        answer += A[i]*B[N - i -1];
    }
	printf("%d\n", answer);
}
