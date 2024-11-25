#include<iostream>

using namespace std;

int n;
int arr[15];
int vis[15];

void dfs(int ind,int k){
	if(k==n){
		for(int i = 0;i<n;i++){
			printf("%5d",arr[i]);
		} 
		cout<<endl;
		return;
	}
	for(int i = 1;i<=n;i++){
		if(vis[i])continue;
		vis[i]=1;
		arr[ind]=i;
		dfs(ind+1,k+1);
		vis[i]=0;
	}
}

int main(){
	cin>>n;
	dfs(0,0);
	return 0;
}
