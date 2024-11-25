#include<iostream>
#include<algorithm>
using namespace std;
const int N = 805;
const int inf = 0x3f3f3f3f;
int n,m,a[N][N],Mn,Mx;
struct Node_y{
	int l,r,mx,mn,v;
};
struct Node_x{
	int l,r;
	Node_y s[N<<2];
}t[N<<2];

void update(int k,int i){
	
	t[k].s[i].mx = max(t[k].s[i].mx,max(t[k].s[lc].mx,t[k].s[rc].mx));
	t[k].s[i].mn = min(t[k].s[i].mn,min(t[k].s[lc].mn,t[k].s[rc].mn));
}

void build_y(int i,int l,int r,int k){
	sl = l,sr = r;
	t[k].s[i].mx=t[k].s[i].mn=t[k].s[i].v=a[k][i];
	if(l==r)return;
	build_y(lc,l,mid,k);
	build_y(rc,mid+1,r,k); 
	update(k,i);
}

void build_x(int i,int l,int r,int ll,int rr){
	t[i].l = l,t[i].r = r;
	build_y(1,ll,rr,i);
	if(l==r)return;
	int mid =(l+r)>>1;
	build_x(lc,l,mid,ll,rr);
	build_x(rc,mid+1,r,ll,rr);
}

void query_y(int i,int y,int l,int k){
	if(sl>y+l/2||sr<y-l/2)return;
	if(y-l/2<=sl&&y+l/2>=sr){
		Mn = min(Mn,t[k].s[i].mn);
		Mx = max(Mx,t[k].s[i].mx);
		return;
	}
	query_y(lc,y,l,k);
	query_y(rc,y,l,k);
}

void query_x(int i,int x,int y,int l){
	if(t[i].l>x+l/2||t[i].r<x-l/2)return;
	if(x-l/2<=t[i].l&&x+l/2>=t[i].r)query_y(1,y,l,i);
	query_x(lc,x,y,l);
	query_x(rc,x,y,l);
}

void update_y(int i,int x,int y,int val,int k){
	
}

void update_x(int i,int x,int y,int val){
	update_y(1,x,y,val,i);
}

int main(){
	int T,x,y,l;
	for(int tt = 1;tt<=T;tt++){
		printf("Case #%d:\n",tt);
		cin>>n;
		for(int i = 1;i<=n;i++){
			for(int j = 1;j<=n;j++){
				cin>>a[i][j];	
			}
		}	
		cin>>m;
		while(m--){
			cin>>x>>y>>l;
			Mn=inf,Mx=-inf;
			query_x(1,x,y,l);
			update_x(1,x,y,	(Mx+Mn)>>1);
		}
	}
	
	return 0;
} 
