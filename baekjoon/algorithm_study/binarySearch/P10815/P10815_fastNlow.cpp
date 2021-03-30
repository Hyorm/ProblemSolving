#include <cstdio>
#include <algorithm>
using namespace std;
int N, M;
int* S;
int* C;

bool bsr(int x, int low, int high);
int find(int x, int mid);

int main(){
	scanf("%d", &N);
	S = new int[N];
	for(int i = 0 ; i < N; i++){
		scanf("%d", &S[i]);
	}
	scanf("%d", &M);
	C = new int[M];
	for(int i = 0 ; i < M; i++){
		scanf("%d", &C[i]);
	}
	sort(S, S+N);
	for(int i = 0 ; i < M; i++){
		if(bsr(C[i], 0, N-1))printf("1 ");
		else printf("0 ");
	}
	printf("\n");
}

bool bsr(int x, int low, int high){
	if(low > high)return false;
	int mid = (low + high)/2;
	int f = find(x, mid);
	if(f == 0)return true;
	else if(f < 0) return bsr(x, low, mid-1);
	return bsr(x, mid+1, high);
}

int find(int x, int mid){
	if(S[mid] == x) return 0;
	else if(S[mid] < x) return 1;
	else return -1;
}
