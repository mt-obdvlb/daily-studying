#include<iostream>
#include<string>



using namespace std;

char ans[105][105] = {0};
char g[105][105] = {0};
int vis[105][105] = {0};
int dir[8][2] ={
	{1,0},{-1,0},{0,1},{0,-1},
	{1,1},{1,-1},{-1,1},{-1,-1}};
char match[8] = "yizhong";

void get_ans(int x,int y){
	for(int i = 0;i<8;i++){
		int flag = 1;
		int dx = x;
		int dy = y;
		for(int j = 0;j<7;j++){
			if(g[dx][dy]!=match[j]){
				flag = 0;
				break;
			}
			dx += dir[i][0];
			dy += dir[i][1];
		}
		if(flag){
			dx = x;
			dy = y;
			for(int j  =0;j<7;j++){
				ans[dx][dy] = 1;
				dx += dir[i][0];
				dy += dir[i][1];
			}
		}
	}
}

void dfs(int x,int y){
	if(g[x][y] == '\0')return;
	if(g[x][y] == 'y'){
		get_ans(x,y);
	}
	if(vis[x][y])return;
	vis[x][y] = 1;
	dfs(x+1,y);
	dfs(x,y+1);
}

int main(){
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++){
		scanf("%s",g[i]+1);
	}
	dfs(1,1);
	for(int i =1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			if(ans[i][j]){
				cout<<g[i][j];
			}else{
				cout<<"*";
			}
		}
		cout<<endl;
	}
	return 0;
} 
