#include<bits/stdc++.h>

using namespace std;
const int N = 1e4;
int dep[N],seq[N],f[N][30],pos[N],vis[N],tot,head[N];
struct Edges{
	int v,nxt;
}e[N];
void dfs(int u,int d){
	vis[u]=1;
	pos[u]=++tot;
	seq[tot]=u;
	dep[tot]=d;
	for(int i = head[u];~i;i = e[i].nxt){
		int v = e[i].v;
		if(vis[v])continue;
		dfs(v,d+1);
		seq[++tot]=u;
		dep[tot]=d;
	}
}

void ST(){
	for(int i = 1;i<=tot;i++)f[i][0]=i;
	int k = log2(tot);
	for(int j = 1;j<=k;j++)
		for(int i = 1;i<=tot+1-(1<<j);i++)
			f[i][j]=dep[f[i][j-1]]<dep[f[i+(1<<(j-1))][j-1]]?f[i][j-1]:f[i+(1<<(j-1))][j-1]	;
}

int RMQ(int l,int r){
	int k = log2(r-l+1);
	return dep[f[l][k]]<dep[f[r+1-(1<<k)][k]]?f[l][k]:f[r+1-(1<<k)][k];
}

int LCA(int x,int y){
	int l = pos[x],r = pos[y];
	if(l>r)swap(l,r);
	return seq[RMQ(l,r)];
}

int main(){
	
	return 0;
}
