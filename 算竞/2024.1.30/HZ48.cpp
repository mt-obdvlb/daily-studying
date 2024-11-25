#include<iostream>


using namespace std;

int n,V;
int dp[10005]={0};

int main(){
	cin>>n>>V;
	for(int c,v,i = 1;i<=n;i++){
		cin>>c>>v;
		for(int j = c;j<=V;j++){
			dp[j] = max(dp[j],dp[j-c]+v);
		}
	}
	cout<<dp[V];
	return 0;
}
