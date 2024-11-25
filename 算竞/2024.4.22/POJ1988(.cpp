#include<bits/stdc++.h>

using namespace std;

char op;
int x,y,fa[30005],d[30005],cnt[30005];

int get(int x){
	int af = fa[x];
	if(af==x)return x;
	fa[x] = get(af);
	d[x]+=d[af];
	return fa[x];
}

void merge(int a,int b){
	int af = get(a),bf = get(b);
	fa[af] = bf;
	d[af] = cnt[bf];
	cnt[bf]+=cnt[af];
}

int main(){
	int p;
	cin>>p;
	for(int i = 0;i<30005;i++){
		fa[i]=i;
		d[i]=0;
		cnt[i]=1;
	}
	while(p--){
		cin>>op;
		if(op=='C'){
			cin>>x;	
			int j = get(x);
			cout<<d[x]<<endl;
		}else{
			cin>>x>>y;
			merge(x,y);
		}
	}
	return 0;
}
