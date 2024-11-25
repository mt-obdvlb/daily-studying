#include<iostream>

using namespace std;

bool has_t(int x,int t){
	while(x){
		int k = x%10;
		if(k==t)return true;
		x/=10;
	}
	return false;
}

int main(){
	int m,t;
	cin>>m>>t;
	int ans = m;
	for(int i = 1;i<=m;i++){
		if(has_t(i,t))ans--;
	}
	cout<<ans<<endl;
	return 0;
}
