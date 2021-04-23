#include <string>
#include <vector>

using namespace std;
int bx = 1, by = 1;
int find(int yx, int brown, int yellow){//n
    int yy = yellow/yx;
    if(yy<=0||yellow%yx!=0)return 2;
    if((yx+2)*(yy+2) == brown+yellow)return 0;
    return -1;    
}
void bin(int low, int high, int brown, int yellow){
    if(low<=high){
        int mid = (low+high)/2;
        int out = find(mid, brown, yellow);
        if(out==0){
            bx = (mid>=yellow/mid)?mid+2:yellow/mid+2;
            by = (mid<yellow/mid)?mid+2:yellow/mid+2;
        }
        else if(out==-1)bin(low, mid-1, brown, yellow);
        else{
            bin(mid+1, high, brown, yellow);
            bin(low, mid-1, brown, yellow);
        }
    }
}
vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    bin(1, yellow,brown, yellow);//width

    answer.push_back(bx);
    answer.push_back(by);
    return answer;
}
