#include<iostream>

using namespace std;
const int N = 1e6+10;
char s[N];
int nxt[N];


int main(){
	int l;
	scanf("%d %s",&l,s+1);
	int j = 0;
	nxt[1]=0;
	for(int i = 2;s[i];i++){
		while(j&&s[i]!=s[j+1])j=nxt[j];
		if(s[i]==s[j+1])j++;
		nxt[i]=j;
		int n = i,m = i-nxt[i];
		if(m){
			if(n%m==0&&n/m>=2)printf("%d %d\n",n,n/m);
		}
	}
	return 0;
}
