#include<bits/stdc++.h>
#define lc t[now].l
#define rc t[now].r
using namespace std;

const int N =1e5+5;
int n,tot,rt,a[N];
struct Treap{
	int l,r,size,key,id,val;
}t[N];

int getnewnode(int id,int val){
	t[++tot].key = rand();
	t[tot].id = id;
	t[tot].val =val;
	t[tot].size=1;
	return tot;
}

void update(int now){
	t[now].size = t[lc].size+t[rc].size+1;
}

void split(int now,int val,int &x,int &y){
	if(!now)x=y=0;
	else{
		if(t[now].val<=val){
			x = now;
			split(rc,val,rc,y);
		}else{
			y = now;
			split(lc,val,x,lc);
		}
		update(now);
	}
}

int merge(int x,int y){
	if(!x||!y)return x|y;
	if(t[x].key<t[y].key){
		t[x].r = merge(t[x].r,y);
		update(x);
		return x;
	}else{
		t[y].l = merge(x,t[y].l);
		update(y);
		return y;
	}
}

int x,y,z;

void ins(int id,int val){
	split(rt,val,x,y);
	rt = merge(merge(x,getnewnode(id,val)),y);
}

int getrank(int val){
	split(rt,val-1,x,y);
	int k = t[x].size+1;
	rt = merge(x,y);
	return k;
}

int kth(int k){
	int now = rt;
	while(now){
		if(t[lc].size+1==k)break;
		else if(t[lc].size+1<k){
			k-=t[lc].size+1;
			now = rc;
		}else{
			now = lc;
		}
	}
	return t[now].id;
}

int main(){
	int id,val,k,id1,id2;
	ins(1,100000);
	a[1] = 100000;
	while(~scanf("%d",&n)&&n){
		while(n--){
			scanf("%d%d",&id,&val);
			ins(id,val);
			a[id]=val;
			k = getrank(val);
			id1 = kth(k-1);
			id2 = kth(k+1);
			if(!id1||!id2){
				printf("%d %d\n",id,id1|id2);
			}else{
				if(a[id]-a[id1]<=a[id2]-a[id]) printf("%d %d\n",id,id1);
				else printf("%d %d\n",id,id2); 
			}
		}
	}
	return 0;
}



