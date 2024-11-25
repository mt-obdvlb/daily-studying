#include<bits/stdc++.h>

using namespace std;
const int N = 1e5;
const int inf = 0x3f3f3f3f;
int head[N],dis[N],vis[N];
int n;
struct Edges{
	int v,nxt,val;
	bool operator<(const struct Edges& a)const{
		return val<a.val;
	}
}e[N];

void Dijkstra(int u){
	priority_queue<Edges> q;
	for(int i = 0;i<n;i++){
		dis[i] = inf;
		vis[i] = 0;
	}
	for(int i = head[u];~i;i = e[i].nxt){
		int v = e[i].v;
		dis[v] = e[i].val;
		q.push(e[i]);
	}
	vis[u]=1;
	for(int i = 0;i<n;i++){
		int t = u;
		while(vis[q.top().v])q.pop();
		if(q.empty())return;
		t = q.top().v;
		vis[t]=1;
		for(int j = head[t];~j;j = e[j].nxt){
			int v = e[j].v;
			if(vis[v])continue;
			if(dis[v]>dis[t]+e[j].val)dis[v]=dis[t]+e[j].val;
			q.push(e[j]);
		}
	}
}

int main(){
	
	
	return 0;
}
