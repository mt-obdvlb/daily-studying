#include<bits/stdc++.h>

using namespace std;

int n,ans = 0;
string s[5005];
int dp[5005];

bool is_valid(int j,int i){
	if(s[j].size()>=s[i].size())return false;
	for(int k = 0;s[j][k];k++){
		if(s[j][k]-s[i][k])return false;
	}
	return true;
}

int main(){
	scanf("%d",&n);
	for(int i = 0;i<n;i++)cin>>s[i];
	for(int i = 0;i<n;i++){
		dp[i]=1;
		for(int j = 0;j<i;j++){
			if(is_valid(j,i))dp[i]=max(dp[i],dp[j]+1);		
		}
		ans =max(ans,dp[i]);
	}
	cout<<ans<<endl;
	return 0;
}
