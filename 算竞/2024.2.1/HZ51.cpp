#include<bits/stdc++.h>

using namespace std;

int n,m;
int dp[1005][1005];
int f[1005][1005];

int main(){
	scanf("%d%d",&n,&m);
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			scanf("%d",&f[i][j]);
		}
	}
	for(int j = 1;j<=m;j++){
		for(int i = n-1;i>=1;i--){
			if(f[i][j]==0)continue;
			f[i][j]+=f[i+1][j];
		}
	}
	int ans = 0;
	for(int i = 1;i<=n;i++){
		for(int j = m;j>=1;j--){
			int k = j;
			while(k<=m&&f[i][k]>=f[i][j])k++;
			dp[i][j]=f[i][j]*(k-j)+dp[i][k];
			dp[i][j]%=100007;
			ans +=dp[i][j];
			ans%=100007;
		}
	}
	printf("%d",ans);
	return 0;
}
