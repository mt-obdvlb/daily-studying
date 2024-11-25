#include<bits/stdc++.h>

using namespace std;
const int N = 1e5;
const int inf = 0x3f3f3f3f;
int head[N],dis[N],vis[N];
int n,cnt;
struct Edges{
	int u,v,nxt,w;
	bool operator<(const struct Edges& a)const{
		return w<a.w;
	}
}e[N];

bool Bellman_Ford(int u){
	for(int i = 0;i<n;i++)dis[i]=inf;
	dis[u]=0;
	for(int i = 1;i<n;i++){
		bool flag = 1;
		for(int j = 0;j<cnt;j++){
			if(dis[e[j].v]>dis[e[j].u]+e[j].w){
				dis[e[j].v] = dis[e[j].u]+e[j].w;
			} 
		}	
		if(flag)return false;
	}
	for(int j = 0;j<cnt;j++){
			if(dis[e[j].v]>dis[e[j].u]+e[j].w)return true;
		}	
	return false;
}


int main(){
	
	
	return 0;
} 
