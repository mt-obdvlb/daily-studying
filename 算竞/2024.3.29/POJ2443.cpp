#include<iostream>
#include<bitset>
using namespace std;

bitset<1010> s[10005];
int tot=0;

int main(){
	int n;
	scanf("%d",&n);
	while(n--){
		int m;
		scanf("%d",&m);
		
		while(m--){
			int t;
			scanf("%d",&t);
			s[t][tot]=1;
		}
		tot++;
	}
	int q;
	scanf("%d",&q);
	while(q--){
		int a,b;
		scanf("%d%d",&a,&b);
		int flag = 1;
		
		if((s[a]&s[b]).any())printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
