#include<bits/stdc++.h>

using namespace std;

const int N = 3e4+5;
int n,m,val[N],head[N],cnt,size[N],fa[N],tot;
int top[N],dep[N],id[N],rev[N],Sum,Max,son[N];
struct edges{
	int to,nxt;
}e[N<<1];;

struct segtree{
	int mx,sum,l,r;
}t[N<<2];

void add(int u,int v){
	e[++cnt].to = v;
	e[cnt].nxt = head[u];
	head[u] = cnt;
}

void dfs1(int u,int f){
	size[u] = 1;
	for(int i = head[u];i;i = e[i].nxt){
		int v = e[i].to;
		if(v==f)continue;
		fa[v] = u;
		dep[v] = dep[u]+1;
		dfs1(v,u);
		size[u]+=size[v];
		if(size[v]>size[son[u]])son[u] = v;
	}
}

void dfs2(int u,int t){
	top[u] = t;
	id[u] = ++tot;
	rev[tot] = u;
	if(!son[u])return;
	dfs2(son[u],top[u]);
	for(int i = head[u];i;i = e[i].nxt){
		int v = e[i].to;
		if(v==fa[u]||v==son[u])continue;
		dfs2(v,v);
	}
}

void build(int k,int l,int r){
	t[k].l = l;
	t[k].r = r;
	if(l==r){
		t[k].mx = t[k].sum = val[rev[l]];
		return;
	}
	int mid,lc,rc;
	mid = (l+r)>>1;
	lc = k<<1,rc=k<<1|1;
	build(lc,l,mid);
	build(rc,mid+1,r);
	t[k].mx = max(t[lc].mx,t[rc].mx);
	t[k].sum = t[lc].sum+t[rc].sum;
}

void update(int k,int i,int val){
	if(t[k].l==t[k].r&&t[k].l == i){
		t[k].mx = t[k].sum = val;
		return;
	}
	int mid,lc,rc;
	mid = (t[k].l+t[k].r)>>1,lc=k<<1,rc=k<<1|1;
	if(i<=mid)update(lc,i,val);
	else update(rc,i,val);
	t[k].mx = max(t[lc].mx,t[rc].mx);
	t[k].sum = t[lc].sum+t[rc].sum;
}

void query(int k,int l,int r){
	if(l<=t[k].l&&r>=t[k].r){
		Max = max(Max,t[k].mx);
		Sum+=t[k].sum;
		return;
	}
	int lc = k<<1,rc = k<<1|1,mid = (t[k].l+t[k].r)>>1;
	if(l<=mid)query(lc,l,r);
	if(r>mid)query(rc,l,r);
}

void ask(int u,int v){
	while(top[u]!=top[v]){
		if(dep[top[u]]<dep[top[v]])swap(u,v);
		query(1,id[top[u]],id[u]);
		u = fa[top[u]];
	}
	if(dep[u]>dep[v])swap(u,v);
	query(1,id[u],id[v]);
}

int main(){
	scanf("%d",&n);
	int u,v,w;
	for(int i = 1;i<n;i++){
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	for(int i = 1;i<=n;i++){
		scanf("%d",val+i);
	}
	dep[1] = 1;
	dfs1(1,0);
	dfs2(1,1);
	build(1,1,n);
	char opt[10];
	scanf("%d",&m);
	while(m--){
		scanf("%s%d%d",opt,&u,&v);
		if(opt[0]=='C'){
			update(1,id[u],v);
		}else{
			Sum =0;
			Max = -0x3f3f3f3f;
			ask(u,v);
			if(opt[1]=='M'){
				printf("%d\n",Max);
			}else{
				printf("%d\n",Sum);
			}
		}
	}
	return 0;
}
