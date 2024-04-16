#include<bits/stdc++.h>

using namespace std;
int n,m;
int dp[3500][505];

int main(){
	cin>>n>>m;
	for(int w,d,i = 1;i<=n;i++){
		cin>>w>>d;
		for(int j = 1;j<=m;j++){
			dp[i][j] = dp[i-1][j];
			if(j-w<0)continue;
			dp[i][j] = max(dp[i][j],dp[i-1][j-w]+d);
		}
	}
	
	cout<<dp[n][m]<<endl;
	return 0;
}
