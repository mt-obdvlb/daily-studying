#include<bits/stdc++.h>

using namespace std;

int n,m,d[105],g[105][105],a[105];

int main(){
	while(cin>>n&&~n){
		memset(d,0,sizeof(d));
		memset(g,0,sizeof(g));
		memset(a,0,sizeof(a));
		for(int i = 1;i<=n;i++){
			cin>>d[i]>>m;
			int v;
			while(m--){
				cin>>v;
				g[i][v]=1;
			}
		}
		int flag = 1;
		a[1] = 100;
		for(int i = 1;i<=n;i++){
			for(int j =1;j<=n;j++){
				if(!g[i][j])continue;
				if(a[j]<a[i]+d[j]){
					a[j]=a[i]+d[j];
				}
			}
		}
		for(int i = 1;i<=n;i++){
			if(a[i]<=0)flag=0;
		}
		if(flag)cout<<"winnable"<<endl;
		else cout<<"hopeless"<<endl;
	}
	return 0; 
}
