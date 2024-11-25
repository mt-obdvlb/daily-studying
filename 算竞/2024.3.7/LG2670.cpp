#include<iostream>

using namespace std;

int n,m;
int board[105][105]={0};
int ans[105][105]={0};
int dir[8][2]={0,1,1,0,0,-1,-1,0,
				1,1,1,-1,-1,1,-1,-1};

int main(){
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		string s;
		cin>>s;
		for(int j = 1;j<=m;j++){
			board[i][j]=(s[j-1]=='*'?1:0);
		}
	}
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			for(int k = 0;k<8;k++){
				ans[i][j]+=board[i+dir[k][0]][j+dir[k][1]];
			}
		}
	}
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			if(board[i][j]==1)printf("*");
			else printf("%d",ans[i][j]);
		}
		printf("\n");
	}
	return 0;
}
