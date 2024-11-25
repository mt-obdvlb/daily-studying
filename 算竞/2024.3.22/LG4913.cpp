#include<iostream>

using namespace std;

int n;
int l[100005],r[100005],d[1000005];
int vis[100005];

void dfs(int x){
	if(vis[x])return;
	vis[x]=1;
	if(x==0)return;
	if(l[x]==0&&r[x]==0)d[x]=1;
	if(l[x]!=0){
		dfs(l[x]);
		d[x]=max(d[x],d[l[x]]+1);
	}
	if(r[x]!=0){
		dfs(r[x]);
		d[x]=max(d[x],d[r[x]]+1);
	}
}
int main(){
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>l[i]>>r[i];
	}
	int ret = 0;
	for(int i =1;i<=n;i++){
		if(vis[i])continue;
		dfs(i);
		ret =max(ret,d[i]);
	}
	cout<<ret<<endl;
	return 0;
}

