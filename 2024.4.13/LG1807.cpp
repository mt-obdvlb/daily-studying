#include<bits/stdc++.h>

using namespace std;

const int INF =0x3f3f3f3f;

int n,m,head[1505],ans,cnt,d[1505],indeg[1505];
struct edges{
	int a,b,nxt,to,w;
}e[50005];

void add(int u,int v,int w){
	e[++cnt].to = v;
	e[cnt].w = w;
	e[cnt].a = u;
	e[cnt].b = v;
	e[cnt].nxt = head[u];
	head[u] = cnt;
}

bool solve(){
	memset(d,-INF,sizeof(d));
	d[1] = 0;
	for(int i = 1;i<n;i++){
		for(int j = 1;j<=cnt;j++){
			if(d[e[j].b]<d[e[j].a]+e[j].w){
				d[e[j].b]=d[e[j].a]+e[j].w;
			}
		}
	}
	for(int j = 1;j<=cnt;j++){
			if(d[e[j].b]<d[e[j].a]+e[j].w){
				return false;
		}
	}
	return true;
}

int main(){
	cin>>n>>m;
	int u,v,w;
	if(n==1){
		cout<<0<<endl;
		return 0;
	}
	if(!m){
		cout<<-1<<endl;
		return 0;
	}
	while(m--){
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);
		indeg[v]++;
	}
	if(!indeg[n]){
		cout<<-1<<endl;
		return 0;
	}
	if(solve())cout<<d[n]<<endl;
	else cout<<-1<<endl;
	return 0;
}
