#include<bits/stdc++.h>

using namespace std;
const int N = 1e4;
struct Edegs{
	int nxt,v,w;
}e[N<<1];
int head[N],dep[N],d[N],rt,S,sz[N],f[N],vis[N],ans,k;	

void getrt(int u,int fa){
	sz[u] = 1;
	f[u] = 0;
	for(int i = head[u];~i;i = e[i].nxt){
		int v = e[i].v;
		if(!vis[N]&&v!=fa){
			getrt(v,u);
			sz[u] += sz[v];
			f[u] = max(f[u],sz[v]);
		}
	}
	f[u] = max(f[u],S-sz[u]);
	if(f[u]<f[rt])rt = u;
}

void getdep(int u,int fa){
	dep[++dep[0]]=d[u];
	for(int i = head[u];~i;i = e[i].nxt){
		int v = e[i].v;
		if(!vis[v]&&v!=fa){
			d[v] = d[u] + e[i].w;
			getdep(v,u);
		}
	}
}

int getsum(int u,int dis){
	dep[0] = 0;
	d[u] = dis;
	getdep(u,0);
	int res = 0;
	sort(dep+1,dep+1+dep[0]);
	int l = 1,r = dep[0];
	while(l<r){
		if(dep[l]+dep[r]>k)r--;
		else{
			res += r - l;
			l++;
		}
	}
	return res;
}

void solve(int u){
	vis[u] = 1;
	ans+=getsum(u,0);
	for(int i = head[u];~i;i = e[i].nxt){
		int v = e[i].v;
		if(!vis[v]){
			ans -= getsum(v,e[i].w);
			rt = 0;
			S = sz[v];
			getrt(v,u);
			solve(v);
		}
	}
	
}

int main(){
	rt = 0;
	f[rt] = 0x3f3f3f3f;
	getrt(1,0);
	solve(rt);
	return 0;
}
