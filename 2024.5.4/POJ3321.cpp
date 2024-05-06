#include<bits/stdc++.h>

using namespace std;

const int maxn = 100005;
int dfn,cnt,head[maxn],c[maxn],a[maxn],l[maxn],r[maxn];
int n,m;
struct edges{
	int u,v,nxt;
}e[maxn];

int lowbit(int i){
	return i&(-i);
}

void adde(int u,int v){
	e[++cnt].u = u;
	e[cnt].v = v;
	e[cnt].nxt = head[u];
	head[u] = cnt;
}

void add(int i,int v){
	for(;i<=n;i+=lowbit(i))c[i]+=v;
}

int sum(int i){
	int s = 0;
	while(i>0){
		s+=c[i];
		i-=lowbit(i);
	}
	return s;
}

void dfs(int u,int fa){
	l[u] = dfn++;
	for(int i = head[u];i;i=e[i].nxt){
		int v = e[i].v;
		if(v==fa)continue;
		dfs(v,u);
	}
	r[u] = dfn - 1;
}

int main(){
	cin>>n;
	int u,v,x;
	for(int i = 1;i<=n;i++){
		a[i] = 1;
		add(i,1);
	}
	for(int i = 1;i<n;i++){
		cin>>u>>v;
		adde(u,v);
	}
	dfn = 1;
	dfs(1,1);
	cin>>m;
	char op;
	while(m--){
		cin>>op>>x;
		if(op=='C'){
			if(a[l[x]])add(l[x],-1);
			else add(l[x],1);
			a[l[x]]^=1;
		}else{
			int s1 = sum(r[x]);
			int s2 = sum(l[x]-1);
			printf("%d\n",s1-s2);
		}
	} 
	return 0;
}
