#include<bits/stdc++.h>

using namespace std;
const int N = 410;
const int M = 1010;
const int inf = 0x3f3f3f3f;
int cnt,head[N],dis[N],pre[N],vis[N],a[N],b[N],c[N];
struct Edges{
	int nxt,v,cap,flow,cost;
}e[M<<1];

void init(){
	memset(head,-1,sizeof(head));
	cnt =0;
}

void add(int u,int v,int w,int c){
	e[cnt].v = v;
	e[cnt].cap = w;
	e[cnt].flow = 0;
	e[cnt].cost = c;
	e[cnt].nxt = head[u];
	head[u] = cnt++;
}

void adde(int u,int v,int w,int c){
	add(u,v,w,c);
	add(v,u,0,-c);
}

bool SPFA(int s,int t){
	memset(pre,-1,sizeof(pre));
	memset(vis,0,sizeof(vis));
	memset(dis,inf,sizeof(dis));
	queue<int> q;
	q.push(s);
	dis[s] = 0;
	vis[s] = 1;
	while(!q.empty()){
		int u = q.front();q.pop();
		vis[u] = 0;
		for(int i = head[u];~i;i = e[i].nxt){
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
	return pre[t]!=-1; 
}

int MCMF(int s,int t){
	int d=0,maxflow=0,mincost=0;
	while(SPFA(s,t)){
		d = inf;
		for(int i = pre[t];~i;i = pre[e[i^1].v])d=min(d,e[i].cap-e[i].flow);
		for(int i = pre[t];~i;i=pre[e[i^1].v]){
			e[i].flow+=d;
			e[i^1].flow-=d;
		}
		maxflow+=d;
		mincost+=dis[t]*d;
	}
	return mincost;
}

int main(){
	int n,k,T,num[N];
	cin>>T;
	while(T--){
		init();
		cin>>n>>k;		
		int m = 0;
		for(int i = 0;i<n;i++){
			cin>>a[i]>>b[i]>>c[i];
			num[m++]=a[i];
			num[m++]=b[i];
		}
		sort(num,num+m);
		m = unique(num,num+m)-num;
		int s=0,t=m+1;
		for(int i = 0;i<=m;i++)adde(i,i+1,k,0);
		for(int i = 0;i<n;i++){
			int u = lower_bound(num,num+m,a[i])-num+1;
			int v = lower_bound(num,num+m,b[i])-num+1;
			adde(u,v,1,-c[i]);
		}
		cout<<-MCMF(s,t)<<endl;
	}
	return 0;
}
