#include<bits/stdc++.h>
#define lc x<<1
#define rc x<<1|1
#define ls t[x].c[0]
#define rs t[x].c[1]
using namespace std;
const int inf = 0x7fffffff;
const int N = 5e4+10;
int v[N],n;
mt19937 rnd(114514);
struct Node{
	int size,c[2],v,cnt,key;
}t[N*30];
int cnt;

struct Treap{
	int rt;
	void update(int x){
		t[x].size = t[ls].size+t[rs].size+1;
	}
	int getnewnode(int val){
		t[++cnt].v=val;
		t[cnt].c[0]=t[cnt].c[1]=0;
		t[cnt].size=1;
		t[cnt].key=rnd();
		return cnt;
	}
	void split(int x,int val,int &t1,int &t2){
		if(!x)t1=t2=0;
		else{
			if(v[x]<val){
				t1 = x;
				split(rs,val,rs,t2);
			}else{
				t2 = x;
				split(ls,val,t1,ls);
			}
			update(x);
		}
	} 
	int merge(int t1,int t2){
		if(!t1||!t2)return t1|t2;
		if(t[t1].key>t[t2].key){
			t[t1].c[1] = merge(t[t1].c[1],t2);
			update(t1);
			return t1;
		}else{
			t[t2].c[0] = merge(t1,t[t2].c[0]);
			update(t2);
			return t2;
		}
	}
	int x,y,z;
	void ins(int val){
		split(rt,val,x,z);
		rt = merge(merge(x,getnewnode(val)),z);
	}
	void del(int val){
		split(rt,val,x,z);
		split(x,val-1,x,y);
		y = merge(t[y].c[0],t[y].c[1]);
		rt = merge(merge(x,y),z);
	}
	int getpre(int val){
		split(rt,val-1,y,z);
		x = y;
		while(rs)x = rs;
		rt = merge(y,z);
		return x;
	}
	int getpost(int val){
		split(rt,val,y,z);
		x = y;
		while(ls)x=ls;
		rt = merge(y,z);
		return x;
	}
	int getrank(int val){
		int x = rt;
		int k = 0;
		while(x){
			if(v[x]==val)return k+t[ls].size+1;
			else if(v[x]<val){
				k+=t[ls].size+1;
				x = rs;
			}else{
				x = ls;
			}
		}
		return k;
	}
}a[N<<2];

void build(int x,int l,int r){
	a[x].rt=0;
	for(int i=l;i<=r;i++)
		a[x].ins(v[i]);//将区间[l,r]数据插入到平衡树中 
	if(l==r) return ;
	build(x<<1,l,l+r>>1);
	build(x<<1|1,(l+r>>1)+1,r);
}

int getrank(int x,int l,int r,int L,int R,int val){
	if(l>R||r<L) return 0;
	if(L<=l&&r<=R)
		return a[x].getrank(val);//平衡树中查询排名
	int ans=0,mid=l+r>>1;
	ans+=getrank(x<<1,l,mid,L,R,val);
	ans+=getrank(x<<1|1,mid+1,r,L,R,val);
	return ans;
}

int kth(int L,int R,int k){
	int l = 0,r = 1e8,mid,s,ans=-1;
	while(l<=r){
		mid = (l+r)>>1;
		if(getrank(1,1,n,L,R,mid)+1<=k)ans=mid,l=mid+1;
		else r = mid-1;		
	}
	return ans;
}

void modify(int x,int l,int r,int pos,int val){
	if(pos<l||pos>r)return;
	a[x].del(v[pos]);
	a[x].ins(val);
	if(l==r)return;
	int mid = (l+r)>>1;
	modify(lc,l,mid,pos,val);
	modify(rc,mid+1,r,pos,val);
}

int getpre(int x,int l,int r,int L,int R,int val){
	if(l>R||r<L)return -inf;
	if(L<=l&&R>=r)return a[x].getpre(val);
	int mid = (l+r)>>1;
	int ans = getpre(x<<1,l,mid,L,R,val);
	ans = max(ans,getpre(x<<1|1,mid+1,r,L,R,val));
	return ans;
}

int getpost(int x,int l,int r,int L,int R,int val){
	if(l>R||r<L)return inf;
	if(L<=l&&R>=r)return a[x].getpost(val);
	int mid = (l+r)>>1;
	int ans = getpost(x<<1,l,mid,L,R,val);
	ans = max(ans,getpost(x<<1|1,mid+1,r,L,R,val));
	return ans;
	
}

int m;

int main(){
	srand(time(0));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&v[i]);
	build(1,1,n);
	while(m--){
		int opt,l,r,k,pos;
		scanf("%d",&opt);;
		if(opt==1){
			scanf("%d%d%d",&l,&r,&k);
			printf("%d\n",getrank(1,1,n,l,r,k)+1);
		}
		else if(opt==2){
			scanf("%d%d%d",&l,&r,&k);
			printf("%d\n",kth(l,r,k));
		}
		else if(opt==3){
			scanf("%d%d",&pos,&k);
			modify(1,1,n,pos,k);v[pos]=k;
		}
		else if(opt==4){
			scanf("%d%d%d",&l,&r,&k);
			printf("%d\n",getpre(1,1,n,l,r,k));
		}
		else{
			scanf("%d%d%d",&l,&r,&k);
			printf("%d\n",getpost(1,1,n,l,r,k));
		}
	}
	return 0;
}




