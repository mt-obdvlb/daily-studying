#include<bits/stdc++.h>

using namespace std;

int n,m,x,y,vis[100005];
vector<int> g[100005];

void dfs(int u){
	cout<<u<<" ";
	for(int i = 0;i<g[u].size();i++){
		int v = g[u][i];
		if(vis[v])continue;
		vis[v]=1;
		dfs(v);
	}
}

void bfs(int u){
	queue<int> q;
	q.push(u);
	while(!q.empty()){
		int sz = q.size();
		while(sz--){
			int cur = q.front();
			q.pop();
			cout<<cur<<" ";
			for(int i = 0;i<g[cur].size();i++){
				int v = g[cur][i];
				if(vis[v])continue;
				vis[v]=1;
				q.push(v);			
			}
		}
	}
}

int main(){
	cin>>n>>m;
	for(int i = 0;i<m;i++){
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
	}
	for(int i =1;i<=n;i++)sort(g[i].begin(),g[i].end());
	vis[1]=1;
	dfs(1);
	cout<<endl;
	memset(vis,0,sizeof(vis));
	vis[1]=1;
	bfs(1);
	return 0;
}
