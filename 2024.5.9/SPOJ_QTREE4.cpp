#include<bits/stdc++.h>

using namespace std;

const int N = 2e5+5;
const int E = 4e6+5;
int n,q,ohead[N],rhead[N],ocnt,rcnt,S,cnt;
int mark[N],tail[N],rt,Max,midedge;
int sz[N];

struct point{
	int u,dis;
	point(){
	}
	point(int u,int dis):u(u),dis(dis){
	}
	bool operator<(const point& p)const{
		return dis<p.dis;
	}
};

struct node{
	int rt,midlen,ans;
	int ls,rs;
	priority_queue<point> q;
}T[N<<1];

struct Edges{
	int to,w,nxt,pre;
}oe[E],re[E];

void oinit(){
	memset(ohead,-1,sizeof(ohead));
	ocnt = 0;
}

void rinit(){
	memset(rhead,-1,sizeof(rhead));
	rcnt = 0;
}

void oadd(int u,int v,int w){
	oe[ocnt].to = v;
	oe[ocnt].w = w;
	oe[ocnt].nxt = ohead[u];
	ohead[u] = ocnt++;
}

void radd(int u,int v,int w){
	re[rcnt].to = v;
	re[rcnt].w = w;
	re[rcnt].nxt = rhead[u];
	rhead[u] = rcnt++;
}

void build(int u,int fa){
	int father = 0;
	for(int i = ohead[u];~i;i = oe[i].nxt){
		int v = oe[i].to,w = oe[i].w;
		if(v==fa)continue;
		if(!father){
			radd(u,v,w);
			radd(v,u,w);
			father = u;
		}else{
			mark[++S] = 0;
			radd(S,father,0);
			radd(father,S,0);
			father = S;
			radd(v,father,w);
			radd(father,v,w);
		}
		build(v,u);
	}
}

void Delete(int u,int i){
	if(rhead[u]==i)rhead[u]=re[i].nxt;
	else re[re[i].pre].nxt = re[i].nxt;
	if(tail[u]==i)tail[u]=re[i].pre;
	else re[re[i].nxt].pre = re[i].pre;
}

void get_pre(){
	memset(tail,-1,sizeof(tail));
	for(int i = 1;i<=S;i++){
		for(int j = rhead[i];~j;j = re[j].nxt){
			re[j].pre = tail[i];
			tail[i] = j;
		}
	}
}

void rebuild(){
	rinit();
	S = n;
	for(int i = 1;i<=S;i++)mark[i] = 1;
	build(1,0);
	get_pre();
	oinit();
}

void dfs_size(int u,int fa,int dis){
	oadd(u,rt,dis);
	if(mark[u])T[rt].q.push(point(u,dis));
	sz[u] = 1;
	for(int i = rhead[u];~i;i = re[i].nxt){
		int v = re[i].to,w = re[i].w;
		if(v==fa)continue;
		dfs_size(v,u,dis+w);
		sz[u]+=sz[v];
	}
}

void dfs_midedge(int u,int code){
	if(max(sz[u],sz[T[rt].rt]-sz[u])<Max){
		Max = max(sz[u],sz[T[rt].rt]-sz[u]);
		midedge = code;
	}
	for(int i  = rhead[u];~i;i = re[i].nxt){
		int v = re[i].to;
		if(i!=(code^1))dfs_midedge(v,i);
	}
}

void pushup(int id){
	T[id].ans = -1;
	while(!T[id].q.empty()&&mark[T[id].q.top().u]==0)T[id].q.pop();
	int ls = T[id].ls,rs = T[id].rs;
	if(!ls&&!rs){
		if(mark[T[id].rt])T[id].ans = 0;
		return;
	} 
	if(T[ls].ans>T[id].ans)//如果左儿子的结果大于根 
			T[id].ans=T[ls].ans;
        if(T[rs].ans>T[id].ans)//如果右儿子的结果大于根
			T[id].ans=T[rs].ans;
        if(!T[ls].q.empty()&&!T[rs].q.empty())//穿过中心边的
            T[id].ans=max(T[id].ans,T[ls].q.top().dis+T[rs].q.top().dis+T[id].midlen);
}

void DFS(int id,int u){
	rt = id,Max = S,midedge = -1;
	T[id].rt = u;
	dfs_size(u,0,0);
	dfs_midedge(u,-1);
	if(~midedge){
		int p1 = re[midedge].to;
		int p2 = re[midedge^1].to;
		T[id].midlen = re[midedge].w;
		T[id].ls = ++cnt;
		T[id].rs = ++cnt;
		Delete(p1,midedge^1);
		Delete(p2,midedge);
		DFS(T[id].ls,p1);
		DFS(T[id].rs,p2);
	}
	pushup(id); 
}

void update(int u){
	mark[u]^=1;
	for(int i = ohead[u];~i;i = oe[i].nxt){
		int v = oe[i].to,w = oe[i].w;
		if(mark[u])T[v].q.push(point(u,w));
		pushup(v);
	}
}

int main(){
	oinit();
	scanf("%d",&n);
	int u,v,w,x;
	for(int i = 1;i<n;i++){
		scanf("%d%d%d",&u,&v,&w);
		oadd(u,v,w);
		oadd(v,u,w);
	}
	rebuild();
	DFS(cnt = 1,1);
	char opt[2];
	scanf("%d",&q);
	while(q--){
		scanf("%s",opt);
		if(opt[0]=='A'){
			if(T[1].ans == -1)printf("They have disappeared.\n");
			else printf("%d\n",T[1].ans);
		}else{
			scanf("%d",&x);
			update(x);
		}
	}
	return 0;
}




