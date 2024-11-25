#include<bits/stdc++.h>
#define lc x<<1
#define rc x<<1|1
using namespace std;
const int N = 4.17e6+10;
int n,p,mn[N<<2],lz[N<<2];

void update(int x){
	mn[x] = min(mn[lc],mn[rc]);
}

void build(int x,int l,int r){
	int mid = (l+r)>>1;
	if(l==r){
		scanf("%d",&mn[x]);
		return;
	}
	build(lc,l,mid);
	build(rc,mid+1,r);
	update(x);
}

void pushdown(int x){
	if(lz[x]){
		lz[lc]+=lz[x],lz[rc]+=lz[x];
		mn[lc]+=lz[x],mn[rc]+=lz[x];
		lz[x]=0;
	}
}

void add(int x,int l,int r,int L,int R,int t){
	if(L<=l&&R>=r){
		mn[x]+=t;
		lz[x]+=t;
		return;
	}
	pushdown(x);
	int mid = (l+r)>>1;
	if(L<=mid)add(lc,l,mid,L,R,t);
	if(R>mid)add(rc,mid+1,r,L,R,t);
	update(x);
}

int main(){
	cin>>n>>p;
	build(1,1,n);
	int x,y,z;
	while(p--){
		scanf("%d%d%d",&x,&y,&z);
		add(1,1,n,x,y,z);
	}
	cout<<mn[1]<<endl;
	return 0;
}
