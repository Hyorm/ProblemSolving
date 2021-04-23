#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string name) {
    int answer = 0;
    int id = 0;
    string str = "";
    int n = name.length();
    for(int i = 0; i < n;i++){
        str+="A";
    }
    while(name.compare(str)!=0){
        if(str.at(id)==name.at(id)){
            int r = -1, l = 1;
            int ti = 1;
            while(r!=l){
                r = (id-ti<0)?n+(id-ti):id-ti;
                l = (id+ti>=n)?id+ti-n:id+ti;
                if(str.at(l)!=name.at(l)){
                    id = l;
                    answer+= ti;
                    break;
                }
                if(str.at(r)!=name.at(r)){
                    id = r;
                    answer+= ti;
                    break;
                }
                ti++;
            }
        }else{
            int tc = name.at(id)-'0';
            answer += (42-tc+1<tc-17)?42-tc+1:tc-17;
            str.at(id) = name.at(id);
        }
        
    }
    return answer;
}
