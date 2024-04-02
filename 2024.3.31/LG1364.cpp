#include<bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

int n,w,u,v;
int g[105][105],val[105];

int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			g[i][j]=1000000;
		}
	}
	for(int i = 1;i<=n;i++){
		cin>>w>>u>>v;
		g[i][i]=0;
		g[i][u]=g[i][v]=1;
		g[u][i]=g[v][i]=1;
		val[i]=w;
	}
	for(int v = 1;v<=n;v++){
		for(int i = 1;i<=n;i++){
			if(i==v)continue;
			for(int j = 1;j<=n;j++){
				if(i==j||j==v)continue;
				if(g[i][j]>g[i][v]+g[v][j])g[i][j]=g[i][v]+g[v][j];
			}
		}
	}
	int ans = INT32_MAX;
	for(int i = 1;i<=n;i++){
		int t = 0;
		for(int j=1;j<=n;j++){
			t+=g[i][j]*val[j];
		}	
		if(ans>t)ans = t;
	}
	cout<<ans<<endl;
	return 0;
}
