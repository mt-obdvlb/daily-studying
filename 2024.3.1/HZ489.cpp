#include<iostream>

using namespace std;

int n;
int a[1005],b[1005];

int main(){	
	cin>>n;
	a[1]=9,b[1]=1;
	int k = 9;
	for(int i = 2;i<=n;i++){
		if(i==n)k=8;
		a[i]=a[i-1]*k+b[i-1]*1;
		a[i]%=12345;
		b[i]=a[i-1]*1+b[i-1]*k;
		b[i]%=12345; 
	}
	cout<<a[n]<<endl;
	return 0; 
}
