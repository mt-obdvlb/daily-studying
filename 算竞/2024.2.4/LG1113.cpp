#include<bits/stdc++.h>

using namespace std;

int n,ans=0;
int dp[10005];

int main(){
	cin>>n;
	for(int i = 1,t,j;i<=n;i++){
		cin>>t>>t;
		dp[i]=t;
		while(cin>>j){
			if(j==0)break;
			dp[i]=max(dp[i],dp[j]+t);
		}
		ans=max(ans,dp[i]);
	}
	cout<<ans<<endl;
	return 0;
}
