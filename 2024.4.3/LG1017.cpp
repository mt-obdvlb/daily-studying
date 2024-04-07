#include<bits/stdc++.h>

using namespace std;

int n,r,t;
map<int,char> mp;

int main(){
	cin>>n>>r;
	cout<<n<<"=";
	string ans;
	for(int i = '0';i<='9';i++)mp[i-'0']=i;
	for(int i = 10;i<=24;i++)mp[i]=i-10+'A';
	while(n){
		t = n%r;
		n/=r;
		if(t<0){
			n++;
			t-=r;
		}
		ans+=mp[t];
	}
	reverse(ans.begin(),ans.end());
	cout<<ans<<"(base"<<r<<")"<<endl;
	return 0;
}
