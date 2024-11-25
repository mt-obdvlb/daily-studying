#include<bits/stdc++.h>

using namespace std;
const int N = 1e5;
const int inf = 0x3f3f3f3f;
int head[N],dis[N],vis[N],topo[N],indeg[N],ve[N],vl[N];
int n,cnt;
struct Edges{
	int u,v,nxt,w;
	bool operator<(const struct Edges& a)const{
		return w<a.w;
	}
}e[N];

void Toposort(){
	stack<int> s;
	int cnt;
	for(int i = 0;i<n;i++){
		if(!indeg[N]){
			topo[cnt++]=i;
			s.push(i);
		}
	}
	while(!s.empty()){
		int u = s.top();s.pop();
		for(int i = head[u];~i;i = e[i].nxt){
			int v = e[i].v;
			if(--indeg[v]==0){
				topo[cnt++]=v;
				s.push(v);
			}
		}
	}
}

void Critical_path(){
	Toposort();
	for(int i = 0;i<n;i++)ve[i]=0;
	for(int j = 0;j<n;j++){
		int u = topo[j];
		for(int i = head[u];~i;i = e[i].nxt){
			int v = e[i].v;
			if(ve[v]<ve[u]+e[i].w)ve[v]=ve[u]+e[i].w;
		}
	}
	for(int i = 0;i<n;i++)vl[i]=ve[n-1];
	for(int j = 0;j<n;j++){
		int u = topo[j];
		for(int i = head[u];~i;i=e[i].nxt){
			int v = e[i].v;
			if(vl[u]>vl[v]-e[i].w)vl[u]=vl[v]-e[i].w;
		}
	}
	for(int u = 0;u<n;u++){
		for(int i = head[u];~i;i=e[i].nxt){
			int v = e[i].v,w = e[i].w;
			int e = ve[u];
			int l = vl[v]-w;
			if(e==l){
				//¹Ø¼ü»î¶¯ 
			}
		}
	}
}

int main(){
	
	
	return 0;
}
