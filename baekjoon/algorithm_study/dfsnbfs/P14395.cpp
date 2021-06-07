#include <cstdio>
#include <string>
#include <queue>
#include <set>
using namespace std;
int in(string c, long long tmp, int t, set<long long>& s, queue<pair<string, long long>>& q){
    if(s.insert(tmp).second){
        if(tmp==t)return 0;
        q.push(make_pair(c, tmp));
        return 1;
    }
    return -1;
}
void pr(string str, char op){
    for(const auto& c: str)printf("%c", c);
    printf("%c\n", op);
}
int main(){
    int s, t;
    scanf("%d %d", &s, &t);
    if(s==t){
        printf("0\n");
        return 0;
    }
    queue<pair<string, long long>> Q;
    set<long long> S;
    Q.push(make_pair("", s));
    while(!Q.empty()){
        long long now = Q.front().second;
        string str = Q.front().first;
        Q.pop();
        if(in(str+"*", now*now, t, S, Q)==0){
            pr(str,'*');
            return 0;
        }
        if(in(str+"+", now+now, t, S, Q)==0){
            pr(str,'+');
            return 0;
        }
        if(in(str+"-", now-now, t, S, Q)==0){
            pr(str,'-');
            return 0;
        }
        if(now!=0&&in(str+"/", now/now, t, S, Q)==0){
            pr(str,'/');
            return 0;
        }
    }
    printf("-1\n");
}
