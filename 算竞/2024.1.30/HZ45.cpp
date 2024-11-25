#include<iostream>
#include<cstring>


using namespace std;

char s1[1005],s2[1005];
int dp[1005][1005];

int main(){
	scanf("%s%s",s1+1,s2+1);
	int n = strlen(s1+1),m = strlen(s2+1);
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			if(s1[i]==s2[j])dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
		} 
	}
	cout<<dp[n][m];
}
