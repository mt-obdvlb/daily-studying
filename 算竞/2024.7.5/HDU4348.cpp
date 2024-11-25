#include<iostream>
#define lc t[i].l
#define Lc t[j].l
#define rc t[i].r
#define Rc t[j].r
#define mid ((l+r)>>1)
using namespace std;
typedef long long ll;
const int N = 1e5+5;
struct segment_tree{
	ll sum,lazy;
	int l,r;
}t[N*20];
int n,m,cnt,rt[N];

void _update(int i){
	t[i].sum = t[lc].sum+t[rc].sum;
}

void build(int &i,int l,int r){
	i = ++cnt;
	t[i].lazy = 0;
	if(l==r){
		scanf("%lld",&t[i].sum);
		return;
	}	
	build(lc,l,mid);
	build(rc,mid+1,r);
	_update(i);
}

void update(int &i,int j,int l,int r,int L,int R,int c){
	i = ++cnt;
	t[i]=t[j];
	t[i].sum+=1ll*(R-L+1)*c;
	if(l>=L&&r<=R){
		t[i].lazy+=c;
		return;
	}
	if(R<=mid) update(lc,Lc,l,mid,L,R,c);
    else if(L>mid) update(rc,Rc,mid+1,r,L,R,c);
    else{
        update(lc,Lc,l,mid,L,mid,c);
		update(rc,Rc,mid+1,r,mid+1,R,c);
    }
}

ll query(int i,int l,int r,int L,int R,ll x){
	if(l>=L&&r<=R)return t[i].sum+x*(r-l+1);
	if(R<=mid) return query(lc,l,mid,L,R,x+t[i].lazy);
    else if(L>mid) return query(rc,mid+1,r,L,R,x+t[i].lazy);
    else return query(lc,l,mid,L,mid,x+t[i].lazy)+query(rc,mid+1,r,mid+1,R,x+t[i].lazy);
}

int main(){
	char op[2];
	while(~scanf("%d%d",&n,&m)){
		cnt =0;
		int now = 0;
		build(rt[0],1,n);
		while(m--){
			int l,r,d,t;
			scanf("%s",op);
			if(op[0]=='Q'){
                scanf("%d%d",&l,&r);
                printf("%lld\n",query(rt[now],1,n,l,r,0));
            }
            else if(op[0]=='H'){
                scanf("%d%d%d",&l,&r,&t);
                printf("%lld\n",query(rt[t],1,n,l,r,0));
            }
            else if(op[0]=='B'){
                scanf("%d",&t);
                now=t;
                cnt=rt[t+1]-1;
            }
            else{
                scanf("%d%d%d",&l,&r,&d);
                now++;
                update(rt[now],rt[now-1],1,n,l,r,d);
            }
		}
	}
	
	return 0;
}
