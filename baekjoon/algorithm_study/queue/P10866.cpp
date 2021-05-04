#include <cstdio>
#include <cstring>
#include <deque>
using namespace std;
int main(){
	int T;
	scanf("%d\n", &T);
	deque<int> dq;
	for(int i = 0; i < T; i++){
		char str[11];
		int t = 0;
		while(true){
			char c;
			scanf("%c", &c);
			if(c==' '||c=='\n')break;
			str[t++] = c;
		}
		str[t] = '\0';
		if(strcmp(str, "push_front")==0){
			int d;
			scanf("%d\n", &d);
			dq.push_front(d);
			continue;
		}
		if(strcmp(str, "push_back")==0){
			int d;
			scanf("%d\n", &d);
			dq.push_back(d);
			continue;
		}
		if(strcmp(str, "pop_front")==0){
			if(!dq.empty()){
				printf("%d\n",dq.front());
				dq.pop_front();
			}else printf("-1\n");
			continue;
		}
		if(strcmp(str, "pop_back")==0){
			if(!dq.empty()){
				printf("%d\n",dq.back());
				dq.pop_back();
			}else printf("-1\n");
			continue;
		}
		if(strcmp(str, "empty")==0){
			if(!dq.empty())printf("0\n");
			else printf("1\n");
			continue;
		}
		if(strcmp(str, "size")==0){
			printf("%lu\n", dq.size());
			continue;
		}
		if(strcmp(str, "front")==0){
			if(!dq.empty())printf("%d\n",dq.front());
			else printf("-1\n");
			continue;
		}
		if(strcmp(str, "back")==0){
			if(!dq.empty())printf("%d\n",dq.back());
			else printf("-1\n");
		}
	}
}
