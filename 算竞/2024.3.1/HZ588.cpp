#include<iostream>
#include<string>
using namespace std;

int n;
string dp[35];

int main(){
	cin>>n;
	dp[1]="1";
	dp[2]="11";
	dp[3]="21";
	for(int i = 4;i<=n;i++){
		char cnt[10]={0};
		for(int i = 0;i<10;i++)cnt[i]='0';
		cnt[dp[i-1][0]-'0']++;
		for(int j = 1;j<dp[i-1].size();j++){
			cnt[dp[i-1][j]-'0']++;
			if(dp[i-1][j-1]!=dp[i-1][j]){
				dp[i]+=cnt[dp[i-1][j-1]-'0'];
				dp[i]+=dp[i-1][j-1]; 
				cnt[dp[i-1][j-1]-'0']='0';
			}
			if(j==dp[i-1].size()-1){
				dp[i]+=cnt[dp[i-1][j]-'0'];
				dp[i]+=dp[i-1][j]; 
			}
		}
	}
	cout<<dp[n]<<endl;
	return 0;
}
