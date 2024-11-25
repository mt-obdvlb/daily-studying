#include<bits/stdc++.h>

using namespace std;

const int N = 205;
int dp[N][N], a[N][N];

int dfs(int l, int r){
	if(dp[l][r])return dp[l][r];
	dp[l][r] = a[l][r];
	for(int k = l + 1; k < r; k++){
		dp[l][r] = min(dp[l][r], dfs(l, k) + dfs(k, r));
	}
	return dp[l][r];
}

int main(){
	int n;
	cin>>n;
	for(int i = 1; i < n; i++){
		for(int j = i + 1; j <= n; j++){
			cin >> a[i][j];
		}
	}
	cout<<dfs(1, n)<<endl;
	return 0;
}
