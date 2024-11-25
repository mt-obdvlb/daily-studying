#include<bits/stdc++.h>
#define lc c[x][0]
#define rc c[x][1]

using namespace std;
const int N = 1e4;
int c[N][2],fa[N],rev[N],st[N],top;

void update(int x){
	
}

void pushdown(int x){
	if(rev[x]){
		swap(lc,rc);
		rev[lc]^=1,rev[rc]^=1;
		rev[x] = 0;
	}
}

bool isrt(int x){
	return c[fa[x]][0]!=x&&c[fa[x]][1]!=x;
}

void rotate(int x){
	int y = fa[x],z = fa[y];	
	int k = c[y][0]==x?1:0;
	if(!isrt(y))c[z][c[z][1]==y?1:0]=x;
	fa[x] = z,fa[y] = z,fa[c[x][k]]=y;
	c[y][k^1] = c[x][k],c[x][k] = y;
	update(y),update(x);
}

void splay(int x){
	st[top=1]=x;
	for(int i = x;!isrt(i);i=fa[i])st[++top]=i;
	while(top)pushdown(st[top--]);
	while(!isrt(x)){
		int y = fa[x],z = fa[y];
		if(!isrt(y))(c[y][0]==x^c[z][0]==y)?rotate(x):rotate(y);
		rotate(x);
	}
}

void access(int x){
	for(int i = 0;x;i = x,x = fa[x])
		splay(x),rc = i,update(x);
}

void mkrt(int x){
	access(x),splay(x),rev[x]^=1;
}

int findrt(int x){
	access(x),splay(x);
	while(lc)x=lc;
	return x;
}

void link(int x,int y){
	mkrt(x),fa[x]=y;
}

void split(int x,int y){
	mkrt(x),access(y),splay(y);
}

void cut(int x,int y){
	split(x,y);
	if(rc||c[y][0]!=x)return;
	c[y][0]=fa[c[y][0]]=0;update(y);
}

int main(){
	
	return 0;
}
