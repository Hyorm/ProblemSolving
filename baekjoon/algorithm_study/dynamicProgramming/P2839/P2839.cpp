#include <cstdio>

using namespace std;

int main(){
	int N;
	int S[5001] = {0,};

	scanf("%d", &N);

	S[3] = 1;
	S[5] = 1;

	for(int i = 6; i <= N; i++){
		if(i%3== 0 && (S[i] == 0 || S[i] > S[i-3]+1))S[i] = S[i-3]+1;
		if(i%5== 0 && (S[i] == 0 || S[i] > S[i-5]+1))S[i] = S[i-5]+1;
		if(S[i-5]!=0 &&(S[i] == 0 || S[i] > S[i-5]+1))S[i] = S[i-5]+1;
		if(S[i-3]!=0 &&(S[i] == 0 || S[i] > S[i-3]+1))S[i] = S[i-3]+1;
	}
	printf("%d\n", S[N]==0?-1:S[N]);
}
