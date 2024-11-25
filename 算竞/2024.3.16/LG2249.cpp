#include<iostream>
#include<algorithm> 
using namespace std;

int a[1000005];

int main(){
	int n,m;
	cin>>n>>m;
	for(int i = 0;i<n;i++){
		cin>>a[i];
	}
	for(int i = 0;i<m;i++){
		if(i)printf(" ");
		int q;
		cin>>q;
		int p =lower_bound(a,a+n,q)-a;
		if(a[p]!=q)printf("-1");
		else printf("%d",p+1);
	}
	return 0;
}
