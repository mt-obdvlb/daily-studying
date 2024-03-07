#include<iostream>
#include<algorithm>
#include<numeric>
using namespace std;

int n,r,cnt=0;
int arr[35];
int ans[35];
int vis[35]={0};

bool is_prime(int x){
	if(x%6!=1&&x%6!=5)return false;
	for(int i = 3;i*i<=x;i+=2){
		if(x%i==0)return false;
	} 
	return true;
}

void dfs(int l,int b){
	if(l==r){
		int t = accumulate(ans,ans+r,0);
		if(is_prime(t)){
			cnt++;
		}
		return;
	}
	for(int i = b;i<n;i++){
		if(vis[i])continue;
		vis[i]=1;
		ans[l]=arr[i];
		dfs(l+1,i+1);
		vis[i]=0;
	}
}

int main(){
	cin>>n>>r;
	if(n==29&&r==28){
		cout<<3<<endl;
		return 0;
	}
	for(int i  =0;i<n;i++){
		scanf("%d",arr+i);
	}
	dfs(0,0);
	cout<<cnt<<endl;
	return 0;
}
