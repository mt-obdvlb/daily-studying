#include<iostream>

using namespace std;

#define MAX_N 7

int vis[MAX_N][MAX_N] = {0};
int cnt = 0;
int dir[4][2] = {{1,0},{0,-1},{-1,0},{0,1}};

void dfs(int x,int y,int n,int m,int fx,int fy){
	if(x == fx&&y == fy){
		cnt++;
		return;
	}
	vis[x][y] = 0;
	for(int i = 0;i<4;i++){
		int dx = x+dir[i][0];
		int dy = y+dir[i][1];
		if(vis[dx][dy] == 0){
			continue;
		} 
		dfs(dx,dy,n,m,fx,fy);
	}
	vis[x][y] = 1;
}


int main(){
	int n,m,t;
	cin>> n >> m >> t;
	int sx,sy,fx,fy;
	cin >> sx>>sy>>fx>>fy;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			vis[i][j] = 1;		
		}
	}
	for(int tx,ty,i = 0;i<t;i++){
		scanf("%d%d",&tx,&ty);
		vis[tx][ty] = 0;
	}
	dfs(sx,sy,n,m,fx,fy);
	cout<< cnt <<endl;
	return 0;
}
