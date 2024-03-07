#include<bits/stdc++.h>

using namespace std;

int n,m,ans = 0;
int dp[1505][1505][2];

int main(){
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		for(int j = 1,a;j<=m;j++){
			scanf("%d",&a);
			dp[i][j][1-a]=0;
			dp[i][j][a]=min(dp[i-1][j-1][a],min(dp[i][j-1][1-a],dp[i-1][j][1-a]))+1;
			ans=max(ans,dp[i][j][a]);				
		}
		
	}
	cout<<ans<<endl;
	return 0;
}
