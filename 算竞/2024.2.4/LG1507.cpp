#include<bits/stdc++.h>

using namespace std;

int H,T,n;
int dp[405][405];

int main(){
	scanf("%d%d%d",&H,&T,&n);
	for(int h,t,k,i = 1;i<=n;i++){
		scanf("%d%d%d",&h,&t,&k);
		for(int j1 = H;j1>=h;j1--){
			for(int j2 = T;j2>=t;j2--){
				dp[j1][j2]=max(dp[j1][j2],dp[j1-h][j2-t]+k);
			}
		}
	}
	cout<<dp[H][T]<<endl;
	return 0;
} 
