#include<bits/stdc++.h>

using namespace std;

int n,m,fa[1005],a,b;

int get(int x){
	return fa[x]==x?x:fa[x] = get(fa[x]);
}

int merge(int a,int b){
	int af = get(a),bf = get(b);
	if(af==bf)return 0;
	fa[af] = bf;
	return 1;
}

int main(){
	while(cin>>n&&n&&cin>>m){
		for(int i = 1;i<=n;i++)fa[i]=i;
		while(m--){
			cin>>a>>b;
			n-=merge(a,b);
		}	
		cout<<n-1<<endl;	
	}
	return 0;
}
