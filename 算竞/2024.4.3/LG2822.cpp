#include<bits/stdc++.h>

using namespace std;

int t,k,n,m;
int dp[2005][2005],c[2005][2005];

int main(){
	cin>>t>>k;
	for(int i = 0;i<2005;i++){
		c[i][i]=c[i][0] = 1;
	}
	for(int i = 2;i<2005;i++){
		for(int j = 1;j<=i;j++){
			c[i][j] = (c[i-1][j-1]+c[i-1][j])%k;
		}
	}
	for(int i = 2;i<2005;i++){
		for(int j = 1;j<=i;j++){
			dp[i][j] = dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
			if(c[i][j]==0)dp[i][j]++;
		}
		dp[i][i+1] = dp[i][i];
	}
	while(t--){
		scanf("%d%d",&n,&m);
		if(m>n)m = n;
		printf("%d\n",dp[n][m]);
	}
	return 0;
}
