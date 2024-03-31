#include<iostream>
#include<queue>
using namespace std;

int dir[8][2]={2,1,2,-1,-2,1,-2,-1,
				1,2,1,-2,-1,2,-1,-2};

typedef pair<int,int> PII;

int main(){
	int t;
	cin>>t;
	while(t--){
		int len,sx,sy,ex,ey;
		scanf("%d%d%d%d%d",&len,&sx,&sy,&ex,&ey);
		int step = 0;
		int vis[305][305]={0};
		queue<PII> q;
		q.push(PII(sx,sy));
		vis[sx][sy]=1;
		int flag = 1;
		while(!q.empty()&&flag){
			int m = q.size();
			while(m--){
				int x = q.front().first,y=q.front().second;
				if(x==ex&&y==ey){
						cout<<step<<endl;
						flag = 0;
					}
				q.pop();
				for(int i = 0;flag&&i<8;i++){
					int nxtx = x+dir[i][0],nxty = y+dir[i][1];
					if(nxtx<0||nxty<0||nxtx>=len||nxty>=len)continue;
					if(vis[nxtx][nxty])continue;
					vis[nxtx][nxty]=1;
					q.push(PII(nxtx,nxty));
					if(nxtx==ex&&nxty==ey){
						cout<<step+1<<endl;
						flag = 0;
					}
				}
			}
			
			step++;
		}
	}
	
	return 0;
}
