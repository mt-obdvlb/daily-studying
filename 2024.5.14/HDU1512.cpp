#include<bits/stdc++.h>
#define lc l[x]
#define rc r[x]
using namespace std;
const int N = 1e5+10;
int n,m,cnt,rt;
int v[N],l[N],r[N],d[N],fa[N];

void init(){
	rt = cnt = 0;
}

int merge(int x,int y){
	if(!x||!y)return x|y;
	if(v[x]<v[y])swap(x,y);
	rc = merge(rc,y);
	fa[rc]=x;
	if(d[lc]<d[rc])swap(lc,rc);
	d[x]=d[rc]+1;
	return x;
}

int get(int x){
	return fa[x]==x?x:fa[x]=get(fa[x]);
}

int del(int x){
	fa[lc]=lc,fa[rc]=rc;
	return merge(lc,rc);
}

int main(){
	int x,y;
	while(~scanf("%d",&n)){
		init();
		for(int i = 1;i<=n;i++){
			scanf("%d",v+i);
			fa[i]=i;
			l[i]=r[i]=d[i]=0;	
		}
		scanf("%d",&m);
		while(m--){
			scanf("%d%d",&x,&y);
			x = get(x),y=get(y);
			if(x==y){
				printf("-1\n");
				continue;
			} 
			int rt = del(x);
			v[x]/=2,lc=rc=d[x]=0;
			x = merge(rt,x);
			swap(x,y);
			rt = del(x);
			v[x]/=2,lc=rc=d[x]=0;
			x = merge(rt,x);
			rt = merge(x,y);
			printf("%d\n",v[rt]);
		}		
	}
	return 0;
} 
