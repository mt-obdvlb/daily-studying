#include<bits/stdc++.h>

using namespace std;
const int N = 3e6+10;
int nxt[N][62],ed[N];
int cnt = 1,rt = 1;

int code(char ch){
	if(ch>='a'&&ch<='z')return ch-'a';
	if(ch>='A'&&ch<='Z')return ch-'A'+26;
	if(ch>='0'&&ch<='9')return ch-'0'+52;
}


void ins(const char *s){
	int p =rt;
	for(int i = 0;s[i];i++){
		ed[p]++;
		int ind = code(s[i]);
		if(!nxt[p][ind])nxt[p][ind]=++cnt;
		p = nxt[p][ind];
	}
	ed[p]++;
}

int query(const char *s){
	int p = rt;
	for(int i = 0;s[i];i++){
		int ind = code(s[i]);
		p = nxt[p][ind];
		if(!p)return 0;
	}
	return ed[p];
}

void init(){
	for(int i = 0;i<=cnt;i++){
		for(int j = 0;j<62;j++)nxt[i][j]=0;
	}
	for(int i = 0;i<=cnt;i++)ed[i]=0;
	cnt = rt = 1;
}

int main(){
	int T,n,m;
	char s[N];
	cin>>T;
	while(T--){
		init();
		scanf("%d%d",&n,&m);
		while(n--){
			scanf("%s",s);
			ins(s);
		}
		while(m--){
			scanf("%s",s);
			printf("%d\n",query(s));
		}
	}
	
	return 0;
}
