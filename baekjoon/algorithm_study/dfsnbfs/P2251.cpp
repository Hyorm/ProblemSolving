#include <cstdio>
#include <queue>
#include <set>
using namespace std;
int main(){
    int A, B, C;
    scanf("%d %d %d", &A, &B, &C);
    queue<pair<pair<int, int>, int> > q;
    set<pair<pair<int, int>, int> > s;
    set<int> S;
    q.push(make_pair(make_pair(0 , 0), C));
    s.insert(make_pair(make_pair(0 , 0), C));
    while(!q.empty()){
        int a = q.front().first.first;
        int b = q.front().first.second;
        int c = q.front().second;
        if(a==0)S.insert(c);
        q.pop();
        //a->b 
        if(a+b > B){if(s.insert(make_pair(make_pair(a+b-B, B),c)).second)q.push(make_pair(make_pair(a+b-B, B),c));
        }else {if(s.insert(make_pair(make_pair(0, a+b),c)).second)q.push(make_pair(make_pair(0, a+b),c));}
        
        //a->c 
        if(a+c > C){if(s.insert(make_pair(make_pair(a+c-C, b),C)).second)q.push(make_pair(make_pair(a+c-C, b),C));
        }else {if(s.insert(make_pair(make_pair(0, b),a+c)).second)q.push(make_pair(make_pair(0, b),a+c));}
        //b->a 
        if(a+b > A){if(s.insert(make_pair(make_pair(A, a+b-A),c)).second)q.push(make_pair(make_pair(A, a+b-A),c));
        }else {if(s.insert(make_pair(make_pair(a+b, 0),c)).second)q.push(make_pair(make_pair(a+b, 0),c));}
        //b->c 
        if(b+c > C){if(s.insert(make_pair(make_pair(a, b+c-C),C)).second)q.push(make_pair(make_pair(a, b+c-C),C));
        }else {if(s.insert(make_pair(make_pair(a, 0),b+c)).second)q.push(make_pair(make_pair(a, 0),b+c));}
        //c->a 
        if(a+c > A){if(s.insert(make_pair(make_pair(A, b),a+c-A)).second)q.push(make_pair(make_pair(A, b),a+c-A));
        }else {if(s.insert(make_pair(make_pair(a+c, b),0)).second)q.push(make_pair(make_pair(a+c, b),0));}
        //c->b 
        if(b+c > B){if(s.insert(make_pair(make_pair(a, B),b+c-B)).second)q.push(make_pair(make_pair(a, B),b+c-B));
        }else{if(s.insert(make_pair(make_pair(a, b+c),0)).second)q.push(make_pair(make_pair(a, b+c),0));}
    }
    for(const int &i : S)printf("%d ", i);
}
