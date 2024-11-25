#include<bits/stdc++.h>
#define ls t[x].c[0]
#define rs t[x].c[1]
#define lc x<<1
#define rc x<<1|1
using namespace std;
const int inf = 0x7fffffff;
const int N = 5e4+10;
const int M = 1e7;
int n,m,cnt,v[N];
struct Node{
	int c[2],size,key,val;
}t[M];

struct Treap{
	int rt;
	int getnewnode(int val){
		t[++cnt].val = val;
		t[cnt].key = rand();
		t[cnt].size = 1;
		return cnt;
	}
	void update(int x){
		t[x].size = t[ls].size+t[rs].size+1;
	}
	void split(int x,int val,int &t1,int &t2){
		if(!x)t1=t2=0;
		else{
			if(t[x].val<=val){
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
		while(rs)x=rs;
		rt = merge(y,z);
		return x?t[x].val:-inf;
	}
	int getpost(int val){
		split(rt,val,y,z);
		x = z;
		while(ls)x=ls;
		rt = merge(y,z);
		return x?t[x].val:inf;
	}
	int getrank(int val){
		split(rt,val-1,x,y);
		int ans = t[x].size+1;
		rt = merge(x,y);
		return ans;
	}
}a[N<<2]; 

void build(int x,int l,int r){
	a[x].rt = 0;
	for(int i = l;i<=r;i++){
		a[x].ins(v[i]);
	}	
	if(l==r)return;
	int mid = (l+r)>>1;
	build(lc,l,mid);
	build(rc,mid+1,r);
}

int getpre(int x,int l,int r,int L,int R,int val){
	if(l>R||r<L)return -inf;
	if(l>=L&&r<=R)return a[x].getpre(val);
	if(l==r)return -inf;
	int mid = (l+r)>>1;
	int ans = getpre(lc,l,mid,L,R,val);
	ans = max(ans,getpre(rc,mid+1,r,L,R,val));
	return ans;
}

int getpost(int x,int l,int r,int L,int R,int val){
	if(l>R||r<L)return inf;
	if(l>=L&&r<=R)return a[x].getpost(val);
	if(l==r)return inf;
	int mid = (l+r)>>1;
	int ans = getpost(lc,l,mid,L,R,val);
	ans = min(ans,getpost(rc,mid+1,r,L,R,val));
	return ans;
}

int getrank(int x,int l,int r,int L,int R,int val){
	if(l>R||r<L)return 0;
	if(l>=L&&r<=R)return a[x].getrank(val)-1;
	if(l==r)return 0;
	int mid = (l+r)>>1;
	int ans = getrank(lc,l,mid,L,R,val);
	ans += getrank(rc,mid+1,r,L,R,val);
	return ans;
}

void revise(int x,int l,int r,int pos,int val){
	if(pos<l||pos>r)return;
	a[x].del(v[pos]);
	a[x].ins(val);
	if(l==r)return;
	int mid = (l+r)>>1;
	revise(lc,l,mid,pos,val);
	revise(rc,mid+1,r,pos,val);
}

int kth(int L,int R,int k){
	int l = 0,r = (int)1e8,mid=(l+r)>>1,ans = -1,s;
	while(l<=r){
		s = getrank(1,1,n,L,R,mid)+1;
	///	printf("%d %d %d %d\n",l,mid,r,s);
		if(s<=k)l = mid+1,ans = mid;
		else r = mid-1;
		mid = (l+r)>>1;
	}
	return ans;
}

int read(){
	int ret = 0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9'){
		ret = ret*10+ch-'0';
		ch = getchar();
	}	
	return ret;
}

int main(){
	cnt = 0;
	int opt,l,r,pos,k,val;
	n = read(),m=read();
	for(int i = 1;i<=n;i++)v[i]=read();
	build(1,1,n);
	while(m--){
		opt=read();
		switch(opt){
			case 1:
				l=read(),r=read(),val=read();
				printf("%d\n",getrank(1,1,n,l,r,val)+1);
				break;
			case 2:
				l=read(),r=read(),k=read();
				printf("%d\n",kth(l,r,k));
				break;
			case 3:
				pos=read(),val=read();
				revise(1,1,n,pos,val);
				v[pos]=val;
				break;
			case 4:
				l=read(),r=read(),val=read();
				printf("%d\n",getpre(1,1,n,l,r,val));
				break;
			case 5:
				l=read(),r=read(),val=read();
				printf("%d\n",getpost(1,1,n,l,r,val));
				break;
		}	
	}
	return 0;
}
