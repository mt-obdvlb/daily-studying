#include<bits/stdc++.h>

using namespace std;
const int N = 1e5;
int n,tot,rt,dfn[N],low[N],head[N];
struct Edegs{
	int v,nxt;
}e[N];

stack<int> s;

void tarjan(int u,int fa){
	s.push(u);
	dfn[u]=low[u]=++tot;
	for(int i = head[u];~i;i = e[i].nxt){
		int v = e[i].v;
		if(v==fa)continue;
		if(!dfn[v]){
			tarjan(v,u);
			low[u] = min(low[u],low[v]);
			
		}else{
			low[u] = min(low[u],dfn[v]);
		}
	}
	if(low[u]==dfn[u]){
		while(s.top()!=u){
			s.pop();//强连通分量 
		}
	}
}

int main(){
	
	return 0;
}
