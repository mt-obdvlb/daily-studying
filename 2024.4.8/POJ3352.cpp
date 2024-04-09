#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1005;

string s;
int n,r,tot,head[MAXN],to[MAXN],nxt[MAXN],ans,dfn[MAXN],degee[MAXN],low[MAXN],cnt,T;

void add(int u,int v){
	to[++tot] = v;
	nxt[tot] = head[u];
	head[u] = tot;
}

void dfs(int u,int fa){
	dfn[u] = low[u] = ++cnt;
	int v;
	for(int i = head[u];i;i=nxt[i]){
		v = to[i];
		if(v==fa)continue;
		if(dfn[v]) low[u] =min(low[u],dfn[v]);
		else{
			dfs(v,u);
			low[u] = min(low[u],low[v]);
		}
	}
}


int main(){
	T=0;
	while(getline(cin,s)){
		T++;
		cin>>n>>r;
		tot=ans=cnt=0;
		memset(head,0,sizeof(head));
		memset(nxt,0,sizeof(head));
		memset(to,0,sizeof(head));
		memset(dfn,0,sizeof(head));
		memset(low,0,sizeof(head));
		memset(degee,0,sizeof(head));
		int u,v;
		while(r--){
			cin>>u>>v;
			add(u,v);
			add(v,u);
		}
		dfs(1,-1);
		for(int u = 1;u<=n;u++){
			for(int i = head[u];i;i=nxt[i]){
				int v = to[i];
				if(low[u]!=low[v]){
					degee[low[u]]++;
				}
			}
		}
		for(int i = 1;i<=n;i++){
			if(degee[i]==1)ans++;
		}
		cout<<"Output for Sample Input "<<T<<endl;
		cout<<(ans+1)/2<<endl<<endl;
		
		if(getchar()==EOF)break;
		if(getchar()==EOF)break;
		
	}
	
	return 0;
}
