#include<iostream>
#include<vector>
using namespace std;

#define mod 10000

int n;

int f[1000005],g[1000005];

int main(){
	cin>>n;
	f[0]=1,f[1]=g[1]=1;
	for(int i=2;i<=n;i++)
	{
		f[i]=((f[i-1]+f[i-2])%mod+2*g[i-2]%mod)%mod;
		
		g[i]=(g[i-1]+f[i-1])%mod;
	}
	cout<<f[n]<<endl;
	return 0;
}
