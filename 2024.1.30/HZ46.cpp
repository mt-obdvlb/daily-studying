#include<iostream>
#include<cstring>

using namespace std;

char s[1005];
int dp[1005][1005]={0};

int main(){
	scanf("%s",s+1);
	int n = strlen(s+1);
	for(int l = 1;l<=n;l++){
		for(int i = 1;i<=n-l+1;i++){
			int j = i+l-1;
			if(s[i]==s[j]&&dp[i+1][j-1]==0)dp[i][j]=0;
			else{
				dp[i][j] = l;
				for(int k =i;k<j;k++){
					dp[i][j] = min(dp[i][j],dp[i][k]+dp[k+1][j]+1);
				}
			}
		}
	}
	cout<<dp[1][n];
	return 0;
}
