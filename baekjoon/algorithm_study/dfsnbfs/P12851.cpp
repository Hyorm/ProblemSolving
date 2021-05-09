#include <cstdio>
#include <queue>
using namespace std;
int V[100001];
int main(){
    int N, K;
    scanf("%d %d", &N, &K);
    int ans_time = -1;
    int ans_num = 0;
    queue<pair<int, int> >q;
    if(N==K){
        printf("0\n1\n");
        return 0;
    }
    q.push(make_pair(N, 1));
    while(!q.empty()){
        int curx = q.front().first;
        int curt = q.front().second;
        V[curx] = curt;
        q.pop();
        if(ans_time==-1||curt<=ans_time){
            if(curx+1==K||curx-1==K||curx*2==K){
                if(ans_time==-1||ans_time>curt){
                    ans_time = curt;
                    ans_num = 0;
                }
                ans_num++;
            }
            if(curx+1<100001&&curx+1!=K&&(V[curx+1]==0||V[curx+1]>curt))q.push(make_pair(curx+1, curt+1));
            if(curx-1>=0&&curx-1!=K&&(V[curx-1]==0||V[curx-1]>curt))q.push(make_pair(curx-1, curt+1));
            if(curx*2<100001&&curx*2!=K&&(V[curx*2]==0||V[curx*2]>curt))q.push(make_pair(curx*2, curt+1));
        }
    }
    printf("%d\n%d\n", ans_time, ans_num);
}
