#include<bits/stdc++.h>

using namespace std;
const int N = 1e5;
int n,tot,rt,dfn[N],low[N],head[N];
struct Edegs{
	int v,nxt;
}e[N];

void tarjan(int u,int fa){
	int cnt = 0;
	dfn[u]=low[u]=++tot;
	for(int i = head[u];~i;i = e[i].nxt){
		int v = e[i].v;
		if(v==fa)continue;
		if(!dfn[v]){
			tarjan(v,u);
			low[u] = min(low[u],low[v]);
			if(low[v]>dfn[u]){
				//ÇÅ 
			}
			
			if(low[v]>=dfn[u]){
				cnt++;
				if(u!=rt||cnt>1){
					//¸îµã 
				}
			}
		}else{
			low[u] = min(low[u],dfn[v]);
		}
	}
}

int main(){
	
	
	return 0;
}
