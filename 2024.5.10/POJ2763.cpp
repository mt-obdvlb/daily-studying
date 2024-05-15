#include<bits/stdc++.h>

using namespace std;

const int N =1e5+5;
int n,q,cnt,tot,s,fa[N],top[N],head[N];
int rev[N],id[N],size[N],dep[N],son[N],Sum;
struct edges{
	int to,nxt;
}e[N<<1];

struct Edegs{
	int u,v,w;
}a[N<<1];

struct segtree{
	int l,r,sum;
}t[N<<2];

void dfs1(int u,int f){
	size[u]=1;
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
	top[u] = u;
	id[u] = ++tot;
	rev[tot] = u;
	if(!son[u])return;
	dfs2(son[u],t);
	for(int i = head[u];i;i = e[i].nxt){
		int v = e[i].to;
		if(v==fa[u]||v==son[u])continue;
		dfs2(v,v);
	}
}

void init(){
	cnt = tot=0;
	memset(head,0,sizeof(head));
	memset(son,0,sizeof(son));
}

void add(int u,int v){
	e[++cnt].nxt = head[u];
	e[cnt].to = v;
	head[u] = cnt;
}

void build(int k,int l,int r){
	t[k].l = l,t[k].r = r,t[k].sum = 0;
	if(l==r)return;
	int lc,rc,mid;
	lc = k<<1,rc=k<<1|1,mid =(l+r)>>1;
	build(lc,l,mid);
	build(rc,mid+1,r);
}

void update(int k,int i,int w){
	if(t[k].l==i&&t[k].r == i){
		t[k].sum = w;
		return;
	}
	int mid = (t[k].l+t[k].r)>>1;
	if(i<=mid)update(k<<1,i,w);
	else update(k<<1|1,i,w);
	t[k].sum = t[k<<1].sum+t[k<<1|1].sum;
}

void query(int k,int l,int r){
	if(l<=t[k].l&&r>=t[k].r){
		Sum+=t[k].sum;
		return;
	}
	int mid = (t[k].l+t[k].r)>>1;
	if(l<=mid)query(k<<1,l,r);
	if(r>mid)query(k<<1|1,l,r);
}

void ask(int u,int v){
	while(top[u]!=top[v]){
		if(dep[top[u]]<dep[top[v]])swap(u,v);
		query(1,id[top[u]],id[u]);
		u = fa[top[u]];
	}
	if(u==v)return;
	if(dep[u]>dep[v])swap(u,v);
	query(1,id[son[u]],id[v]);
}

int main(){
	cin>>n>>q>>s; 
	int u,v,w,x,y,op;
	for(int i = 1;i<n;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;	
		add(a[i].u,a[i].v);
		add(a[i].v,a[i].u);
	}
	dep[1] = 1;
	dfs1(1,0);
	dfs2(1,1);
	build(1,1,n);
	for(int i = 1;i<n;i++){
		if(dep[a[i].u]>dep[a[i].v])swap(a[i].u,a[i].v);
		update(1,id[a[i].v],a[i].w);
	}
	while(q--){
		cin>>op;
		if(op){
			cin>>x>>y;
			update(1,id[a[x].v],y);
		}else{
			cin>>u;
			Sum = 0;
			ask(s,u);
			cout<<Sum<<endl;
			s = u;
		}
	}
	return 0;
}


