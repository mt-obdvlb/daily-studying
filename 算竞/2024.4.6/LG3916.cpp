#include<bits/stdc++.h>

using namespace std;

int n,m,u,v,d[100005];
vector<int> g[100005];


void dfs(int i,int dep){
	if(d[i])return;
	d[i] = dep;
	for(int j = 0;j<g[i].size();j++)dfs(g[i][j],dep);
}

int main(){
	cin>>n>>m;
	for(int i = 0;i<m;i++){
		scanf("%d%d",&u,&v); 
		g[v].push_back(u);
	}
	for(int i = n;i>0;i--)dfs(i,i);
	for(int i = 1;i<=n;i++)printf("%d ",d[i]);
	return 0;
}
