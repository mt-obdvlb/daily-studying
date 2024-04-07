#include<bits/stdc++.h>

using namespace std;

long long r[1000005],c[1000005];

int main(){
	long long n,k;
	cin>>n>>k;
	for(int i = 1;i<=k;i++){
		scanf("%lld%lld",r+i,c+i);
	}
	sort(r+1,r+1+k);
	sort(c+1,c+1+k);
	int x = 0,y = 0;
	for(int i = 1;i<=k;i++){
		if(r[i] != r[i+1])x++;
		if(c[i] != c[i+1])y++;
	}
	cout<< n*n - (n-x)*(n-y)<<endl;
	return 0;
}
