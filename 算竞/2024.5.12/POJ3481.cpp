#include<bits/stdc++.h>
#include<random>
#define lc t[now].l
#define rc t[now].r
using namespace std;

const int N =1e6+6;
int cnt,rt;
struct Treap{
	int l,r,pri,val,key;
}t[N];

std::mt19937 rnd(114514);

int getnewnode(int val,int pri){
	t[++cnt].pri = pri;
	t[cnt].val = val;
	t[cnt].key = rnd();
	return cnt;
}

void split(int now,int pri,int &x,int &y){
	if(!now)x=y=0;
	else{
		if(t[now].pri<=pri){
			x = now;
			split(rc,pri,rc,y);
		}else{
			y = now;
			split(lc,pri,x,lc);
		}
	}
}

int merge(int x,int y){
	if(!x||!y)return x+y;
	if(t[x].key>t[y].key){
		t[x].r = merge(t[x].r,y);
		return x;
	}else{
		t[y].l = merge(x,t[y].l);
		return y;
	}
}

int x,y,z;

void ins(int val,int pri){
	split(rt,pri,x,y);
	rt = merge(merge(x,getnewnode(val,pri)),y);
}

void del(int pri){
	split(rt,pri,x,z);
	split(x,pri-1,x,y);
	y = merge(t[y].l,t[y].r);
	rt = merge(merge(x,y),z);
}

void findmax(){
	int now = rt;
	while(rc)now=rc;
	printf("%d\n",t[now].val);
	del(t[now].pri);
}

void findmin(){
	int now = rt;
	while(lc)now =lc;
	printf("%d\n",t[now].val);
	del(t[now].pri);
}

void lds(int now){
	if(!now)return;
	lds(lc);
	printf("%d ",t[now].pri);
	lds(rc);
}

int main(){
	int opt,k,p;
	while(scanf("%d",&opt)&&opt){
		switch(opt){
			case 1:
				scanf("%d%d",&k,&p);
				ins(k,p);
				break;
			case 2:
				findmax();
				break;
			case 3:
				findmin();
				break;
		}		
	}
	return 0;
}



