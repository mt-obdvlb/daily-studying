#include<iostream>


using namespace std;

int n,m;
int val[355],cnt[4]={0};
int dp[45][45][45];

int main(){
	cin>>n>>m;
	for(int i = 0;i<n;i++){
		scanf("%d",val+i);
	}
	for(int a, i = 0;i<m;i++){
		scanf("%d",&a);
		cnt[a-1]++;
	}
	for(int a = 0;a<=cnt[0];a++){
		for(int b=0;b<=cnt[1];b++){
			for(int c=0;c<=cnt[2];c++){
				for(int d=0;d<=cnt[3];d++){
					int s = a+2*b+3*c+4*d;
					int ans =dp[b][c][d] ; 
					if(b)ans=max(ans,dp[b-1][c][d]);
					if(c)ans=max(ans,dp[b][c-1][d]);
					if(d)ans=max(ans,dp[b][c][d-1]);
					dp[b][c][d] = ans +val[s];
				}
			}
		}
	}
	cout<<dp[cnt[1]][cnt[2]][cnt[3]]<<endl;
	return 0;
}
