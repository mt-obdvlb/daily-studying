#include<bits/stdc++.h>

using namespace std;
const int N = 1e4+5;
const int base = 26;
int rt[N],ch[N*30][26];
int cnt,val[N*30];

void ins(int x,int lst,const char *s){
	for(int i = 0;s[i];i++){
		int ind = s[i]-'a';
		ch[x][ind]=++cnt;
		for(int j = 0;j<base;j++){
			if(ch[x][ind])continue;
			ch[x][j]=ch[lst][j];
		}
		x = ch[x][ind],lst = ch[lst][ind];
		val[x] = val[lst];
	}
	val[x]+=1;
}

int find_once(int x,const char *s){
	int p = rt[x];
	for(int i = 0;s[i];i++){
		p = ch[p][s[i]-'a'];
	}
	return val[p];
}

int query(int l,int r,const char *s){
	int x1 = find_once(r,s);
	int x2 = find_once(l-1,s);
	return x1-x2;
}

int main(){
	int n;
	char s[100];
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>s;
		rt[i]=++cnt;
		ins(rt[i],rt[i-1],s);
	}
	int l,r;
	while(cin>>l>>r>>s){
		cout<<query(l,r,s)<<endl;
	}
	return 0;
}
