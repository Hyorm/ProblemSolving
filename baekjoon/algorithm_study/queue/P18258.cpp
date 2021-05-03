#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
int main(){
	int T;
	queue<int> q;
	scanf("%d\n", &T);
	for(int i = 0; i < T; i++){
		char str[6];
		int t = 0;
		while(true){
			char c;
			scanf("%c", &c);
			if(c=='\n'||c==' ')break;
			str[t++] = c;
		}
		str[t++] = '\0';
		if(strcmp("push", str)==0){
			int n;
			scanf("%d\n", &n);
			q.push(n);
			continue;
		}
		if(strcmp("front", str)==0){
			if(!q.empty())printf("%d\n",q.front());
			else printf("-1\n");
			continue;
		}
		if(strcmp("pop", str)==0){
			if(!q.empty())printf("%d\n",q.front());
			else printf("-1\n");
			if(!q.empty())q.pop();
			continue;
		}
		if(strcmp("size", str)==0){
			printf("%lu\n",q.size());
			continue;
		}
		if(strcmp("empty", str)==0){
			if(!q.empty())printf("0\n");
			else printf("1\n");
			continue;
		}
		if(strcmp("back", str)==0){
			if(!q.empty())printf("%d\n",q.back());
			else printf("-1\n");
			continue;
		}
	}
}
