#include<bits/stdc++.h>
#include<random> 
#define lc t[now].l
#define rc t[now].r
using namespace std;

const long long N = 1e5+5;
long long cnt,rt;

struct Node{
	long long l,r,key,val,size;
}t[N];

std::mt19937 rnd(233);

inline long long getNewNode(long long val){
	t[++cnt].val=val;
	t[cnt].key = rnd();
	t[cnt].size = 1;
	t[cnt].l=t[cnt].r = 0; 
	return cnt;
} 

void update(long long now){
	t[now].size = t[lc].size+t[rc].size+1;
}
 
void split(long long now,long long val,long long &x,long long &y){
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

long long merge(long long x,long long y){
	if(!x||!y)return x+y;
	if(t[x].key>t[y].key){
		t[x].r = merge(t[x].r,y);
		update(x);
		return x;	
	}else{
		t[y].l = merge(x,t[y].l);
		update(y);
		return y;
	}
} 


long long x,y,z;
void ins(long long val){
	split(rt,val,x,y);
	rt = merge(merge(x,getNewNode(val)),y);
}

void del(long long val){
	split(rt,val,x,z);
	split(x,val-1,x,y);
	y = merge(t[y].l,t[y].r);
	rt = merge(merge(x,y),z);
}
 
void getrank(long long val){
	split(rt,val-1,x,y);
	printf("%lld\n",t[x].size+1);
	rt = merge(x,y);
}

void kth(long long rank){
	long long now =rt;
	while(now){
		if(t[t[now].l].size+1==rank)break;
		else if(t[t[now].l].size>=rank)now =t[now].l;
		else{
			rank -=t[t[now].l].size+1;
			now = t[now].r;
		}
	}
	printf("%lld\n",t[now].val);
}

void pre(long long val){
	split(rt,val-1,x,y);
	long long now = x;
	while(t[now].r)now=t[now].r;
	printf("%lld\n",t[now].val);
	rt = merge(x,y); 
}

void post(long long val){
	split(rt,val,x,y);
	long long now = y;
	while(t[now].l)now =t[now].l;
	printf("%lld\n",t[now].val);
	rt = merge(x,y);
}


int main(){
	t[0].size=0;
	long long t,opt,a,b;
	cin>>t;
	while(t--){
		scanf("%lld%lld",&opt,&a);
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
				kth(a);
				break;
			case 5:
				pre(a);
				break;
			case 6:
				post(a);
				break;
		}
	}
	
	return 0;
}





