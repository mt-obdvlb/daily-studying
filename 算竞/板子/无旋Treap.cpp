#include<bits/stdc++.h>
#define lc t[now].l
#define rc t[now].r
using namespace std;
const int N = 1e5+5;
struct Treap{
	int l,r,sz,val,key,rev;
}t[N]; 
int rt,cnt=0,x,y,z;

int getnewnode(int val){
	t[++cnt].val=val;
	t[cnt].key=rand();
	t[cnt].sz=1;
	t[cnt].l = t[cnt].r = 0;
	return cnt;
}

void update(int now){
	t[now].sz = t[lc].sz + t[rc].sz +1;
}

void pushdown(int now){
	if(t[now].rev){
		t[now].rev=0;
		swap(lc,rc);
		t[lc].rev^=1,t[rc].rev^=1;
	}
}

void split1(int now,int val,int &x,int &y){
	if(!now)x=y=0;
	else{
		pushdown(now);
		if(t[now].val<=val){
			x = now;
			split1(rc,val,rc,y);
		}else{
			y = now;
			split1(lc,val,x,lc);
		} 
		update(now);
	}
}

void split2(int now,int sz,int &x,int &y){
	if(!now)x=y=0;
	else{
		pushdown(now);
		if(t[now].sz<sz){
			x = now;
			split2(rc,sz-t[lc].sz-1,rc,y);
		}else{
			y = now;
			split2(lc,sz,x,lc);
		}
		update(now);
	}	
}

int merge(int x,int y){
	if(!x||!y)return x|y;
	if(t[x].key<t[y].key){
		pushdown(x);
		t[x].r = merge(t[x].r,y);
		update(x);
		return x;
	}else{
		pushdown(y);
		t[y].l = merge(x,t[y].l);
		update(y);
		return y;
	}
}

void reverse(int l,int r){
	split2(rt,l-1,x,y);
	split2(y,r-l+1,y,z);
	t[y].rev^=1;
	rt = merge(merge(x,y),z);
}

void ins(int val){
	split1(rt,val,x,y);
	rt = merge(merge(x,getnewnode(val)),y);
}

int getrank(int val){
	split1(rt,val-1,x,y);
	int ans = t[x].sz+1;
	rt = merge(x,y);
	return ans;
}

int kth(int rk){
	int now = rt;
	int ans = -1;
	while(now){
		if(t[lc].sz+1==rk){
			ans = t[now].val;
			break;
		}else if(t[lc].sz+1>rk){
			now = lc;
		}else{
			rk -= t[lc].sz+1;
			now = rc;
		}
	}
	return ans;
}

int main(){
	//1 2 2 2 3 3 6 7 8 10
	int a[10]={3,2,1,6,2,7,3,8,10,2};
	for(int i = 0;i<10;i++){
		ins(a[i]);
	}
	int k;
	while(cin>>k){
		cout<<kth(k)<<endl;;
		
	}
	return 0;
}
