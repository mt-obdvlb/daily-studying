#include<bits/stdc++.h>

using namespace std;

const int maxn = 80005;
int head1[maxn],head2[maxn],dis[maxn],fa[maxn],vis[maxn];
int n,m,k,tot1,tot2;
struct edges{
	int to,nxt,lca;
}e1[maxn],e2[maxn];

int get(int x){
	return x==fa[x]?x:fa[x] = get(fa[x]); 
}

void add(int u,int v,int w){
	e1[++tot1].nxt = head1[u];
	e1[tot1].to = v;
	e1[tot1].lca = w;
	head1[u] = tot1;
}

void add(int u,int v){
	e2[tot2].nxt = head2[u];
	e2[tot2].to = v;
	head2[u] = tot2++;
}

void LCA(int u){
	fa[u] = u;
	vis[u] = 1;
	for(int i = head1[u];i;i = e1[i].nxt){
		int v = e1[i].to,w = e1[i].lca;
		if(vis[v])continue;
		dis[v] = dis[u]+w;
		LCA(v);
		fa[v] = u;
	}
	for(int i = head2[u];~i;i = e2[i].nxt){
		int v = e2[i].to;
		if(!vis[v])continue;
		int lca = get(v);
		e2[i].lca = dis[v]+dis[u]-2*dis[lca];
		e2[i^1].lca = e2[i].lca;
	}
}

int main(){
	cin>>n>>m;
	int u,v,w;
	memset(head2,-1,sizeof(head2));
	for(int i = 0;i<m;i++){
		scanf("%d%d%d %*c",&u,&v,&w);
		add(u,v,w);
		add(v,u,w);
	}
	scanf("%d",&k);
	for(int i =0;i<k;i++){
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	LCA(1);
	for(int i = 0;i<tot2;i+=2)cout<<e2[i].lca<<endl;
	return 0;
}
