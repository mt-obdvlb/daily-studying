#include<bits/stdc++.h>

#define lc c[x][0]
#define rc c[x][1]

using namespace std;

const int N =3e5+5;
int n,a[N],top,fa[N];
int st[N],rev[N],c[N][2],mx[N],add[N];

void pushdown(int x){
    int l=c[x][0],r=c[x][1];
    if(rev[x]){
        rev[l]^=1;rev[r]^=1;rev[x]^=1;
        swap(c[x][0],c[x][1]);
    }
    if(add[x]){
        if(l){add[l]+=add[x];mx[l]+=add[x];a[l]+=add[x];}
        if(r){add[r]+=add[x];mx[r]+=add[x];a[r]+=add[x];}
        add[x]=0;
    }
}

void update(int x){
	mx[x] = max(a[x],max(mx[lc],mx[rc]));
}

bool isroot(int x){
	return c[fa[x]][0]!=x&&c[fa[x]][1]!=x;
}

void rotate(int x){
	int y = fa[x],z = fa[y];
	int k = x==c[y][0]?1:0;
	if(!isroot(y))c[z][c[z][1]==y?1:0]=x;
	fa[x] =z,fa[y] = x,fa[c[x][k]]=y;
	c[y][k^1]=c[x][k],c[x][k]=y;
	update(y),update(x);
}

void splay(int x){
	st[top=1]=x;
	for(int i = x;!isroot(i);i = fa[i])st[++top]=fa[i];
	while(top)pushdown(st[top--]);
	while(!isroot(x)){
		int y = fa[x],z = fa[y];
		if(!isroot(y)) (c[y][0]==x)^(c[z][0]==y)?rotate(x):rotate(y);
		rotate(x);
	} 
}

void access(int x){
	for(int y = 0;x;y = x,x =fa[x]){
		splay(x),rc=y,update(x);
	}
}

void makeroot(int x){
	access(x),splay(x),rev[x]^=1;
}

int findroot(int x){
	access(x),splay(x);
	while(lc) x= lc;
	return x;
} 

void link(int x,int y){
	makeroot(x),fa[x] = y;
}

void split(int x,int y){
	makeroot(x),access(y),splay(y);
}

void cut(int x,int y){
	split(x,y);
	c[y][0]=fa[c[y][0]]=0,update(y);
}

void addval(int x,int y,int w){
	split(x,y);
	add[y]+=w,mx[y]+=w,a[y]+=w;
}

#define P printf("-1\n")
#define inf 0x3f3f3f3f

int main(){
	int opt,x,y,w,m;
	while(~scanf("%d",&n)){
        for(int i=0;i<=n;i++)
            add[i]=rev[i]=fa[i]=c[i][0]=c[i][1]=0;
        mx[0]=-inf;
        for(int i=1;i<n;i++){
            scanf("%d%d",&x,&y);
            link(x,y);
        }
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),mx[i]=a[i];
        scanf("%d",&m);
        while(m--){
            scanf("%d%d%d",&opt,&x,&y);
			switch(opt){
            case 1:
                if(findroot(x)==findroot(y)) {puts("-1");break;}
                link(x,y);break;
            case 2:
                if(findroot(x)!=findroot(y)||x==y) {puts("-1");break;}
				cut(x,y);break;
            case 3:
				w=x;x=y;scanf("%d",&y);
				if(findroot(x)!=findroot(y)) {puts("-1");break;}
                addval(x,y,w);break;
            case 4:
                if(findroot(x)!=findroot(y)) {puts("-1");break;}
                split(x,y);printf("%d\n",mx[y]);break;
            }
        }
		puts("");
    }
	return 0;
}
