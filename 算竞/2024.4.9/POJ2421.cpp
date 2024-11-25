#include<bits/stdc++.h>

using namespace std;

struct edges{
	int a,b,w;
	bool operator<(const edges &b)const{
		return w<b.w;
	}	
}e[100005];
int n,q,cnt,fa[105],g[105][105];

void add(int a,int b,int w){
	e[++cnt].a=a;
	e[cnt].b=b;
	e[cnt].w=w;
}

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
	cin>>n;
	for(int i = 1;i<=n;i++){
		fa[i]=i;
		for(int j = 1;j<=n;j++){
			cin>>g[i][j];
		}
	}
	cin>>q;
	int u,v;
	for(int i =0;i<q;i++){
		cin>>u>>v;
		g[u][v] = 0;
		g[v][u] = 0;
	}
	for(int i =1;i<=n;i++){
		for(int j =1;j<=n;j++)add(i,j,g[i][j]);
	}
	sort(e+1,e+1+cnt);
	int ans = 0;
	for(int i = 1;i<=cnt;i++){
		if(merge(e[i].a,e[i].b)){
			ans+=e[i].w;
			n--;
			if(n==1)break;
		}
	}
	cout<<ans<<endl;
	return 0;
}
