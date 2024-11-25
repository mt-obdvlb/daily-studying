#include<bits/stdc++.h>


using namespace std;

int dp[100005]={0};

int main(){
	int V,n;
	cin>>V>>n;
	for(int v,w,s,i = 0;i<n;i++){
		cin>>v>>w>>s;
		for(int k=1;s;s-=k,k*=2){
			k = min(k,s);
			for(int j = V;j>=k*v;j--){
				dp[j] = max(dp[j],dp[j-k*v]+w*k);
			}
		}
	}
	cout<<dp[V]<<endl;
	return 0; 
}

