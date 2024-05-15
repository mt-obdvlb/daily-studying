#include<bits/stdc++.h>
#define lc t[now].l
#define rc t[now].r
using namespace std;

const int N = 1e5+5;
int cnt,rt;
struct Node{
	int l,r,val,key,size,rev;
}t[N];

std::mt19937 rnd(721);

int getnewnode(int val){
	t[++cnt].val = val;
	t[cnt].key = rnd();
	t[cnt].size = 1;
	return cnt;
}

void update(int now){
	t[now].size = t[lc].size+t[rc].size+1;
}

void pushdown(int now){
	if(t[now].rev){
		t[lc].rev^=1,t[rc].rev^=1,t[now].rev=0;
		swap(lc,rc);
	}
}

void split(int now,int sz,int &x,int &y){
	if(!now)x=y=0;
	else{
		pushdown(now);
		if(t[lc].size<sz){
			x = now;
			split(rc,sz-t[lc].size-1,rc,y);
		}else{
			y = now;
			split(lc,sz,x,lc);
		}
		update(now);
	}
}

int merge(int x,int y){
	if(!x||!y)return x+y;
	if(t[x].key<t[y].key){
		pushdown(x);
		t[x].r = merge(t[x].r,y);
		update(x);
		return x;
	}else{
		pushdown(y);
		t[y].l = merge(x,t[y].l);
		update(y);
		return y;
	}
}

void reverse(int l,int r){
	int x,y,z;
	split(rt,l-1,x,y);
	split(y,r-l+1,y,z);
	t[y].rev ^=1;
	rt = merge(merge(x,y),z);
}

void ldr(int now){
	if(!now)return;
	pushdown(now);
	ldr(lc);
	printf("%d ",t[now].val);
	ldr(rc);
}



int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i = 1;i<=n;i++)rt = merge(rt,getnewnode(i));		
	while(m--){
		int l,r;
		scanf("%d%d",&l,&r);
		reverse(l,r);
	}
	ldr(rt);
	return 0;;
}
