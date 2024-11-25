#include<iostream>

using namespace std;

int dp[50][4];

int main(){
	int n;
	cin>>n;
	dp[1][1]=dp[1][2]=dp[1][3]=1;
	dp[1][2]=0;
	for(int i = 2;i<=n;i++){
		dp[i][1]+=dp[i-1][3]+dp[i-1][2];
		dp[i][2]+=dp[i-1][1];
		dp[i][3]+=dp[i-1][1]+dp[i-1][2];
	}
	cout<<dp[n][1]+dp[n][3]<<endl; 
	return 0;
}
