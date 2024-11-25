#include<iostream>

using namespace std;

const int N = 4e4+5;
int tot,T,n,m,cnt,dis[N],head[N];
int size[N],fa[N],son[N],top[N],dep[N];
struct edges{
	int nxt,to,w;
}e[N<<1];

void dfs1(int u,int f){
	size[u] = 1;
	for(int i = head[u];i;i = e[i].nxt){
		int v = e[i].to,w = e[i].w;
		if(v==f)continue;
		fa[v] = u;
		dep[v] = dep[u]+1;
		dis[v] = dis[u]+w;
		dfs1(v,u);
		size[u]+=size[v];
		if(size[v]>size[son[u]])son[u] = v;
	}
}

void dfs2(int u){
	if(u == son[fa[u]])top[u] = top[fa[u]];
	else top[u] = u;
	for(int i = head[u];i;i = e[i].nxt){
		int v = e[i].to;
		if(v!=fa[u])dfs2(v);
	}
}

int LCA(int u,int v){
	while(top[u]!=top[v]){
		if(dep[top[u]]>dep[top[v]])u =fa[top[u]];
		else v = fa[top[v]];
	}
	return dep[u]>dep[v]?v:u;
}

void add(int u,int v,int w){
	e[++cnt].nxt = head[u];
	e[cnt].to = v;
	e[cnt].w = w;
	head[u] = cnt;
}

int main(){
	scanf("%d",&T);
	int u,v,w,lca;
	while(T--){
		for(int i=1;i<=n;i++)
			head[i]=dep[i]=dis[i]=son[i]=0;
		cnt = 0;
		scanf("%d%d",&n,&m);		
		for(int i = 1;i<n;i++){
			scanf("%d%d%d",&u,&v,&w);
			add(u,v,w);
			add(v,u,w);
		}
		dep[1] = 1;
		dfs1(1,0);
		dfs2(1);
		while(m--){
			scanf("%d%d",&u,&v);
			lca = LCA(u,v);
			printf("%d\n",dis[u]+dis[v]-2*dis[lca]);
		}
	}
	return 0;
}
