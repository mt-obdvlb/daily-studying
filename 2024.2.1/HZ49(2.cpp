#include<bits/stdc++.h>


using namespace std;

int n,V;
int dp[105][100005];

int main(){
	scanf("%d%d",&V,&n);
	for(int w,v,s,i = 1;i<=n;i++){
		scanf("%d%d%d",&v,&w,&s);
		for(int r = 0;r<v;r++){
			deque<int> d;
			for(int j = r;j<=V;j+=v){
				dp[i-1][j]-=j/v*w ;
				while(!d.empty()&&dp[i-1][d.back()]<dp[i-1][j])d.pop_back();
				d.push_back(j);
				if((j-d.front())/v>s)d.pop_front();
				dp[i][j]=dp[i-1][d.front()]+j/v*w;
			}
		}
	}
	cout<<dp[n][V];
	return 0;
}
