#include <string>
#include <vector>
#include <set>
#include <cmath>
using namespace std;
set<int> D[9];
set<int> P;
int solution(int N, int number) {
    int answer = 0;
    if(N==number)return 1;
    D[1].insert(N);
    P.insert(N);
    for(int i = 2; i <= 8; i++){
        int t = i, tmp = N;
        while(t-->1){tmp*=10;tmp+=N;}
        if(tmp==number)return i;
        if(P.insert(tmp).second)D[i].insert(tmp);
        for(int j = 1; j <=((i%2==1)?i/2+1:i/2); j++){
            for(const auto &it : D[i-j]){
                for(const auto &tt : D[j]){
                    if(it+tt==number)return i;
                    if(P.insert(it+tt).second)D[i].insert(it+tt);
                    if(it-tt==number)return i;
                    if(it-tt>0&&P.insert(it-tt).second)D[i].insert(it-tt);
                    if(it/tt!=0&&it/tt==number)return i;
                    if(it/tt!=0&&P.insert(it/tt).second)D[i].insert(it/tt);
                    if(it*tt==number)return i;
                    if(P.insert(it*tt).second)D[i].insert(it*tt);
                }  
            }
        }
    }

    return -1;
}
