#include<bits/stdc++.h>

#define lson k<<1,l,m
#define rson k<<1|1,m+1,r 

using namespace std;

typedef long long ll;
const int maxn = 1e5;
int n,m,maxs[maxn<<2],lazy[maxn<<2];

void pushup(int k){
	maxs[k] = max(maxs[k<<1],maxs[k<<1|1]);
}

void build(int k,int l,int r){
	if(l==r){
		scanf("%d",lazy+k);
		maxs[k] = lazy[k];
		return ;
	}
	int m = (l+r)>>1;
	build(lson);
	build(rson);
	pushup(k);
}

void pushdown(int k){
	if(lazy[k]){
		int lc = k<<1;
		int rc = k<<1|1;
		maxs[lc] = maxs[rc] = maxs[k];
		lazy[lc] = lazy[rc] = lazy[k];
		lazy[k] = 0;
		
	}
}
void print(int k,int l,int r){
	if(l==r){
		printf("%d ",lazy[k]);
		return;
	}
	pushdown(k);
	int m = (l+r)>>1;
	print(lson);
	print(rson);
}


void update1(int k,int l,int r,int L,int R,int x){
	if(l>=L&&r<=R){
		maxs[k] = lazy[k] = x;
		return;
	}
	pushdown(k);
	int m = (l+r)>>1;
	if(L<=m)update1(lson,L,R,x);
	if(R>m)update1(rson,L,R,x);
	pushup(k);
}

int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}

void update2(int k,int l,int r,int L,int R,int x){
	if(maxs[k]<=x)return;
	if(lazy[k]&&l>=L&&r<=R){
		maxs[k] = lazy[k] = gcd(lazy[k],x);
		return;
	}
	pushdown(k);
	int m = (l+r)>>1;
	if(L<=m)update2(lson,L,R,x);
	if(R>m)update2(rson,L,R,x);
	pushup(k);
}


int main(){
	int T,op,q,l,r,x;
	cin>>T;
	while(T--){
		scanf("%d",&n);
		build(1,1,n);
		cin>>q;
		while(q--){
			cin>>op>>l>>r>>x;
			if(op==1)update1(1,1,n,l,r,x);
			else update2(1,1,n,l,r,x);
		}
		print(1,1,n);
	}
	
	return 0;
}
