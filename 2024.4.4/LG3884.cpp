#include<bits/stdc++.h>

using namespace std;

int n,u,v,x,y,w,d,rt,len = 0;;
int vis[105],dep[105],fa[105],indeg[105];

int main(){
	cin>>n;
	vector<int> g[105];
	
	for(int i = 1;i<n;i++){
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	cin>>x>>y;
	queue<int> q;
	q.push(1);
	vis[1] =1;
	while(!q.empty()){
		int m = q.size();
		w = max(w,m);
		while(m--){
			int cur = q.front();
			dep[cur] = d;
			q.pop();
			for(int i = 0;i<g[cur].size();i++){
				if(!vis[g[cur][i]]){
					fa[g[cur][i]]=cur;
					q.push(g[cur][i]);
					vis[g[cur][i]]=1;
				}
			}
		}
		d++;
	}
	memset(vis,0,sizeof(vis));
	int tx = dep[x],ty = dep[y];
	while(x!=1){
		vis[x] = 1;
		x = fa[x];
	}
	rt = 1;
	while(y!=1){
		if(vis[y]){
			rt = y;
			break;
		}
		vis[y] = 1;
		y = fa[y];
	}
	len=2*(tx-dep[rt])+ty-dep[rt];
	cout<<d<<endl<<w<<endl<<len<<endl;
	return 0;
}
