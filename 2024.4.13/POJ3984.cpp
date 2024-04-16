#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> PII;
int dir[4][2]={1,0,0,1,-1,0,0,-1};
int board[10][10],vis[10][10];
PII pre[10][10];

void print(int x,int y){
	if(x==1&&y==1)return;
	print(pre[x][y].first,pre[x][y].second);
	printf("(%d, %d)\n",x-1,y-1);
}

int main(){
	int n = 5; 
	for(int i = 0;i<10;i++){
		for(int j = 0;j<10;j++)board[i][j] = 1;
	}
	for(int i =1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			cin>>board[i][j];
		}
	}
	queue<PII> q;
	int flag = 1;
	board[1][1] = 1;
	q.push(PII(1,1));
	while(!q.empty()&&flag){
		int m = q.size();
		while(flag&&m--){
			int x = q.front().first,y = q.front().second;
			q.pop();
			for(int k = 0;k<4;k++){
				int tx = x+dir[k][0],ty = y+dir[k][1];
				if(board[tx][ty])continue;
				board[tx][ty] = 1;
				pre[tx][ty].first = x,pre[tx][ty].second = y;
				q.push(PII(tx,ty));
				if(tx==5&&ty==5){
					flag = 0;
					break;
				}
			}
		}
	}
	printf("(%d, %d)\n",0,0);
	print(5,5);
	return 0;
}
