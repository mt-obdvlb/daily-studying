#include<bits/stdc++.h>

using namespace std;
const int inf=0x3f3f3f3f;
const int N=205;
const int M=40410;
int cnt;
int head[N],dist[N],pre[N];//dist[i]表示源点到点i最短距离，pre[i]记录前驱
bool vis[N];//标记数组
int G[N][N],q[N],num[N],shelter[N];
struct node{
	int x,y,p;
}a[N],b[N];

struct Edges{
	int v,nxt,cap,flow,cost;
}e[M<<1];

void init(){
	memset(head,-1,sizeof(head));
	cnt=0;
}

void add(int u,int v,int w,int c,int flow){
	e[cnt].v=v;
	e[cnt].cap = w;
	e[cnt].flow = flow;
	e[cnt].cost = c;
	e[cnt].nxt = head[u];
	head[u] = cnt++;
}

void adde(int u,int v,int w,int c,int flow = 0){
	add(u,v,w,c,flow);
	add(v,u,0,-c,flow);
}

int SPFA(int s,int t){
	memset(pre,-1,sizeof(pre));
	memset(vis,0,sizeof(vis));
	memset(dis,inf,sizeof(dis));
	queue<int>q;
	q.push(s);
	vis[s]=1;
	dis[s]=0;
	while(!q.empty()){
		int u = q.front();q.pop();
		vis[u]=0;
		for(int i = head[u];~i;i=e[i].nxt){
			int v = e[i].v;
			if(e[i].cap>e[i].flow&&dis[v]>dis[u]+e[i].cost){
				dis[v] = dis[u]+e[i].cost;
				pre[v]=i;
				if(!vis[v]){
					vis[v]=1;
					q.push(v);
				}
			}
		}
	}
	return pre[v]!=-1;
}

void MCMF(int s,int t){
	int d= 0;
	while(SPFA(s,t)){
		d=inf;
		for(int i = pre[t];~i;i=pre[e[i^1].v])d=min(d,e[i].cap-e[i].flow);
		for(int i = pre[t];~i;i=pre[e[i^1].v])e[i].flow+=d,e[i^1].flow-=d;
		maxflow+=d,mincost+=vis[t]*d;
	}
}

int getdis(int i,int j){
	return abs(a[i]-p[i])+abs(b[i]-q[j])+1;
}

int negative_loop(int s,int t){
	int f,r,top=-1;
	f=0,r=-1;
	memset(num,0,sizeof(num));
	memset(dis,0,sizeof(dis));
	memset(vis,1,sizeof(vis));
	memset(pre,-1,sizeof(pre));
	for(int i =s;i<=t;i++)q[++r]=i;
	while(f<=r){
		int  u = q[r--];
		vis[u]=0;
		for(int i = head[u];~i;i=e[i].nxt){
			int v = e[i].v;
			if(e[i].cap>e[i].flow&&dis[v]>dis[u]+e[i].cost){
				dis[v]=dis[u]+e[i].cost;
				pre[v]=i;
				if(!vis[v]){
					q[++r]=v;
					vis[v]=1;
					if(++num[v]>t+1)return v;
				}
			}
		}
	}
	return -1;
}

int main(){
	int n,m,s,t,tmp,a,b,;
	cin>>n>>m;
	s=0,t = n+m+1;
	for(int i = 1;i<=n;i++){
		cin>>x[i]>>y[i]>>num[i];			
		adde(s,i,0,num[i]);
	}
	for(int i = 1;i<=m;i++){
		cin>>p[i]>>q[i]>>ct[i];
	}
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			cin>>a;
			shelter[j]+=a;
			adde(i,j+n,inf,getdis(i,j),a);
		}
	}
	for(int j = 1;j<=m;j++)adde(j+n,t,ct[j],0,shelter[j]);
	int k = negative_loop(s,t);
	if(~k){
		printf("SUBOPTIMAL\n");
		memset(vis,0,sizeof(vis));
		memset(g,0,sizeof(g));
		for(int i = pre[k];!vis[e[i.v]];i=pre[e[i^1].v])vis[e[i].v]=1,k=e[i].v;
		
	}else printf("OPTIMAL\n");
	return 0;
}















