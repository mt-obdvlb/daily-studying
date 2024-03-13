#include<iostream>

using namespace std;

int n,r;
int arr[25];
int vis[25];

void dfs(int ind,int l,int k){
	if(k==r){
		for(int i = 0;i<r;i++)printf("%3d",arr[i]);
		cout<<endl;
		return;
	}
	for(int i = l;i<=n;i++){
		if(vis[i])continue;
		vis[i]=1;
		arr[ind]=i;
		dfs(ind+1,i+1,k+1);
		vis[i]=0;
	}
}

int main(){
	cin>>n>>r;
	dfs(0,1,0);
	return 0;
}
