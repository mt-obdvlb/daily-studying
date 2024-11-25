#include<iostream>
#include<algorithm>

using namespace std;

const int N = 1e3+5;

int dp[N], v[N], w[N];
int T, n, V;

int main(){
	cin>>T;
	while(T--){
		memset(dp, 0, sizeof(dp));
		cin>>n>>V;
		for(int i = 1; i <= n; i++)
			cin>>w[i];
		for(int i = 1; i <= n; i++)
			cin>>v[i];
		for(int i = 1; i <= n; i++){
			for(int j = V; j >= v[i]; j--){
				dp[j] = max(dp[j - v[i]] + w[i], dp[j]);
			}
		}			
		cout<<dp[V]<<endl;
	}
	return 0; 
}
