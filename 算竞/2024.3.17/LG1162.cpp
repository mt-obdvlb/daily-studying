#include<iostream>

using namespace std;

int n;

int board[50][50];
int vis[50][50];
int dir[4][2]={0,1,0,-1,
				1,0,-1,0};

//2环 1暂定 3非环 

int dfs(int x,int y){
	if(vis[x][y]==2)return 2;
	if(vis[x][y]==1)return 1;
	if(vis[x][y]==3)return 3;
	if(board[x][y]==1){
		vis[x][y]=1;
		return 1;
	}
	if(board[x][y]==-1){
		vis[x][y]==3;
		return 3;
	}
	for(int i = 0;i<4;i++){
		int nxtx = x+dir[i][0],nxty =y+dir[i][1];
		int t = dfs(nxtx,nxty);	
		if(t==3){
			vis[x][y]=3;
			return 3;
		} 
		if(t==2){
			vis[x][y]=2;
			return 2;
		}
	}
}

int main(){
	cin>>n;
	for(int i = 0;i<50;i++){
		for(int j =0;j<50;j++)board[i][j]=-1;
	}
	for(int i =1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			cin>>board[i][j];
		}
	}
	for(int i =1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			if(board[i][j]==1)continue;
			if(vis[i][j]==2||vis[i][j]==3)continue;
			int x = dfs(i,j);
			if(x==3){
				vis[i][j]=3;
				
			} 
			if(x==2){
				vis[i][j]=2;
				
			}
		}
	}
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			if(j!=1)cout<<" ";
			if(vis[i][j]==2)board[i][j]=2;
			cout<<board[i][j];
		}
		cout<<endl;
	}
	
	return 0;
}
