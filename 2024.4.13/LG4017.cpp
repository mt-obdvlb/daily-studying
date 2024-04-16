#include<bits/stdc++.h>

using namespace std;

const long long mod = 80112002;
long long n,m,head[5005],indeg[5005],outdeg[5005],cnt,ans,dp[5005];
struct edges{
	long long nxt,to;
}e[500005];

void dfs(long long x){
	if(dp[x])return;
	for(long long i = head[x];i;i = e[i].nxt){
		long long j = e[i].to;
		dfs(j);
		dp[x] = (dp[x]+dp[j])%mod;
	}
}

void add(long long u,long long v){
	e[++cnt].to = v;
	e[cnt].nxt = head[u];
	head[u] = cnt;
}

int main(){
	cin>>n>>m;
	while(m--){
		long long u,v;
		scanf("%lld%lld",&u,&v);
		add(u,v);
		indeg[v]++;
		outdeg[u]++;
	}
	for(long long i = 1;i<=n;i++){
		if(!outdeg[i])dp[i]=1;
	}
	for(long long i = 1;i<=n;i++){
		if(!indeg[i])dfs(i);
	}
	
	for(long long i = 1;i<=n;i++){
		if(!indeg[i]){
			ans = (ans+dp[i])%mod;
		}
	}
	cout<<ans<<endl;
	return 0;
}
