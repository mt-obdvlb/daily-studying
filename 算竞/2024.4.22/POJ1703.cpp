#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e5;
int T,n,m,fa[MAXN],val[MAXN];
char op;
int get(int x){
	int fx = fa[x];
	if(x==fx)return fx;
	fa[x] = get(fx);
	val[x] = (val[x]+val[fx]+2)%2;
	return fa[x];
}

void merge(int a,int b,int c){
	int af = get(a),bf = get(b);
	if(af==bf)return;
	fa[af] =bf;
	val[af] = (val[b]+c-val[a]+2)%2;
}

int main(){
	cin>>T;
	while(T--){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			val[i]=0;
			fa[i]=i;
		}
		int x,y;
		while(m--){
			cin>>op>>x>>y;	
			if(op=='A'){
				int fx = get(x),fy = get(y);
				if(fx!=fy)cout<<"Not sure yet."<<endl;
				else if((val[x]-val[y]+2)%2)cout<<"In different gangs."<<endl;
				else cout<<"In the same gang."<<endl;
			}else{
				merge(x,y,1);
			}
		}
	}
	return 0;
}
