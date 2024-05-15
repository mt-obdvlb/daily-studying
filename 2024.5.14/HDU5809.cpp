#include<iostream>
#include<algorithm>
#define lc (rt<<1)
#define rc (rt<<1|1)
#define sq(x) ((x)*(x))
using namespace std;
typedef long long ll;
const int N = 1e5+5;
const ll inf = 1e18;
int n,q,idx,sz[N<<2],fa[N];
struct Node{
	int x[2],id;
	bool operator<(const Node &b)const{
		return x[idx]<b.x[idx];
	}
}a[N],b[N],kd[N<<2];
typedef pair<ll,Node> PLN;
PLN ans;
void build(int rt,int l,int r,int dep){
	if(l>r)return;
	int mid =(l+r)>>1;
	idx = dep%2;
	nth_element(a+l,a+mid,a+r+1,[&](const Node& a,const Node& b)->bool{
		return a.x[idx]<b.x[idx];
	});
	kd[rt] = a[mid];
	sz[rt]=1;
	sz[lc]=sz[rc]=0;
	build(lc,l,mid-1,dep+1);
	build(rc,mid+1,r,dep+1);
}

ll getdis(int rt,Node &p){
	return sq((ll)kd[rt].x[0]-p.x[0])+sq((ll)kd[rt].x[1]-p.x[1])?
	sq((ll)kd[rt].x[0]-p.x[0])+sq((ll)kd[rt].x[1]-p.x[1]):inf;
}

void query(int rt,int dep,Node &p){
	if(!sz[rt])return;
	ll flag=0,dis = getdis(rt,p);
	idx = dep%2;
	ll rd = sq((ll)kd[rt].x[idx]-p.x[idx]);
	int l = lc,r = rc;
	if(p.x[idx]>=kd[rt].x[idx])swap(l,r);
	query(l,dep+1,p);
	if(dis<ans.first)ans = PLN(dis,kd[rt]),flag = 1;
	else if(dis==ans.first){
		if(kd[rt].x[0]<ans.second.x[0]||
		(kd[rt].x[0]==ans.second.x[0]&&kd[rt].x[1]<ans.second.x[1]))
		ans = PLN(dis,kd[rt]);
		if(rd<=ans.first)flag =1;
	}
	if(flag)query(r,dep+1,p);
}

int get(int x){
	return fa[x]==x?x:fa[x]=get(fa[x]);
}

void merge(int a,int b){
	int af = get(a),bf = get(b);
	if(af==bf)return;
	fa[af] = bf;
}

int main(){
	int T;
	cin>>T;
	for(int tt = 1;tt<=T;tt++){
		scanf("%d%d",&n,&q);
		for(int i = 1;i<=n;i++)fa[i]=i;
		for(int i = 1;i<=n;i++){
			for(int j = 0;j<2;j++)scanf("%d",&a[i].x[j]);
			a[i].id = i;
			b[i] = a[i];
		}
		build(1,1,n,0);
		for(int i = 1;i<=n;i++){
			ans = PLN(inf,b[i]);
			query(1,0,b[i]);
			merge(i,ans.second.id);
		}
		int i,j;
		printf("Case #%d:\n",tt);		
		while(q--){
			scanf("%d%d",&i,&j);
			if(get(i)==get(j))printf("YES\n");
			else printf("NO\n");
		}
	}
	return 0;
}
