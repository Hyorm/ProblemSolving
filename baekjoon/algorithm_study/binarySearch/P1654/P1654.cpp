#include <stdio.h>
#include <iostream>
#include <memory.h>

using namespace std;

int solution(int k, int n, int min, int* list);

int main(int argv, char** argc){
	int K, N;

	scanf("%d %d", &K, &N);
	
	int* list = new int[K];
	int min = -1;
	for(int i = 0; i<K; i++){
		scanf("%d",&list[i]);
		if(min == -1 || min > list[i]){
			min = list[i];
		}
	}
	printf("%d\n",solution(K, N, min, list));
	delete[] list;
}

int solution(int K, int N, int min, int* list){

	int sum = 0, len = min;
	int answer = 0;
	
	while(sum < N){
		sum = 0;
		for(int i = 0; i < K; i++){
			sum += list[i] / len;
		}
		len--;
	}	
	answer = len + 1;
	return answer;
}
