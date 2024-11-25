#include<bits/stdc++.h>

using namespace std;
const int N =220;
int n,m,k,g[N][N],vis[N],match[N];

bool dfs(int x){
	for(int i = n;i<n+m;i++){
		if(!vis[i]&&g[x][i]){
			vis[i]=1;
			if(!match[i]||dfs(match[i])){
				match[i]=x;
				return 1;
			}
		}
	}
	return 0;
}


int main(){
	int a,x,y;
	while(cin>>n>>m>>k&&n){
		memset(match,0,sizeof(match));
		memset(g,0,sizeof(g));
		for(int i = 0;i<k;i++){
			cin>>a>>x>>y;
			if(x*y!=0)g[x][y+n]=1;
		}
		int ans = 0;
		for(int i = 0;i<n;i++){
			memset(vis,0,sizeof(vis));
			if(dfs(i))ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
