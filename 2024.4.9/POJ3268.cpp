#include<bits/stdc++.h>

using namespace std;

int n,m,x;
int g[1005][1005],dis[1005];



int main(){
	cin>>n>>m>>x;
	int a,b,t;
	memset(g,0x3f3f3f3f,sizeof(g));
	while(m--){
		cin>>a>>b>>t;
		g[a][b] =t;
	}
	
	for(int k = 1;k<=n;k++){
		for(int i = 1;i<=n;i++){
			for(int j = 1;j<=n;j++){
				if(g[i][j]>g[i][k]+g[k][j]){
					g[i][j] = g[i][k]+g[k][j];
				}			
			}
		}
	}
	int ans = 0;
	for(int i = 1;i<=n;i++){
		ans = max(g[i][x]+g[x][i],ans);
	}
	cout<<ans<<endl;
	return 0;
}
