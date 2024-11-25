#include<iostream>

using namespace std;

int n,m;
int arr[10005];
int cnt = 0;
int vis[10005];
int ans[10005];

void dfs(int ind){
	if(cnt>m+1)return;
	if(ind>n){
		cnt++;
		if(cnt==m+1){
			for(int i = 1;i<=n;i++){
				if(i!=1)printf(" ");
				printf("%d",ans[i]);
			}
			cnt++;
		}
	}
	for(int i = 1;i<=n;i++){
		if(cnt==0)i=arr[ind];
		if(vis[i])continue;
		vis[i]=1;
		ans[ind]=i;
		dfs(ind+1);
		vis[i]=0;
	}
}

int main(){
	cin>>n>>m;
	for(int i = 1;i<=n;i++)scanf("%d",arr+i);
	dfs(1);
	return 0;
}
