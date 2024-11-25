#include<bits/stdc++.h>

using namespace std;

struct edges{
	int a,b,w;
	bool operator<(const edges &b)const{
		return w<b.w;
	}
}e[10005];
int n,m,cnt,ans,fa[100005];

void add(int a,int b,int w){
	e[++cnt].a = a;
	e[cnt].b = b;
	e[cnt].w = w;
}

int get(int x){
	return fa[x]==x?x:fa[x] = get(fa[x]);
}

bool merge(int a,int b){
	int af = get(a),bf = get(b);
	if(af==bf)return 0;
	fa[af] = bf;
	return 1;
}

int main(){
	while(cin>>n&&n&&cin>>m){
		int u,v,w;
		ans  = cnt = 0;
		for(int i = 0;i<m;i++){
			cin>>u>>v>>w;
			add(u,v,w);
		}
		sort(e+1,e+1+cnt);
		for(int i = 1;i<=n;i++)fa[i] = i;
		for(int i = 1;i<=cnt;i++){
			if(merge(e[i].a,e[i].b)){
				ans +=e[i].w;
				n--;
				if(n==1)break;
			}
		}
		cout<<ans<<endl; 
	}
	return 0;
}
