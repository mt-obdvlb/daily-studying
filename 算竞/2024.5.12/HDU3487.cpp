#include<bits/stdc++.h>
#define lc t[x].c[0]
#define rc t[x].c[1]
using namespace std;

const int inf = 0x3f3f3f3f;
const int N = 3e5+10;
int cnt,n,st[N],rt,top;
struct Splay{
	int c[2],fa,val,rev,sz;
}t[N];

void pushdown(int x){
	if(t[x].rev){
		t[lc].rev^=1,t[rc].rev^=1,t[x].rev=0;
		swap(lc,rc);
	}
}

void update(int x){
	t[x].sz = t[lc].sz +t[rc].sz+1;
}

void rotate(int x){
	pushdown(x);
	int y = t[x].fa,z = t[y].fa;
	int k = t[y].c[0]==x?1:0;
	if(z)t[z].c[t[z].c[1]==y?1:0]=x;
	t[x].fa=z,t[y].fa =x,t[t[x].c[k]].fa=y;
	t[y].c[k^1]=t[x].c[k],t[x].c[k]=y;
	update(y),update(x);
}

void splay(int x,int goal){
	while(t[x].fa!=goal){
		int y  =t[x].fa,z = t[y].fa;
		if(z!=goal)(t[y].c[0]==x^t[z].c[0]==y)?rotate(x):rotate(y);
		rotate(x);
	}
	if(!goal)rt = x;
}

int getnewnode(int fa,int val){
	t[++cnt].fa =fa;
	t[cnt].val = val;
	t[cnt].c[0]=t[cnt].c[1]=0;
	t[cnt].rev = 0;
	t[cnt].sz=1;
	return cnt;
}

int find(int k){
	int x = rt;
	while(x&&k){
		pushdown(x);
		if(t[lc].sz+1==k){
			return x;
		}else if(t[lc].sz+1<k){
			k-=t[lc].sz+1;
			x=rc;			
		}else x=lc;
	}
	return x;
}


void ldr(int x){
	if(!x)return;
	pushdown(x);
	ldr(lc);
	if(t[x].val!=-inf&&t[x].val!=inf) printf("%d ",t[x].val);
	ldr(rc); 
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
	t[0].c[0]=t[0].c[1]=0;
	rt = getnewnode(0,-inf);
	t[rt].c[1]=getnewnode(rt,inf);
	build(1,n,t[t[rt].c[1]].c[0],t[rt].c[1]);
}

void cut(int l,int r,int c){
	int x = find(l-1),y=find(r+1);
	splay(x,0),splay(y,x);
	int tmp = t[y].c[0];
	t[y].c[0] = 0;
	x = find(c),y = find(c+1);
	splay(x,0),splay(y,x);
	t[y].c[0] = tmp;
	t[tmp].fa = y;
}

void flip(int l,int r){
	int x = find(l-1),y = find(r+1);
	splay(x,0),splay(y,x);
	t[t[y].c[0]].rev^=1;
}

int main(){
	int m,a,b,c;
	char opt[10];
	while(~scanf("%d%d",&n,&m)&&~n&&~m){
		init();
		while(m--){
			scanf("%s",opt);
			if(opt[0]=='C'){
				scanf("%d%d%d",&a,&b,&c);
				cut(a+1,b+1,c+1);
			}else{
				scanf("%d%d",&a,&b);
				flip(a+1,b+1);				
			}
		}	
		ldr(rt);
		printf("\n");
	}		
	return 0; 
}
