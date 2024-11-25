#include<bits/stdc++.h>

using namespace std;

const int NN = 4e4+5;
const int NE = 4e5+5;

int n,k,midedge,rt,Max;
int head[NN],Head[NN],tot,rear,cnt,S;
int sz[NN],mark[NN],tail[NN],len[NN];

struct Edges{
	int v,nxt,pre,w;
}e[NE],E[NE];

struct node{
	int rt,ls,rs,midlen;	
}T[NN];

void add(int u,int v,int w){
	e[tot].v = v;
	e[tot].w = w;
	e[tot].nxt = head[u];
	head[u] = tot++;
}

void Add(int u,int v,int w){
	E[rear].v = v;
	E[rear].w = w;
	E[rear].nxt = Head[u];
	Head[u] = rear++;
}

void init(){
	memset(head,-1,sizeof(head));
	tot = 0;
}

void Init(){
	memset(Head,-1,sizeof(Head));
	rear = 0;
}

void get_pre(){
	memset(tail,-1,sizeof(tail));
	for(int i = 1;i<=S;i++){
		for(int j = Head[i];~j;j = E[j].nxt){
			E[j].pre = tail[i];
			tail[i] = j;			
		}
	}
}

void build(int u,int fa){
	int father = 0;
	for(int i = head[u];~i;i = e[i].nxt){
		int v = e[i].v,w = e[i].w;
		if(v==fa)continue;
		if(!father){
			Add(u,v,w);
			Add(v,u,w);
			father = v;
		}else{
			mark[++S] = 0;
			Add(S,father,0);
			Add(father,S,0);
			father = S;
			Add(v,father,0);
			Add(father,v,0);
		}
		build(v,u);
	}
}

void rebuild(){
	Init();
	S = n;
	for(int i = 1;i<=S;i++)mark[i] = 1;
	build(1,0);
	get_pre();
}

void dfs_size(int u,int fa,int dir,int flag){
	if(mark[u])q[flag][len[flag]++]=dir;
	
}

int getmide(int id,int u,int flag){
	Max = S,midedge = -1;
	rt = id,T[id].rt = u;
	len[flag] = 0;
	dfs_size(u,0,0,flag);
	dfs_midedge(u,-1);
	return midedge;
}

int main(){
	int u,v,w;
	while(scanf("%d%d",&n,&k)&&n&&k){
		init();
		for(int i = 1;i<n;i++){
			scanf("%d%d%d",&u,&v,&w);
			add(u,v,w);
			add(v,u,w);
		}	
		int ans = 0;
		if(n>1){
			rebuild();
			rt = 1;
			T[rt].rt = 1;
			len[0] = 0;
			cnt = 1;
			int t = getmide(1,1,0);
		}
	}
	return 0;
}
