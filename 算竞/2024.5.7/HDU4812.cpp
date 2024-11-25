#pragma comment(linker,"/STACK:102400000,102400000")
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

typedef long long ll;
const int N =1e5+5;
const int inf = 0x3f3f3f3f;
const int mod = 1e6+3;
int n,k,head[N],S,rt,size[N],f[N],id[N],cnt,ans1,ans2,top;
ll inv[mod+5],mp[mod+5];
ll val[N],d[N],dep[N];
bool vis[N];
struct edges{
	int to,nxt;
}e[N<<1];

void inv_build(){
	inv[1] = 1;
	for(int i =2;i<mod;i++){
		inv[i] = (mod-mod/i)*inv[mod%i]%mod;
	}
}

void add(int u,int v){
	e[++cnt].nxt = head[u];
	e[cnt].to = v;
	head[u] = cnt;
}

void getrt(int u,int fa){
	size[u] = 1;
	f[u] = 0;
	for(int i = head[u];i;i = e[i].nxt){
		int v = e[i].to;
		if(v==fa)continue;
		if(vis[v])continue;
		getrt(v,u);
		size[u]+=size[v];
		f[u] = max(f[u],size[v]);
	}
	f[u] = max(f[u],S-size[u]);
	if(f[u]<f[rt])rt = u;
}

void getdep(int u,int fa){
	dep[++top] = d[u];
	id[top] = u;
	for(int i = head[u];i;i = e[i].nxt){
		int v = e[i].to;
		if(v==fa)continue;
		if(vis[v])continue;
		d[v] = (d[u]*val[v])%mod;
		getdep(v,u);
	}
}

void query(int x,int id){
	x = inv[x]*val[rt]*k%mod;
	int y = mp[x];
	if(!y)return;
	if(y>id)swap(y,id);
	if(y<ans1||(y==ans1&&id<ans2)){
		ans1 = y,ans2 = id;
	}
}

void solve(int u){
	vis[u] = 1;
	mp[val[u]] = u;
	for(int i = head[u];i; i = e[i].nxt){
		int v = e[i].to;
		if(vis[v])continue;
		top = 0;
		d[v] = (val[v] *val[u])%mod;
		getdep(v,u);
		for(int j =1;j<=top;j++){
			query(dep[j],id[j]);
		}
		for(int j  =1;j<=top;j++){
			if(!mp[dep[j]]||mp[dep[j]]>id[j]){
				mp[dep[j]] =id[j];
			}
		}
	}
	mp[val[u]] = 0;
	for(int i = head[u];i;i = e[i].nxt){
		int v = e[i].to;
		if(vis[v])continue;
		top = 0;
		d[v] = (val[u]*val[v])%mod;
		getdep(v,u);
		for(int j = 1;j<=top;j++){
			mp[dep[j]] = 0;
		}
	}
	for(int i = head[u];i;i = e[i].nxt){
		int v= e[i].to;
		if(vis[v])continue;
		rt = 0;
		S = size[v];
		getrt(v,0);
		solve(rt);
	}
}

int main(){
	int u,v,w;
	inv_build();
	f[0] = 0x7fffffff;
	while(~scanf("%d%d",&n,&k)){
		for(int i = 1;i<=n;i++){
			scanf("%d",val+i);
		}
		memset(head,0,sizeof(head));
		ans1 = ans2 = inf;
		memset(vis,0,sizeof(vis));
		top = cnt = rt = 0;
		S = n;
		for(int i = 1;i<n;i++){
			scanf("%d%d",&u,&v);
			add(u,v);
			add(v,u);
		}
		getrt(1,0);
		solve(rt);
		if(ans1==inf)cout<<"No solution"<<endl;
		else printf("%d %d\n",ans1,ans2);
	}
	return 0;
}
