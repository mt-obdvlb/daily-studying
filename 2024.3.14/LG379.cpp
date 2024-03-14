#include<iostream>
#include<algorithm>
using namespace std;

long long n,ans=0;

#define mod 1000000007

long long cnt[5005]={0};


long long C(int n){
	return n*(n-1)/2;
}


int main(){
	cin>>n;
	for(int i = 0;i<n;i++){
		int t;
		cin>>t;		
		cnt[t]++;
	}
	for(int i = 1;i<=5000;i++){
		if(cnt[i]==0)continue;
		for(int j = i;j<=5000;j++){
			if(i+j>5000)break;
			if(cnt[j]==0)continue;
			if(i==j)ans=(ans+((C(cnt[i+j]))%mod*(C(cnt[i]))%mod)%mod)%mod;
			else ans=(ans+((C(cnt[i+j])%mod)*(((cnt[i]%mod)*(cnt[j]%mod))%mod))%mod)%1000000007;
		}
	}
	cout<<ans<<endl;
	return 0;
}
