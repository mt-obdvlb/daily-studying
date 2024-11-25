#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int INF = 0x3f3f3f3f;
const int M = 1e4+5;

int dp[M], w[M], v[M];
int n,T,e,f,W;

int main(){
	cin>>T;
	while(T--){
		cin>>e>>f;
		W = f - e;
		cin>>n;
		for(int i=0;i<n;i++)
    		cin>>v[i]>>w[i];
    	memset(dp,0x3f,sizeof(dp));
    	for(int i = 0; i < M; i++)
			cout<<dp[i]<<" ";
		cout<<endl; 
    	dp[0]=0;
	    for(int i=0;i<n;i++)//计算dp[j]
	        for(int j=w[i];j<=W;j++)//比较此硬币放与不放是否能使得存钱罐内面值之和最小
	        	dp[j]=min(dp[j],dp[j-w[i]]+v[i]);
    	if(dp[W]<INF)
			cout<<"The minimum amount of money in the piggy-bank is "<<dp[W]<<"."<<endl;
		else
			cout<<"This is impossible."<<endl;
	}
	
	return 0;
}
