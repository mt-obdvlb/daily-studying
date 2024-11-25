#include<bits/stdc++.h>
#define lc t[x].c[0]
#define rc t[x].c[1]
using namespace std;

const int N = 1e5+5;
int tot,rt;
struct Splay{
	int c[2],fa,id,val;
}t[N];

void rotate(int x,int goal){
	int y = t[x].fa,z = t[y].fa;
	int k = t[y].c[0]==x?1:0;
	if(z!=goal)t[z].c[t[z].c[1]==y?1:0]=x;
	t[x].fa=z,t[y].fa =x,t[t[x].c[k]].fa=y;
	t[y].c[k^1]=t[x].c[k],t[x].c[k]=y;
}

void splay(int x,int goal){
	while(t[x].fa!=goal){
		int y = t[x].fa,z=t[y].fa;
		if(z!=goal) (t[y].c[0]==x^t[z].c[0]==y)?rotate(x,goal):rotate(y,goal);
		rotate(x,goal);
	} 
	if(!goal)rt = x;
} 

void ins(int id,int val){
	int x = rt,fa = rt;
	while(x){
		if(t[x].val<=val){
			fa = x;
			x = rc;
		}else{
			fa = x;
			x = lc;
		}
	}
	t[++tot].fa =fa;
	t[tot].val = val;
	t[tot].id = id;
	if(!fa)t[fa].c[t[fa].val<=val?1:0]=tot;
	splay(tot,0);
}

void del(int val){
	int x = rt;
	while(x){
		if(t[x].val==val)break;
		else if(t[x].val<val)x=rc;
		else x = lc;
	}
	splay(x,0);
	if(!lc&&!rc){
		rt = 0;
		return;
	}
	if(!lc||!rc){
		int k = lc|rc;
		lc = rc = 0;
		t[k].fa=0;
		rt = k;
		return;
	}
	int t1=lc , t2=rc ,y = lc;
	t[lc].fa = 0,t[rc].fa = 0,lc=rc=0;
	while(t[y].c[1])y = t[y].c[1];
	splay(y,0);
	t[y].c[1]=t2;
	t[t2].fa = y;
}

void findmin(){
	int x = rt;
	while(rc)x=rc;
	printf("%d\n",t[x].id);
	del(t[x].val);
}

void findmax(){
	int x = rt;
	while(lc)x=lc;
	printf("%d\n",t[x].id);
	del(t[x].val);
}

void ldr(int x){
	if(!x)return;
	ldr(lc);
	printf("%d ",t[x].val);
	ldr(rc);
}

int main(){
	int opt,k,p;
	while(~scanf("%d",&opt)&&opt){
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
		ldr(rt);
		cout<<endl;
	}	
	return 0;
}
