#include<bits/stdc++.h>


using namespace std;

int n,M,R,maxP;
int t[105],rp[105],rm[105];
int dp[105][105];
int dpt[105][105];

int main(){
	scanf("%d",&n);
	for(int i = 1;i<=n;i++)scanf("%d%d%d",rm+i,rp+i,t+i);
	scanf("%d%d",&M,&R);
	for(int i = 1;i<=n;i++){
		int tm = rm[i],tr = rp[i];
		for(int j = M;j>=tm;j--){
			for(int k = R;k>=tr;k--){
				if(dp[j][k]<dp[j-tm][k-tr]+1){
					dp[j][k]=dp[j-tm][k-tr]+1;
					dpt[j][k]=dpt[j-tm][k-tr]+t[i];
				}else if(dp[j][k]==dp[j-tm][k-tr]+1){
					dpt[j][k]=min(dpt[j][k],dpt[j-tm][k-tr]+t[i]);
				}
			}
		}
	}
	cout<<dpt[M][R]<<endl;
	return 0;
}
