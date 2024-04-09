#include<bits/stdc++.h>

using namespace std;

int n,low[105],dfn[105],cut[105],tot,ans;
int head[105],to[105],nxt[105],cnt;

void dfs(int u,int rt){
	dfn[u]=low[u] = ++tot;
	int v;
	int count = 0;
	int cur = head[u];
	while(cur){
		v = to[cur];
		cur = nxt[cur];
		if(dfn[v])low[u] = min(low[u],dfn[v]);
		else{
			dfs(v,u);
			low[u] = min(low[u],low[v]);
			if(low[v]>=dfn[u]){
				count++;
				if(rt!=u||count>1){
					cut[u] = 1;
				}
			}
		}
	}
}

void add(int u,int v){
	nxt[++cnt] = head[u];
	to[cnt] = v;
	head[u] = cnt;
}

int main(){
	while(cin>>n&&n){
		tot=0;
		ans=0;
		memset(low,0,sizeof(low));
		memset(dfn,0,sizeof(dfn));
		memset(head,0,sizeof(dfn));
		memset(to,0,sizeof(dfn));
		memset(nxt,0,sizeof(dfn));
		memset(cut,0,sizeof(cut));
		int u,v;
		string s,t;
		while(getline(cin,s)){
			if(s=="0")break;
			stringstream input(s);
			input>>t;
			u = atoi(t.c_str());
			while(input>>t){
				v = atoi(t.c_str());
				add(u,v);
				add(v,u);
			}
		}	
		dfs(u,u);
		for(int i = 1;i<=n;i++)if(cut[i])ans++;
		cout<<ans<<endl;
	}
	return 0;
}
