#include<bits/stdc++.h>

using namespace std;
const int inf =0x3f3f3f3f;
const int N = 105;
const int M = 10005;
int cnt,head[N],pre[N],dis[N],vis[N],maxflow,mincost;
struct Edegs{
	int cap,flow,nxt,v,cost;
}e[M<<1];

void add(int u,int v,int w,int c){
	e[cnt].cost = c;
	e[cnt].v = v;
	e[cnt].flow = 0;
	e[cnt].cap = w;
	e[cnt].nxt = head[u];
	head[u] = cnt++;
}

void init(){
	memset(head,-1,sizeof(head));	
	cnt = 0;
}

void adde(int u,int v,int w,int c){
	add(u,v,w,c);
	add(v,u,0,-c);
}

bool SPFA(int s,int t){
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
		for(int i  = head[u];~i;i=e[i].nxt){
			int v = e[i].v;
			if(e[i].cap>e[i].flow&&dis[v]>dis[u]+e[i].cost){
				dis[v] = dis[u]+e[i].cost;
				pre[v] = i;
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
	int d;
	while(SPFA(s,t)){
		d = inf;
		for(int i = pre[t];~i;i = pre[e[i^1].v]){
			d = min(d,e[i].cap-e[i].flow);
		}
		maxflow+=d;
		for(int i = pre[t];~i;i = pre[e[i^1].v]){
			e[i].flow+=d;
			e[i^1].flow-=d;
		}
		mincost+=dis[t]*d;
	}
	return maxflow;
}

map<string,int> simp;
map<int,string> ismp;

void print(int s,int t){
	int v;
	vis[s] = 1;
	for(int  i= head[s];~i;i=e[i].nxt){
		if(!vis[v=e[i].v]&&((e[i].flow>0&&e[i].cost<=0)||(e[i].flow<0&&e[i].cost>=0))){
			print(v,t);
			if(v<=t)cout<<ismp[v]<<endl;
		}
	}
}

int main(){
	int n,v,s,t;
	cin>>n>>v;
	init();
	string a,b;
	for(int i = 1;i<=n;i++){
		cin>>a;
		simp[a] = i;
		ismp[i] = a;
		if(i==1||i==n){
			adde(i,i+n,2,0);
		}else{
			adde(i,i+n,1,0);
		}
	}
	for(int i = 1;i<=v;i++){
		cin>>a>>b;
		int aa = simp[a],bb=simp[b];
		if(aa>bb)swap(aa,bb);
		if(aa==1&&bb==n)adde(aa+n,bb,2,-1);
		else adde(aa+n,bb,1,-1);
	}
	if(MCMF(1,2*n)==2){
		cout<<-mincost<<endl;
		cout<<ismp[1]<<endl;
		memset(vis,0,sizeof(vis));
		print(1,n);
		cout<<ismp[1]<<endl;
	}else cout<<"No Solution!"<<endl;
	return 0;
}
