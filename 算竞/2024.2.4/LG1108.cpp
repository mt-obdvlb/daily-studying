#include<bits/stdc++.h>

using namespace std;

int n;
int val[5005],dp[5005],f[5005];
int max_len = 0,cnt=0;

int main(){
	scanf("%d",&n);
	for(int i = 1;i<=n;i++){
		scanf("%d",val+i);
	}
	val[0]=INT32_MAX;
	f[0]=1;	
	for(int i = 1;i<=n;i++){
		for(int j = 0;j<i;j++){
			if(val[j]<=val[i])continue;
			dp[i]=max(dp[i],dp[j]+1);
		}	
		for(int j = 0;j<i;j++){
			if(val[j]<val[i])continue;
			if(val[j]>val[i]&&dp[i]==dp[j]+1)f[i]+=f[j];
			else if(val[j]==val[i]&&dp[i]==dp[j])f[j]=0;
		}
		max_len=max(max_len,dp[i]);
	}
	for(int i = 1;i<=n;i++){
		if(dp[i]==max_len)cnt+=f[i];
	}
	printf("%d %d",max_len,cnt);
	return 0;
}
