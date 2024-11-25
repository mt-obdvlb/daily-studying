#include<iostream>
#include<vector>
using namespace std;

vector<int> query[40005],query_id[40005];
int n,m;
int head[40005],dis[40005],cnt;
int fa[40005],ans[40005],vis[40005];
struct edges{
	int to,w,nxt;
}e[80005];

void add(int u,int v,int w){
	e[++cnt].w = w;
	e[cnt].to = v;
	e[cnt].nxt = head[u];
	head[u] = cnt;
}

int get(int x){
	return x==fa[x]?fa[x]:fa[x] = get(fa[x]);
}

void add_query(int x,int y,int id){
	query[x].push_back(y);
	query[y].push_back(x);
	query_id[x].push_back(id);
	query_id[y].push_back(id);
	
}

void tarjan(int u){
	vis[u] = 1;
	for(int i = head[u];i;i=e[i].nxt){
		int v = e[i].to,w = e[i].w;
		if(vis[v])continue;
		dis[v]= dis[u] +w;
		tarjan(v);
		fa[v] = u;
	}
	for(int i = 0;i<query[u].size();i++){
		int v = query[u][i];
		int id = query_id[u][i];
		if(vis[v]){
			int lca = get(v);
			ans[id] = dis[u] +dis[v]-2*dis[lca];
		}
	}
}

int main(){
	int T,u,v,w,x,y;
	cin>>T;
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i = 1;i<=n;i++){
			head[i] = vis[i] = dis[i] = 0;
			fa[i] = i;
			query[i].clear();
			query_id[i].clear();
		}
		for(int i = 1;i<n;i++){
			cin>>u>>v>>w;
			add(u,v,w);
			add(v,u,w);
		}
		for(int i = 1;i<=m;i++){
			cin>>x>>y;
			if(x==y)ans[i] = 0;
			else add_query(x,y,i);
		}
		tarjan(1);
		for(int i = 1;i<=m;i++)cout<<ans[i]<<endl;
	}	
	return 0;
}
