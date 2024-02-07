#include<bits/stdc++.h>

using namespace std;

#define N 200005

int n,ans=0;
int sum[N]={0};
int dp[N];

int main(){
	scanf("%d",&n);
	for(int i = 1;i<=n;i++){
		scanf("%d",sum+i);
		sum[i]+=sum[i-1];
	}
	deque<int> d;
	dp[0]=INT32_MIN;
	d.push_back(0);
	for(int i = 1;i<=n;i++){
		dp[i] = max(dp[i-1],sum[i]-sum[d.front()]);
		while(!d.empty()&&sum[d.back()]>=sum[i])d.pop_back();
		d.push_back(i);
	}
	cout<<dp[n]<<endl;
	return 0;
}
