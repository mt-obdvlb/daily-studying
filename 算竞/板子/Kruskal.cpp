#include<bits/stdc++.h>

using namespace std;
const int N = 1e5;
const int inf = 0x3f3f3f3f;
int head[N],dis[N],vis[N],fa[N];
int n,cnt;
struct Edges{
	int u,v,nxt,w;
	bool operator<(const struct Edges& a)const{
		return w<a.w;
	}
}e[N];

int get(int x){
	return fa[x]==x?x:fa[x]=get(fa[x]);
}

void merge(int a,int b){
	fa[get(a)]=get(b);
}

int Kruskal(){
	for(int i = 0;i<=n;i++)fa[i]=i;
	sort(e,e+cnt);
	int ans = 0;
	for(int i = 0;i<cnt;i++){
		if(get(e[i].u)!=get(e[i].v)){
			merge(e[i].u,e[i].v);
			ans += e[i].w;
			if(--n==1)return ans;
		}
	}
	return 0;
}
 

int main(){
	
	return 0;
}
