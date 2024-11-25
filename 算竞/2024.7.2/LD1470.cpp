#include<bits/stdc++.h>

using namespace std;
const int N = 2e5+10;
int nxt[N][26],ed[N],dep[N];
int cnt = 1,rt = 1;
int dp[N];

void ins(const char *s){
	int p = rt;
	for(int i = 0;s[i];i++){
		int ind = s[i]-'A';
		if(!nxt[p][ind]){
			nxt[p][ind]=++cnt;
			dep[cnt]=dep[p]+1;
		}
		p = nxt[p][ind];
	}
	ed[p]++;
}

void mark(string &s,int pos){
	int p = rt;
	for(int i = pos;s[i];i++){
		int ind = s[i]-'A';
		p = nxt[p][ind];
		if(!p)break;
		if(ed[p])dp[pos+dep[p]]=1;
	}
}

int main(){
	string s,t;
	while(cin>>s){
		if(s==".")break;
		ins(s.c_str());
	}
	s="";
	while(cin>>t)s+=t;
	dp[0]=1;
	int ans = 0;
	for(int i = 0;s[i];i++){
		if(!dp[i])continue;
		ans = i;
		mark(s,i);
	}
	if(dp[s.size()])ans = s.size();
	cout<<ans<<endl;
	return 0;
}
