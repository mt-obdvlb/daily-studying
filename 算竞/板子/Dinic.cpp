#include<bits/stdc++.h>

using namespace std;

const int inf = 0x3f3f3f3f;
const int N = 1e4;
const int M = 1e5;
int n,cnt,head[N],d[N],cur[N];
struct Edges{
	int v,nxt,cap,flow;
}e[M<<1];

void _add(int u,int v,int w){
	e[cnt].cap=w;
	e[cnt].v=v;
	e[cnt].flow=0;
	e[cnt].nxt = head[u];
	head[u] = cnt++;
}

void add(int u,int v,int w){
	_add(u,v,w);
	_add(v,u,0);
}

bool bfs(int s,int t){
	memset(d,0,sizeof(d));
	queue<int> q;
	q.push(s);
	d[s]=1;
	while(!q.empty()){
		int u = q.front();q.pop();
		for(int i = head[u];~i;i = e[i].nxt){
			int v = e[i].v;
			if(d[v])continue;
			if(e[i].cap>e[i].flow){
				d[v] = d[u] + 1;
				q.push(v);
				if(v==t)return 1;
			}
		}
	}
	return 0;
}

int dfs(int u,int flow,int t){
	if(u==t)return flow;
	int rest = flow;
	for(int &i = cur[u];~i;i = e[i].nxt){
		int v = e[i].v;
		if(d[v]==d[u]+1&&e[i].cap>e[i].flow){
			int k = dfs(v,min(rest,e[i].cap-e[i].flow),t);
			if(!k)d[v]=0;
			e[i].flow+=k;
			e[i^1].flow-=k;
			rest-=k;
			if(!rest)break;
		}
	}
	return flow-rest;
}

int Dinic(int s,int t){
	int maxflow = 0;
	while(bfs(s,t)){
		for(int i = 0;i<n+2;i++)cur[i]=head[i];
		maxflow+=dfs(s,inf,t);
	}
	return maxflow;
}

int main(){
	
	return 0;
}
