#include<bits/stdc++.h>

using namespace std;

int n,ans;
int dir[4][2]={1,1,1,-1,-1,1,-1,-1};
int vis[15],vis2[15][15];
int board[15][15];

bool check(int i,int j);

void dfs(int x){
	if(x>n){
		ans++;
		return;
	}
	for(int i = 1;i<=n;i++){
		if(vis[i])continue;
		if(check(x,i))continue;
		vis[i] = 1;
		board[x][i] = 1;
		dfs(x+1);
		board[x][i] = 0;
		vis[i] = 0;
	}
}

bool dfs2(int i,int j,int k){
	if(vis2[i][j])return false;
	if(board[i][j])return true;
	return dfs2(i+dir[k][0],j+dir[k][1],k);
}

bool check(int i,int j){
	for(int k = 0;k<4;k++){
		if(dfs2(i,j,k))return true;
	}
	return false;
}



int main(){
	while(cin>>n&&n){
		for(int i = 0;i<=15;i++){
			for(int j = 0;j<=15;j++)vis2[i][j]=1;
		}		
		for(int i = 1;i<=n;i++){
			for(int j = 1;j<=n;j++)vis2[i][j]=0;
		}
		ans = 0;
		dfs(1);
		
		cout<<ans<<endl;
	}
	return 0;
}
