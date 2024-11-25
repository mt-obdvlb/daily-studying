#include<bits/stdc++.h>

#define lc c[x][0]
#define rc c[x][1]

using namespace std;
const int N = 3e5+5;
int n,m,top;
int a[N],v[N],st[N],rev[N],c[N][2];
int fa[N];

void pushdown(int x){
	if(rev[x]){
		rev[lc]^=1,rev[rc]^=1,rev[x]=0;
		swap(lc,rc);
	}
}

void update(int x){
	v[x] = v[lc]^v[rc]^a[x];
}

bool isroot(int x){
	return c[fa[x]][0]!=x&&c[fa[x]][1]!=x;
}

void rotate(int x){
	int y = fa[x],z = fa[y];
	int k = c[y][0]==x?1:0;
	if(!isroot(y))c[z][c[z][1]==y?1:0]=x;
	fa[x] = z,fa[y] = x,fa[c[x][k]] = y;
	c[y][k^1] = c[x][k],c[x][k] = y; 
	update(y),update(x);
}

void splay(int x){
	st[top=1] = x;
	for(int i = x;!isroot(i);i = fa[i])st[++top]=fa[i];
	while(top)pushdown(st[top--]);
	while(!isroot(x)){
		int y = fa[x],z = fa[y];
		if(!isroot(y)) (c[y][0]==x)^(c[z][0]==y)?rotate(x):rotate(y);
		rotate(x);
	}
}

void access(int x){
	for(int y = 0;x;y= x,x=fa[x]){
		splay(x),rc=y,update(x);
	}
}

void makeroot(int x){
	access(x),splay(x),rev[x]^=1;
}

int findroot(int x){
	access(x),splay(x);
	while(lc)x=lc;
	return x;
}

void split(int x,int y){
	makeroot(x),access(y),splay(y);
}

void link(int x,int y){
	makeroot(x),fa[x] = y;
}

void cut(int x,int y){
	split(x,y);
	if(c[y][0]!=x||c[x][1])return;
	c[y][0] =fa[c[y][0]] = 0,update(y);	
}

int main(){
	int op,x,y;
	scanf("%d%d",&n,&m);
	for(int i = 1;i<=n;i++){
		scanf("%d",a+i);
		v[i] = a[i];
	}
	while(m--){
		scanf("%d%d%d",&op,&x,&y);
		if(op==0){
			split(x,y);
			printf("%d\n",v[y]);
		}else if(op==1){
			if(findroot(x)!=findroot(y))link(x,y);
		}else if(op==2){
			if(findroot(x)==findroot(y))cut(x,y);
		}else{
			splay(x);a[x] = y;
		}
	}
	return 0;
}
