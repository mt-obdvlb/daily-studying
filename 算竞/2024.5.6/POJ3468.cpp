#include<bits/stdc++.h>


using namespace std;

typedef long long ll;
const int maxn = 1e5+5;
int n,q;
struct segTree{
	int l,r;
	ll lazy,val;
}t[maxn<<2];


void pushdown(int k){
	int lc = k<<1,rc = k<<1|1;
	t[lc].lazy += t[k].lazy;
	t[rc].lazy += t[k].lazy;
	t[lc].val += t[k].lazy;
	t[rc].val += t[k].lazy;
	t[k].lazy = 0;
}

int query(int k,int l,int r){
	if(t[k].l>=l&&t[k].r<=r){
		return t[k].val;
	}
	if(t[k].lazy)pushdown(k);
	int m = (t[k].l+t[k].r)>>1;
	int ret = 0;
	if(l<=m)ret +=query(k<<1,l,r);
	if(r>m) ret+=query(k<<1|1,l,r);
	return ret;
}

void update(int k,int l,int r,int x){
	if(t[k].l>=l&&t[k].r<=r){
		t[k].val+=x;
		t[k].lazy+=x;
		return;
	}
	int m = (t[k].l+t[k].r)>>1;
	if(l<=m)update(k<<1,l,r,x);
	if(r>m) update(k<<1|1,l,r,x);
}

void pushup(int k){
	t[k].val = t[k<<1].val + t[k<<1|1].val;
}

void build(int k,int l,int r){
	t[k].l = l,t[k].r = r,t[k].lazy=0;
	if(l==r){
		scanf("%d",&t[k].val);
		return;
	}
	int m = (l+r)>>1;
	build(k<<1,l,m);
	build(k<<1|1,m+1,r);
	pushup(k);
}

int main(){
	scanf("%d%d",&n,&q);
	build(1,1,n);	
	char op[2];
	int a,b,c;
	while(q--){
		scanf("%s%d%d",op,&a,&b);
		if(op[0]=='C'){
			scanf("%d",&c);
			update(1,a,b,c);
		}else{
			cout<<query(1,a,b)<<endl;
		}
	}
	return 0;
}
