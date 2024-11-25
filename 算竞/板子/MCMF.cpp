#include<bits/stdc++.h>

using namespace std;

const int inf = 0x3f3f3f3f;
const int N = 1e4;
const int M = 1e5;
int n,cnt,head[N],d[N],cur[N],vis[N],pre[N],dis[N];
struct Edges{
	int v,nxt,cap,flow,cost;
}e[M<<1];

void _add(int u,int v,int w,int c){
	e[cnt].cap=w;
	e[cnt].v=v;
	e[cnt].flow=0;
	e[cnt].cost = c;
	e[cnt].nxt = head[u];
	head[u] = cnt++;
}

void add(int u,int v,int w,int c){
	_add(u,v,w,c);
	_add(v,u,0,-c);
}

bool SPFA(int s,int t,int n){
	memset(vis,0,sizeof(vis));
	memset(pre,-1,sizeof(pre));
	memset(dis,inf,sizeof(dis));
	queue<int> q;
	q.push(s);
	dis[s]=0;
	vis[s]=1;
	while(!q.empty()){
		int u = q.front();q.pop();
		vis[u]=0;
		for(int i = head[u];~i;i = e[i].nxt){
			int v = e[i].v;
			if(e[i].cap>e[i].flow&&dis[v]>dis[u]+e[i].cost){
				dis[v] = dis[u] + e[i].cost;
				pre[v] = i;
				if(!vis[v]){
					q.push(v);
					vis[v]=1;
				}
			}
		}
	}
	return pre[t]!=-1;
}

int MCMF(int s,int t,int n){
	int maxflow = 0,mincost = 0;
	while(SPFA(s,t,n)){
		int d = inf;
		for(int i = pre[t];~i;i = pre[e[i^1].v])
			d = min(d,e[i].cap-e[i].flow);
		maxflow+=d;
		mincost+=d*dis[t];
		for(int i = pre[t];~i;i = pre[e[i^1].v]){
			e[i].flow+=d;
			e[i^1].flow-=d;
		}
	}
	return mincost;
}

int main(){
	
	
	return 0;
}
