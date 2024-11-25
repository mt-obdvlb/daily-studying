#include<bits/stdc++.h>
#define lc t[x].c[0]
#define rc t[x].c[1]
using namespace std;
const int N = 1e5+10;
const int inf = 0x3f3f3f3f;
struct Splay{
	int sz,val,c[2],fa;
}t[N];
int rt,cnt,n;

void update(int x){
	t[x].sz = t[lc].sz + t[rc].sz + 1;
}

void rotate(int x){
	int y = t[x].fa,z = t[y].fa;
	int k = t[y].c[0]==x?1:0;
	if(z)t[z].c[t[z].c[1]==y?1:0]=x;
	t[x].fa = z,t[y].fa = x,t[t[x].c[k]].fa = y;
	t[x].c[k]=y,t[y].c[k^1]=t[x].c[k];
	update(y),update(x);
}

void splay(int goal,int x){
	while(t[x].fa!=goal){
		int y = t[x].fa,z = t[y].fa;
		if(z!=goal)(t[y].c[0]==x)^(t[z].c[0]==y)?rotate(x):rotate(y);
		rotate(x);
	}
	if(!goal)rt = x;
}

int getnewnode(int fa,int val){
	t[++cnt].fa = fa;
	t[cnt].val = val;
	t[cnt].sz = 1;
	t[cnt].c[0]=t[cnt].c[1]=0;
	return cnt;
} 

void ins(int val){
	int x=rt;
	while(t[x].c[t[x].val<val?1:0])x = t[x].c[t[x].val<val?1:0];
	t[x].c[t[x].val<val?1:0] = getnewnode(x,val);
	splay(0,t[x].c[t[x].val<val?1:0]);
}

void build(int l,int r,int &x,int fa){
	if(l>r)return;
	int mid = (l+r)>>1;
	x = getnewnode(fa,mid);
	build(l,mid-1,lc,x);
	build(mid+1,r,rc,x);
	update(x);
}


void init(){
	cnt = rt = 0;
	rt = getnewnode(0,-inf);
	t[rt].c[1]=getnewnode(rt,inf);
	t[rt].sz=2;
	build(1,n,t[t[rt].c[1]].c[0],t[rt].c[1]);
	update(t[rt].c[1]);
	update(rt);
} 

int main(){
	
	return 0;
}
