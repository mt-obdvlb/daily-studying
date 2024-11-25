#include<bits/stdc++.h>

using namespace std;
const int N = 1e5+10;
int n,m,a[N];

int main(){
	cin>>n;
	for(int i = 1;i<=n;i++){
		scanf("%d",a+i);
		a[i]+=a[i-1];
	}
	cin>>m;
	int l,r;
	while(m--){
		scanf("%d%d",&l,&r);
		printf("%d\n",a[r]-a[l-1]);
	}
	return 0;
}
