#include<bits/stdc++.h>

using namespace std;
const int N = 2e4+10;
int n,a[N],b[N];
int main(){
	cin>>n;
	for(int i = 1;i<=n;i++){
		scanf("%d%d",a+i,b+i);
	}	
	sort(a+1,a+1+n);
	sort(b+1,b+1+n);
	int ans = 0;
	for(int i = 1;i<=n;i++){
		ans += b[i]-a[i];
		if(i!=1&&b[i-1]>a[i])ans-=b[i-1]-a[i];
	}
	cout<<ans<<endl;
	return 0;
} 
