#include<bits/stdc++.h>

using namespace std;

const int N = 1e4+5;
int rt,S,size[N],f[N],d[N],dep[N];
int cnt,k,ans,n,head[N];
bool vis[N];
struct edges{
	int to,nxt,w;
}e[N<<1];

void add(int u,int v,int w){
	e[++cnt].w = w;
	e[cnt].to = v;
	e[cnt].nxt = head[u];
	head[u] = cnt;
}

void getroot(int u,int fa){
	size[u] = 1;
	f[u] = 0;
	for(int i = head[u];i;i = e[i].nxt){
		int v = e[i].to,w = e[i].w;
		if(v==fa)continue;
		if(vis[v])continue;
		getroot(v,u);
		size[u]+=size[v];
		f[u] = max(f[u],size[v]);
	} 
	f[u] = max(f[u],S-size[u]);
	if(f[u]<f[rt]){
		rt = u;
	}
}

void getdep(int u,int fa);

int getsum(int u,int dis){
	d[u] = dis;
	dep[0] = 0;
	getdep(u,0);
	sort(dep+1,dep+dep[0]+1);
	int L = 1,R = dep[0],sum = 0;
	while(L<R){
		if(dep[L]+dep[R]<=k)sum+=R-L,L++;
		else R--;
	}
	return sum;
}

void getdep(int u,int fa){
	dep[++dep[0]] = d[u];
	for(int i = head[u];i;i = e[i].nxt){
		int v = e[i].to,w = e[i].w;
		if(vis[v])continue;
		if(v==fa)continue;
		d[v] = d[u] +w;
		getdep(v,u);
	}
}

void solve(int u){
	vis[u] = 1;
	ans+=getsum(u,0);
	for(int i = head[u];i;i = e[i].nxt){
		int v = e[i].to,w = e[i].w;
		if(vis[v])continue;
		ans-=getsum(v,w);
		rt = 0;
		S = size[v];
		getroot(v,0);
		solve(rt);
	}
}

int main(){
	f[0] = 0x7fffffff;
	int x,y,z;
	while(~scanf("%d%d",&n,&k)&&n&&k){
		memset(vis,0,sizeof(vis));
		memset(head,0,sizeof(vis));
		for(int i = 1;i<n;i++){
			scanf("%d%d%d",&x,&y,&z);
			add(x,y,z);
			add(y,x,z);
		}	
		rt = 0;
		S = n;
		getroot(1,-1);
		solve(rt);
		printf("%d\n",ans);
	}
	return 0;
}
