#include<iostream>

using namespace std;

long long n,m;
long long dp[35][1005];

int main(){
	cin>>n>>m;
	if(n==1){
		cout<<m<<endl;
		return 0;
	}
	for(int i = 1;i<=1000;i++)dp[1][i]=i;
	for(int i = 2;i<=n;i++){
		for(int j = 1;j<=1000;j++){
			dp[i][j] = dp[i-1][j-1]+dp[i][j-1]+1;
			if(dp[i][j]>m)break;
		}
	}
	int k = 1;
	while(dp[n][k]<m)k++;
	cout<<k<<endl;
	return 0;
}
