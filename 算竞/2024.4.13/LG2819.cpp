#include<bits/stdc++.h>

using namespace std;

int n,k,m,ans=0;
int col[105];
vector<int> g[105];

void dfs(int x){
	if(x>n){
		ans++;
		return;
	}
	for(int i = 1;i<=m;i++){
		col[x] = i;
		int flag = 1;
		for(int j = 0;flag&&j<g[x].size();j++){
			int v = g[x][j];
			if(col[v]==col[x])flag=0;
		}
		if(flag)dfs(x+1);
	}
	col[x]=0;
}


int main(){
	cin>>n>>k>>m;
	while(k--){
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1);
	cout<<ans<<endl;
	return 0;
}
