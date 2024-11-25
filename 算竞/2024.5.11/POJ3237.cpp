#include<bits/stdc++.h>

#define lc c[x][0]
#define rc c[x][1] 

using namespace std;

const int N = 2e4+5;
const int inf = 0x3f3f3f3f;
int top,fa[N],val[N],mx[N],mn[N],rev[N];
int n,ne[N],c[N][2],st[N];

void update(int x){
	int l = c[x][0],r = c[x][1];
	mx[x] = max(mx[l],mx[r]);
	mn[x] = min(mn[l],mn[r]);
	if(val[x]!=inf&&val[x]!=-inf){
		mx[x]=max(val[x],mx[x]);
		mn[x]=min(val[x],mn[x]);
	}
}

void Swap(int x){
	mx[x] = -mx[x],mn[x]=-mn[x];
	swap(mx[x],mn[x]);
}

void pushdown(int x){
	if(rev[x]){
		rev[lc]^=1,rev[rc]^=1,rev[x]=0;
		swap(lc,rc);
	}
	if(ne[x]){
		ne[lc]^=1,ne[rc]^=1,ne[x]=0;
		Swap(lc);
		Swap(rc);
	}
}

bool isroot(int x){
	return c[fa[x]][0]!=x&&c[fa[x]][1]!=x;
}

void rotate(int x){
	int y = fa[x],z =fa[y];
	int k = c[y][0]==x?1:0;
	if(!isroot(y))c[z][c[z][1]==y?1:0]=x;
	fa[x]=z,fa[y]=x,fa[c[x][k]]=y;
	c[y][k^1]=c[x][k],c[x][k]=y;
	update(y),update(x);
}

void splay(int x){
	st[top=1]=x;
	for(int i = x;!isroot(i);i=fa[i])st[++top]=fa[i];
	while(top)pushdown(st[top--]);
	while(!isroot(x)){
		int y = fa[x],z=fa[y];
		if(!isroot(y))(c[y][0]==x^c[z][0]==y)?rotate(x):rotate(y);
		rotate(x);
	}
}

void access(int x){
	for(int y = 0;x;y=x,x=fa[x]){
		splay(x),rc=y,update(x);
	}
}

void makeroot(int x){
	access(x),splay(x),rev[x]^=1;
}

void split(int x,int y){
	makeroot(x),access(y),splay(y); 
}

int findroot(int x){
	access(x),splay(x);
	while(lc)x=lc;
	return x;
}

void link(int x,int y){
	makeroot(x),fa[x]=y;
}

void change(int x,int w){
	splay(x);
	val[x] = w;
}

void query(int x,int y){
	split(x,y);
	printf("%d\n",mx[y]);
}

void neg(int x,int y){
	split(x,y);
	ne[y]^=1;
	Swap(y);
}

void init(){
    memset(c,0,sizeof(c));
	memset(fa,0,sizeof(fa));
    memset(rev,0,sizeof(rev));
    memset(ne,0,sizeof(ne));
    memset(val,0,sizeof(val));
}

int main(){
    int T,x,y,w;
    char opt[10];
    scanf("%d",&T);
	while(T--){
        init();
		scanf("%d",&n);
        mx[0]=-inf,mn[0]=inf;
		for(int i=1;i<n;i++){
            scanf("%d%d%d",&x,&y,&w);
            val[i]=-inf;
			val[n+i]=w;
            link(x,n+i);
            link(n+i,y);
        }
        val[n]=-inf;
        while(~scanf("%s",&opt)){
            if(opt[0]=='D') break;
            scanf("%d%d",&x,&y);
            if(opt[0]=='C') change(n+x,y);
            else if(opt[0]=='Q') query(x,y);
            else if(opt[0]=='N') neg(x,y);
        }
    }
    return 0;
}
