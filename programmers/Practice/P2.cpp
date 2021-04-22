#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    sort(phone_book.begin(), phone_book.end());
    for(int i = 0; i < phone_book.size()-1; i++){
        if(phone_book[i].length()<=phone_book[i+1].length())if(phone_book[i].compare(phone_book[i+1].substr(0,phone_book[i].length()))==0)return false;
    }
    return answer;
}
