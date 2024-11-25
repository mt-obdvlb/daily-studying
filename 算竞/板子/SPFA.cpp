#include<bits/stdc++.h>

using namespace std;
const int N = 1e5;
const int inf = 0x3f3f3f3f;
int head[N],dis[N],vis[N],sum[N];
int n,cnt;
struct Edges{
	int u,v,nxt,w;
	bool operator<(const struct Edges& a)const{
		return w<a.w;
	}
}e[N];

bool SPFA(int s){
	for(int i = 0;i<n;i++){
		vis[i]=sum[i]=0;
		dis[i]=inf;
	}
	queue<int> q;
	q.push(s);
	vis[s]=1;
	dis[s]=0;
	while(!q.empty()){
		int u = q.front();q.pop();
		vis[u]=0;
		for(int i = head[u];~i; i = e[i].nxt){
			int v = e[i].v;
			if(dis[v]>dis[u]+e[i].w){
				dis[v]=dis[u]+e[i].w;
				if(!vis[v]){
					if(++sum[v]>=n)return true;
					vis[v]=1;
					q.push(v);
				}
			}
		}
	}
	return false;
}

int main(){
	
	return 0;
}
