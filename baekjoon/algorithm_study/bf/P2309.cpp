#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> K[2];
int main(){
    int sum = 0;
    for(int i = 0; i < 9; i++){
        int tmp;
        scanf("%d", &tmp);
        K[0].push_back(tmp);
        K[1].push_back(0);
    }
    sort(K[0].begin(), K[0].end());
    for(int i = 0; i < 9; i++)sum+=K[0][i];
    for(int i = 0; i < 8; i++){
            sum -= K[0][i];
            K[1][i] = 1;
        for(int j = i+1; j < 9; j++){
            sum -= K[0][j];
            K[1][j] = 1;
            if(sum == 100){
                for(int k = 0; k < 9; k++){
                    if(K[1][k]==0){
                        printf("%d\n", K[0][k]);
                    }
                }
                return 0 ;
            }
            K[1][j] = 0;
            sum += K[0][j];
        }
        K[1][i] = 0;
        sum += K[0][i];
    }
}
