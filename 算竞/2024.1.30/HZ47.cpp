#include<iostream>



using namespace std;

int n,V;
int dp[10005]={0};

int main(){
	cin>>V>>n;
	for(int v,w,i = 1;i<=n;i++){
		cin>>v>>w;
		for(int j = V;j>=v;j--){
			dp[j] = max(dp[j],dp[j-v]+w);
		}
	}
	cout<<dp[V]<<endl;
	return 0;
}
