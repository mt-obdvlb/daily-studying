#include<bits/stdc++.h>

using namespace std;

const int inf = 0x3f3f3f3f;
const int N = 1e4;
const int M = 1e5;
int n,cnt,head[N],pre[N],h[N],g[N];
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

void set_h(int t,int n){
	memset(h,-1,sizeof(h));
	memset(g,0,sizeof(g));
	queue<int> q;
	q.push(t);
	h[t]=0;
	while(!q.empty()){
		int u = q.front();q.pop();
		g[h[u]]++;
		for(int i = head[u];~i;i = e[i].nxt){
			int v = e[i].v;
			if(h[v]==-1){
				h[v] = h[u]+1;
				q.push(v);
			}
		}
	}
}

int ISAP(int s,int t){
	set_h(t,n);
	int i,d,u=s,maxflow=0;
	while(h[s]<n){
		if(u==s)d = inf;
		for(i = head[u];~i;i = e[i].nxt){
			int v = e[i].v;
			if(h[u]==h[v]+1&&e[i].cap>e[i].flow){
				u = v;
				pre[v] = i;
				d = min(d,e[i].cap-e[i].flow);
				if(u==t){
					while(u!=s){
						int j = pre[u];
						e[j].flow+=d;
						e[j^1].flow-=d;
						u = e[j^1].v;
					}
					maxflow+=d;
					d=inf;
				}
				break;
			}
		}
		if(i==-1){
			if(--g[h[u]]==0)break;
			int hmin = n-1;
			for(int j = head[u];~j;j = e[j].nxt)
				if(e[j].cap>e[j].flow)hmin = min(hmin,e[j].v);
			g[h[u]=hmin+1]++;
			if(u!=s)u = e[pre[u]^1].v;
		}
		
	}
	return maxflow;
}


int main(){
	
	
	return 0;
}
