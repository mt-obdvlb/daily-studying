#include<bits/stdc++.h>

using namespace std;

int n,vis[10005],fa[10005],tot,x,y;
struct edges{
	int nxt,to;
}e[10005];

int LCA(int u,int v){
	if(u==v)return u;
	vis[u] = 1;
	while(fa[u]!=u){
		u = fa[u];
		vis[u] = 1;
	}
	while(fa[v]!=v){
		if(vis[v])return v;	
		v = fa[v];
	}
	return 0;
}

int main(){
	int T,u,v,rt;
	cin>>T;
	while(T--){
		tot = 0;
		scanf("%d",&n);
		memset(vis,0,sizeof(vis));
		for(int i = 1;i<=n;i++)fa[i] = i;
		for(int i = 1;i<n;i++){
			scanf("%d%d",&u,&v);
			fa[v] = u;
		}
		scanf("%d%d",&x,&y);
		printf("%d\n",LCA(x,y));		
	}
	return 0;
}
