#include<bits/stdc++.h>
#include<cstring>

using namespace std;

int K,V,N;
int dp[5005][205];
int tmp[205];

int main(){
	cin>>K>>V>>N;
	dp[0][0]=1,dp[1][0]=0;
	for(int v,w,i = 0;i<N;i++){
		cin>>v>>w;
		for(int j = V;j>=v;j--){
			int p1 = 1,p2 = 1,t = 1;
			int n1 = dp[j][0],n2 = dp[j-v][0];
			while(p1<=n1||p2<=n2){
				if((p2>n2)||(p1<=n1&&dp[j][p1]>=dp[j-v][p2]+w)){
					tmp[t++]=dp[j][p1++];
				}else{
					tmp[t++]=dp[j-v][p2++]+w;
				}
				if(t>K)break;
			}
			tmp[0]=t-1;
			memcpy(dp[j],tmp,sizeof(int)*t);
		}
	}
	int ans = 0;
	for(int i = 1;i<=K;i++)ans+=dp[V][i];
	cout<<ans<<endl;
	return 0;
}
