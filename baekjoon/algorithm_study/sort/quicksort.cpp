#include <cstdio>
using namespace std;
int ptt(int A[], int left, int right){
    int pivot = A[left];
    int low = left;
    int high = right+1;
    while(low<high){
        do{low++;}
        while(low<=right&&pivot > A[low]);
        do{high--;}
        while(left<=high&&pivot < A[high]);
        if(low<high){
            int t = A[low];
            A[low] = A[high];
            A[high] = t;
        }
    }
    int t = A[left];
    A[left] = A[high];
    A[high] = t;
    return high;
}
void quicksort(int A[], int left, int right){
    if(left<right){
        int pivot = ptt(A, left, right);
        quicksort(A, left, pivot-1);
        quicksort(A, pivot+1, right);
    }
}
int main(){
    int* A;
    int N;
    scanf("%d", &N);
    A = new int[N];
    for(int i = 0; i < N; i++)scanf("%d", &A[i]);
    quicksort(A, 0, N-1);
    for(int i = 0; i < N; i++){
        printf("%d\n", A[i]);
    }
}
