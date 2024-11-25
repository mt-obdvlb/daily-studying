#include<bits/stdc++.h>

using namespace std;
const int inf=0x3f3f3f3f;
const int N=1010;
const int M=101010;
int cnt,tot;
int head[N],ans[N],pre[N],h[N],g[N];
bool vis[N];
struct Edges{
   int v,nxt;
   int cap,flow;
}e[M<<1];//Ë«±ß

void init(){
	memset(head,-1,sizeof(head));
	cnt=0;
}

void add(int u,int v,int w){
	e[cnt].v=v;
	e[cnt].cap=w;
	e[cnt].flow=0;
	e[cnt].nxt=head[u];
	head[u]=cnt++;
}

void adde(int u,int v,int w){
	add(u,v,w);
	add(v,u,0);
}

void set_h(int t){
	memset(h,-1,sizeof(h));
	memset(g,0,sizeof(g));
	queue<int> q;
	q.push(t);
	h[t]=0;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		g[h[u]]++;
		for(int i = head[u];~i;i=e[i].nxt){
			int v = e[i].v;
			if(h[v]==-1){
				h[v]=h[u]+1;
				q.push(v);
			}
		}
	}
}

int ISAP(int s,int t,int n){
	set_h(t);
	int d,u=s,ans=0;
	while(h[s]<n){
		if(u==s)d=inf;
		int i = head[u];
		for(;~i;i=e[i].nxt){
			int v = e[i].v;
			if(e[i].cap>e[i].flow&&h[u]==h[v]+1){
				u = v;
				pre[v]=i;
				d=min(d,e[i].cap-e[i].flow);
				if(u==t){
					while(u!=s){
						int j = pre[u];
						e[j].flow+=d;
						e[j^1].flow-=d;
						u = e[j^1].v;
					}
					ans+=d;
					d=inf;
				}
				break;
			}
		}
		if(i==-1){
			if(--g[h[u]]==0)break;
			int hmin = n-1;
			for(int j = head[u];~j;j=e[j].nxt)
				if(e[j].cap>e[j].flow)hmin=min(hmin,h[e[j].v]);
			h[u]=hmin+1;
			g[h[u]]++;
			if(u!=s)u=e[pre[u]^1].v;
		}
	}
	return ans;
}

void dfs(int u){
	for(int i = head[u];~i;i=e[i].nxt){
		int v = e[i].v;
		if(!vis[v]&&e[i].cap>e[i].flow){
			vis[v]=1;
			dfs(v);
		}
	}
}

int main(){
	int T,n,m,f,u,v,w;
	cin>>T;
	for(int cas = 1;cas<=T;cas++){
		cin>>n>>m>>f;
		int s=1,t=n+1;
		init();
		int tot=0;
		for(int i = 1;i<=m;i++){
			cin>>u>>v>>w;
			adde(u,v,w);
		}
		for(int i = 1;i<=f;i++){
			cin>>u>>w;
			tot+=w;
			adde(u,t,w);
		}
		printf("Case %d: %d\n",cas,tot-ISAP(s,t,t));
		memset(vis,0,sizeof(vis));
		vis[s]=1;
		dfs(s);
		tot=0;
		for(int i = 0;i<2*m;i+=2){
			int u = e[i^1].v,v=e[i].v;
			if(vis[u]&&!vis[v])ans[tot++]=i/2;
		}
		cout<<tot;
		for(int i=0;i<tot;i++)
			printf(" %d",ans[i]+1);
        printf("\n");
	}
	return 0;
}
