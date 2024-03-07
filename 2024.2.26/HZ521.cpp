#include<iostream>
#include<algorithm>
#include<numeric>
#include<unordered_map>
using namespace std;

unordered_map<int,int> h;
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

void dfs(int l,int k){
	if(l==r){
		int t = accumulate(ans,ans+r,0);
		//for(int i =0;i<r;i++)cout<<ans[i]<<" ";
		//cout<<endl;
		
		if(is_prime(t)){
			cnt++;
		}
		return;
	}
	for(int i = k&(-k);k;k-=i,i=k&(-k)){
		int t = h[i];
		ans[l]=arr[t];
		dfs(l+1,k-i);
	}
}


int main(){
	cin>>n>>r;
	for(int i  =0;i<n;i++){
		scanf("%d",arr+i);
	}
	for(int i = 1,j=0;j<31;j++,i<<=1)h[i]=j;
	int k = ((1<<(n))-1);
	dfs(0,k);
	cout<<cnt<<endl;
	return 0;
}
