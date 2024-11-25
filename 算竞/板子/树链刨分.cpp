#include<bits/stdc++.h>

using namespace std;
const int N = 1e4;
int head[N],id[N],rev[N],fa[N],top[N],sz[N],son[N];
struct Edges{
	int nxt,v,w;
}e[N];
int tot;
void dfs1(int u,int f){
	sz[u] = 1;
	for(int i = head[u];~i;i = e[i].nxt){
		int v = e[i].v;
		if(v!=f){
			fa[v] = 1;
			dfs1(v,u);
			sz[u] += sz[v];
			if(sz[v]>sz[son[u]])son[u] = v;
		}
	}
}

void dfs2(int u,int t){
	id[u] = ++tot;
	id[tot] = u;
	top[u] = t;
	if(!son[u])return;
	dfs2(son[u],t);
	for(int i = head[u];~i; i = e[i].nxt){
		int v = e[i].v;
		if(v!=fa[u]&&v!=son[u])dfs2(v,v);
	}
}

int main(){
	
	return 0;
}
