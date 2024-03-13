#include<iostream>
#include<cinttypes>
using namespace std;

int n,m;

int c[4][55];
int ans = INT32_MAX;
int vis[55][5]={0};

void dfs(int k,int co,int sum){
	if(vis[k][co]&&sum>vis[k][co])return;
	vis[k][co]=sum;
	if(k==n){
		if(co==3)ans=min(ans,sum+c[3][n]);
		return;
	}
	for(int i = co;i<=co+1&&i<=3;i++){
		dfs(k+1,i,sum+c[co][k]);
	}
}

int main(){
	cin>>n>>m;
	int dir[256]={0};
	dir['W']=1;
	dir['B']=2;
	dir['R']=3;
	for(int i = 1;i<=n;i++){
		string s;
		cin>>s;
		int t[4]={0};
		for(int k = 0;k<s.size();k++)t[dir[s[k]]]++;
		c[1][i]=m-t[1];
		c[2][i]=m-t[2];
		c[3][i]=m-t[3];
	}
	
	dfs(1,1,0);
	cout<<ans<<endl;
	return 0;
}
