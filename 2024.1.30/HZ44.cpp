#include<iostream>


using namespace std;

int dp[100005] = {0};
int n,val[100005],ans = 0;


int main(){
	cin>>n;
	for(int i =1;i<=n;i++)scanf("%d",val+i);
	for(int i =1;i<=n;i++){
		for(int j = 0;j<i;j++){
			if(val[i]>val[j])dp[i] = max(dp[i],dp[j]+1);
		}
		ans = max(ans,dp[i]);
	}
	printf("%d",ans);
	return 0;
}
