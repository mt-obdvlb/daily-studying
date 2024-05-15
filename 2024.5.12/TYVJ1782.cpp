#include<bits/stdc++.h>
#define lc t[now].l
#define rc t[now].r
using namespace std;
mt19937 rnd(114514);
const int N =1e5+5;
int tot,rt;
struct Treap{
	int l,r,size,val,key,cnt;
}t[N];

int getnewnode(int val){
	t[++tot].val =val;
	t[tot].key = rnd();
	t[tot].size = 1;
	t[tot].cnt = 1;
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

void ins(int val){
	split(rt,val,x,y);
	int tmp = x;
	while(t[tmp].r)tmp = t[tmp].r;
	if(t[tmp].val==val){
		t[tmp].cnt++,t[tmp].size++;
		rt = merge(x,y);
	}else{
		rt = merge(merge(x,getnewnode(val)),y);
	}
}

void del(int val){
	split(rt,val,x,z);
	split(x,val-1,x,y);
	if(--t[y].cnt){
		t[y].size--;
		rt = merge(merge(x,y),z);		
	}else{
		rt = merge(x,z);
	}
}

void getnum(int rank){
	int now = rt;
	while(now){
		if(rank>=t[lc].size+1&&rank<=t[lc].size+t[now].cnt)break;
		else if(rank<t[lc].size+1){
			rank-=t[lc].size+1;
			now = rc;
		}else{
			now = lc;
		}
	}
	printf("%d\n",t[now].val);
}

void getrank(int val){
	split(rt,val,x,z);
	split(x,val-1,x,y);
	printf("%d\n",t[x].size+1);
	rt = merge(merge(x,y),z);
}

void getpre(int val){
	split(rt,val,x,z);
	split(rt,val-1,x,y);
	int now =x;
	while(rc)now=rc;
	printf("%d\n",t[now].val);
	rt = merge(merge(x,y),z);
}

void getpost(int val){
	split(rt,val,x,y);
	int now = y;
	while(lc)now=lc;
	printf("%d\n",t[now].val);
	rt = merge(x,y);
}

int main(){
	int n,opt,a;
	scanf("%d",&n);
	while(n--){
		scanf("%d%d",&opt,&a);
		switch(opt){
			case 1:
				ins(a);
				break;
			case 2:
				del(a);
				break;
			case 3:
				getrank(a);
				break;
			case 4:
				getnum(a);
				break;
			case 5:
				getpre(a);
				break;
			case 6:
				getpost(a);
				break;
		}
	}
	return 0;
}
