#include<bits/stdc++.h>

using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 405;
const int M = 40500;
int cnt,head[N],match[N];
bool vis[N];
struct Edges{
	int v,nxt;
}e[M<<1];
void init(){
	memset(head,-1,sizeof(head));
	memset(match,0,sizeof(match));
	cnt=0;
}

void add(int u,int v){
	e[cnt].v=v;
	e[cnt].nxt=head[u];
	head[u]=cnt++;
}

bool find(int u){
	for(int i = head[u];~i;i=e[i].nxt){
		int v = e[i].v;
		if(!vis[v]){
			vis[v]=1;
			if(!match[v]||find(match[v])){
				match[v]=u;
				return true;
			}
		}
	}
	return false;
}

int main(){
	int n,m,k,v;
	while(cin>>n>>m){
		init();		
		for(int i=1;i<=n;i++){
			scanf("%d",&k);
	        for(int j=1;j<=k;j++){
				scanf("%d",&v);
	        	add(i,n+v);
			}
    	}
		int ans = 0;
		for(int i = 1;i<=n;i++){
			memset(vis,0,sizeof(vis));
			if(find(i))ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
