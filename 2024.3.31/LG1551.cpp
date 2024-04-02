#include<bits/stdc++.h>

using namespace std;

struct UnionSet{
	int fa[5005];
	UnionSet(){
		for(int i = 0;i<5005;i++)fa[i]=i;
	}
	int get(int x){
		return fa[x]==x?x:fa[x] = get(fa[x]);
	}
	void merge(int a,int b){
		int af = get(a),bf = get(b);
		if(af==bf)return;
		fa[bf] = af;
	}
};

int main(){
	int n,m,p;
	int a,b;
	cin>>n>>m>>p;
	UnionSet u;
	while(m--){
		cin>>a>>b;
		u.merge(a,b);
	}
	while(p--){
		cin>>a>>b; 
		if(u.get(a)==u.get(b))cout<<"Yes\n";
		else cout<<"No\n";
	}
	return 0;
}
