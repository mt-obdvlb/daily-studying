#include<bits/stdc++.h>

using namespace std;

const long long N = 3e6+5;
long long n,p;
long long inv[N];

int main(){
	cin>>n>>p;
	inv[1]=1;
	for(int i = 2;i<=n;i++){
		inv[i] = (long long)(p-p/i)*inv[p%i]%p;		
	}
	for(int i =1;i<=n;i++)printf("%d\n",inv[i]);
	return 0;
}
