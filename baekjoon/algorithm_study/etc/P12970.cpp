#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
int N, K;
bool count(string str);
string find(string str, int d){
    for(int i = d; i < str.length();i++){
        str.at(i) = 'B';
        if(count(str))return str;
        str.at(i) = 'A';
        string tmp = find(str, i+1);
        if(tmp!="")return tmp;
        str.at(i) = 'B';
    }
    return "";
}
bool count(string str){
    int t = 0;
    for(int i = 0; i < str.length(); i++){
        if(str.at(i)=='B')for(int j = 0; j < i; j++)if(str.at(j)=='A')t++;
        if(t>K)return false;
    }
    if(t==K)return true;
    return false;
}
int main(){
    scanf("%d %d",&N, &K);
    string answer = "";
    for(int i = 0; i < N; i++)answer+="B";
    int a = 0;
    if(K==0){
        cout<<answer<<"\n";
        return 0;
    }
    while(true){
        if(a*(N-a)>=K){
            for(int i = 0;i<a-1;i++)answer.at(i) = 'A';
            int back = (a-1)*(N-a);
            answer.at(N - 1 - (K - back)) = 'A';
            if(count(answer))break;
        }else a++;
        if(a>=N){
            answer = "";
            break;
        }
    }

    if(answer!="")cout<<answer<<"\n";
    else printf("-1\n");
}
