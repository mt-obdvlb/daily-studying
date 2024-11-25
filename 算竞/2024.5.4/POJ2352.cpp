#include<bits/stdc++.h>

using namespace std;

int n,ans[15005],c[33005],maxn;
const int maxx = 32005;

int lowbit(int i){
	return i&(-i);
}

int sum(int i){
	int s = 0;
	for(;i>0;i-=lowbit(i)){
		s+=c[i];
	}
	return s;
}

void add(int i){
	for(;i<=maxx;i+=lowbit(i)){
		c[i]+=1;
	}
}

int main(){
	cin>>n;
	int x,y;
	for(int i = 1;i<=n;i++){
		scanf("%d%d",&x,&y);
		ans[sum(x)]++;
		add(x);
	}
	for(int i = 0;i<n;i++)cout<<ans[i]<<endl;
	return 0;
}
