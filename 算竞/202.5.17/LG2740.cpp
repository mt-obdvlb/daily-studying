#include<bits/stdc++.h>

using namespace std;
const int inf = 1e7+10;
const int N = 205;
int n,cnt,m,head[N],pre[N],vis[N];
struct Edegs{
	int to,nxt,cap,flow;
}e[N<<1];

void add(int u,int v,int w){
	e[cnt].to = v;
	e[cnt].cap = w;
	e[cnt].flow = 0;
	e[cnt].nxt = head[u];
	head[u]=cnt++;
}

int bfs(int s,int t){
	queue<int> q;
	memset(vis,0,sizeof(vis));
	memset(pre,-1,sizeof(pre));
	vis[s]=1;
	q.push(s);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int i = head[u];~i;i = e[i].nxt){
			int v = e[i].to;
			if(vis[v])continue;
			if(e[i].cap>e[i].flow){
				vis[v]=1;
				pre[v] = i;
				q.push(v);
				if(v==t)return 1;
			}
		}
	}
	return 0;
}

int EK(int s,int t){
	int maxflow = 0;
	while(bfs(s,t)){
		int v = t,d=inf;
		while(v!=s){
			int i = pre[v];
			d = min(d,e[i].cap-e[i].flow);
			v = e[i^1].to;
		}
		maxflow+=d;
		v = t;
		while(v!=s){
			int i = pre[v];
			e[i].flow+=d;
			e[i^1].flow -=d;
			v = e[i^1].to;
		} 
	}
	return maxflow;
}

int main(){
	cin>>m>>n;
	int u,v,w;
	memset(head,-1,sizeof(head));
	while(m--){
		cin>>u>>v>>w;
		add(u,v,w);
		add(v,u,0);
	}
	cout<<EK(1,n)<<endl;
	return 0;
}
