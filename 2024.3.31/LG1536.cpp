#include<bits/stdc++.h>

using namespace std;

int n,m,a,b;

struct UnionSet{
	int fa[1005];
	UnionSet(){
		for(int i = 0;i<1005;i++)fa[i]=i;
	} 
	int get(int x){
		return fa[x]==x?x:fa[x]=get(fa[x]);
	}
	int merge(int a,int b){
		int af = get(a),bf = get(b);
		if(af==bf)return 1;
		fa[bf] = af;
		return 0;
	}
};

int main(){
	while(cin>>n&&n&&cin>>m){
		UnionSet u;
		while(m--){
			cin>>a>>b;
			u.merge(a,b);
		}
		int ans = 0,vis[n+1]={0};
		for(int i = 1;i<=n;i++){
			if(vis[u.get(i)])continue;
			ans++;
			vis[i]=1;
			vis[u.get(i)]=1;
		}
		cout<<ans-1<<endl;
	}
	return 0;
}
