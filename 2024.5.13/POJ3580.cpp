#include<bits/stdc++.h>
#define lc t[x].c[0]
#define rc t[x].c[1]
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 2e5+10;
int n,m,cnt,a[N],rt; 
struct Splay{
	int c[2],val,size,rev,add,mn,fa;
}t[N];
void update(int x){
	t[x].size = t[lc].size+t[rc].size+1;
	t[x].mn = t[x].val;
	if(lc)t[x].mn=min(t[x].mn,t[lc].mn);
	if(rc)t[x].mn=min(t[x].mn,t[rc].mn);
}
void pushdown(int x){
	if(t[x].rev){
		if(lc)t[lc].rev^=1;
		if(rc)t[rc].rev^=1;
		t[x].rev=0;
		swap(lc,rc);
	} 
	if(t[x].add){
		if(lc)t[lc].add+=t[x].add,t[lc].mn+=t[x].add,t[lc].val+=t[x].add;
		if(rc)t[rc].add+=t[x].add,t[rc].mn+=t[x].add,t[rc].val+=t[x].add;
		t[x].add = 0;
	}
}

void rotate(int x){
	pushdown(x);
	int y = t[x].fa,z = t[y].fa;
	int k = t[y].c[0]==x?1:0;
	if(z)t[z].c[t[z].c[1]==y?1:0]=x;
	t[x].fa = z,t[y].fa = x,t[t[x].c[k]].fa = y;
	t[y].c[k^1]=t[x].c[k],t[x].c[k]=y; 
	update(y),update(x);
}

void splay(int x,int goal){
	while(t[x].fa!=goal){
		int y = t[x].fa,z = t[y].fa;
		if(z!=goal)(t[y].c[0]==x^t[z].c[0]==y)?rotate(x):rotate(y);
		rotate(x);
	}
	if(!goal)rt = x;
}

int getnewnode(int fa,int val){
	t[++cnt].fa =fa;
	t[cnt].val = val;
	t[cnt].size = 1;
	t[cnt].mn = val;
	t[cnt].rev = t[cnt].add = t[cnt].c[0]=t[cnt].c[1]=0;
	return cnt;
}

int findk(int k){
	int x = rt;
	while(x&&k){
		pushdown(x);
		int sz = t[lc].size+1;
		if(sz==k)return x;
		else if(sz<k){
			k-=sz;
			x=rc;
		}else x=lc;
	}
	return x;
}

void add(int l,int r,int val){
	int x = findk(l-1),y = findk(r+1);
	splay(x,0),splay(y,x);
	t[t[y].c[0]].val+=val;
	t[t[y].c[0]].mn+=val;
	t[t[y].c[0]].add+=val;
	update(y),update(x);
}

void flip(int l,int r){
	int x = findk(l-1),y = findk(r+1);
	splay(x,0),splay(y,x);
	t[t[y].c[0]].rev^=1;
}

void ins(int k,int p){
	int x = findk(k),y = findk(k+1);
	splay(x,0),splay(y,x);
	t[y].c[0]=getnewnode(y,p);
	update(y),update(x);
}

void del(int k){
	int x = findk(k-1),y = findk(k+1);
	splay(x,0),splay(y,x);
	t[y].c[0]=0;
	update(y),update(x);
}

void getmin(int l,int r){
	int x = findk(l-1),y = findk(r+1);
	splay(x,0),splay(y,x);
	printf("%d\n",t[t[y].c[0]].mn);
}

void build(int l,int r,int &x,int fa){
	if(l>r)return;
	int mid = (l+r)>>1;
	x = getnewnode(fa,a[mid]);
	build(l,mid-1,lc,x);
	build(mid+1,r,rc,x);
	update(x);
}

void revolve(int l,int r,int k){
	k %=r-l+1;
	int x = findk(r-k),y=findk(r+1);
	splay(x,0),splay(y,x);
	int tmp = t[y].c[0];
	t[y].c[0] = 0;
	update(y),update(x);
	x = findk(l-1),y = findk(l);
	t[y].c[0]=tmp;
	t[tmp].fa = y;
	update(y),update(x);
	
}

int main(){
	int x,y,p;
	char opt[10];
	scanf("%d",&n);
	for(int i = 1;i<=n;i++){
		scanf("%d",a+i);
	}
	rt = getnewnode(0,-inf);
	t[rt].c[1] = getnewnode(rt,inf);
	t[rt].size = 2;
	build(1,n,t[t[rt].c[1]].c[0],t[rt].c[1]);
	update(t[rt].c[1]),update(rt);
	scanf("%d",&m);
	while(m--){
		scanf("%s",opt);
		if(opt[0]=='I'){
			scanf("%d%d",&x,&p);
			ins(x+1,p);
		}else if(opt[0]=='D'){
			scanf("%d",&x);
			del(x+1);
		}else{
			scanf("%d%d",&x,&y);
			if(opt[0]=='A'){
				scanf("%d",&p);
				add(x+1,y+1,p); 
			}else if(opt[0]=='M'){
				getmin(x+1,y+1);
			}else if(opt[3]=='E'){
				flip(x+1,y+1);
			}else{
				scanf("%d",&p);
				revolve(x+1,y+1,p);
			}
		}
	}
	return 0;
}
