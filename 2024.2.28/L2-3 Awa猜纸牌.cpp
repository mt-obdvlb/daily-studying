#include<iostream>

using namespace std;

int n,l,r;
int arr[1000005];

void dfs(int l,int r){
	if(l==r)return;
	int mid = (r+l)/2;
	int tl=l,tr=r;
	while(tl<tr){
		swap(arr[tl],arr[tr]);
		tl++,tr--;
	}
	dfs(l,mid);
	dfs(mid+1,r);
}

int main(){
	cin>>n>>l>>r;
	for(int i = 1;i<=n;i++){
		arr[i]=i;
	}
	dfs(1,n);
	int ans = 0;
	for(int i = l;i<=r;i++){
		ans+=arr[i];
	}
	cout<<ans<<endl;
	return 0;
}
