#include<bits/stdc++.h>

using namespace std;
const int N = 5e6+10;
int n,m;
int a[N],d[N];

int main(){
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		scanf("%d",a+i);
		d[i] = a[i] - a[i-1];
	}
	int x,y,z; 
	while(m--){
		scanf("%d%d%d",&x,&y,&z);
		d[x]+=z,d[y+1]-=z; 
	}
	int mn = 0x3f3f3f3f;
	for(int i = 1;i<=n;i++){
		a[i] = a[i-1]+d[i];
		mn = min(a[i],mn);
	}
	cout<<mn<<endl;
}
