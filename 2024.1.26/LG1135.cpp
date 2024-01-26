#include<iostream>
#include<numeric>
#include<algorithm>

#define MAX_N 205

using namespace std;

int dis[MAX_N],arr[MAX_N];

void dfs(int k,int level,int n){
	if(k>=dis[level]){
		return;
	}
	dis[level] = k;
	if(level + arr[level]<=n){
		dfs(k+1,level + arr[level],n);
	}
	if(level - arr[level]>0){
		dfs(k+1,level - arr[level],n);
	}
}

int main(){
	int n,a,b;
	cin >> n>>a >> b;
	for(int i = 1;i<=n;i++){
		scanf("%d",arr + i);
		dis[i] = n+1;
	}
	dfs(0,a,n);
	cout<<(dis[b] == n+1?-1:dis[b])<<endl;
	return 0;
}
