#include<iostream>
#include<cctype>
#include<vector>
#include<queue>
using namespace std;

int n,m;
int vis[305][305];

typedef pair<int,int> PII;
int dir[4][2]={0,1,1,0,0,-1,-1,0};

char board[305][305];

int main(){
	cin>>n>>m;
	vector<PII> v[36];
	for(int i = 0;i<305;i++)fill(vis[i],vis[i]+305,1);
	int sx,sy,ex,ey;
	queue<PII> q;
	for(int i = 1;i<=n;i++){
		fill(vis[i]+1,vis[i]+m+1,0);
		string s;
		cin>>s;
		for(int j = 1;j<=m;j++){
			board[i][j]=s[j-1];
			if(board[i][j]=='@')sx=i,sy=j;
			if(board[i][j]=='#')vis[i][j]=1;
			if(board[i][j]=='=')ex=i,ey=j;			
			if(isalpha(board[i][j])){
				vis[i][j]=board[i][j]-'A'+10;
				v[board[i][j]-'A'+10].push_back(PII(i,j));
			}			
		}
	}
	q.push(PII(sx,sy));
	if(sx==ex&&sy==ey){
		cout<<0<<endl;
		return 0;
	}
	int step = 0;
	while(!q.empty()){
		int m = q.size();
		while(m--){
			int x = q.front().first,y = q.front().second;
			q.pop();
			for(int k = 0;k<4;k++){
				int nxtx = x+dir[k][0],nxty=y+dir[k][1];
				if(vis[nxtx][nxty]==1)continue;
				if(vis[nxtx][nxty]!=0){
					int ax=v[vis[nxtx][nxty]][0].first,ay=v[vis[nxtx][nxty]][0].second;
					int bx=v[vis[nxtx][nxty]][1].first,by=v[vis[nxtx][nxty]][1].second;
					if(ax==nxtx&&ay==nxty){
						q.push(PII(bx,by));
					}else{
						q.push(PII(ax,ay));
					}
				}else{
					q.push(PII(nxtx,nxty));
					if(nxtx==ex&&nxty==ey){
						cout<<step+1<<endl;
						return 0;
					}
				vis[nxtx][nxty]=1;
				}
			}
		}
		step++;
	}
	return 0;
}
