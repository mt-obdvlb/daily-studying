#include<bits/stdc++.h>

using namespace std;

bitset<1005> b[1005];

int k,n,m,c[105];



int main(){
	cin>>k>>n>>m;
	for(int i = 1;i<=k;i++)cin>>c[i];
	while(m--){
		int u,v;
		cin>>u>>v;
		b[u][v] = 1;
	}
	for(int i = 1;i<=n;i++)b[i][i]=1;
	for(int j = 1;j<=n;j++){
		for(int i = 1;i<=n;i++){
			if(b[i][j])b[i]|=b[j];
		}
	}
	bitset<1005> ans(b[c[1]]);
	for(int i = 2;i<=k;i++){
		ans&=b[c[i]];
	}
	cout<<ans.count()<<endl;
	return 0;
}
