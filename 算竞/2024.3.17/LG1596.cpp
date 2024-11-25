#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

int n,m;
char board[205][205];

int dir[8][2]={0,1,1,0,0,-1,-1,0,
				1,1,1,-1,-1,1,-1,-1};
int vis[205][205];

void dfs(int i,int j){
	//if(vis[i][j])return;
	board[i][j]='.';
	//vis[i][j]=1;
	for(int k = 0;k<8;k++){
		int nxti = i+dir[k][0],nxtj = j+dir[k][1];
		if(board[nxti][nxtj]=='.')continue;
		dfs(nxti,nxtj);
	}
}

int main(){
	for(int i = 0;i<205;i++){
		for(int j =0 ;j<205;j++)board[i][j]='.';
	}
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		string s;
		cin>>s;
		for(int j = 1;j<=m;j++){
			board[i][j]=s[j-1];
		} 
	}

	int cnt = 0;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			if(vis[i][j])continue;
			if(board[i][j]=='.')continue;
			cnt++;
			dfs(i,j);
		}
		
	}
	
	cout<<cnt<<endl;
	return 0;
}
