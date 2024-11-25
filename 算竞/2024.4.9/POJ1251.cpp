#include<bits/stdc++.h>

using namespace std;

int n,m,cnt,ans,fa[105];
struct edges{
	int a,b,w;
	bool operator<(const edges& b)const{
		return w<b.w;
	}
}e[10000];

void add(int a,int b,int w){
	e[++cnt].a = a;
	e[cnt].b = b;
	e[cnt].w = w;
}

int get(int x){
	return fa[x]==x?fa[x]:fa[x] = get(fa[x]);
}

bool merge(int a,int b){
	
	int af = get(a),bf = get(b);
	if(af==bf)return false;
	fa[af] = bf;
	return true;
}

int main(){
	while(cin>>n&&n){
		char u,v;	
		int w;
		cnt = ans = 0;
		for(int i = 1;i<n;i++){
			cin>>u>>m;
			for(int i = 0;i<m;i++){
				cin>>v>>w;
				add((int)(u-'A'),(int)(v-'A'),w);
			}
		}
		for(int i = 0;i<30;i++)fa[i]=i;
		sort(e+1,e+1+cnt);
		for(int i = 1;i<=cnt;i++){
			if(merge(e[i].a,e[i].b)){
				ans+=e[i].w;
				n--;
				if(n==1)break;
			}
		}
		cout<<ans<<endl;
	}	
	return 0;
}
