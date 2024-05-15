#include<bits/stdc++.h>
#define lc t[now].l
#define rc t[now].r
using namespace std;
mt19937 rnd(114514);
const int N =3e4+5;
int a[N],tot,rt;
struct Treap{
	int l,r,sz,val,key;
}t[N];

int getnewnode(int val){
	t[++tot].sz =1;
	t[tot].key=rnd();
	t[tot].val = val;
	return tot;
}

void update(int now){
	t[now].sz = t[lc].sz +t[rc].sz+1;
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

void ins(int val){
	split(rt,val-1,x,y);
	rt = merge(merge(x,getnewnode(val)),y);
}

int kth(int k){
	int now = rt;
	while(now){
		if(t[lc].sz+1==k)break;
		else if(t[lc].sz+1<k){
			k-=t[lc].sz+1;
			now = rc;
		}else{
			now = lc;
		}
	}
	return t[now].val;
}

void ldr(int now){
	if(!now)return;
	ldr(lc);
	printf("%d ",t[now].val);
	ldr(rc);
}

int n,m;

int main(){
	cin>>n>>m; 
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	int j,now=0;
	for(int i = 1;i<=m;i++){
		scanf("%d",&j);
		while(now<j)ins(a[++now]);
		printf("%d\n",kth(i)); 
	}
	return 0;
}	
