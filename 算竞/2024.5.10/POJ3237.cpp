#include<bits/stdc++.h>


#define lc k<<1
#define rc k<<1|1

using namespace std;

const int inf = 0x3f3f3f3f;
const int N =1e4+5;
int n,tot,cnt,head[N],top[N],id[N],rev[N];
int size[N],son[N],fa[N],dep[N],ans;
struct Data{
	int u,v,w;
}a[N];

struct edges{
	int to,nxt;
}e[N<<1];

struct segtree{
	int lazytag,l,r,Max,Min;
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

void init(){
	memset(son,0,sizeof(son));
	memset(head,0,sizeof(head));
	cnt = tot  = 0;
}

void dfs2(int u,int t){
	top[u] = t;
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

void build(int k,int l,int r){
	t[k].l = l,t[k].r = r,t[k].Max = -inf,
	t[k].Min=inf,t[k].lazytag = 0;
	if(l==r)return;
	int mid = (l+r)>>1;
	build(lc,l,mid);
	build(rc,mid+1,r);
}

void Swap(int k){
	int tmp = t[k].Max;
	t[k].Max = -t[k].Min;
	t[k].Min = -tmp;
}

void pushdown(int k){
	if(t[k].l==t[k].r)return;
	if(t[k].lazytag){
		t[lc].lazytag ^=1;
		t[rc].lazytag ^=1;
		Swap(k<<1),Swap(k<<1|1);
		t[k].lazytag = 0;
	}
}

void pushup(int k){
	t[k].Max = max(t[lc].Max,t[rc].Max);
	t[k].Min = min(t[lc].Min,t[rc].Min);
}

void _Negate(int k,int l,int r){
	if(l<=t[k].l&&r>=t[k].r){
		t[k].lazytag^=1;
		Swap(k);	
		return;
	}
	pushdown(k);
	int mid = (t[k].l+t[k].r)>>1;
	if(l<=mid)_Negate(lc,l,r);
	if(r>mid)_Negate(rc,l,r);
	pushup(k);
}

void Negate(int u,int v){
	while(top[u]!=top[v]){
		if(dep[top[u]]<dep[top[v]])swap(u,v);
		_Negate(1,id[top[u]],id[u]);
		u = fa[top[u]];
	}
	if(u==v)return;
	if(dep[u]>dep[v])swap(u,v);
	_Negate(1,id[son[u]],id[v]);
}

void update(int k,int i,int w){
	if(t[k].l==i&&t[k].r==i){
		t[k].Max = t[k].Min = w;
		return;
	}
	pushdown(k);
	int mid = (t[k].l+t[k].r)>>1;
	if(i<=mid)update(lc,i,w);
	else update(rc,i,w);
	pushup(k);
}

void query(int k,int l,int r){
	if(t[k].l>=l&&t[k].r<=r){
		ans = max(ans,t[k].Max);
		return;
	}
	pushdown(k);
	int mid = (t[k].l+t[k].r)>>1;
	if(l<=mid)query(lc,l,r);
	if(r>mid)query(rc,l,r);
	pushup(k);
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
	int T,x,y;	
	cin>>T;
	char opt[10];
	while(T--){
		init();
		scanf("%d",&n);	
		for(int i = 1;i<n;i++){
			scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
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
		while(scanf("%s",opt)&&opt[0]!='D'&&scanf("%d%d",&x,&y)){
			if(opt[0]=='C'){
				update(1,id[a[x].v],y);
			}else if(opt[0]=='N'){
				Negate(x,y);
			}else{
				ans = -0x3f3f3f3f;
				ask(x,y);
				cout<<ans<<endl;
			}
		}
	}
	return 0;
}
