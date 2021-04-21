int solution(int N) {
    // write your code in C++14 (g++ 6.2.0)
    int bin = 0;
    int max = 0;
    int tmp = 0;
    int bf = 0;
    while(N>0){
        bin*=10;
        bin+=N%2;
        if(N%2==0)if(bf==1)tmp++;
        if(N%2==1){
            bf = 1;
            if(tmp>max)max = tmp;
            tmp = 0;
        }
        N/=2;
    }
    if(tmp>max)max = tmp;
    return max;
}

