#include<iostream>
using namespace std;

#define INF 0x3f3f3f3f 

long long n;
long long s[1500],b[1500];
long long vis[1500];
long long ans = INF;

void dfs(long long k,long long S,long long B){
	if(k==n){
		if(S==1&&B==0)return;
		ans=min(ans,abs(S-B));
		return;
	}
	dfs(k+1,S*s[k],B+b[k]);
	dfs(k+1,S,B);
}

int main(){
	cin>>n;
	s[0]=1;
	for(long long i = 0;i<n;i++)cin>>s[i]>>b[i];
	dfs(0,1,0);
	cout<<ans<<endl;
	return 0;
}
