#include<bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;
const int maxn=1005,maxe=1000001;
const int inf=0x3f3f3f3f;
int T,n,m,cnt;
int head[maxn],dis[maxn];
bool vis[maxn];//标记是否已访问 
struct node{
	int to,next,w;
}e[maxe];


typedef pair<int,int> PII;

void add(int u,int v,int w){
	e[++cnt].to = v;
	e[cnt].next = head[u];
	e[cnt].w = w;
	head[u] = cnt;
}



int main(){
	cin>>T;
	for(int i = 1;i<=T;i++){
		cin>>n>>m;
		int u,v,w;
		for(int i = 0;i<m;i++){
			cin>>u>>v>>w;
			add(u,v,w);
			add(v,u,w);
		}
		priority_queue<PII>q;
		dis[1] = INF;
		vis[1] = 1;
		q.push(PII(dis[1],1));
		while(!q.empty()){
			u = q.top().second;
			q.pop();
			for(int i = head[u];i;i=e[i].next){
				v = e[i].to;
				if(vis[v])continue;
				vis[v] = 1;
				if(dis[v]<min(dis[u],e[i].w)){
					dis[v] = min(dis[u],e[i].w);
					q.push(PII(dis[v],v));
				}
			}
		}
		printf("Scenario #%d:\n",i);
		cout<<dis[n]<<endl;
	}
	return 0;
}
