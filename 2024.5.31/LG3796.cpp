#include<bits/stdc++.h>

using namespace std;
const int N = 2e4;
int n,cnt,tcnt[205],rt;
struct AC{
	int fail,nxt[26];
	vector<int> ind;
}ac[N];
char s[1000005],t[200][75];

int getnewnode(){
	++cnt;
	ac[cnt].fail=0;
	for(int i = 0;i<26;i++)ac[cnt].nxt[i]=0;
	ac[cnt].ind.clear();
	return cnt;
}

void ins(const char *s,int k){
	int p = rt;
	for(int i = 0;s[i];i++){
		int ind = s[i] - 'a';
		if(!ac[p].nxt[ind])ac[p].nxt[ind]=getnewnode();
		p = ac[p].nxt[ind];
	}
	ac[p].ind.push_back(k);
}

void init(){
	cnt = 0;
	rt = getnewnode();
	memset(tcnt,0,sizeof(tcnt));
}

void build(){
	queue<int> q;
	q.push(rt);
	while(!q.empty()){
		int cur = q.front();q.pop();
		int p = ac[cur].fail;
		if(p){
			for(int i = 0;i<ac[p].ind.size();i++){
				ac[cur].ind.push_back(ac[p].ind[i]);
			}
		}
		for(int i = 0;i<26;i++){
			int nxt = ac[cur].nxt[i];
			p = ac[cur].fail;
			if(!nxt){
				if(!p)ac[cur].nxt[i]=rt;
				else ac[cur].nxt[i] = ac[p].nxt[i];
			}else{
				if(!p)p = rt;
				else p = ac[p].nxt[i];
				ac[nxt].fail = p;
				q.push(nxt);
			}
		}
	}
}

void query(const char *s){
	int p = rt,q;
	for(int i = 0;s[i];i++){
		int ind = s[i]-'a';
		p = ac[p].nxt[ind];
		for(int i=0;i<ac[p].ind.size();i++){
			tcnt[ac[p].ind[i]]++;
		}
	} 
}

int main(){
	while(cin>>n&&n){
		init();		
		for(int i= 0;i<n;i++){
			scanf("%s",t[i]);
			ins(t[i],i);
		}
		build();
		scanf("%s",s);
		query(s);
		int ans = -1;
		for(int i = 0;i<n;i++){
			ans =max(ans,tcnt[i]);
		}		
		cout<<ans<<endl;
		for(int i = 0;i<n;i++){
			if(tcnt[i]==ans)cout<<t[i]<<endl;
		}
	}
}
