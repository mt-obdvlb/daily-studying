#include<bits/stdc++.h>

using namespace std;

int n;
int dp[500005];
char s[500005];
vector<int> g[500005];

void extract(int i,int j){
	while(s[i]==s[j]){
		g[i].push_back(j-1);
		i++,j--;
	}
}

int main(){
	cin>>(s+1);
	int n = strlen(s+1);
	for(int i = 1;i<=n;i++){
		extract(i,i);
		extract(i,i+1);
	}
	dp[0]=-1;
	for(int i = 1;s[i];i++){
		dp[i]=i;
		for(auto x:g[i]){
			dp[i]=min(dp[i],dp[x]+1);
		}
	}
	cout<<dp[n]<<endl;
	return 0;
}
