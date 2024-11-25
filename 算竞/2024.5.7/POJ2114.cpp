#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int N = 10005;
int n,k,cnt,S,rt,ans,head[N];
int f[N],dep[N],vis[N],size[N],d[N];
struct edges{
	int to,nxt,w;
}e[N<<2];

void add(int u,int v,int w){
	e[++cnt].w = w;
	e[cnt].to = v;
	e[cnt].nxt = head[u];
	head[u] = cnt;
}

void getrt(int u,int fa){
	size[u] = 1;
	f[u] = 0;
	for(int i = head[u];i;i=e[i].nxt){
		int v = e[i].to,w = e[i].w;
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
	dep[++dep[0]] = d[u];
	for(int i = head[u];i;i=e[i].nxt){
		int v = e[i].to,w = e[i].w;
		if(vis[v])continue;
		if(v==fa)continue;
		d[v] = d[u]+w;
		getdep(v,u);
	}
}

int getsum(int u,int dis){
	d[u] = dis;
	dep[0] = 0;
	getdep(u,0);
	sort(dep+1,dep+1+dep[0]);
	int L =1,R = dep[0],sum =0;
	while(L<R){
		if(dep[L]+dep[R]==k){
			if(dep[L]==dep[R]){
				sum+=(R-L+1)*(R-L)/2;
				break;
			}
			int st =L,ed = R;
			while(dep[st]==dep[L])st++;
			while(dep[ed]==dep[R])ed--;
			sum+=(st-L)*(R-ed);
			L = st,R = ed;
		}
		else if(dep[L]+dep[R]<k)L++;
		else R--;
	}
	return sum;
}

void solve(int u){
	vis[u] = 1;
	ans+=getsum(u,0);
	for(int i = head[u];i;i = e[i].nxt){
		int v = e[i].to,w = e[i].w;
		if(vis[v])continue;
		ans+=getsum(v,w);
		rt = 0;
		S = size[v];
		getrt(v,u);
		solve(rt);
	}
}

int main(){
	f[0] = 0x3f3f3f3f;
	while(scanf("%d",&n)&&n){
		memset(head,0,sizeof(head));
		int j,w;
		for(int i = 1;i<=n;i++){
			while(~scanf("%d",&j)&&j){
				scanf("%d",&w);
				add(i,j,w);
				add(j,i,w);
			}
		}
		while(scanf("%d",&k)&&k){
			memset(vis,0,sizeof(vis));
			rt = 0;
			ans = 0;
			S = n;
			getrt(1,0);
			solve(rt);
			if(ans)printf("AYE\n");
			else printf("NAY\n");
		}
		printf(".\n");
	}
	
	return 0;
}
