#include<iostream>
#include<queue>

#define MAX_N 405


using namespace std;

int dis[MAX_N][MAX_N];
int dir[8][2] = {{2,1},{2,-1},{-2,1},{-2,-1},
	{1,2},{1,-2},{-1,2},{-1,-2}};

struct Data{
	Data(int x,int y,int s):x(x),y(y),s(s){}
	int x,y,s;
};

void bfs(int n,int m,int x,int y){
	queue<Data> q;
	q.push(Data(x,y,0));
	dis[x][y] = 0; 
	while(!q.empty()){
		Data d = q.front();
		q.pop();
		for(int i = 0;i<8;i++){
			int tx = d.x + dir[i][0];
			int ty = d.y + dir[i][1];
			if(tx<1||tx>n){
				continue;
			}
			if(ty<1||ty>m){
				continue;
			}
			if(dis[tx][ty]!=-1){
				continue;
			}
			dis[tx][ty] = d.s+1;
			q.push(Data(tx,ty,d.s+1));
		}
	}
}


int main(){
	int n,m,x,y;
	cin >>n>>m>>x>>y;
	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			dis[i+1][j+1] = -1;
		}
	}
	bfs(n,m,x,y);
	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			if(j){
				printf(" ");
			}
			printf("%d",dis[i+1][j+1]);
		}
		printf("\n");
	}
	return 0;
}
