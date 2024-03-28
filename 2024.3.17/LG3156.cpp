#include<iostream>

using namespace std;

int n,m;
long long a[2000005];

int main(){
	cin>>n>>m;
	for(int i = 1;i<=n;i++)scanf("%d",a+i);
	while(m--){
		int t;
		scanf("%d",&t);
		printf("%d\n",a[t]);
	}
	return 0;
}
