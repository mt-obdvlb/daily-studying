#include<bits/stdc++.h>


using namespace std;

int n,K;

struct Data{
	int x,y;
}arr[105];
int dp[105][105];

int main(){
	scanf("%d%d",&n,&K);
	K = n-K;
	for(int i = 1;i<=n;i++){
		cin>>arr[i].x>>arr[i].y;
	}
	sort(arr+1,arr+1+n,[&](const Data &a,const Data &b)->bool{
		return a.x<b.x;
	});
	memset(dp,0x3f,sizeof(dp));
	for(int i = 1;i<=n;i++){
		dp[i][0]=dp[i][1]=0;
		for(int k =2;k<=K;k++){
			for(int j = 1;j<i;j++){
				dp[i][k]=min(dp[i][k],dp[j][k-1]+abs(arr[i].y-arr[j].y));
			}
		}
	}
	int ans = INT32_MAX;
	for(int i = 1;i<=n;i++)ans = min(ans,dp[i][K]);
	cout<<ans<<endl;
	return 0;
}
