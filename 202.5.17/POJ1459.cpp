#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 110;
const int M = 10100;
int n,m,cnt,head[N],d[N],cur[N];
struct Edges{
	int v,nxt,cap,flow;
}e[M<<1];

void init(){
	memset(head,-1,sizeof(head));
	cnt=0;
}

void add(int u,int v,int w){
	e[cnt].v = v;
	e[cnt].cap = w;
	e[cnt].flow = 0;
	e[cnt].nxt = head[u];
	head[u] = cnt++;
}

void adde(int u,int v,int w){
	add(u,v,w);
	add(v,u,0);
}

bool bfs(int s,int t){
	memset(d,0,sizeof(d));
	d[s]=1;
	queue<int> q;
	q.push(s);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int i = head[u];~i;i = e[i].nxt){
			int v = e[i].v;
			if(!d[v]&&e[i].cap>e[i].flow){
				d[v]=d[u]+1;
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
	int ret = 0;
	while(bfs(s,t)){
		for(int i = 0;i<=n+2;i++)cur[i]=head[i];
		ret+=dfs(s,inf,t);
	}
	return ret;
}

int main(){
	int np,nc,u,v,w;
	char ch;
    while(cin>>n>>np>>nc>>m){
        init();
        for(int i=1;i<=m;i++){
			cin>>ch>>u>>ch>>v>>ch>>w;
            adde(u,v,w);
        }
        for(int i=1;i<=np;i++){
			cin>>ch>>v>>ch>>w;
            adde(n+1,v,w);
        }
        for(int i=1;i<=nc;i++){
            cin>>ch>>u>>ch>>w;
            adde(u,n+2,w);
        }
        cout<<Dinic(n+1,n+2)<<endl;
    }
	return 0;
}
