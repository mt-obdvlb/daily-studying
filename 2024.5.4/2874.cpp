#include<bits/stdc++.h>

using namespace std;

const int maxn = 10005;
int n,m,c;
int head1[maxn],head2[maxn],tot1,tot2,vis[maxn],fa[maxn],dis[maxn];
struct edges{
	int to,nxt,lca;
}e1[maxn<<1],e2[maxn<<1];

int get(int x){
	return x==fa[x]?x:fa[x] = get(fa[x]);
}

void add(int u,int v,int w){
	e1[++tot1].to = v;
	e1[tot1].nxt = head1[u];
	e1[tot1].lca = w;
	head1[u] = tot1;
}

void add(int u,int v){
	e2[tot2].to = v;
	e2[tot2].nxt = head2[u];
	head2[u] = tot2++;
}

void LCA(int u,int rt){
	vis[u] = rt;
	fa[u] = u;
	for(int i = head1[u];i;i = e1[i].nxt){
		int v = e1[i].to,w = e1[i].lca;
		if(vis[v]==-1){
			dis[v] = dis[u] + w;
			LCA(v,rt);
			fa[v] = u;
		}
	}
	for(int i = head2[u];~i;i = e2[i].nxt){
		int v = e2[i].to;
		if(vis[v]==-1)continue;
		if(vis[v]!=vis[u]){
			e2[v].lca = -1;
			e2[v^1].lca = -1;
		}else{
			int lca = get(v);
			e2[i].lca = dis[v]+dis[u] - 2*dis[lca];
			e2[i^1].lca = e2[v].lca;
		}
	}
}

int main(){
	int u,v,w;
	while(~scanf("%d%d%d",&n,&m,&c)){
		memset(vis,-1,sizeof(vis));
		memset(head2,-1,sizeof(head2));
		memset(head1,0,sizeof(head1));
		memset(dis,0,sizeof(dis));
		tot1 = tot2 = 0;
		while(m--){
			scanf("%d%d%d",&u,&v,&w);
			add(u,v,w);
			add(v,u,w);
		}	
		while(c--){
			scanf("%d%d",&u,&v);
			add(u,v);
			add(v,u);
		}	
		for(int i = 1;i<=n;i++){
			if(vis[i]==-1)LCA(i,i);
		}
		for(int i = 0;i<tot2;i+=2){
			if(e2[i].lca==-1)cout<<"Not connected"<<endl;
			else cout<<e2[i].lca<<endl; 
		}
	}
	return 0;
}
