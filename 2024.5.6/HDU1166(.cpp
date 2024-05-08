#include<bits/stdc++.h>

using namespace std;

const int maxn = 50005;
int n;
int sum[maxn<<1];
string s;



void build(int k,int l,int r){
	if(l==r){
		scanf("%d",sum+k);	
		return;
	}
	int m = (l+r)>>1;
	build(k<<1,l,m);
	build(k<<1|1,m+1,r);
	sum[k] = sum[k<<1]+sum[k<<1|1];
}


int query(int k,int l,int r,int L,int R){
	if(l>=L&&r<=R){
		return sum[k];
	}
	int m = (l+r)>>1;
	int ret = 0;
	if(L<=m)ret+=query(k<<1,l,m,L,R);
	if(R>m)ret += query(k<<1|1,m+1,r,L,R);
	return ret;
}

void update(int i,int x,int k,int l,int r){
	if(l==r){
		sum[k]+=x;
		return; 
	}
	int m = (l+r)>>1;
	if(i<=m) update(i,x,k<<1,l,m);
	else update(i,x,k<<1|1,m+1,r);
	sum[k] = sum[k<<1]+sum[k<<1|1];
}

void solve(){
	scanf("%d",&n);
	build(1,1,n);
	int l,r,i,x;
	while(cin>>s){
		if(s=="End")break;
		else if(s=="Query"){
			scanf("%d%d",&l,&r);	
			printf("%d\n",query(1,1,n,l,r));
		}else if(s=="Add"){
			scanf("%d%d%d",&i,&x);
			update(i,x,1,1,n);
		}else{
			scanf("%d%d%d",&i,&x);
			update(i,-x,1,1,n);
		}
	}
}


int main(){
	int T;
	cin>>T;
	for(int i = 1;i<=T;i++){
		printf("Case %d:\n",i);
		solve();
	}
	return 0;
}
