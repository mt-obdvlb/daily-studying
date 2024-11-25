#include<bits/stdc++.h>
#define lc l[x]
#define rc r[x] 
using namespace std;
const int N = 1e5+5;
int n,m,v[N],d[N],l[N],r[N],fa[N];
bool vis[N];
int merge(int x,int y){
	if(!x||!y)return x|y;
	if(v[x]>v[y]||(v[x]==v[y]&&x>y))swap(x,y);
	rc = merge(rc,y);
	fa[rc] = x;
	if(d[lc]<d[rc])swap(lc,rc);
	d[x]=d[rc]+1;
	return x;
}

int del(int x){
	fa[lc]=lc,fa[rc]=rc;
	vis[x]=1;
	return merge(lc,rc);
}

int get(int x){
	return fa[x]==x?x:fa[x]=get(fa[x]);
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i = 1;i<=n;i++){
		scanf("%d",v+i);
		l[i]=r[i]=d[i]=vis[i]=0;
		fa[i]=i;
	}
	int opt,x,y;
	while(m--){
		scanf("%d",&opt);
		if(opt==1){
			scanf("%d%d",&x,&y);
			if(get(x)==get(y)||vis[x]||vis[y])continue;
			merge(get(x),get(y));	
		}else{
			scanf("%d",&x);
			if(vis[x]){
				printf("-1\n");
				continue; 
			}
			x = get(x);
			printf("%d\n",v[x]);
			fa[x]=del(x);
		}
	}
	return 0;
} 
