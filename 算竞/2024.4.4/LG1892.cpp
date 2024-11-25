#include<bits/stdc++.h>

using namespace std;

int fa[2005],val[1005],vis[1005];

int get(int x){
	return fa[x]==x?x:fa[x] = get(fa[x]);
}

void merge(int a,int b){
	fa[get(a)]=get(b);
}


int main(){
	for(int i = 0;i<2005;i++)val[i]=0,fa[i]=i;
	int n,m,p,q;
	char c;
	cin>>n>>m;
	while(m--){
		cin>>c;
		scanf("%d%d",&p,&q);
		if(c=='F')merge(p,q);
		else merge(p+n,q),merge(q+n,p);		
	}
	int ans = 0;
	for(int i = 1;i<=n;i++){
		if(fa[i]==i)ans++;
	}
	
	cout<<ans<<endl;
	return 0;
}
