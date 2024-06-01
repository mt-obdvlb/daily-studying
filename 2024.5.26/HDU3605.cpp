#include<bits/stdc++.h>

using namespace std;
const int N = 1e5+5;
int n,m;
int cap[12],cnt[12],g[N][12],match[12][N],vis[12];


bool dfs(int u){
	for(int i = 0;i<m;i++){
		if(g[u][i]&&!vis[i]){
			vis[i]=1;
			if(cnt[i]<cap[i]){
				match[i][cnt[i]++]=u;
				return 1;
			}
			for(int j = 0;j<cnt[i];j++){
				if(dfs(match[i][j])){
					match[i][j]=u;
					return 1;
				}
			}
		}
	}
	return 0;
}

int main(){
	while(cin>>n>>m){
		for(int i = 0;i<n;i++){
			for(int j = 0;j<m;j++){
				cin>>g[i][j];
			}
		}
		memset(cnt,0,sizeof(cnt));
		for(int i=0;i<m;i++)cin>>cap[i];
		bool flag = true;
		for(int i = 0;flag&&i<n;i++){
			memset(vis,0,sizeof(vis));
			if(!dfs(i))flag=0;
		}
		if(flag)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
