#include<bits/stdc++.h>

using namespace std;

int m,n,ans;
char g[105][105],vis[105][105];
int dir[8][2]={0,1,1,0,0,-1,-1,0,
				1,1,1,-1,-1,1,-1,-1};
string s;

void dfs(int x,int y){
	for(int k = 0;k<8;k++){
		int tx = x+dir[k][0],ty = y+dir[k][1];
		if(g[tx][ty]=='*')continue;
		if(vis[tx][ty])continue;
		vis[tx][ty] = 1;
		dfs(tx,ty);
	}
}

int main(){
	while(cin>>m>>n&&m&&n){
		memset(g,'*',sizeof(g));
		memset(vis,0,sizeof(vis));
		for(int i = 1;i<=m;i++){
			cin>>s;
			for(int j = 1;j<=n;j++){
				g[i][j]=s[j-1];
			}
		}
		ans = 0;
		for(int i = 1;i<=m;i++){
			for(int j = 1;j<=n;j++){
				if(vis[i][j])continue;
				if(g[i][j]=='*')continue;
				ans++;
				vis[i][j]=1;
				dfs(i,j);
			}
		}	
		cout<<ans<<endl;
	}
	return 0;
} 
