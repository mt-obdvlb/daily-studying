#include<iostream>
#include<algorithm>

using namespace std;

const long long mod = 1e9 + 7;
long long n,m,a[1005];

int main(){
	cin>>n;
	long long ans = 1;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i = 1;i<=n;i++){
		ans*=(a[i]-i+1)%mod;
		ans%=mod;
	}
	cout<<ans<<endl;
	return 0;
} 
