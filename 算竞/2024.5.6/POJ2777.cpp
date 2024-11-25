#include<iostream>
#include<cstring>

#define ls k<<1,l,m
#define rs k<<1|1,m+1,r

using namespace std;

const int N =1e5+5;
int n,t,o;
int lazy[N<<2],color[N<<2],vis,ans;

void build(int k,int l,int r){
	lazy[k] = 0;
	if(l==r){
		return;
	}
	int m  =(l+r)>>1;
	build(ls);
	build(rs);
}

void pushdown(int k){
	if(lazy[k]){
		int lc = k<<1,rc = k<<1|1;
		lazy[lc] = lazy[rc] = lazy[k];
		color[lc] = color[rc] = lazy[k];
		lazy[k] = 0;
	}
}

void liftup(int k){
	color[k] = color[k<<1]|color[k<<1|1];
}

void update(int k,int l,int r,int L,int R,int x){
	if(l>=L&&r<=R){
		color[k] = lazy[k] = 1<<(x-1);
		return ;
	}
	pushdown(k);
	int m = (l+r)>>1;
	if(L<=m)update(ls,L,R,x);
	if(R>m)update(rs,L,R,x);
	liftup(k);
}

void print(int k,int l,int r,int L,int R){
	if(l==r&&color[k]){
		vis|= color[k];
		return;
	}
	if(lazy[k]){
		vis|=lazy[k];
		return;
	}
	int m = (l+r)>>1;
	if(L<=m)print(ls,L,R);
	if(R>m)print(rs,L,R);
}

int main(){
	scanf("%d%*d%d",&n,&o);
	char opt[2];
	build(1,1,n); 
	lazy[1]=1;
	int a,b,c;
	while(o--){
		scanf("%s%d%d",opt,&a,&b);
		if(a>b)swap(a,b);
		if(opt[0]=='C'){
			scanf("%d",&c);
			update(1,1,n,a,b,c);
		}else{
			ans = 0,vis = 0;
			print(1,1,n,a,b);
			while(vis){
				ans++;
				vis&=vis-1;
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
