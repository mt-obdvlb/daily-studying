#include<iostream>
#include<queue>;
using namespace std;

int vis[35][35];
int grid[35][35];

typedef pair<int,int> PII;
int dir[4][2]={0,1,1,0,0,-1,-1,0};

void bfs(int i,int j,int m,int n){
        queue<PII> q;
        q.push(PII(i,j));
        vis[i][j]=1;
        int cnt = 1;
        while(!q.empty()){
            int x = q.front().first,y=q.front().second;
            q.pop();
            //cout<<x<<" "<<y<<endl;
            if(x==0||y==0||x==m-1||y==n-1||vis[x][y]==2){
                for(int k = 0;k<4;k++){
                    int nxtx = x+dir[k][0],nxty = y+dir[k][1];
                    if(nxtx<0||nxty<0||nxtx>=m||nxty>=n)continue;
                    if(vis[nxtx][nxty]==2)continue;
                    if(grid[nxtx][nxty]==1)continue;
                    vis[nxtx][nxty]=2;
                    //cnt++;
                    q.push(PII(nxtx,nxty));
                }
            }else{
                for(int k = 0;k<4;k++){
                    int nxtx = x+dir[k][0],nxty = y+dir[k][1];
                    if(nxtx<0||nxty<0||nxtx>=m||nxty>=n)continue;
                    if(vis[nxtx][nxty])continue;
                    if(grid[nxtx][nxty]==1)continue;
                    vis[nxtx][nxty]=1;
                    cnt++;
                    q.push(PII(nxtx,nxty));
                }
            }
            
        }
    }

int main(){
	int n=0;
	cin>>n;
	for(int i= 0;i<n;i++){
		for(int j =0;j<n;j++)cin>>grid[i][j];
	}
	for(int i =1;i<n-1;i++){
		for(int j =1;j<n-1;j++){
			if(grid[i][j]==1)continue;
			if(vis[i][j])continue;
			bfs(i,j,n,n);
		}
	}
	for(int i= 0;i<n;i++){
		for(int j =0;j<n;j++){
			if(vis[i][j]==1)grid[i][j]=2; 
		}
	}
	for(int i= 0;i<n;i++){
		for(int j =0;j<n;j++){
			if(j)cout<<" ";
			cout<<grid[i][j];
		}
		cout<<endl;
	}
	return 0;
}
