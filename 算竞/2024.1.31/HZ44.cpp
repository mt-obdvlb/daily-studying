#include<bits/stdc++.h>

using namespace std;

#define N 1000005
int n,ans=0;
int dp[N],len[N];

int bsearch(int n,int x){
	int head = 0,tail = n,mid;
	while(head<tail){
		mid = (head+tail+1)>>1;
		if(len[mid]<x)head = mid;
		else tail = mid -1;
	}
	return head;
} 

int main(){
	cin>>n;
	len[0]=-1;
	for(int i = 0,a;i<n;i++){
		cin>>a;
		dp[i]=bsearch(ans,a)+1;
		len[dp[i]]=a;
		if(dp[i]>ans)ans=dp[i];
	}
	cout<<ans<<endl;
	return 0;
} 
