#include<bits/stdc++.h>
#define lc i<<1
#define rc i<<1|1
#define sl t[k].s[i].l
#define sr t[k].s[i].r
using namespace std;
const int N = 2005;
int n;
struct node_y{
	int l,r,sum;
};

struct node_x{
	int l,r;
	node_y s[N<<2];
}t[N<<2]; 

void build_y(int i,int l,int r,int k){
	sl=l,sr=r,t[k].s[i].sum=0;
	if(l==r)return;
	int mid = (l+r)>>1;
	build_y(lc,l,mid,k);
	build_y(rc,mid+1,r,k);
}

void build_x(int i,int l,int r,int ll,int rr){
	t[i].l=l,t[i].r=r;
	build_y(1,ll,rr,i);
	if(l==r)return;
	int mid = (l+r)>>1;
	build_x(lc,l,mid,ll,rr);
	build_x(rc,mid+1,r,ll,rr);
}

void update_y(int i,int y,int val,int k){
	t[k].s[i].sum+=val;
	if(sl==sr)return;
	int mid = (sl+sr)>>1;
	if(y<=mid)update_y(lc,y,val,k);
	else update_y(rc,y,val,k);
}

void update_x(int i,int x,int y,int val){
	update_y(1,y,val,i);
	if(t[i].l==t[i].r)return;
	int mid = (t[i].l+t[i].r)>>1;
	if(x<=mid)update_x(lc,x,y,val);
	else update_x(rc,x,y,val);
}

int query_y(int i,int l,int r,int k){
	if(sl>r||sr<l)return 0;
	if(l<=sl&&r>=sr)return t[k].s[i].sum;
	int mid = (sl+sr)>>1;
	int ans = 0;
	ans+=query_y(lc,l,r,k);
	ans+=query_y(rc,l,r,k);
	return ans;
}

int query_x(int i,int l,int r,int ll,int rr){
	if(t[i].l>r||t[i].r<l)return 0;
	if(t[i].l>=l&&t[i].r<=r)return query_y(1,ll,rr,i);
	int mid = (t[i].l+t[i].r)>>1;
	int ans = 0;
	ans+=query_x(lc,l,r,ll,rr);
	ans+=query_x(rc,l,r,ll,rr);
	return ans;
}

int main(){
	int opt,x,y,a,x1,x2,y1,y2;
	while(cin>>opt){
		if(opt==3)break;
		switch(opt){
			case 0:
				cin>>n;
				build_x(1,0,n-1,0,n-1);
				break;
			case 1:
				cin>>x>>y>>a;
				update_x(1,x,y,a);
				break;
			case 2:
				cin>>x1>>y1>>x2>>y2;
				cout<<query_x(1,x1,x2,y1,y2)<<endl; 
		}
	}	
	return 0;
}
