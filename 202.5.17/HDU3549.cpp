#include<bits/stdc++.h>

using namespace std;
const int inf = 0x3f3f3f3f;
const int N =25;
const int M = 1005;
int T,n,m,cnt,head[N],vis[N],pre[N];
struct Edges{
	int flow,v,nxt,cap;	
}e[M<<1];
int bfs(int s,int t){
	memset(pre,-1,sizeof(pre));
	memset(vis,0,sizeof(vis));
	queue<int> q;
	vis[s] = 1;
	q.push(s);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int i = head[u];~i;i = e[i].nxt){
			int v = e[i].v;
			if(vis[v])continue;
			if(e[i].cap>e[i].flow){
				vis[v] = 1;
				pre[v] = i;
				q.push(v);
				if(v==t)return 1;
			}
		}
	}
	return 0;
}

int EK(){
	int maxflow = 0,s = 1,t = n;
	while(bfs(1,n)){
		int v = t,d = inf;
		while(v!=s){
			int i = pre[v];
			d = min(d,e[i].cap-e[i].flow);
			v=e[i^1].v;
		}
		maxflow+=d;
		v=t;
		while(v!=s){
			int i = pre[v];
			e[i].flow+=d;
			e[i^1].flow-=d;
			v=e[i^1].v;
		}
	}	
	return maxflow;
}

void init(){
	memset(head,-1,sizeof(head));
	memset(vis,0,sizeof(vis)); 
	cnt=0;
}

void add(int u,int v,int w){
	e[cnt].v = v;
	e[cnt].cap = w;
	e[cnt].flow = 0;
	e[cnt].nxt = head[u];
	head[u]=cnt++;
}

int main(){
	cin>>T;
	int u,v,w;
	for(int tt = 1;tt<=T;tt++){
		scanf("%d%d",&n,&m);
		init();
		for(int i = 1;i<=m;i++){
			scanf("%d%d%d",&u,&v,&w);
			add(u,v,w);
			add(v,u,0);
		}
		printf("Case %d: %d\n",tt,EK());
	}
	return 0;
}
