#include<bits/stdc++.h>
#include<cstdlib>
#include<cstdio>
using namespace std;

int n,m,cnt=0;

int ans[100005][2];
int d[10][2]={{0,0},{-1,0},{0,-1},{1,-1}
					,{-1,1},{-1,-1},{1,0}
					,{0,1},{1,1}};

bool dfs(int** board,int i,int j,int dir,int n,int m){
	if(board[i][j]==1)return true;
	if(dir==0){
		for(int ind = 1;ind<=8;ind++){
			if(i+d[ind][0]<1||i+d[ind][0]>n||j+d[ind][1]<1||j+d[ind][1]>m)continue;
			if(dfs(board,i+d[ind][0],j+d[ind][1],ind,n,m))return true;
		}
	}else{
		if(i<=0||j<=0)return false;
		if(board[i][j]==2)return false;
		if(i+d[dir][0]<1||i+d[dir][0]>n||j+d[dir][1]<1||j+d[dir][1]>m)return false;
		dfs(board,i+d[dir][0],j+d[dir][1],dir,n,m);
	}
}

int main(){
	cin>>n>>m;
	int** board = (int**)calloc(100005,sizeof(int*));
	board[0]=(int*)calloc(100005,sizeof(int));
	board[n+1]=(int*)calloc(100005,sizeof(int));
	for(int i = 1;i<=n;i++){
		board[i]=(int*)calloc(100005,sizeof(int));
		for(int j = 1;j<=m;j++){
			scanf("%d",&board[i][j]);
		}
	}
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			if(board[i][j]==2){
				if(dfs(board,i,j,0,n,m)){
					ans[cnt][0]=i;
					ans[cnt][1]=j;
					cnt++;
				}
			}
		}
	}
	printf("%d\n",cnt);
	for(int i = 0;i<cnt;i++){
		printf("%d %d\n",ans[i][0],ans[i][1]);
	}
	return 0;
} 
