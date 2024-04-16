#include<bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;
int n,m,a[1005],c,head[1005],cnt,ans,flag,vis[1005];
struct edges{
	int nxt,to,w;
}e[10005];

void add(int u,int v,int w){
	e[++cnt].to = v;
	e[cnt].w = w;
	e[cnt].nxt = head[u];
	head[u] = cnt;
}

void dfs(int cur,int end,int sum,int a){
	if(cur==end){
		flag = 1;
		ans = min(ans,sum);
	}
	for(int i = head[cur] ; i ; i = e[i].nxt){
		int j = e[i].to;
		int w = e[i].w;
		if(w>c)continue;
		dfs(j,end,sum+a[cur]*w);
	}
}

int main(){
	cin>>n>>m;
	for(int i = 0;i<n;i++){
		cin>>a[i];
	}
	int u,v,w;
	while(m--){
		cin>>u>>v>>w;
		add(u,v,w);
	}
	int q;
	cin>>q;
	while(q--){
		cin>>c>>u>>v;
		dfs(u,v,0,0);
		ans = INF;
		flag = 0;
		if(flag)cout<<ans<<endl;
		else cout<<"impossible"<<endl;
	} 
	return 0;
}
