#include<iostream>

using namespace std;

int dp[1005];

int main(){
	int n;
	cin>>n;
	dp[1]=1;
	dp[2]=3;
	for(int i = 3,k=-1;i<=n;i++,k=-k){
		dp[i]=dp[i-1]*2+k;
		dp[i]%=12345;
	}
	cout<<dp[n]<<endl;
	return 0;
}
