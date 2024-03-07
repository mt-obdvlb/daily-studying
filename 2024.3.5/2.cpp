#include<bits/stdc++.h>

using namespace std;

int n,q;
int a[200005],b[100];

int main(){
	cin>>n>>q;
	for(int i = 1;i<=n;i++){
		scanf("%d",a+i);
		b[i]=1;
	}
	for(int i = 1;i<=n;i++){
		for(int j = i+1;j<=n;j++){
			b[i]*=a[j];
		}
		
	}
	for(int i = 1;i<=q;i++){
		int ans = 0;
		for(int j = 1;j<=n;j++){
			int t;
			scanf("%d",&t);
			ans += (t-1)*(b[j]);
			
		}
		cout<<ans+1<<endl;
	}
	
	return 0;
} 
