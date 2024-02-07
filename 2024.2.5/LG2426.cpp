#include<bits/stdc++.h>

using namespace std;

int n;
int arr[105];
int dp[105];

int main(){
	cin>>n;
	for(int i =1;i<=n;i++)cin>>arr[i];
	for(int i = 1;i<=n;i++){
		dp[i]=dp[i-1]+arr[i];
		for(int j = 0;j<i-1;j++){
			dp[i]=max(dp[i],dp[j]+abs(arr[i]-arr[j+1])*(i-j));
		}
	}
	cout<<dp[n]<<endl;
	return 0;
}
