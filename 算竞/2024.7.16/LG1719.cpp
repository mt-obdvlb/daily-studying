#include<bits/stdc++.h>

using namespace std;

const int inf = 0x3f3f3f3f;
const int N = 150;
int n,a[N][N];


int main(){
	cin>>n;
	int ans = -inf;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			scanf("%d",&a[i][j]);
			a[i][j]+=a[i-1][j];
		}
	}
	for(int i = 1;i<=n;i++){
		for(int k = 1;k<=i;k++){
			int dp[N]={0},f[N];
			for(int j = 1;j<=n;j++){
				f[j] = a[i][j]-a[i-k][j];
				dp[j] = max(dp[j-1]+f[j],f[j]);
				ans = max(ans,dp[j]);
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
