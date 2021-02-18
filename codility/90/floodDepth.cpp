#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> &A);

int main(int argc, char** argv){

	vector<int> vec = {1,3,2,1,2,1,5,3,3,4,2};
	cout<<solution(vec)<<endl;
	
}

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int answer = 0;
    int in_max = 0, in_min = 100000001, max_depth = 0, tmp_depth = 0;
    for(const int &in: A){
        if(in >= in_max){
            if(in_min == 100000001){
                in_max = in;
            }
            else{
                tmp_depth = in_max - in_min;
                if(tmp_depth > max_depth){
                    max_depth = tmp_depth;
                }
                in_max = in;
                in_min = 100000001;
            }
        }
		else{
        	if(in > in_min){
           		tmp_depth = in - in_min;
            	if(tmp_depth > max_depth){
               		max_depth = tmp_depth;
            	}
        	}
			else{
				in_min = in;
			}
		}
    }

    answer = max_depth;

    return answer;
}
