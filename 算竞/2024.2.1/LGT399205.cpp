#include<bits/stdc++.h>

using namespace std;
#define N 200005
#define _INF 0x3f3f3f3f3f3f3f3f
#define INF 0x3f3f3f3f
int id,T;
long long dp[2][2][200005]={0};
int cnt[2][2][200005]={0};
long long ret[20000],C=0;

int main(){
	scanf("%d%d",&id,&T);
	while(T--){
		int n,K,t,p;
		long long a[2];
		scanf("%d%d%d%d%lld%lld",&n,&K,&t,&p,a,a+1);
		dp[1][0][0]=a[0];
		dp[1][1][0]=a[1];
		cnt[1][0][0]=cnt[1][1][0]=-INF;
		for(int i = 1;i<=K;i++){
			dp[1][0][i]=-_INF;
			dp[1][1][i]=-_INF;	
		}
		for(int i=2;i<=n;i++){
			scanf("%lld%lld",a,a+1);
			for(int j = 0;j<2;j++){
				for(int k=0;k<=K;k++){
					if(k>i-1){
						dp[i%2][j][k]=-_INF;
						cnt[i%2][j][k]=-INF;
						continue;
					}
					dp[i%2][j][k]=dp[(i-1)%2][j][k]+a[j];
					cnt[i%2][j][k]=cnt[(i-1)%2][j][k];
					if(k==0)continue;
					long long tmp = dp[(i-1)%2][(j+1)%2][k-1]+a[j];
					if(i-cnt[(i-1)%2][(j+1)%2][k-1]<=t)tmp+=p;
					if(tmp>dp[i%2][j][k]){
						dp[i%2][j][k]=tmp;
						cnt[i%2][j][k]=i;
					}
					
				}
			}
		}
		long long ans=-INF;
		for(int i =0;i<=K;i++){
			for(int j = 0;j<2;j++){
				ans=max(ans,dp[n%2][j][i]);
			}
		}
		ret[C++]=ans;
		
	}
	for(int i =0 ;i<C;i++){
		printf("%lld\n",ret[i]);
	}
	return 0;
}
